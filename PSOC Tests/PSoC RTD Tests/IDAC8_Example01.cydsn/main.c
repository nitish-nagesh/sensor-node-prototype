/*******************************************************************************
* File: main.c
*
* Version: 1.2
*
* Description: 
*   This is a source code for basic functionality of IDAC8.
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>
#include <stdio.h>


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Main function performs following functions:
*   1: Initializes the LCD and clears the display
*   2: Start the IDAC
*   3: IDAC range is set to 255uA and value to 100
*   4: Prints test name on LCD
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
int main()
{
    char ch = 'A';
    int16 output;
	char8 str[10];
    /* Start the IDAC component */
    IDAC8_1_Start();    
    ADC_DelSig_1_Start();
    UART_1_Start();
    
   
    /* Sets the IDAC full scale range to 255uA */
    IDAC8_1_SetRange(IDAC8_1_RANGE_2mA);    

    /* Sets the IDAC value to 100 */
    IDAC8_1_SetValue(253u);     
    
    /* Start the ADC conversion */
    ADC_DelSig_1_StartConvert();

//  /*  
    
    
// */
    
    
    for(;;)
    {
    if(ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_RETURN_STATUS))
        {
            output = ADC_DelSig_1_GetResult16();
			output = ADC_DelSig_1_CountsTo_mVolts(output) ;
			sprintf(str, "%d", output);
            CyDelay(100u);
            UART_1_PutString(str);
        }
        UART_1_PutString("\n"); 
    }
    
}


/* [] END OF FILE */

