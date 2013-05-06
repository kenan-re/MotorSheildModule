/*******************************************************************************
* File Name: Motor_1_PWM_6_PM.c
* Version 2.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include "cytypes.h"
#include "Motor_1_PWM_6.h"

static Motor_1_PWM_6_backupStruct Motor_1_PWM_6_backup;


/*******************************************************************************
* Function Name: Motor_1_PWM_6_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  Motor_1_PWM_6_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Motor_1_PWM_6_SaveConfig(void) 
{
    
    #if(!Motor_1_PWM_6_UsingFixedFunction)
        #if (CY_PSOC5A)
            Motor_1_PWM_6_backup.PWMUdb = Motor_1_PWM_6_ReadCounter();
            Motor_1_PWM_6_backup.PWMPeriod = Motor_1_PWM_6_ReadPeriod();
            #if (Motor_1_PWM_6_UseStatus)
                Motor_1_PWM_6_backup.InterruptMaskValue = Motor_1_PWM_6_STATUS_MASK;
            #endif /* (Motor_1_PWM_6_UseStatus) */
            
            #if(Motor_1_PWM_6_UseOneCompareMode)
                Motor_1_PWM_6_backup.PWMCompareValue = Motor_1_PWM_6_ReadCompare();
            #else
                Motor_1_PWM_6_backup.PWMCompareValue1 = Motor_1_PWM_6_ReadCompare1();
                Motor_1_PWM_6_backup.PWMCompareValue2 = Motor_1_PWM_6_ReadCompare2();
            #endif /* (Motor_1_PWM_6_UseOneCompareMode) */
            
           #if(Motor_1_PWM_6_DeadBandUsed)
                Motor_1_PWM_6_backup.PWMdeadBandValue = Motor_1_PWM_6_ReadDeadTime();
            #endif /* (Motor_1_PWM_6_DeadBandUsed) */
          
            #if ( Motor_1_PWM_6_KillModeMinTime)
                Motor_1_PWM_6_backup.PWMKillCounterPeriod = Motor_1_PWM_6_ReadKillTime();
            #endif /* ( Motor_1_PWM_6_KillModeMinTime) */
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            #if(!Motor_1_PWM_6_PWMModeIsCenterAligned)
                Motor_1_PWM_6_backup.PWMPeriod = Motor_1_PWM_6_ReadPeriod();
            #endif /* (!Motor_1_PWM_6_PWMModeIsCenterAligned) */
            Motor_1_PWM_6_backup.PWMUdb = Motor_1_PWM_6_ReadCounter();
            #if (Motor_1_PWM_6_UseStatus)
                Motor_1_PWM_6_backup.InterruptMaskValue = Motor_1_PWM_6_STATUS_MASK;
            #endif /* (Motor_1_PWM_6_UseStatus) */
            
            #if(Motor_1_PWM_6_DeadBandMode == Motor_1_PWM_6__B_PWM__DBM_256_CLOCKS || \
                Motor_1_PWM_6_DeadBandMode == Motor_1_PWM_6__B_PWM__DBM_2_4_CLOCKS)
                Motor_1_PWM_6_backup.PWMdeadBandValue = Motor_1_PWM_6_ReadDeadTime();
            #endif /*  deadband count is either 2-4 clocks or 256 clocks */
            
            #if(Motor_1_PWM_6_KillModeMinTime)
                 Motor_1_PWM_6_backup.PWMKillCounterPeriod = Motor_1_PWM_6_ReadKillTime();
            #endif /* (Motor_1_PWM_6_KillModeMinTime) */
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(Motor_1_PWM_6_UseControl)
            Motor_1_PWM_6_backup.PWMControlRegister = Motor_1_PWM_6_ReadControlRegister();
        #endif /* (Motor_1_PWM_6_UseControl) */
    #endif  /* (!Motor_1_PWM_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Motor_1_PWM_6_RestoreConfig
********************************************************************************
* 
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  Motor_1_PWM_6_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Motor_1_PWM_6_RestoreConfig(void) 
{
        #if(!Motor_1_PWM_6_UsingFixedFunction)
            #if (CY_PSOC5A)
                /* Interrupt State Backup for Critical Region*/
                uint8 Motor_1_PWM_6_interruptState;
                /* Enter Critical Region*/
                Motor_1_PWM_6_interruptState = CyEnterCriticalSection();
                #if (Motor_1_PWM_6_UseStatus)
                    /* Use the interrupt output of the status register for IRQ output */
                    Motor_1_PWM_6_STATUS_AUX_CTRL |= Motor_1_PWM_6_STATUS_ACTL_INT_EN_MASK;
                    
                    Motor_1_PWM_6_STATUS_MASK = Motor_1_PWM_6_backup.InterruptMaskValue;
                #endif /* (Motor_1_PWM_6_UseStatus) */
                
                #if (Motor_1_PWM_6_Resolution == 8)
                    /* Set FIFO 0 to 1 byte register for period*/
                    Motor_1_PWM_6_AUX_CONTROLDP0 |= (Motor_1_PWM_6_AUX_CTRL_FIFO0_CLR);
                #else /* (Motor_1_PWM_6_Resolution == 16)*/
                    /* Set FIFO 0 to 1 byte register for period */
                    Motor_1_PWM_6_AUX_CONTROLDP0 |= (Motor_1_PWM_6_AUX_CTRL_FIFO0_CLR);
                    Motor_1_PWM_6_AUX_CONTROLDP1 |= (Motor_1_PWM_6_AUX_CTRL_FIFO0_CLR);
                #endif /* (Motor_1_PWM_6_Resolution == 8) */
                /* Exit Critical Region*/
                CyExitCriticalSection(Motor_1_PWM_6_interruptState);
                
                Motor_1_PWM_6_WriteCounter(Motor_1_PWM_6_backup.PWMUdb);
                Motor_1_PWM_6_WritePeriod(Motor_1_PWM_6_backup.PWMPeriod);
                
                #if(Motor_1_PWM_6_UseOneCompareMode)
                    Motor_1_PWM_6_WriteCompare(Motor_1_PWM_6_backup.PWMCompareValue);
                #else
                    Motor_1_PWM_6_WriteCompare1(Motor_1_PWM_6_backup.PWMCompareValue1);
                    Motor_1_PWM_6_WriteCompare2(Motor_1_PWM_6_backup.PWMCompareValue2);
                #endif /* (Motor_1_PWM_6_UseOneCompareMode) */
                
               #if(Motor_1_PWM_6_DeadBandMode == Motor_1_PWM_6__B_PWM__DBM_256_CLOCKS || \
                   Motor_1_PWM_6_DeadBandMode == Motor_1_PWM_6__B_PWM__DBM_2_4_CLOCKS)
                    Motor_1_PWM_6_WriteDeadTime(Motor_1_PWM_6_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
                #if ( Motor_1_PWM_6_KillModeMinTime)
                    Motor_1_PWM_6_WriteKillTime(Motor_1_PWM_6_backup.PWMKillCounterPeriod);
                #endif /* ( Motor_1_PWM_6_KillModeMinTime) */
            #endif /* (CY_PSOC5A) */
            
            #if (CY_PSOC3 || CY_PSOC5LP)
                #if(!Motor_1_PWM_6_PWMModeIsCenterAligned)
                    Motor_1_PWM_6_WritePeriod(Motor_1_PWM_6_backup.PWMPeriod);
                #endif /* (!Motor_1_PWM_6_PWMModeIsCenterAligned) */
                Motor_1_PWM_6_WriteCounter(Motor_1_PWM_6_backup.PWMUdb);
                #if (Motor_1_PWM_6_UseStatus)
                    Motor_1_PWM_6_STATUS_MASK = Motor_1_PWM_6_backup.InterruptMaskValue;
                #endif /* (Motor_1_PWM_6_UseStatus) */
                
                #if(Motor_1_PWM_6_DeadBandMode == Motor_1_PWM_6__B_PWM__DBM_256_CLOCKS || \
                    Motor_1_PWM_6_DeadBandMode == Motor_1_PWM_6__B_PWM__DBM_2_4_CLOCKS)
                    Motor_1_PWM_6_WriteDeadTime(Motor_1_PWM_6_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
                
                #if(Motor_1_PWM_6_KillModeMinTime)
                    Motor_1_PWM_6_WriteKillTime(Motor_1_PWM_6_backup.PWMKillCounterPeriod);
                #endif /* (Motor_1_PWM_6_KillModeMinTime) */
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            
            #if(Motor_1_PWM_6_UseControl)
                Motor_1_PWM_6_WriteControlRegister(Motor_1_PWM_6_backup.PWMControlRegister); 
            #endif /* (Motor_1_PWM_6_UseControl) */
        #endif  /* (!Motor_1_PWM_6_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Motor_1_PWM_6_Sleep
********************************************************************************
* 
* Summary:
*  Disables block's operation and saves the user configuration. Should be called 
*  just prior to entering sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  Motor_1_PWM_6_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Motor_1_PWM_6_Sleep(void) 
{
    #if(Motor_1_PWM_6_UseControl)
        if(Motor_1_PWM_6_CTRL_ENABLE == (Motor_1_PWM_6_CONTROL & Motor_1_PWM_6_CTRL_ENABLE))
        {
            /*Component is enabled */
            Motor_1_PWM_6_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Motor_1_PWM_6_backup.PWMEnableState = 0u;
        }
    #endif /* (Motor_1_PWM_6_UseControl) */

    /* Stop component */
    Motor_1_PWM_6_Stop();
    
    /* Save registers configuration */
    Motor_1_PWM_6_SaveConfig();
}


/*******************************************************************************
* Function Name: Motor_1_PWM_6_Wakeup
********************************************************************************
* 
* Summary:
*  Restores and enables the user configuration. Should be called just after 
*  awaking from sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  Motor_1_PWM_6_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Motor_1_PWM_6_Wakeup(void) 
{
     /* Restore registers values */
    Motor_1_PWM_6_RestoreConfig();
    
    if(Motor_1_PWM_6_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Motor_1_PWM_6_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
