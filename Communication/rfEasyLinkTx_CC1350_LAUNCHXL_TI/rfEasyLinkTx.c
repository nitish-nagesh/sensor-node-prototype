/*
 *  ======== empty_min.c ========
 */
/* XDCtools Header files */
#include <stdlib.h>
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Clock.h>
#include <stdlib.h>

/* TI-RTOS Header files */
#include <ti/drivers/PIN.h>

/* Board Header files */
#include "Board.h"

/* EasyLink API Header files */
#include "easylink/EasyLink.h"

#include "sensorDataFrame.h"
#include "wsnQueue.h"
#include <ti/drivers/I2C.h>

/* Undefine to not use async mode */
#define RFEASYLINKTX_ASYNC
#define RFEASYLINKTX_BURST_SIZE         10
#define RFEASYLINKTXPAYLOAD_LENGTH      30
#define TRANSMITTER_ADDRESS_SIZE         4

// ****** Tx Task configuration *********//
#define RFEASYLINKTX_TASK_STACK_SIZE    1024
#define RFEASYLINKTX_TASK_PRIORITY      2
Task_Struct txTask; /* not static so you can see in ROV */
static Task_Params txTaskParams;
static uint8_t txTaskStack[RFEASYLINKTX_TASK_STACK_SIZE];

// ****** Sensor data read Task configuration *********//
#define SDR_TASK_STACK_SIZE    512
#define SDR_TASK_PRIORITY      2
Task_Struct workTask;
#define STACKSIZE 1024
static uint8_t workTaskStack[SDR_TASK_STACK_SIZE];
Task_Params workTaskParams;

/* Pin driver handle */
static PIN_Handle pinHandle;
static PIN_State pinState;

/*
 * Application LED pin configuration table:
 *   - All LEDs board LEDs are off.
 */
PIN_Config pinTable[] = {
Board_LED1 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
                          Board_LED2 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW
                                  | PIN_PUSHPULL | PIN_DRVSTR_MAX,
                          PIN_TERMINATE };

static uint16_t seqNumber;
static Semaphore_Handle txDoneSem;

// *************** Globals and declarations for dataQueue
struct Queue* queue;

int dataReady = 0;
void measureTemperature(I2C_Handle *i2c, I2C_Transaction *i2cTransaction)
{
    uint16_t temperature;
    uint8_t txBuffer[1];
    uint8_t rxBuffer[2];
    /* Point to the T ambient register and read its 2 bytes */
    txBuffer[0] = 0x0001;
    i2cTransaction->slaveAddress = 0x40;
    i2cTransaction->writeBuf = txBuffer;
    i2cTransaction->writeCount = 1;
    i2cTransaction->readBuf = rxBuffer;
    i2cTransaction->readCount = 2;

    if (I2C_transfer(*i2c, i2cTransaction))
    {
        /* Extract degrees C from the received data; see TMP102 datasheet */
        temperature = (rxBuffer[0] << 6) | (rxBuffer[1] >> 2);

        /*
         * If the MSB is set '1', then we have a 2's complement
         * negative value which needs to be sign extended
         */
        if (rxBuffer[0] & 0x80)
        {
            temperature |= 0xF000;
        }
        /*
         * For simplicity, divide the temperature value by 32 to get rid of
         * the decimal precision; see TI's TMP007 datasheet
         */
        temperature /= 32;

//        Display_printf(display, 0, 0, "Sample %u: %d (C)\n", i, temperature);
    }
    else
    {
//        Display_printf(display, 0, 0, "I2C Bus fault\n");
    }

    int i = 0;

    DataFrame d;
    // since we have 28 data bytes as payload we can send 28 different parameters
    // however as the board is only measuring temperature lets fill the whole data
    // frame with same temperature value
    for (i = 0; i < 23; i++)
    {
        d.data[i] = temperature;
    }
    if (queue->size < queue->capacity)
    {
        enqueue(queue, d);
    }

}
void workTaskFunc(UArg arg0, UArg arg1)
{
    I2C_Handle i2c;
    I2C_Params i2cParams;
    I2C_Transaction i2cTransaction;

    /* Create I2C for usage */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;
    i2c = I2C_open(Board_I2C0, &i2cParams);
    if (i2c == NULL)
    {
//        Display_printf(display, 0, 0, "Error Initializing I2C\n");
        while (1)
            ;
    }
    else
    {
//        Display_printf(display, 0, 0, "I2C Initialized!\n");
    }

    while (1)
    {
        measureTemperature(&i2c, &i2cTransaction);
        /* Wait a while, because doWork should be a periodic thing, not continuous.*/
        //myDelay(24000000);
        Task_sleep(2000 * (1000 / Clock_tickPeriod));
    }
}

void txDoneCb(EasyLink_Status status)
{
    Semaphore_post(txDoneSem);
}

static void rfEasyLinkTxFnx(UArg arg0, UArg arg1)
{
    uint8_t txBurstSize = 0;

    /* Create a semaphore for Async */
    Semaphore_Params params;
    Error_Block eb;

    /* Init params */
    Semaphore_Params_init(&params);
    Error_init(&eb);

    /* Create semaphore instance */
    txDoneSem = Semaphore_create(0, &params, &eb);

    EasyLink_init(EasyLink_Phy_Custom);

    /* If you wich to use a frequency other than the default use
     * the below API
     * EasyLink_setFrequency(868000000);
     */

    /* Set output power to 12dBm */
    EasyLink_setRfPwr(12);

    while (1)
    {
        while (queue->size > 0)
        {
            dataReady = 0;
            EasyLink_TxPacket txPacket = { { 0 }, 0, 0, { 0 } };

            /* Create packet with incrementing sequence number and random payload */
            txPacket.payload[0] = (uint8_t) (seqNumber >> 8);
            txPacket.payload[1] = (uint8_t) (seqNumber++);
            uint8_t i;

            txPacket.payload[2] = 192;
            txPacket.payload[3] = 168;
            txPacket.payload[4] = 100;
            txPacket.payload[5] = 17;
            DataFrame d = dequeue(queue);
            for (i = 6; i < 28; i++)
            {
                txPacket.payload[i] = d.data[i];
            }
            txPacket.payload[28] = 13;
            txPacket.payload[29] = 10;

            txPacket.len = RFEASYLINKTXPAYLOAD_LENGTH;
            txPacket.dstAddr[0] = 0xaa;

            /* Add a Tx delay for > 500ms, so that the abort kicks in and brakes the burst */
            if (txBurstSize++ >= RFEASYLINKTX_BURST_SIZE)
            {
                /* Set Tx absolute time to current time + 1s */
                txPacket.absTime =
                        EasyLink_getAbsTime() + EasyLink_ms_To_RadioTime(1000);
                txBurstSize = 0;
            }
            /* Else set the next packet in burst to Tx in 100ms */
            else
            {
                /* Set Tx absolute time to current time + 100ms */
                txPacket.absTime =
                        EasyLink_getAbsTime() + EasyLink_ms_To_RadioTime(100);
            }

            // ACTUAL TRANSMIT HAPPENS HERE
            EasyLink_transmitAsync(&txPacket, txDoneCb);
            /* Wait 300ms for Tx to complete */
            if (Semaphore_pend(txDoneSem, (300000 / Clock_tickPeriod)) == FALSE)
            {
                /* TX timed out, abort */
                if (EasyLink_abort() == EasyLink_Status_Success)
                {
                    /*
                     * Abort will cause the txDoneCb to be called, and the txDoneSem ti
                     * Be released. So we must consume the txDoneSem
                     * */
                    Semaphore_pend(txDoneSem, BIOS_WAIT_FOREVER);
                }
            }
        }
        Task_sleep(2000 * (1000 / Clock_tickPeriod));
    }
}

void txTask_init(PIN_Handle inPinHandle)
{
    pinHandle = inPinHandle;

    Task_Params_init(&txTaskParams);
    txTaskParams.stackSize = RFEASYLINKTX_TASK_STACK_SIZE;
    txTaskParams.priority = RFEASYLINKTX_TASK_PRIORITY;
    txTaskParams.stack = &txTaskStack;
    txTaskParams.arg0 = (UInt) 1000000;

    Task_construct(&txTask, rfEasyLinkTxFnx, &txTaskParams, NULL);
}

void sensorDataTaskInit()
{
    Task_Params_init(&workTaskParams);
    workTaskParams.stackSize = SDR_TASK_STACK_SIZE;
    workTaskParams.priority = SDR_TASK_PRIORITY;
    workTaskParams.stack = &workTaskStack;
    Task_construct(&workTask, workTaskFunc, &workTaskParams, NULL);
}
/*
 *  ======== main ========
 */
int main(void)
{
    /* Call board init functions. */
    Board_initGeneral()
    ;

    /* Open LED pins */
    pinHandle = PIN_open(&pinState, pinTable);
    if (!pinHandle)
    {
        System_abort("Error initializing board LED pins\n");
    }

    /* Clear LED pins */
    PIN_setOutputValue(pinHandle, Board_LED1, 0);
    PIN_setOutputValue(pinHandle, Board_LED2, 0);
    txTask_init(pinHandle);
    sensorDataTaskInit();
    queue = createQueue(20);

    /* Start BIOS */
    BIOS_start();

    return (0);
}
