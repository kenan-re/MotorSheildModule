/*******************************************************************************
* File Name: Motor_1_PWM_4_PM.c
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
#include "Motor_1_PWM_4.h"

static Motor_1_PWM_4_backupStruct Motor_1_PWM_4_backup;


/*******************************************************************************
* Function Name: Motor_1_PWM_4_SaveConfig
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
*  Motor_1_PWM_4_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Motor_1_PWM_4_SaveConfig(void) 
{
    
    #if(!Motor_1_PWM_4_UsingFixedFunction)
        #if (CY_PSOC5A)
            Motor_1_PWM_4_backup.PWMUdb = Motor_1_PWM_4_ReadCounter();
            Motor_1_PWM_4_backup.PWMPeriod = Motor_1_PWM_4_ReadPeriod();
            #if (Motor_1_PWM_4_UseStatus)
                Motor_1_PWM_4_backup.InterruptMaskValue = Motor_1_PWM_4_STATUS_MASK;
            #endif /* (Motor_1_PWM_4_UseStatus) */
            
            #if(Motor_1_PWM_4_UseOneCompareMode)
                Motor_1_PWM_4_backup.PWMCompareValue = Motor_1_PWM_4_ReadCompare();
            #else
                Motor_1_PWM_4_backup.PWMCompareValue1 = Motor_1_PWM_4_ReadCompare1();
                Motor_1_PWM_4_backup.PWMCompareValue2 = Motor_1_PWM_4_ReadCompare2();
            #endif /* (Motor_1_PWM_4_UseOneCompareMode) */
            
           #if(Motor_1_PWM_4_DeadBandUsed)
                Motor_1_PWM_4_backup.PWMdeadBandValue = Motor_1_PWM_4_ReadDeadTime();
            #endif /* (Motor_1_PWM_4_DeadBandUsed) */
          
            #if ( Motor_1_PWM_4_KillModeMinTime)
                Motor_1_PWM_4_backup.PWMKillCounterPeriod = Motor_1_PWM_4_ReadKillTime();
            #endif /* ( Motor_1_PWM_4_KillModeMinTime) */
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            #if(!Motor_1_PWM_4_PWMModeIsCenterAligned)
                Motor_1_PWM_4_backup.PWMPeriod = Motor_1_PWM_4_ReadPeriod();
            #endif /* (!Motor_1_PWM_4_PWMModeIsCenterAligned) */
            Motor_1_PWM_4_backup.PWMUdb = Motor_1_PWM_4_ReadCounter();
            #if (Motor_1_PWM_4_UseStatus)
                Motor_1_PWM_4_backup.InterruptMaskValue = Motor_1_PWM_4_STATUS_MASK;
            #endif /* (Motor_1_PWM_4_UseStatus) */
            
            #if(Motor_1_PWM_4_DeadBandMode == Motor_1_PWM_4__B_PWM__DBM_256_CLOCKS || \
                Motor_1_PWM_4_DeadBandMode == Motor_1_PWM_4__B_PWM__DBM_2_4_CLOCKS)
                Motor_1_PWM_4_backup.PWMdeadBandValue = Motor_1_PWM_4_ReadDeadTime();
            #endif /*  deadband count is either 2-4 clocks or 256 clocks */
            
            #if(Motor_1_PWM_4_KillModeMinTime)
                 Motor_1_PWM_4_backup.PWMKillCounterPeriod = Motor_1_PWM_4_ReadKillTime();
            #endif /* (Motor_1_PWM_4_KillModeMinTime) */
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(Motor_1_PWM_4_UseControl)
            Motor_1_PWM_4_backup.PWMControlRegister = Motor_1_PWM_4_ReadControlRegister();
        #endif /* (Motor_1_PWM_4_UseControl) */
    #endif  /* (!Motor_1_PWM_4_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Motor_1_PWM_4_RestoreConfig
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
*  Motor_1_PWM_4_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Motor_1_PWM_4_RestoreConfig(void) 
{
        #if(!Motor_1_PWM_4_UsingFixedFunction)
            #if (CY_PSOC5A)
                /* Interrupt State Backup for Critical Region*/
                uint8 Motor_1_PWM_4_interruptState;
                /* Enter Critical Region*/
                Motor_1_PWM_4_interruptState = CyEnterCriticalSection();
                #if (Motor_1_PWM_4_UseStatus)
                    /* Use the interrupt output of the status register for IRQ output */
                    Motor_1_PWM_4_STATUS_AUX_CTRL |= Motor_1_PWM_4_STATUS_ACTL_INT_EN_MASK;
                    
                    Motor_1_PWM_4_STATUS_MASK = Motor_1_PWM_4_backup.InterruptMaskValue;
                #endif /* (Motor_1_PWM_4_UseStatus) */
                
                #if (Motor_1_PWM_4_Resolution == 8)
                    /* Set FIFO 0 to 1 byte register for period*/
                    Motor_1_PWM_4_AUX_CONTROLDP0 |= (Motor_1_PWM_4_AUX_CTRL_FIFO0_CLR);
                #else /* (Motor_1_PWM_4_Resolution == 16)*/
                    /* Set FIFO 0 to 1 byte register for period */
                    Motor_1_PWM_4_AUX_CONTROLDP0 |= (Motor_1_PWM_4_AUX_CTRL_FIFO0_CLR);
                    Motor_1_PWM_4_AUX_CONTROLDP1 |= (Motor_1_PWM_4_AUX_CTRL_FIFO0_CLR);
                #endif /* (Motor_1_PWM_4_Resolution == 8) */
                /* Exit Critical Region*/
                CyExitCriticalSection(Motor_1_PWM_4_interruptState);
                
                Motor_1_PWM_4_WriteCounter(Motor_1_PWM_4_backup.PWMUdb);
                Motor_1_PWM_4_WritePeriod(Motor_1_PWM_4_backup.PWMPeriod);
                
                #if(Motor_1_PWM_4_UseOneCompareMode)
                    Motor_1_PWM_4_WriteCompare(Motor_1_PWM_4_backup.PWMCompareValue);
                #else
                    Motor_1_PWM_4_WriteCompare1(Motor_1_PWM_4_backup.PWMCompareValue1);
                    Motor_1_PWM_4_WriteCompare2(Motor_1_PWM_4_backup.PWMCompareValue2);
                #endif /* (Motor_1_PWM_4_UseOneCompareMode) */
                
               #if(Motor_1_PWM_4_DeadBandMode == Motor_1_PWM_4__B_PWM__DBM_256_CLOCKS || \
                   Motor_1_PWM_4_DeadBandMode == Motor_1_PWM_4__B_PWM__DBM_2_4_CLOCKS)
                    Motor_1_PWM_4_WriteDeadTime(Motor_1_PWM_4_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
                #if ( Motor_1_PWM_4_KillModeMinTime)
                    Motor_1_PWM_4_WriteKillTime(Motor_1_PWM_4_backup.PWMKillCounterPeriod);
                #endif /* ( Motor_1_PWM_4_KillModeMinTime) */
            #endif /* (CY_PSOC5A) */
            
            #if (CY_PSOC3 || CY_PSOC5LP)
                #if(!Motor_1_PWM_4_PWMModeIsCenterAligned)
                    Motor_1_PWM_4_WritePeriod(Motor_1_PWM_4_backup.PWMPeriod);
                #endif /* (!Motor_1_PWM_4_PWMModeIsCenterAligned) */
                Motor_1_PWM_4_WriteCounter(Motor_1_PWM_4_backup.PWMUdb);
                #if (Motor_1_PWM_4_UseStatus)
                    Motor_1_PWM_4_STATUS_MASK = Motor_1_PWM_4_backup.InterruptMaskValue;
                #endif /* (Motor_1_PWM_4_UseStatus) */
                
                #if(Motor_1_PWM_4_DeadBandMode == Motor_1_PWM_4__B_PWM__DBM_256_CLOCKS || \
                    Motor_1_PWM_4_DeadBandMode == Motor_1_PWM_4__B_PWM__DBM_2_4_CLOCKS)
                    Motor_1_PWM_4_WriteDeadTime(Motor_1_PWM_4_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
                
                #if(Motor_1_PWM_4_KillModeMinTime)
                    Motor_1_PWM_4_WriteKillTime(Motor_1_PWM_4_backup.PWMKillCounterPeriod);
                #endif /* (Motor_1_PWM_4_KillModeMinTime) */
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            
            #if(Motor_1_PWM_4_UseControl)
                Motor_1_PWM_4_WriteControlRegister(Motor_1_PWM_4_backup.PWMControlRegister); 
            #endif /* (Motor_1_PWM_4_UseControl) */
        #endif  /* (!Motor_1_PWM_4_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Motor_1_PWM_4_Sleep
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
*  Motor_1_PWM_4_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Motor_1_PWM_4_Sleep(void) 
{
    #if(Motor_1_PWM_4_UseControl)
        if(Motor_1_PWM_4_CTRL_ENABLE == (Motor_1_PWM_4_CONTROL & Motor_1_PWM_4_CTRL_ENABLE))
        {
            /*Component is enabled */
            Motor_1_PWM_4_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Motor_1_PWM_4_backup.PWMEnableState = 0u;
        }
    #endif /* (Motor_1_PWM_4_UseControl) */

    /* Stop component */
    Motor_1_PWM_4_Stop();
    
    /* Save registers configuration */
    Motor_1_PWM_4_SaveConfig();
}


/*******************************************************************************
* Function Name: Motor_1_PWM_4_Wakeup
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
*  Motor_1_PWM_4_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Motor_1_PWM_4_Wakeup(void) 
{
     /* Restore registers values */
    Motor_1_PWM_4_RestoreConfig();
    
    if(Motor_1_PWM_4_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Motor_1_PWM_4_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
