/*******************************************************************************
* File Name: R_ref_positive.h  
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

#if !defined(CY_PINS_R_ref_positive_H) /* Pins R_ref_positive_H */
#define CY_PINS_R_ref_positive_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "R_ref_positive_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 R_ref_positive__PORT == 15 && ((R_ref_positive__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    R_ref_positive_Write(uint8 value);
void    R_ref_positive_SetDriveMode(uint8 mode);
uint8   R_ref_positive_ReadDataReg(void);
uint8   R_ref_positive_Read(void);
void    R_ref_positive_SetInterruptMode(uint16 position, uint16 mode);
uint8   R_ref_positive_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the R_ref_positive_SetDriveMode() function.
     *  @{
     */
        #define R_ref_positive_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define R_ref_positive_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define R_ref_positive_DM_RES_UP          PIN_DM_RES_UP
        #define R_ref_positive_DM_RES_DWN         PIN_DM_RES_DWN
        #define R_ref_positive_DM_OD_LO           PIN_DM_OD_LO
        #define R_ref_positive_DM_OD_HI           PIN_DM_OD_HI
        #define R_ref_positive_DM_STRONG          PIN_DM_STRONG
        #define R_ref_positive_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define R_ref_positive_MASK               R_ref_positive__MASK
#define R_ref_positive_SHIFT              R_ref_positive__SHIFT
#define R_ref_positive_WIDTH              1u

/* Interrupt constants */
#if defined(R_ref_positive__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in R_ref_positive_SetInterruptMode() function.
     *  @{
     */
        #define R_ref_positive_INTR_NONE      (uint16)(0x0000u)
        #define R_ref_positive_INTR_RISING    (uint16)(0x0001u)
        #define R_ref_positive_INTR_FALLING   (uint16)(0x0002u)
        #define R_ref_positive_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define R_ref_positive_INTR_MASK      (0x01u) 
#endif /* (R_ref_positive__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define R_ref_positive_PS                     (* (reg8 *) R_ref_positive__PS)
/* Data Register */
#define R_ref_positive_DR                     (* (reg8 *) R_ref_positive__DR)
/* Port Number */
#define R_ref_positive_PRT_NUM                (* (reg8 *) R_ref_positive__PRT) 
/* Connect to Analog Globals */                                                  
#define R_ref_positive_AG                     (* (reg8 *) R_ref_positive__AG)                       
/* Analog MUX bux enable */
#define R_ref_positive_AMUX                   (* (reg8 *) R_ref_positive__AMUX) 
/* Bidirectional Enable */                                                        
#define R_ref_positive_BIE                    (* (reg8 *) R_ref_positive__BIE)
/* Bit-mask for Aliased Register Access */
#define R_ref_positive_BIT_MASK               (* (reg8 *) R_ref_positive__BIT_MASK)
/* Bypass Enable */
#define R_ref_positive_BYP                    (* (reg8 *) R_ref_positive__BYP)
/* Port wide control signals */                                                   
#define R_ref_positive_CTL                    (* (reg8 *) R_ref_positive__CTL)
/* Drive Modes */
#define R_ref_positive_DM0                    (* (reg8 *) R_ref_positive__DM0) 
#define R_ref_positive_DM1                    (* (reg8 *) R_ref_positive__DM1)
#define R_ref_positive_DM2                    (* (reg8 *) R_ref_positive__DM2) 
/* Input Buffer Disable Override */
#define R_ref_positive_INP_DIS                (* (reg8 *) R_ref_positive__INP_DIS)
/* LCD Common or Segment Drive */
#define R_ref_positive_LCD_COM_SEG            (* (reg8 *) R_ref_positive__LCD_COM_SEG)
/* Enable Segment LCD */
#define R_ref_positive_LCD_EN                 (* (reg8 *) R_ref_positive__LCD_EN)
/* Slew Rate Control */
#define R_ref_positive_SLW                    (* (reg8 *) R_ref_positive__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define R_ref_positive_PRTDSI__CAPS_SEL       (* (reg8 *) R_ref_positive__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define R_ref_positive_PRTDSI__DBL_SYNC_IN    (* (reg8 *) R_ref_positive__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define R_ref_positive_PRTDSI__OE_SEL0        (* (reg8 *) R_ref_positive__PRTDSI__OE_SEL0) 
#define R_ref_positive_PRTDSI__OE_SEL1        (* (reg8 *) R_ref_positive__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define R_ref_positive_PRTDSI__OUT_SEL0       (* (reg8 *) R_ref_positive__PRTDSI__OUT_SEL0) 
#define R_ref_positive_PRTDSI__OUT_SEL1       (* (reg8 *) R_ref_positive__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define R_ref_positive_PRTDSI__SYNC_OUT       (* (reg8 *) R_ref_positive__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(R_ref_positive__SIO_CFG)
    #define R_ref_positive_SIO_HYST_EN        (* (reg8 *) R_ref_positive__SIO_HYST_EN)
    #define R_ref_positive_SIO_REG_HIFREQ     (* (reg8 *) R_ref_positive__SIO_REG_HIFREQ)
    #define R_ref_positive_SIO_CFG            (* (reg8 *) R_ref_positive__SIO_CFG)
    #define R_ref_positive_SIO_DIFF           (* (reg8 *) R_ref_positive__SIO_DIFF)
#endif /* (R_ref_positive__SIO_CFG) */

/* Interrupt Registers */
#if defined(R_ref_positive__INTSTAT)
    #define R_ref_positive_INTSTAT            (* (reg8 *) R_ref_positive__INTSTAT)
    #define R_ref_positive_SNAP               (* (reg8 *) R_ref_positive__SNAP)
    
	#define R_ref_positive_0_INTTYPE_REG 		(* (reg8 *) R_ref_positive__0__INTTYPE)
#endif /* (R_ref_positive__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_R_ref_positive_H */


/* [] END OF FILE */
