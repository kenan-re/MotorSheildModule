/*******************************************************************************
* File Name: Motor_1_PWM_10_PM.c
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
#include "Motor_1_PWM_10.h"

static Motor_1_PWM_10_backupStruct Motor_1_PWM_10_backup;


/*******************************************************************************
* Function Name: Motor_1_PWM_10_SaveConfig
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
*  Motor_1_PWM_10_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Motor_1_PWM_10_SaveConfig(void) 
{
    
    #if(!Motor_1_PWM_10_UsingFixedFunction)
        #if (CY_PSOC5A)
            Motor_1_PWM_10_backup.PWMUdb = Motor_1_PWM_10_ReadCounter();
            Motor_1_PWM_10_backup.PWMPeriod = Motor_1_PWM_10_ReadPeriod();
            #if (Motor_1_PWM_10_UseStatus)
                Motor_1_PWM_10_backup.InterruptMaskValue = Motor_1_PWM_10_STATUS_MASK;
            #endif /* (Motor_1_PWM_10_UseStatus) */
            
            #if(Motor_1_PWM_10_UseOneCompareMode)
                Motor_1_PWM_10_backup.PWMCompareValue = Motor_1_PWM_10_ReadCompare();
            #else
                Motor_1_PWM_10_backup.PWMCompareValue1 = Motor_1_PWM_10_ReadCompare1();
                Motor_1_PWM_10_backup.PWMCompareValue2 = Motor_1_PWM_10_ReadCompare2();
            #endif /* (Motor_1_PWM_10_UseOneCompareMode) */
            
           #if(Motor_1_PWM_10_DeadBandUsed)
                Motor_1_PWM_10_backup.PWMdeadBandValue = Motor_1_PWM_10_ReadDeadTime();
            #endif /* (Motor_1_PWM_10_DeadBandUsed) */
          
            #if ( Motor_1_PWM_10_KillModeMinTime)
                Motor_1_PWM_10_backup.PWMKillCounterPeriod = Motor_1_PWM_10_ReadKillTime();
            #endif /* ( Motor_1_PWM_10_KillModeMinTime) */
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            #if(!Motor_1_PWM_10_PWMModeIsCenterAligned)
                Motor_1_PWM_10_backup.PWMPeriod = Motor_1_PWM_10_ReadPeriod();
            #endif /* (!Motor_1_PWM_10_PWMModeIsCenterAligned) */
            Motor_1_PWM_10_backup.PWMUdb = Motor_1_PWM_10_ReadCounter();
            #if (Motor_1_PWM_10_UseStatus)
                Motor_1_PWM_10_backup.InterruptMaskValue = Motor_1_PWM_10_STATUS_MASK;
            #endif /* (Motor_1_PWM_10_UseStatus) */
            
            #if(Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_256_CLOCKS || \
                Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_2_4_CLOCKS)
                Motor_1_PWM_10_backup.PWMdeadBandValue = Motor_1_PWM_10_ReadDeadTime();
            #endif /*  deadband count is either 2-4 clocks or 256 clocks */
            
            #if(Motor_1_PWM_10_KillModeMinTime)
                 Motor_1_PWM_10_backup.PWMKillCounterPeriod = Motor_1_PWM_10_ReadKillTime();
            #endif /* (Motor_1_PWM_10_KillModeMinTime) */
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(Motor_1_PWM_10_UseControl)
            Motor_1_PWM_10_backup.PWMControlRegister = Motor_1_PWM_10_ReadControlRegister();
        #endif /* (Motor_1_PWM_10_UseControl) */
    #endif  /* (!Motor_1_PWM_10_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Motor_1_PWM_10_RestoreConfig
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
*  Motor_1_PWM_10_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Motor_1_PWM_10_RestoreConfig(void) 
{
        #if(!Motor_1_PWM_10_UsingFixedFunction)
            #if (CY_PSOC5A)
                /* Interrupt State Backup for Critical Region*/
                uint8 Motor_1_PWM_10_interruptState;
                /* Enter Critical Region*/
                Motor_1_PWM_10_interruptState = CyEnterCriticalSection();
                #if (Motor_1_PWM_10_UseStatus)
                    /* Use the interrupt output of the status register for IRQ output */
                    Motor_1_PWM_10_STATUS_AUX_CTRL |= Motor_1_PWM_10_STATUS_ACTL_INT_EN_MASK;
                    
                    Motor_1_PWM_10_STATUS_MASK = Motor_1_PWM_10_backup.InterruptMaskValue;
                #endif /* (Motor_1_PWM_10_UseStatus) */
                
                #if (Motor_1_PWM_10_Resolution == 8)
                    /* Set FIFO 0 to 1 byte register for period*/
                    Motor_1_PWM_10_AUX_CONTROLDP0 |= (Motor_1_PWM_10_AUX_CTRL_FIFO0_CLR);
                #else /* (Motor_1_PWM_10_Resolution == 16)*/
                    /* Set FIFO 0 to 1 byte register for period */
                    Motor_1_PWM_10_AUX_CONTROLDP0 |= (Motor_1_PWM_10_AUX_CTRL_FIFO0_CLR);
                    Motor_1_PWM_10_AUX_CONTROLDP1 |= (Motor_1_PWM_10_AUX_CTRL_FIFO0_CLR);
                #endif /* (Motor_1_PWM_10_Resolution == 8) */
                /* Exit Critical Region*/
                CyExitCriticalSection(Motor_1_PWM_10_interruptState);
                
                Motor_1_PWM_10_WriteCounter(Motor_1_PWM_10_backup.PWMUdb);
                Motor_1_PWM_10_WritePeriod(Motor_1_PWM_10_backup.PWMPeriod);
                
                #if(Motor_1_PWM_10_UseOneCompareMode)
                    Motor_1_PWM_10_WriteCompare(Motor_1_PWM_10_backup.PWMCompareValue);
                #else
                    Motor_1_PWM_10_WriteCompare1(Motor_1_PWM_10_backup.PWMCompareValue1);
                    Motor_1_PWM_10_WriteCompare2(Motor_1_PWM_10_backup.PWMCompareValue2);
                #endif /* (Motor_1_PWM_10_UseOneCompareMode) */
                
               #if(Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_256_CLOCKS || \
                   Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_2_4_CLOCKS)
                    Motor_1_PWM_10_WriteDeadTime(Motor_1_PWM_10_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
                #if ( Motor_1_PWM_10_KillModeMinTime)
                    Motor_1_PWM_10_WriteKillTime(Motor_1_PWM_10_backup.PWMKillCounterPeriod);
                #endif /* ( Motor_1_PWM_10_KillModeMinTime) */
            #endif /* (CY_PSOC5A) */
            
            #if (CY_PSOC3 || CY_PSOC5LP)
                #if(!Motor_1_PWM_10_PWMModeIsCenterAligned)
                    Motor_1_PWM_10_WritePeriod(Motor_1_PWM_10_backup.PWMPeriod);
                #endif /* (!Motor_1_PWM_10_PWMModeIsCenterAligned) */
                Motor_1_PWM_10_WriteCounter(Motor_1_PWM_10_backup.PWMUdb);
                #if (Motor_1_PWM_10_UseStatus)
                    Motor_1_PWM_10_STATUS_MASK = Motor_1_PWM_10_backup.InterruptMaskValue;
                #endif /* (Motor_1_PWM_10_UseStatus) */
                
                #if(Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_256_CLOCKS || \
                    Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_2_4_CLOCKS)
                    Motor_1_PWM_10_WriteDeadTime(Motor_1_PWM_10_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
                
                #if(Motor_1_PWM_10_KillModeMinTime)
                    Motor_1_PWM_10_WriteKillTime(Motor_1_PWM_10_backup.PWMKillCounterPeriod);
                #endif /* (Motor_1_PWM_10_KillModeMinTime) */
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            
            #if(Motor_1_PWM_10_UseControl)
                Motor_1_PWM_10_WriteControlRegister(Motor_1_PWM_10_backup.PWMControlRegister); 
            #endif /* (Motor_1_PWM_10_UseControl) */
        #endif  /* (!Motor_1_PWM_10_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Motor_1_PWM_10_Sleep
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
*  Motor_1_PWM_10_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Motor_1_PWM_10_Sleep(void) 
{
    #if(Motor_1_PWM_10_UseControl)
        if(Motor_1_PWM_10_CTRL_ENABLE == (Motor_1_PWM_10_CONTROL & Motor_1_PWM_10_CTRL_ENABLE))
        {
            /*Component is enabled */
            Motor_1_PWM_10_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Motor_1_PWM_10_backup.PWMEnableState = 0u;
        }
    #endif /* (Motor_1_PWM_10_UseControl) */

    /* Stop component */
    Motor_1_PWM_10_Stop();
    
    /* Save registers configuration */
    Motor_1_PWM_10_SaveConfig();
}


/*******************************************************************************
* Function Name: Motor_1_PWM_10_Wakeup
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
*  Motor_1_PWM_10_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Motor_1_PWM_10_Wakeup(void) 
{
     /* Restore registers values */
    Motor_1_PWM_10_RestoreConfig();
    
    if(Motor_1_PWM_10_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Motor_1_PWM_10_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
