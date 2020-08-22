/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include<removeOffsetNoise.h>
#include<getResistance.h>
#include<stdio.h>
int main(void)
{
   
	/* Calculated RTD resistance */
	int32 rtdRes = 0;
    
    /* Calculated temperature in 1/100th of degree celcius using RTD sensor resistance */
    int32 rtdTemp = 0;
	
	/* Voltage(ADC counts) across reference resistance */
	int32 vRef;
    
    /*Decimal Temp*/
    int32 decTemp;
    
    /*Fractional Temp*/
    int32 fracTemp;
    
	/* LCD display variable */
	char printBuf[16]={'\0'};
    
    CyGlobalIntEnable; /* Enable global interrupts. */
	
	/* Start LCD, ADC and IDAC; Initialize LCD */
	LCD_Start();
    LCD_Position(0,0);
    LCD_PrintString("RTD Temperature");
	ADCMux_Start();
    CurrentMux_Start();
	ADC_Start();
	IDAC_Start();
    UART_Start();
    

    for(;;)
    {
       /* Measure the voltage across reference resistance */
		vRef = MeasureRefResVoltage();
		
		/* Find the RTD resistance */
		rtdRes = GetRTDRes(vRef);
        /* Calculate RTD temperature from resistance */
		rtdTemp = RTD_GetTemperature(rtdRes);
		
        /*Determine decimal portion of temperature by dividing temperature by 100*/
        decTemp = rtdTemp/100;
        
        /*Determine fraction portion of temperature by subtracting decimal portion from result*/
        fracTemp = rtdTemp - (decTemp * 100);   
        /*If fractional temperature is negative make it positive*/
        if(fracTemp < 0)
        {
            fracTemp *= -1;
        }
        
        /*format string to print out over UART*/
        sprintf(printBuf, "RTD Temp=%ld.%02ld    ", decTemp, fracTemp); 
		
        /*Print result over UART*/
        UART_PutString(printBuf);
        UART_PutString("\n\r");
        
		/* Display RTD temperature */
		LCD_Position(1,0);
		
        /*Print out temperature*/
		LCD_PrintString(printBuf);
	}
}
    


/* [] END OF FILE */
