/*******************************************************************************
* File Name: Motor_1_Timer_1_PM.c
* Version 2.40
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Motor_1_Timer_1.h"
static Motor_1_Timer_1_backupStruct Motor_1_Timer_1_backup;


/*******************************************************************************
* Function Name: Motor_1_Timer_1_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Motor_1_Timer_1_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Motor_1_Timer_1_SaveConfig(void) 
{
    #if (!Motor_1_Timer_1_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for PSoC5A*/
        #if (CY_PSOC5A)
            Motor_1_Timer_1_backup.TimerUdb = Motor_1_Timer_1_ReadCounter();
            Motor_1_Timer_1_backup.TimerPeriod = Motor_1_Timer_1_ReadPeriod();
            Motor_1_Timer_1_backup.InterruptMaskValue = Motor_1_Timer_1_STATUS_MASK;
            #if (Motor_1_Timer_1_UsingHWCaptureCounter)
                Motor_1_Timer_1_backup.TimerCaptureCounter = Motor_1_Timer_1_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for PSoC5A */
        #endif /* Backup the UDB non-rentention registers for PSoC5A */

        #if (CY_PSOC3 || CY_PSOC5LP)
            Motor_1_Timer_1_backup.TimerUdb = Motor_1_Timer_1_ReadCounter();
            Motor_1_Timer_1_backup.InterruptMaskValue = Motor_1_Timer_1_STATUS_MASK;
            #if (Motor_1_Timer_1_UsingHWCaptureCounter)
                Motor_1_Timer_1_backup.TimerCaptureCounter = Motor_1_Timer_1_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for PSoC3 or PSoC5LP */

        #if(!Motor_1_Timer_1_ControlRegRemoved)
            Motor_1_Timer_1_backup.TimerControlRegister = Motor_1_Timer_1_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Motor_1_Timer_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Motor_1_Timer_1_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Motor_1_Timer_1_RestoreConfig(void) 
{   
    #if (!Motor_1_Timer_1_UsingFixedFunction)
        /* Restore the UDB non-rentention registers for PSoC5A */
        #if (CY_PSOC5A)
            /* Interrupt State Backup for Critical Region*/
            uint8 Motor_1_Timer_1_interruptState;

            Motor_1_Timer_1_WriteCounter(Motor_1_Timer_1_backup.TimerUdb);
            Motor_1_Timer_1_WritePeriod(Motor_1_Timer_1_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Motor_1_Timer_1_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            Motor_1_Timer_1_STATUS_AUX_CTRL |= Motor_1_Timer_1_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(Motor_1_Timer_1_interruptState);
            Motor_1_Timer_1_STATUS_MASK =Motor_1_Timer_1_backup.InterruptMaskValue;
            #if (Motor_1_Timer_1_UsingHWCaptureCounter)
                Motor_1_Timer_1_SetCaptureCount(Motor_1_Timer_1_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for PSoC5A */
        #endif /* Restore the UDB non-rentention registers for PSoC5A */

        #if (CY_PSOC3 || CY_PSOC5LP)
            Motor_1_Timer_1_WriteCounter(Motor_1_Timer_1_backup.TimerUdb);
            Motor_1_Timer_1_STATUS_MASK =Motor_1_Timer_1_backup.InterruptMaskValue;
            #if (Motor_1_Timer_1_UsingHWCaptureCounter)
                Motor_1_Timer_1_SetCaptureCount(Motor_1_Timer_1_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for PSoC3 or PSoC5LP */

        #if(!Motor_1_Timer_1_ControlRegRemoved)
            Motor_1_Timer_1_WriteControlRegister(Motor_1_Timer_1_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Motor_1_Timer_1_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Motor_1_Timer_1_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Motor_1_Timer_1_Sleep(void) 
{
    #if(!Motor_1_Timer_1_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Motor_1_Timer_1_CTRL_ENABLE == (Motor_1_Timer_1_CONTROL & Motor_1_Timer_1_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Motor_1_Timer_1_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Motor_1_Timer_1_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Motor_1_Timer_1_Stop();
    Motor_1_Timer_1_SaveConfig();
}


/*******************************************************************************
* Function Name: Motor_1_Timer_1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Motor_1_Timer_1_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Motor_1_Timer_1_Wakeup(void) 
{
    Motor_1_Timer_1_RestoreConfig();
    #if(!Motor_1_Timer_1_ControlRegRemoved)
        if(Motor_1_Timer_1_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Motor_1_Timer_1_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
