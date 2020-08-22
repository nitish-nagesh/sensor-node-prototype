/*******************************************************************************
* File Name: RTD_Current.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RTD_Current_H) /* Pins RTD_Current_H */
#define CY_PINS_RTD_Current_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RTD_Current_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RTD_Current__PORT == 15 && ((RTD_Current__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RTD_Current_Write(uint8 value);
void    RTD_Current_SetDriveMode(uint8 mode);
uint8   RTD_Current_ReadDataReg(void);
uint8   RTD_Current_Read(void);
void    RTD_Current_SetInterruptMode(uint16 position, uint16 mode);
uint8   RTD_Current_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RTD_Current_SetDriveMode() function.
     *  @{
     */
        #define RTD_Current_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RTD_Current_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RTD_Current_DM_RES_UP          PIN_DM_RES_UP
        #define RTD_Current_DM_RES_DWN         PIN_DM_RES_DWN
        #define RTD_Current_DM_OD_LO           PIN_DM_OD_LO
        #define RTD_Current_DM_OD_HI           PIN_DM_OD_HI
        #define RTD_Current_DM_STRONG          PIN_DM_STRONG
        #define RTD_Current_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RTD_Current_MASK               RTD_Current__MASK
#define RTD_Current_SHIFT              RTD_Current__SHIFT
#define RTD_Current_WIDTH              1u

/* Interrupt constants */
#if defined(RTD_Current__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RTD_Current_SetInterruptMode() function.
     *  @{
     */
        #define RTD_Current_INTR_NONE      (uint16)(0x0000u)
        #define RTD_Current_INTR_RISING    (uint16)(0x0001u)
        #define RTD_Current_INTR_FALLING   (uint16)(0x0002u)
        #define RTD_Current_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RTD_Current_INTR_MASK      (0x01u) 
#endif /* (RTD_Current__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RTD_Current_PS                     (* (reg8 *) RTD_Current__PS)
/* Data Register */
#define RTD_Current_DR                     (* (reg8 *) RTD_Current__DR)
/* Port Number */
#define RTD_Current_PRT_NUM                (* (reg8 *) RTD_Current__PRT) 
/* Connect to Analog Globals */                                                  
#define RTD_Current_AG                     (* (reg8 *) RTD_Current__AG)                       
/* Analog MUX bux enable */
#define RTD_Current_AMUX                   (* (reg8 *) RTD_Current__AMUX) 
/* Bidirectional Enable */                                                        
#define RTD_Current_BIE                    (* (reg8 *) RTD_Current__BIE)
/* Bit-mask for Aliased Register Access */
#define RTD_Current_BIT_MASK               (* (reg8 *) RTD_Current__BIT_MASK)
/* Bypass Enable */
#define RTD_Current_BYP                    (* (reg8 *) RTD_Current__BYP)
/* Port wide control signals */                                                   
#define RTD_Current_CTL                    (* (reg8 *) RTD_Current__CTL)
/* Drive Modes */
#define RTD_Current_DM0                    (* (reg8 *) RTD_Current__DM0) 
#define RTD_Current_DM1                    (* (reg8 *) RTD_Current__DM1)
#define RTD_Current_DM2                    (* (reg8 *) RTD_Current__DM2) 
/* Input Buffer Disable Override */
#define RTD_Current_INP_DIS                (* (reg8 *) RTD_Current__INP_DIS)
/* LCD Common or Segment Drive */
#define RTD_Current_LCD_COM_SEG            (* (reg8 *) RTD_Current__LCD_COM_SEG)
/* Enable Segment LCD */
#define RTD_Current_LCD_EN                 (* (reg8 *) RTD_Current__LCD_EN)
/* Slew Rate Control */
#define RTD_Current_SLW                    (* (reg8 *) RTD_Current__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RTD_Current_PRTDSI__CAPS_SEL       (* (reg8 *) RTD_Current__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RTD_Current_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RTD_Current__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RTD_Current_PRTDSI__OE_SEL0        (* (reg8 *) RTD_Current__PRTDSI__OE_SEL0) 
#define RTD_Current_PRTDSI__OE_SEL1        (* (reg8 *) RTD_Current__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RTD_Current_PRTDSI__OUT_SEL0       (* (reg8 *) RTD_Current__PRTDSI__OUT_SEL0) 
#define RTD_Current_PRTDSI__OUT_SEL1       (* (reg8 *) RTD_Current__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RTD_Current_PRTDSI__SYNC_OUT       (* (reg8 *) RTD_Current__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RTD_Current__SIO_CFG)
    #define RTD_Current_SIO_HYST_EN        (* (reg8 *) RTD_Current__SIO_HYST_EN)
    #define RTD_Current_SIO_REG_HIFREQ     (* (reg8 *) RTD_Current__SIO_REG_HIFREQ)
    #define RTD_Current_SIO_CFG            (* (reg8 *) RTD_Current__SIO_CFG)
    #define RTD_Current_SIO_DIFF           (* (reg8 *) RTD_Current__SIO_DIFF)
#endif /* (RTD_Current__SIO_CFG) */

/* Interrupt Registers */
#if defined(RTD_Current__INTSTAT)
    #define RTD_Current_INTSTAT            (* (reg8 *) RTD_Current__INTSTAT)
    #define RTD_Current_SNAP               (* (reg8 *) RTD_Current__SNAP)
    
	#define RTD_Current_0_INTTYPE_REG 		(* (reg8 *) RTD_Current__0__INTTYPE)
#endif /* (RTD_Current__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RTD_Current_H */


/* [] END OF FILE */
