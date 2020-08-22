/*******************************************************************************
* File Name: RTD_Current.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RTD_Current_ALIASES_H) /* Pins RTD_Current_ALIASES_H */
#define CY_PINS_RTD_Current_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define RTD_Current_0			(RTD_Current__0__PC)
#define RTD_Current_0_INTR	((uint16)((uint16)0x0001u << RTD_Current__0__SHIFT))

#define RTD_Current_INTR_ALL	 ((uint16)(RTD_Current_0_INTR))

#endif /* End Pins RTD_Current_ALIASES_H */


/* [] END OF FILE */
