/*******************************************************************************
* File Name: Motor_1_PWM_3.h  
* Version 2.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the 
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_Motor_1_PWM_3_H)
#define CY_PWM_Motor_1_PWM_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Motor_1_PWM_3_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define Motor_1_PWM_3_Resolution 8u
#define Motor_1_PWM_3_UsingFixedFunction 0u
#define Motor_1_PWM_3_DeadBandMode 0u
#define Motor_1_PWM_3_KillModeMinTime 0u
#define Motor_1_PWM_3_KillMode 0u
#define Motor_1_PWM_3_PWMMode 2u
#define Motor_1_PWM_3_PWMModeIsCenterAligned 0u
#define Motor_1_PWM_3_DeadBandUsed 0u
#define Motor_1_PWM_3_DeadBand2_4 0u
#if !defined(Motor_1_PWM_3_PWMUDB_sSTSReg_stsreg__REMOVED)
    #define Motor_1_PWM_3_UseStatus 1u
#else
    #define Motor_1_PWM_3_UseStatus 0u
#endif /* !defined(Motor_1_PWM_3_PWMUDB_sSTSReg_stsreg__REMOVED) */
#if !defined(Motor_1_PWM_3_PWMUDB_sCTRLReg_ctrlreg__REMOVED)
    #define Motor_1_PWM_3_UseControl 1u
#else
    #define Motor_1_PWM_3_UseControl 0u
#endif /* !defined(Motor_1_PWM_3_PWMUDB_sCTRLReg_ctrlreg__REMOVED) */
#define Motor_1_PWM_3_UseOneCompareMode 0u
#define Motor_1_PWM_3_MinimumKillTime 1u
#define Motor_1_PWM_3_EnableMode 2u

#define Motor_1_PWM_3_CompareMode1SW 0u
#define Motor_1_PWM_3_CompareMode2SW 0u

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v2_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define Motor_1_PWM_3__B_PWM__DISABLED 0
#define Motor_1_PWM_3__B_PWM__ASYNCHRONOUS 1
#define Motor_1_PWM_3__B_PWM__SINGLECYCLE 2
#define Motor_1_PWM_3__B_PWM__LATCHED 3
#define Motor_1_PWM_3__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define Motor_1_PWM_3__B_PWM__DBMDISABLED 0
#define Motor_1_PWM_3__B_PWM__DBM_2_4_CLOCKS 1
#define Motor_1_PWM_3__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define Motor_1_PWM_3__B_PWM__ONE_OUTPUT 0
#define Motor_1_PWM_3__B_PWM__TWO_OUTPUTS 1
#define Motor_1_PWM_3__B_PWM__DUAL_EDGE 2
#define Motor_1_PWM_3__B_PWM__CENTER_ALIGN 3
#define Motor_1_PWM_3__B_PWM__DITHER 5
#define Motor_1_PWM_3__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define Motor_1_PWM_3__B_PWM__LESS_THAN 1
#define Motor_1_PWM_3__B_PWM__LESS_THAN_OR_EQUAL 2
#define Motor_1_PWM_3__B_PWM__GREATER_THAN 3
#define Motor_1_PWM_3__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define Motor_1_PWM_3__B_PWM__EQUAL 0
#define Motor_1_PWM_3__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{
    
    uint8 PWMEnableState;
       
    #if(!Motor_1_PWM_3_UsingFixedFunction)
        #if (CY_PSOC5A)
            uint8 PWMUdb;               /* PWM Current Counter value  */
            uint8 PWMPeriod;            /* PWM Current Period value   */
            #if (Motor_1_PWM_3_UseStatus)
                uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
            #endif /* (Motor_1_PWM_3_UseStatus) */
            #if(Motor_1_PWM_3_UseOneCompareMode)
                uint8 PWMCompareValue;     /* PWM Current Compare value */
            #else
                uint8 PWMCompareValue1;     /* PWM Current Compare value1 */
                uint8 PWMCompareValue2;     /* PWM Current Compare value2 */
            #endif /* (Motor_1_PWM_3_UseOneCompareMode) */
            
            /* Backup for Deadband parameters */
            #if(Motor_1_PWM_3_DeadBandMode == Motor_1_PWM_3__B_PWM__DBM_256_CLOCKS || \
                Motor_1_PWM_3_DeadBandMode == Motor_1_PWM_3__B_PWM__DBM_2_4_CLOCKS)
                uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
            #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
            /* Backup Kill Mode Counter*/
            #if(Motor_1_PWM_3_KillModeMinTime)
                uint8 PWMKillCounterPeriod; /* Kill Mode period value */
            #endif /* (Motor_1_PWM_3_KillModeMinTime) */
            
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            uint8 PWMUdb;               /* PWM Current Counter value  */
            #if(!Motor_1_PWM_3_PWMModeIsCenterAligned)
                uint8 PWMPeriod;
            #endif /* (!Motor_1_PWM_3_PWMModeIsCenterAligned) */
            #if (Motor_1_PWM_3_UseStatus)
                uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
            #endif /* (Motor_1_PWM_3_UseStatus) */
            
            /* Backup for Deadband parameters */
            #if(Motor_1_PWM_3_DeadBandMode == Motor_1_PWM_3__B_PWM__DBM_256_CLOCKS || \
                Motor_1_PWM_3_DeadBandMode == Motor_1_PWM_3__B_PWM__DBM_2_4_CLOCKS)
                uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
            #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
            /* Backup Kill Mode Counter*/
            #if(Motor_1_PWM_3_KillModeMinTime)
                uint8 PWMKillCounterPeriod; /* Kill Mode period value */
            #endif /* (Motor_1_PWM_3_KillModeMinTime) */
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        
        /* Backup control register */
        #if(Motor_1_PWM_3_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (Motor_1_PWM_3_UseControl) */
        
    #endif /* (!Motor_1_PWM_3_UsingFixedFunction) */
   
}Motor_1_PWM_3_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/
 
void    Motor_1_PWM_3_Start(void) ;
void    Motor_1_PWM_3_Stop(void) ;

#if (Motor_1_PWM_3_UseStatus || Motor_1_PWM_3_UsingFixedFunction)
    void  Motor_1_PWM_3_SetInterruptMode(uint8 interruptMode) ;
    uint8 Motor_1_PWM_3_ReadStatusRegister(void) ;
#endif /* (Motor_1_PWM_3_UseStatus || Motor_1_PWM_3_UsingFixedFunction) */

#define Motor_1_PWM_3_GetInterruptSource() Motor_1_PWM_3_ReadStatusRegister()

#if (Motor_1_PWM_3_UseControl)
    uint8 Motor_1_PWM_3_ReadControlRegister(void) ; 
    void  Motor_1_PWM_3_WriteControlRegister(uint8 control) ;
#endif /* (Motor_1_PWM_3_UseControl) */

#if (Motor_1_PWM_3_UseOneCompareMode)
   #if (Motor_1_PWM_3_CompareMode1SW)
       void    Motor_1_PWM_3_SetCompareMode(uint8 comparemode) ;
   #endif /* (Motor_1_PWM_3_CompareMode1SW) */
#else
    #if (Motor_1_PWM_3_CompareMode1SW)
        void    Motor_1_PWM_3_SetCompareMode1(uint8 comparemode) ;
    #endif /* (Motor_1_PWM_3_CompareMode1SW) */
    #if (Motor_1_PWM_3_CompareMode2SW)
        void    Motor_1_PWM_3_SetCompareMode2(uint8 comparemode) ;
    #endif /* (Motor_1_PWM_3_CompareMode2SW) */
#endif /* (Motor_1_PWM_3_UseOneCompareMode) */

#if (!Motor_1_PWM_3_UsingFixedFunction)
    uint8   Motor_1_PWM_3_ReadCounter(void) ;
    uint8 Motor_1_PWM_3_ReadCapture(void) ;
    
	#if (Motor_1_PWM_3_UseStatus)
	        void Motor_1_PWM_3_ClearFIFO(void) ;
	#endif /* (Motor_1_PWM_3_UseStatus) */

    void    Motor_1_PWM_3_WriteCounter(uint8 counter) ;
#endif /* (!Motor_1_PWM_3_UsingFixedFunction) */

void    Motor_1_PWM_3_WritePeriod(uint8 period) ;
uint8 Motor_1_PWM_3_ReadPeriod(void) ;

#if (Motor_1_PWM_3_UseOneCompareMode)
    void    Motor_1_PWM_3_WriteCompare(uint8 compare) ;
    uint8 Motor_1_PWM_3_ReadCompare(void) ; 
#else
    void    Motor_1_PWM_3_WriteCompare1(uint8 compare) ;
    uint8 Motor_1_PWM_3_ReadCompare1(void) ; 
    void    Motor_1_PWM_3_WriteCompare2(uint8 compare) ;
    uint8 Motor_1_PWM_3_ReadCompare2(void) ; 
#endif /* (Motor_1_PWM_3_UseOneCompareMode) */


#if (Motor_1_PWM_3_DeadBandUsed)
    void    Motor_1_PWM_3_WriteDeadTime(uint8 deadtime) ;
    uint8   Motor_1_PWM_3_ReadDeadTime(void) ;
#endif /* (Motor_1_PWM_3_DeadBandUsed) */

#if ( Motor_1_PWM_3_KillModeMinTime)
    void Motor_1_PWM_3_WriteKillTime(uint8 killtime) ;
    uint8 Motor_1_PWM_3_ReadKillTime(void) ; 
#endif /* ( Motor_1_PWM_3_KillModeMinTime) */

void Motor_1_PWM_3_Init(void) ;
void Motor_1_PWM_3_Enable(void) ;
void Motor_1_PWM_3_Sleep(void) ;
void Motor_1_PWM_3_Wakeup(void) ;
void Motor_1_PWM_3_SaveConfig(void) ;
void Motor_1_PWM_3_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define Motor_1_PWM_3_INIT_PERIOD_VALUE        255u
#define Motor_1_PWM_3_INIT_COMPARE_VALUE1      127u
#define Motor_1_PWM_3_INIT_COMPARE_VALUE2      63u
#define Motor_1_PWM_3_INIT_INTERRUPTS_MODE     (uint8)(((uint8)(0u << Motor_1_PWM_3_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                  (uint8)((uint8)(0u << Motor_1_PWM_3_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                  (uint8)((uint8)(0u << Motor_1_PWM_3_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                  (uint8)((uint8)(0u << Motor_1_PWM_3_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define Motor_1_PWM_3_DEFAULT_COMPARE2_MODE    (uint8)((uint8)3u << Motor_1_PWM_3_CTRL_CMPMODE2_SHIFT)
#define Motor_1_PWM_3_DEFAULT_COMPARE1_MODE    (uint8)((uint8)1u << Motor_1_PWM_3_CTRL_CMPMODE1_SHIFT)
#define Motor_1_PWM_3_INIT_DEAD_TIME           1u


/********************************
*         Registers
******************************** */

#if (Motor_1_PWM_3_UsingFixedFunction)
   #define Motor_1_PWM_3_PERIOD_LSB          (*(reg16 *) Motor_1_PWM_3_PWMHW__PER0)
   #define Motor_1_PWM_3_PERIOD_LSB_PTR      ( (reg16 *) Motor_1_PWM_3_PWMHW__PER0)
   #define Motor_1_PWM_3_COMPARE1_LSB        (*(reg16 *) Motor_1_PWM_3_PWMHW__CNT_CMP0)
   #define Motor_1_PWM_3_COMPARE1_LSB_PTR    ( (reg16 *) Motor_1_PWM_3_PWMHW__CNT_CMP0)
   #define Motor_1_PWM_3_COMPARE2_LSB        0x00u
   #define Motor_1_PWM_3_COMPARE2_LSB_PTR    0x00u
   #define Motor_1_PWM_3_COUNTER_LSB         (*(reg16 *) Motor_1_PWM_3_PWMHW__CNT_CMP0)
   #define Motor_1_PWM_3_COUNTER_LSB_PTR     ( (reg16 *) Motor_1_PWM_3_PWMHW__CNT_CMP0)
   #define Motor_1_PWM_3_CAPTURE_LSB         (*(reg16 *) Motor_1_PWM_3_PWMHW__CAP0)
   #define Motor_1_PWM_3_CAPTURE_LSB_PTR     ( (reg16 *) Motor_1_PWM_3_PWMHW__CAP0)
   #define Motor_1_PWM_3_RT1                 (*(reg8 *)  Motor_1_PWM_3_PWMHW__RT1)
   #define Motor_1_PWM_3_RT1_PTR             ( (reg8 *)  Motor_1_PWM_3_PWMHW__RT1)
      
#else
   #if (Motor_1_PWM_3_Resolution == 8u) /* 8bit - PWM */
	   
	   #if(Motor_1_PWM_3_PWMModeIsCenterAligned)
	       #define Motor_1_PWM_3_PERIOD_LSB      (*(reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__D1_REG)
	       #define Motor_1_PWM_3_PERIOD_LSB_PTR   ((reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__D1_REG)
	   #else
	       #define Motor_1_PWM_3_PERIOD_LSB      (*(reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__F0_REG)
	       #define Motor_1_PWM_3_PERIOD_LSB_PTR   ((reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__F0_REG)
	   #endif /* (Motor_1_PWM_3_PWMModeIsCenterAligned) */
	   
	   #define Motor_1_PWM_3_COMPARE1_LSB    (*(reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__D0_REG)
	   #define Motor_1_PWM_3_COMPARE1_LSB_PTR ((reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__D0_REG)
	   #define Motor_1_PWM_3_COMPARE2_LSB    (*(reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__D1_REG)
	   #define Motor_1_PWM_3_COMPARE2_LSB_PTR ((reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__D1_REG)
	   #define Motor_1_PWM_3_COUNTERCAP_LSB   (*(reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__A1_REG)
	   #define Motor_1_PWM_3_COUNTERCAP_LSB_PTR ((reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__A1_REG)
	   #define Motor_1_PWM_3_COUNTER_LSB     (*(reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__A0_REG)
	   #define Motor_1_PWM_3_COUNTER_LSB_PTR  ((reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__A0_REG)
	   #define Motor_1_PWM_3_CAPTURE_LSB     (*(reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__F1_REG)
	   #define Motor_1_PWM_3_CAPTURE_LSB_PTR  ((reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__F1_REG)
   
   #else
   		#if(CY_PSOC3) /* 8-bit address space */	
			#if(Motor_1_PWM_3_PWMModeIsCenterAligned)
		       #define Motor_1_PWM_3_PERIOD_LSB      (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__D1_REG)
		       #define Motor_1_PWM_3_PERIOD_LSB_PTR   ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__D1_REG)
		    #else
		       #define Motor_1_PWM_3_PERIOD_LSB      (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__F0_REG)
		       #define Motor_1_PWM_3_PERIOD_LSB_PTR   ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__F0_REG)
		    #endif /* (Motor_1_PWM_3_PWMModeIsCenterAligned) */
		   
		    #define Motor_1_PWM_3_COMPARE1_LSB    (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__D0_REG)
		    #define Motor_1_PWM_3_COMPARE1_LSB_PTR ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__D0_REG)
		    #define Motor_1_PWM_3_COMPARE2_LSB    (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__D1_REG)
		    #define Motor_1_PWM_3_COMPARE2_LSB_PTR ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__D1_REG)
		    #define Motor_1_PWM_3_COUNTERCAP_LSB   (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__A1_REG)
		    #define Motor_1_PWM_3_COUNTERCAP_LSB_PTR ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__A1_REG)
		    #define Motor_1_PWM_3_COUNTER_LSB     (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__A0_REG)
		    #define Motor_1_PWM_3_COUNTER_LSB_PTR  ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__A0_REG)
		    #define Motor_1_PWM_3_CAPTURE_LSB     (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__F1_REG)
		    #define Motor_1_PWM_3_CAPTURE_LSB_PTR  ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__F1_REG)
		#else
			#if(Motor_1_PWM_3_PWMModeIsCenterAligned)
		       #define Motor_1_PWM_3_PERIOD_LSB      (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
		       #define Motor_1_PWM_3_PERIOD_LSB_PTR   ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
		    #else
		       #define Motor_1_PWM_3_PERIOD_LSB      (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
		       #define Motor_1_PWM_3_PERIOD_LSB_PTR   ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
		    #endif /* (Motor_1_PWM_3_PWMModeIsCenterAligned) */
		   
		    #define Motor_1_PWM_3_COMPARE1_LSB    (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
		    #define Motor_1_PWM_3_COMPARE1_LSB_PTR ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
		    #define Motor_1_PWM_3_COMPARE2_LSB    (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
		    #define Motor_1_PWM_3_COMPARE2_LSB_PTR ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
		    #define Motor_1_PWM_3_COUNTERCAP_LSB   (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
		    #define Motor_1_PWM_3_COUNTERCAP_LSB_PTR ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
		    #define Motor_1_PWM_3_COUNTER_LSB     (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
		    #define Motor_1_PWM_3_COUNTER_LSB_PTR  ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
		    #define Motor_1_PWM_3_CAPTURE_LSB     (*(reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
		    #define Motor_1_PWM_3_CAPTURE_LSB_PTR  ((reg16 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
		#endif
		
	   #define Motor_1_PWM_3_AUX_CONTROLDP1    (*(reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)
       #define Motor_1_PWM_3_AUX_CONTROLDP1_PTR  ((reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (Motor_1_PWM_3_Resolution == 8) */
   
   #define Motor_1_PWM_3_AUX_CONTROLDP0      (*(reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)
   #define Motor_1_PWM_3_AUX_CONTROLDP0_PTR  ((reg8 *) Motor_1_PWM_3_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (Motor_1_PWM_3_UsingFixedFunction) */
   
#if(Motor_1_PWM_3_KillModeMinTime )
    #define Motor_1_PWM_3_KILLMODEMINTIME      (*(reg8 *) Motor_1_PWM_3_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define Motor_1_PWM_3_KILLMODEMINTIME_PTR   ((reg8 *) Motor_1_PWM_3_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (Motor_1_PWM_3_KillModeMinTime ) */

#if(Motor_1_PWM_3_DeadBandMode == Motor_1_PWM_3__B_PWM__DBM_256_CLOCKS)
    #define Motor_1_PWM_3_DEADBAND_COUNT      (*(reg8 *) Motor_1_PWM_3_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Motor_1_PWM_3_DEADBAND_COUNT_PTR  ((reg8 *) Motor_1_PWM_3_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Motor_1_PWM_3_DEADBAND_LSB_PTR    ((reg8 *) Motor_1_PWM_3_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define Motor_1_PWM_3_DEADBAND_LSB        (*(reg8 *) Motor_1_PWM_3_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(Motor_1_PWM_3_DeadBandMode == Motor_1_PWM_3__B_PWM__DBM_2_4_CLOCKS)
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (Motor_1_PWM_3_UsingFixedFunction)
        #define Motor_1_PWM_3_DEADBAND_COUNT        (*(reg8 *) Motor_1_PWM_3_PWMHW__CFG0) 
        #define Motor_1_PWM_3_DEADBAND_COUNT_PTR     ((reg8 *) Motor_1_PWM_3_PWMHW__CFG0)
        #define Motor_1_PWM_3_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Motor_1_PWM_3_DEADBAND_COUNT_SHIFT)
        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define Motor_1_PWM_3_DEADBAND_COUNT_SHIFT   0x06u  
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define Motor_1_PWM_3_DEADBAND_COUNT        (*(reg8 *) Motor_1_PWM_3_PWMUDB_sDB3_AsyncCtl_dbctrlreg__CONTROL_REG)
        #define Motor_1_PWM_3_DEADBAND_COUNT_PTR     ((reg8 *) Motor_1_PWM_3_PWMUDB_sDB3_AsyncCtl_dbctrlreg__CONTROL_REG)
        #define Motor_1_PWM_3_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Motor_1_PWM_3_DEADBAND_COUNT_SHIFT) 
        /* As defined by the verilog implementation of the Control Register */
        #define Motor_1_PWM_3_DEADBAND_COUNT_SHIFT   0x00u 
    #endif /* (Motor_1_PWM_3_UsingFixedFunction) */
#endif /* (Motor_1_PWM_3_DeadBandMode == Motor_1_PWM_3__B_PWM__DBM_256_CLOCKS) */



#if (Motor_1_PWM_3_UsingFixedFunction)
    #define Motor_1_PWM_3_STATUS                (*(reg8 *) Motor_1_PWM_3_PWMHW__SR0)
    #define Motor_1_PWM_3_STATUS_PTR            ((reg8 *) Motor_1_PWM_3_PWMHW__SR0)
    #define Motor_1_PWM_3_STATUS_MASK           (*(reg8 *) Motor_1_PWM_3_PWMHW__SR0)
    #define Motor_1_PWM_3_STATUS_MASK_PTR       ((reg8 *) Motor_1_PWM_3_PWMHW__SR0)
    #define Motor_1_PWM_3_CONTROL               (*(reg8 *) Motor_1_PWM_3_PWMHW__CFG0)
    #define Motor_1_PWM_3_CONTROL_PTR           ((reg8 *) Motor_1_PWM_3_PWMHW__CFG0)    
    #define Motor_1_PWM_3_CONTROL2              (*(reg8 *) Motor_1_PWM_3_PWMHW__CFG1)    
    #if(CY_PSOC3 || CY_PSOC5LP)
        #define Motor_1_PWM_3_CONTROL3              (*(reg8 *) Motor_1_PWM_3_PWMHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Motor_1_PWM_3_GLOBAL_ENABLE         (*(reg8 *) Motor_1_PWM_3_PWMHW__PM_ACT_CFG)
    #define Motor_1_PWM_3_GLOBAL_ENABLE_PTR       ( (reg8 *) Motor_1_PWM_3_PWMHW__PM_ACT_CFG)
    #define Motor_1_PWM_3_GLOBAL_STBY_ENABLE      (*(reg8 *) Motor_1_PWM_3_PWMHW__PM_STBY_CFG)
    #define Motor_1_PWM_3_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) Motor_1_PWM_3_PWMHW__PM_STBY_CFG)
  
  
    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define Motor_1_PWM_3_BLOCK_EN_MASK          Motor_1_PWM_3_PWMHW__PM_ACT_MSK
    #define Motor_1_PWM_3_BLOCK_STBY_EN_MASK     Motor_1_PWM_3_PWMHW__PM_STBY_MSK 
    /* Control Register definitions */
    #define Motor_1_PWM_3_CTRL_ENABLE_SHIFT      0x00u
    
    #if(CY_PSOC5A)
        #define Motor_1_PWM_3_CTRL_CMPMODE1_SHIFT    0x01u   /* As defined by Register map as MODE_CFG bits in CFG1*/
    #endif /* (CY_PSOC5A) */
    #if(CY_PSOC3 || CY_PSOC5LP)
        #define Motor_1_PWM_3_CTRL_CMPMODE1_SHIFT    0x04u  /* As defined by Register map as MODE_CFG bits in CFG2*/
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    
    #define Motor_1_PWM_3_CTRL_DEAD_TIME_SHIFT   0x06u   /* As defined by Register map */
    /* Fixed Function Block Only CFG register bit definitions */
    #define Motor_1_PWM_3_CFG0_MODE              0x02u   /*  Set to compare mode */
    /* #define Motor_1_PWM_3_CFG0_ENABLE            0x01u */  /* Enable the block to run */
    #define Motor_1_PWM_3_CFG0_DB                0x20u   /* As defined by Register map as DB bit in CFG0 */

    /* Control Register Bit Masks */
    #define Motor_1_PWM_3_CTRL_ENABLE            (uint8)((uint8)0x01u << Motor_1_PWM_3_CTRL_ENABLE_SHIFT)
    #define Motor_1_PWM_3_CTRL_RESET             (uint8)((uint8)0x01u << Motor_1_PWM_3_CTRL_RESET_SHIFT)
    #define Motor_1_PWM_3_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Motor_1_PWM_3_CTRL_CMPMODE2_SHIFT)
    #if(CY_PSOC5A)
        #define Motor_1_PWM_3_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Motor_1_PWM_3_CTRL_CMPMODE1_SHIFT)
    #endif /* (CY_PSOC5A) */
    #if(CY_PSOC3 || CY_PSOC5LP)
        #define Motor_1_PWM_3_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Motor_1_PWM_3_CTRL_CMPMODE1_SHIFT)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    
    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Motor_1_PWM_3_CTRL2_IRQ_SEL_SHIFT    0x00u       
    #define Motor_1_PWM_3_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << Motor_1_PWM_3_CTRL2_IRQ_SEL_SHIFT)  
    
    /* Status Register Bit Locations */
    #define Motor_1_PWM_3_STATUS_TC_SHIFT            0x07u   /* As defined by Register map as TC in SR0 */
    #define Motor_1_PWM_3_STATUS_CMP1_SHIFT          0x06u   /* As defined by the Register map as CAP_CMP in SR0 */
    
    /* Status Register Interrupt Enable Bit Locations */
    #define Motor_1_PWM_3_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)    
    #define Motor_1_PWM_3_STATUS_TC_INT_EN_MASK_SHIFT            (Motor_1_PWM_3_STATUS_TC_SHIFT - 4u)
    #define Motor_1_PWM_3_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)  
    #define Motor_1_PWM_3_STATUS_CMP1_INT_EN_MASK_SHIFT          (Motor_1_PWM_3_STATUS_CMP1_SHIFT - 4u)
    
    /* Status Register Bit Masks */
    #define Motor_1_PWM_3_STATUS_TC              (uint8)((uint8)0x01u << Motor_1_PWM_3_STATUS_TC_SHIFT)
    #define Motor_1_PWM_3_STATUS_CMP1            (uint8)((uint8)0x01u << Motor_1_PWM_3_STATUS_CMP1_SHIFT)
    
    /* Status Register Interrupt Bit Masks*/
    #define Motor_1_PWM_3_STATUS_TC_INT_EN_MASK              (uint8)((uint8)Motor_1_PWM_3_STATUS_TC >> 4u)
    #define Motor_1_PWM_3_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)Motor_1_PWM_3_STATUS_CMP1 >> 4u)
    
    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP*/
    #define Motor_1_PWM_3_RT1_SHIFT             0x04u
    #define Motor_1_PWM_3_RT1_MASK              (uint8)((uint8)0x03u << Motor_1_PWM_3_RT1_SHIFT)/* Sync TC and CMP bit masks */
    #define Motor_1_PWM_3_SYNC                  (uint8)((uint8)0x03u << Motor_1_PWM_3_RT1_SHIFT)
    #define Motor_1_PWM_3_SYNCDSI_SHIFT         0x00u
    #define Motor_1_PWM_3_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << Motor_1_PWM_3_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    #define Motor_1_PWM_3_SYNCDSI_EN            (uint8)((uint8)0x0Fu << Motor_1_PWM_3_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    

#else
    #define Motor_1_PWM_3_STATUS                (*(reg8 *) Motor_1_PWM_3_PWMUDB_sSTSReg_nrstSts_stsreg__STATUS_REG )
    #define Motor_1_PWM_3_STATUS_PTR            ((reg8 *) Motor_1_PWM_3_PWMUDB_sSTSReg_nrstSts_stsreg__STATUS_REG )
    #define Motor_1_PWM_3_STATUS_MASK           (*(reg8 *) Motor_1_PWM_3_PWMUDB_sSTSReg_nrstSts_stsreg__MASK_REG)
    #define Motor_1_PWM_3_STATUS_MASK_PTR       ((reg8 *) Motor_1_PWM_3_PWMUDB_sSTSReg_nrstSts_stsreg__MASK_REG)
    #define Motor_1_PWM_3_STATUS_AUX_CTRL       (*(reg8 *) Motor_1_PWM_3_PWMUDB_sSTSReg_nrstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Motor_1_PWM_3_CONTROL               (*(reg8 *) Motor_1_PWM_3_PWMUDB_sCTRLReg_AsyncCtl_ctrlreg__CONTROL_REG)
    #define Motor_1_PWM_3_CONTROL_PTR           ((reg8 *) Motor_1_PWM_3_PWMUDB_sCTRLReg_AsyncCtl_ctrlreg__CONTROL_REG)
    
    
    /***********************************
    *          Constants
    ***********************************/

    /* Control Register definitions */
    #define Motor_1_PWM_3_CTRL_ENABLE_SHIFT      0x07u
    #define Motor_1_PWM_3_CTRL_RESET_SHIFT       0x06u
    #define Motor_1_PWM_3_CTRL_CMPMODE2_SHIFT    0x03u
    #define Motor_1_PWM_3_CTRL_CMPMODE1_SHIFT    0x00u
    #define Motor_1_PWM_3_CTRL_DEAD_TIME_SHIFT   0x00u   /* No Shift Needed for UDB block */
    /* Control Register Bit Masks */
    #define Motor_1_PWM_3_CTRL_ENABLE            (uint8)((uint8)0x01u << Motor_1_PWM_3_CTRL_ENABLE_SHIFT)
    #define Motor_1_PWM_3_CTRL_RESET             (uint8)((uint8)0x01u << Motor_1_PWM_3_CTRL_RESET_SHIFT)
    #define Motor_1_PWM_3_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Motor_1_PWM_3_CTRL_CMPMODE2_SHIFT)
    #define Motor_1_PWM_3_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Motor_1_PWM_3_CTRL_CMPMODE1_SHIFT) 
    
    /* Status Register Bit Locations */
    #define Motor_1_PWM_3_STATUS_KILL_SHIFT          0x05u
    #define Motor_1_PWM_3_STATUS_FIFONEMPTY_SHIFT    0x04u
    #define Motor_1_PWM_3_STATUS_FIFOFULL_SHIFT      0x03u  
    #define Motor_1_PWM_3_STATUS_TC_SHIFT            0x02u
    #define Motor_1_PWM_3_STATUS_CMP2_SHIFT          0x01u
    #define Motor_1_PWM_3_STATUS_CMP1_SHIFT          0x00u
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Motor_1_PWM_3_STATUS_KILL_INT_EN_MASK_SHIFT          Motor_1_PWM_3_STATUS_KILL_SHIFT          
    #define Motor_1_PWM_3_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    Motor_1_PWM_3_STATUS_FIFONEMPTY_SHIFT    
    #define Motor_1_PWM_3_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      Motor_1_PWM_3_STATUS_FIFOFULL_SHIFT        
    #define Motor_1_PWM_3_STATUS_TC_INT_EN_MASK_SHIFT            Motor_1_PWM_3_STATUS_TC_SHIFT            
    #define Motor_1_PWM_3_STATUS_CMP2_INT_EN_MASK_SHIFT          Motor_1_PWM_3_STATUS_CMP2_SHIFT          
    #define Motor_1_PWM_3_STATUS_CMP1_INT_EN_MASK_SHIFT          Motor_1_PWM_3_STATUS_CMP1_SHIFT   
    /* Status Register Bit Masks */
    #define Motor_1_PWM_3_STATUS_KILL            (uint8)((uint8)0x00u << Motor_1_PWM_3_STATUS_KILL_SHIFT )
    #define Motor_1_PWM_3_STATUS_FIFOFULL        (uint8)((uint8)0x01u << Motor_1_PWM_3_STATUS_FIFOFULL_SHIFT)
    #define Motor_1_PWM_3_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << Motor_1_PWM_3_STATUS_FIFONEMPTY_SHIFT)
    #define Motor_1_PWM_3_STATUS_TC              (uint8)((uint8)0x01u << Motor_1_PWM_3_STATUS_TC_SHIFT)
    #define Motor_1_PWM_3_STATUS_CMP2            (uint8)((uint8)0x01u << Motor_1_PWM_3_STATUS_CMP2_SHIFT) 
    #define Motor_1_PWM_3_STATUS_CMP1            (uint8)((uint8)0x01u << Motor_1_PWM_3_STATUS_CMP1_SHIFT)
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Motor_1_PWM_3_STATUS_KILL_INT_EN_MASK            Motor_1_PWM_3_STATUS_KILL
    #define Motor_1_PWM_3_STATUS_FIFOFULL_INT_EN_MASK        Motor_1_PWM_3_STATUS_FIFOFULL
    #define Motor_1_PWM_3_STATUS_FIFONEMPTY_INT_EN_MASK      Motor_1_PWM_3_STATUS_FIFONEMPTY
    #define Motor_1_PWM_3_STATUS_TC_INT_EN_MASK              Motor_1_PWM_3_STATUS_TC
    #define Motor_1_PWM_3_STATUS_CMP2_INT_EN_MASK            Motor_1_PWM_3_STATUS_CMP2
    #define Motor_1_PWM_3_STATUS_CMP1_INT_EN_MASK            Motor_1_PWM_3_STATUS_CMP1
                                                          
    /* Datapath Auxillary Control Register definitions */
    #define Motor_1_PWM_3_AUX_CTRL_FIFO0_CLR     0x01u
    #define Motor_1_PWM_3_AUX_CTRL_FIFO1_CLR     0x02u
    #define Motor_1_PWM_3_AUX_CTRL_FIFO0_LVL     0x04u
    #define Motor_1_PWM_3_AUX_CTRL_FIFO1_LVL     0x08u
    #define Motor_1_PWM_3_STATUS_ACTL_INT_EN_MASK  0x10u /* As defined for the ACTL Register */
#endif /* Motor_1_PWM_3_UsingFixedFunction */

#endif  /* CY_PWM_Motor_1_PWM_3_H */


/* [] END OF FILE */
