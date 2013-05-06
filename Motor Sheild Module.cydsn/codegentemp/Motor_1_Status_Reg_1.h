/*******************************************************************************
* File Name: Motor_1_Status_Reg_1.h  
* Version 1.80
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_Motor_1_Status_Reg_1_H) /* CY_STATUS_REG_Motor_1_Status_Reg_1_H */
#define CY_STATUS_REG_Motor_1_Status_Reg_1_H

#include "cytypes.h"
#include "CyLib.h"


/***************************************
*        Function Prototypes
***************************************/

uint8 Motor_1_Status_Reg_1_Read(void) ;
void Motor_1_Status_Reg_1_InterruptEnable(void) ;
void Motor_1_Status_Reg_1_InterruptDisable(void) ;
void Motor_1_Status_Reg_1_WriteMask(uint8 mask) ;
uint8 Motor_1_Status_Reg_1_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define Motor_1_Status_Reg_1_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define Motor_1_Status_Reg_1_INPUTS              3


/***************************************
*             Registers
***************************************/

/* Status Register */
#define Motor_1_Status_Reg_1_Status             (* (reg8 *) Motor_1_Status_Reg_1_sts_sts_reg__STATUS_REG )
#define Motor_1_Status_Reg_1_Status_PTR         (  (reg8 *) Motor_1_Status_Reg_1_sts_sts_reg__STATUS_REG )
#define Motor_1_Status_Reg_1_Status_Mask        (* (reg8 *) Motor_1_Status_Reg_1_sts_sts_reg__MASK_REG )
#define Motor_1_Status_Reg_1_Status_Aux_Ctrl    (* (reg8 *) Motor_1_Status_Reg_1_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_Motor_1_Status_Reg_1_H */


/* [] END OF FILE */
