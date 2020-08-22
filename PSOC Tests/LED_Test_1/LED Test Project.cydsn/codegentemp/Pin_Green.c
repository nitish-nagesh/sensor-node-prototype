/*******************************************************************************
* File Name: Pin_Green.c  
* Version 1.70
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "Pin_Green.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_Green__PORT == 15 && (Pin_Green__MASK & 0xC0))

/*******************************************************************************
* Function Name: Pin_Green_Write
********************************************************************************
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  void 
*  
*******************************************************************************/
void Pin_Green_Write(uint8 value) 
{
    uint8 staticBits = Pin_Green_DR & ~Pin_Green_MASK;
    Pin_Green_DR = staticBits | ((value << Pin_Green_SHIFT) & Pin_Green_MASK);
}


/*******************************************************************************
* Function Name: Pin_Green_SetDriveMode
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  void
*
*******************************************************************************/
void Pin_Green_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Pin_Green_0, mode);
}


/*******************************************************************************
* Function Name: Pin_Green_Read
********************************************************************************
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Pin_Green_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pin_Green_Read(void) 
{
    return (Pin_Green_PS & Pin_Green_MASK) >> Pin_Green_SHIFT;
}


/*******************************************************************************
* Function Name: Pin_Green_ReadDataReg
********************************************************************************
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Pin_Green_ReadDataReg(void) 
{
    return (Pin_Green_DR & Pin_Green_MASK) >> Pin_Green_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pin_Green_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pin_Green_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  void 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Pin_Green_ClearInterrupt(void) 
    {
        return (Pin_Green_INTSTAT & Pin_Green_MASK) >> Pin_Green_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif
/* [] END OF FILE */ 
