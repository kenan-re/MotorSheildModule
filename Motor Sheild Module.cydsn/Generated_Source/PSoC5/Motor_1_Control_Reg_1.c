/*******************************************************************************
* File Name: Motor_1_Control_Reg_1.c  
* Version 1.70
*
* Description:
*  This file contains API to enable firmware control of a Control Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Motor_1_Control_Reg_1.h"

#if !defined(Motor_1_Control_Reg_1_Async_ctrl_reg__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
* Function Name: Motor_1_Control_Reg_1_Write
********************************************************************************
*
* Summary:
*  Write a byte to the Control Register.
*
* Parameters:
*  control:  The value to be assigned to the Control Register.
*
* Return:
*  None.
*
*******************************************************************************/
void Motor_1_Control_Reg_1_Write(uint8 control) 
{
    Motor_1_Control_Reg_1_Control = control;
}


/*******************************************************************************
* Function Name: Motor_1_Control_Reg_1_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Control Register.
*
* Parameters:
*  None.
*
* Return:
*  Returns the current value in the Control Register.
*
*******************************************************************************/
uint8 Motor_1_Control_Reg_1_Read(void) 
{
    return Motor_1_Control_Reg_1_Control;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */