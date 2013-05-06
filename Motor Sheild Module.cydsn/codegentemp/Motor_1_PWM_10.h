/*******************************************************************************
* File Name: Motor_1_PWM_10.h  
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

#if !defined(CY_PWM_Motor_1_PWM_10_H)
#define CY_PWM_Motor_1_PWM_10_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Motor_1_PWM_10_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define Motor_1_PWM_10_Resolution 8u
#define Motor_1_PWM_10_UsingFixedFunction 0u
#define Motor_1_PWM_10_DeadBandMode 0u
#define Motor_1_PWM_10_KillModeMinTime 0u
#define Motor_1_PWM_10_KillMode 3u
#define Motor_1_PWM_10_PWMMode 0u
#define Motor_1_PWM_10_PWMModeIsCenterAligned 0u
#define Motor_1_PWM_10_DeadBandUsed 0u
#define Motor_1_PWM_10_DeadBand2_4 0u
#if !defined(Motor_1_PWM_10_PWMUDB_sSTSReg_stsreg__REMOVED)
    #define Motor_1_PWM_10_UseStatus 1u
#else
    #define Motor_1_PWM_10_UseStatus 0u
#endif /* !defined(Motor_1_PWM_10_PWMUDB_sSTSReg_stsreg__REMOVED) */
#if !defined(Motor_1_PWM_10_PWMUDB_sCTRLReg_ctrlreg__REMOVED)
    #define Motor_1_PWM_10_UseControl 1u
#else
    #define Motor_1_PWM_10_UseControl 0u
#endif /* !defined(Motor_1_PWM_10_PWMUDB_sCTRLReg_ctrlreg__REMOVED) */
#define Motor_1_PWM_10_UseOneCompareMode 1u
#define Motor_1_PWM_10_MinimumKillTime 1u
#define Motor_1_PWM_10_EnableMode 2u

#define Motor_1_PWM_10_CompareMode1SW 0u
#define Motor_1_PWM_10_CompareMode2SW 0u

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v2_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define Motor_1_PWM_10__B_PWM__DISABLED 0
#define Motor_1_PWM_10__B_PWM__ASYNCHRONOUS 1
#define Motor_1_PWM_10__B_PWM__SINGLECYCLE 2
#define Motor_1_PWM_10__B_PWM__LATCHED 3
#define Motor_1_PWM_10__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define Motor_1_PWM_10__B_PWM__DBMDISABLED 0
#define Motor_1_PWM_10__B_PWM__DBM_2_4_CLOCKS 1
#define Motor_1_PWM_10__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define Motor_1_PWM_10__B_PWM__ONE_OUTPUT 0
#define Motor_1_PWM_10__B_PWM__TWO_OUTPUTS 1
#define Motor_1_PWM_10__B_PWM__DUAL_EDGE 2
#define Motor_1_PWM_10__B_PWM__CENTER_ALIGN 3
#define Motor_1_PWM_10__B_PWM__DITHER 5
#define Motor_1_PWM_10__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define Motor_1_PWM_10__B_PWM__LESS_THAN 1
#define Motor_1_PWM_10__B_PWM__LESS_THAN_OR_EQUAL 2
#define Motor_1_PWM_10__B_PWM__GREATER_THAN 3
#define Motor_1_PWM_10__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define Motor_1_PWM_10__B_PWM__EQUAL 0
#define Motor_1_PWM_10__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{
    
    uint8 PWMEnableState;
       
    #if(!Motor_1_PWM_10_UsingFixedFunction)
        #if (CY_PSOC5A)
            uint8 PWMUdb;               /* PWM Current Counter value  */
            uint8 PWMPeriod;            /* PWM Current Period value   */
            #if (Motor_1_PWM_10_UseStatus)
                uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
            #endif /* (Motor_1_PWM_10_UseStatus) */
            #if(Motor_1_PWM_10_UseOneCompareMode)
                uint8 PWMCompareValue;     /* PWM Current Compare value */
            #else
                uint8 PWMCompareValue1;     /* PWM Current Compare value1 */
                uint8 PWMCompareValue2;     /* PWM Current Compare value2 */
            #endif /* (Motor_1_PWM_10_UseOneCompareMode) */
            
            /* Backup for Deadband parameters */
            #if(Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_256_CLOCKS || \
                Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_2_4_CLOCKS)
                uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
            #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
            /* Backup Kill Mode Counter*/
            #if(Motor_1_PWM_10_KillModeMinTime)
                uint8 PWMKillCounterPeriod; /* Kill Mode period value */
            #endif /* (Motor_1_PWM_10_KillModeMinTime) */
            
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            uint8 PWMUdb;               /* PWM Current Counter value  */
            #if(!Motor_1_PWM_10_PWMModeIsCenterAligned)
                uint8 PWMPeriod;
            #endif /* (!Motor_1_PWM_10_PWMModeIsCenterAligned) */
            #if (Motor_1_PWM_10_UseStatus)
                uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
            #endif /* (Motor_1_PWM_10_UseStatus) */
            
            /* Backup for Deadband parameters */
            #if(Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_256_CLOCKS || \
                Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_2_4_CLOCKS)
                uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
            #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
            /* Backup Kill Mode Counter*/
            #if(Motor_1_PWM_10_KillModeMinTime)
                uint8 PWMKillCounterPeriod; /* Kill Mode period value */
            #endif /* (Motor_1_PWM_10_KillModeMinTime) */
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        
        /* Backup control register */
        #if(Motor_1_PWM_10_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (Motor_1_PWM_10_UseControl) */
        
    #endif /* (!Motor_1_PWM_10_UsingFixedFunction) */
   
}Motor_1_PWM_10_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/
 
void    Motor_1_PWM_10_Start(void) ;
void    Motor_1_PWM_10_Stop(void) ;

#if (Motor_1_PWM_10_UseStatus || Motor_1_PWM_10_UsingFixedFunction)
    void  Motor_1_PWM_10_SetInterruptMode(uint8 interruptMode) ;
    uint8 Motor_1_PWM_10_ReadStatusRegister(void) ;
#endif /* (Motor_1_PWM_10_UseStatus || Motor_1_PWM_10_UsingFixedFunction) */

#define Motor_1_PWM_10_GetInterruptSource() Motor_1_PWM_10_ReadStatusRegister()

#if (Motor_1_PWM_10_UseControl)
    uint8 Motor_1_PWM_10_ReadControlRegister(void) ; 
    void  Motor_1_PWM_10_WriteControlRegister(uint8 control) ;
#endif /* (Motor_1_PWM_10_UseControl) */

#if (Motor_1_PWM_10_UseOneCompareMode)
   #if (Motor_1_PWM_10_CompareMode1SW)
       void    Motor_1_PWM_10_SetCompareMode(uint8 comparemode) ;
   #endif /* (Motor_1_PWM_10_CompareMode1SW) */
#else
    #if (Motor_1_PWM_10_CompareMode1SW)
        void    Motor_1_PWM_10_SetCompareMode1(uint8 comparemode) ;
    #endif /* (Motor_1_PWM_10_CompareMode1SW) */
    #if (Motor_1_PWM_10_CompareMode2SW)
        void    Motor_1_PWM_10_SetCompareMode2(uint8 comparemode) ;
    #endif /* (Motor_1_PWM_10_CompareMode2SW) */
#endif /* (Motor_1_PWM_10_UseOneCompareMode) */

#if (!Motor_1_PWM_10_UsingFixedFunction)
    uint8   Motor_1_PWM_10_ReadCounter(void) ;
    uint8 Motor_1_PWM_10_ReadCapture(void) ;
    
	#if (Motor_1_PWM_10_UseStatus)
	        void Motor_1_PWM_10_ClearFIFO(void) ;
	#endif /* (Motor_1_PWM_10_UseStatus) */

    void    Motor_1_PWM_10_WriteCounter(uint8 counter) ;
#endif /* (!Motor_1_PWM_10_UsingFixedFunction) */

void    Motor_1_PWM_10_WritePeriod(uint8 period) ;
uint8 Motor_1_PWM_10_ReadPeriod(void) ;

#if (Motor_1_PWM_10_UseOneCompareMode)
    void    Motor_1_PWM_10_WriteCompare(uint8 compare) ;
    uint8 Motor_1_PWM_10_ReadCompare(void) ; 
#else
    void    Motor_1_PWM_10_WriteCompare1(uint8 compare) ;
    uint8 Motor_1_PWM_10_ReadCompare1(void) ; 
    void    Motor_1_PWM_10_WriteCompare2(uint8 compare) ;
    uint8 Motor_1_PWM_10_ReadCompare2(void) ; 
#endif /* (Motor_1_PWM_10_UseOneCompareMode) */


#if (Motor_1_PWM_10_DeadBandUsed)
    void    Motor_1_PWM_10_WriteDeadTime(uint8 deadtime) ;
    uint8   Motor_1_PWM_10_ReadDeadTime(void) ;
#endif /* (Motor_1_PWM_10_DeadBandUsed) */

#if ( Motor_1_PWM_10_KillModeMinTime)
    void Motor_1_PWM_10_WriteKillTime(uint8 killtime) ;
    uint8 Motor_1_PWM_10_ReadKillTime(void) ; 
#endif /* ( Motor_1_PWM_10_KillModeMinTime) */

void Motor_1_PWM_10_Init(void) ;
void Motor_1_PWM_10_Enable(void) ;
void Motor_1_PWM_10_Sleep(void) ;
void Motor_1_PWM_10_Wakeup(void) ;
void Motor_1_PWM_10_SaveConfig(void) ;
void Motor_1_PWM_10_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define Motor_1_PWM_10_INIT_PERIOD_VALUE        255u
#define Motor_1_PWM_10_INIT_COMPARE_VALUE1      64u
#define Motor_1_PWM_10_INIT_COMPARE_VALUE2      126u
#define Motor_1_PWM_10_INIT_INTERRUPTS_MODE     (uint8)(((uint8)(0u << Motor_1_PWM_10_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                  (uint8)((uint8)(0u << Motor_1_PWM_10_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                  (uint8)((uint8)(0u << Motor_1_PWM_10_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                  (uint8)((uint8)(0u << Motor_1_PWM_10_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define Motor_1_PWM_10_DEFAULT_COMPARE2_MODE    (uint8)((uint8)1u << Motor_1_PWM_10_CTRL_CMPMODE2_SHIFT)
#define Motor_1_PWM_10_DEFAULT_COMPARE1_MODE    (uint8)((uint8)1u << Motor_1_PWM_10_CTRL_CMPMODE1_SHIFT)
#define Motor_1_PWM_10_INIT_DEAD_TIME           1u


/********************************
*         Registers
******************************** */

#if (Motor_1_PWM_10_UsingFixedFunction)
   #define Motor_1_PWM_10_PERIOD_LSB          (*(reg16 *) Motor_1_PWM_10_PWMHW__PER0)
   #define Motor_1_PWM_10_PERIOD_LSB_PTR      ( (reg16 *) Motor_1_PWM_10_PWMHW__PER0)
   #define Motor_1_PWM_10_COMPARE1_LSB        (*(reg16 *) Motor_1_PWM_10_PWMHW__CNT_CMP0)
   #define Motor_1_PWM_10_COMPARE1_LSB_PTR    ( (reg16 *) Motor_1_PWM_10_PWMHW__CNT_CMP0)
   #define Motor_1_PWM_10_COMPARE2_LSB        0x00u
   #define Motor_1_PWM_10_COMPARE2_LSB_PTR    0x00u
   #define Motor_1_PWM_10_COUNTER_LSB         (*(reg16 *) Motor_1_PWM_10_PWMHW__CNT_CMP0)
   #define Motor_1_PWM_10_COUNTER_LSB_PTR     ( (reg16 *) Motor_1_PWM_10_PWMHW__CNT_CMP0)
   #define Motor_1_PWM_10_CAPTURE_LSB         (*(reg16 *) Motor_1_PWM_10_PWMHW__CAP0)
   #define Motor_1_PWM_10_CAPTURE_LSB_PTR     ( (reg16 *) Motor_1_PWM_10_PWMHW__CAP0)
   #define Motor_1_PWM_10_RT1                 (*(reg8 *)  Motor_1_PWM_10_PWMHW__RT1)
   #define Motor_1_PWM_10_RT1_PTR             ( (reg8 *)  Motor_1_PWM_10_PWMHW__RT1)
      
#else
   #if (Motor_1_PWM_10_Resolution == 8u) /* 8bit - PWM */
	   
	   #if(Motor_1_PWM_10_PWMModeIsCenterAligned)
	       #define Motor_1_PWM_10_PERIOD_LSB      (*(reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__D1_REG)
	       #define Motor_1_PWM_10_PERIOD_LSB_PTR   ((reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__D1_REG)
	   #else
	       #define Motor_1_PWM_10_PERIOD_LSB      (*(reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__F0_REG)
	       #define Motor_1_PWM_10_PERIOD_LSB_PTR   ((reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__F0_REG)
	   #endif /* (Motor_1_PWM_10_PWMModeIsCenterAligned) */
	   
	   #define Motor_1_PWM_10_COMPARE1_LSB    (*(reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__D0_REG)
	   #define Motor_1_PWM_10_COMPARE1_LSB_PTR ((reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__D0_REG)
	   #define Motor_1_PWM_10_COMPARE2_LSB    (*(reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__D1_REG)
	   #define Motor_1_PWM_10_COMPARE2_LSB_PTR ((reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__D1_REG)
	   #define Motor_1_PWM_10_COUNTERCAP_LSB   (*(reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__A1_REG)
	   #define Motor_1_PWM_10_COUNTERCAP_LSB_PTR ((reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__A1_REG)
	   #define Motor_1_PWM_10_COUNTER_LSB     (*(reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__A0_REG)
	   #define Motor_1_PWM_10_COUNTER_LSB_PTR  ((reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__A0_REG)
	   #define Motor_1_PWM_10_CAPTURE_LSB     (*(reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__F1_REG)
	   #define Motor_1_PWM_10_CAPTURE_LSB_PTR  ((reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__F1_REG)
   
   #else
   		#if(CY_PSOC3) /* 8-bit address space */	
			#if(Motor_1_PWM_10_PWMModeIsCenterAligned)
		       #define Motor_1_PWM_10_PERIOD_LSB      (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__D1_REG)
		       #define Motor_1_PWM_10_PERIOD_LSB_PTR   ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__D1_REG)
		    #else
		       #define Motor_1_PWM_10_PERIOD_LSB      (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__F0_REG)
		       #define Motor_1_PWM_10_PERIOD_LSB_PTR   ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__F0_REG)
		    #endif /* (Motor_1_PWM_10_PWMModeIsCenterAligned) */
		   
		    #define Motor_1_PWM_10_COMPARE1_LSB    (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__D0_REG)
		    #define Motor_1_PWM_10_COMPARE1_LSB_PTR ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__D0_REG)
		    #define Motor_1_PWM_10_COMPARE2_LSB    (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__D1_REG)
		    #define Motor_1_PWM_10_COMPARE2_LSB_PTR ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__D1_REG)
		    #define Motor_1_PWM_10_COUNTERCAP_LSB   (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__A1_REG)
		    #define Motor_1_PWM_10_COUNTERCAP_LSB_PTR ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__A1_REG)
		    #define Motor_1_PWM_10_COUNTER_LSB     (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__A0_REG)
		    #define Motor_1_PWM_10_COUNTER_LSB_PTR  ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__A0_REG)
		    #define Motor_1_PWM_10_CAPTURE_LSB     (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__F1_REG)
		    #define Motor_1_PWM_10_CAPTURE_LSB_PTR  ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__F1_REG)
		#else
			#if(Motor_1_PWM_10_PWMModeIsCenterAligned)
		       #define Motor_1_PWM_10_PERIOD_LSB      (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
		       #define Motor_1_PWM_10_PERIOD_LSB_PTR   ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
		    #else
		       #define Motor_1_PWM_10_PERIOD_LSB      (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
		       #define Motor_1_PWM_10_PERIOD_LSB_PTR   ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
		    #endif /* (Motor_1_PWM_10_PWMModeIsCenterAligned) */
		   
		    #define Motor_1_PWM_10_COMPARE1_LSB    (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
		    #define Motor_1_PWM_10_COMPARE1_LSB_PTR ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
		    #define Motor_1_PWM_10_COMPARE2_LSB    (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
		    #define Motor_1_PWM_10_COMPARE2_LSB_PTR ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
		    #define Motor_1_PWM_10_COUNTERCAP_LSB   (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
		    #define Motor_1_PWM_10_COUNTERCAP_LSB_PTR ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
		    #define Motor_1_PWM_10_COUNTER_LSB     (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
		    #define Motor_1_PWM_10_COUNTER_LSB_PTR  ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
		    #define Motor_1_PWM_10_CAPTURE_LSB     (*(reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
		    #define Motor_1_PWM_10_CAPTURE_LSB_PTR  ((reg16 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
		#endif
		
	   #define Motor_1_PWM_10_AUX_CONTROLDP1    (*(reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)
       #define Motor_1_PWM_10_AUX_CONTROLDP1_PTR  ((reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (Motor_1_PWM_10_Resolution == 8) */
   
   #define Motor_1_PWM_10_AUX_CONTROLDP0      (*(reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)
   #define Motor_1_PWM_10_AUX_CONTROLDP0_PTR  ((reg8 *) Motor_1_PWM_10_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (Motor_1_PWM_10_UsingFixedFunction) */
   
#if(Motor_1_PWM_10_KillModeMinTime )
    #define Motor_1_PWM_10_KILLMODEMINTIME      (*(reg8 *) Motor_1_PWM_10_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define Motor_1_PWM_10_KILLMODEMINTIME_PTR   ((reg8 *) Motor_1_PWM_10_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (Motor_1_PWM_10_KillModeMinTime ) */

#if(Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_256_CLOCKS)
    #define Motor_1_PWM_10_DEADBAND_COUNT      (*(reg8 *) Motor_1_PWM_10_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Motor_1_PWM_10_DEADBAND_COUNT_PTR  ((reg8 *) Motor_1_PWM_10_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Motor_1_PWM_10_DEADBAND_LSB_PTR    ((reg8 *) Motor_1_PWM_10_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define Motor_1_PWM_10_DEADBAND_LSB        (*(reg8 *) Motor_1_PWM_10_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_2_4_CLOCKS)
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (Motor_1_PWM_10_UsingFixedFunction)
        #define Motor_1_PWM_10_DEADBAND_COUNT        (*(reg8 *) Motor_1_PWM_10_PWMHW__CFG0) 
        #define Motor_1_PWM_10_DEADBAND_COUNT_PTR     ((reg8 *) Motor_1_PWM_10_PWMHW__CFG0)
        #define Motor_1_PWM_10_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Motor_1_PWM_10_DEADBAND_COUNT_SHIFT)
        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define Motor_1_PWM_10_DEADBAND_COUNT_SHIFT   0x06u  
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define Motor_1_PWM_10_DEADBAND_COUNT        (*(reg8 *) Motor_1_PWM_10_PWMUDB_sDB3_AsyncCtl_dbctrlreg__CONTROL_REG)
        #define Motor_1_PWM_10_DEADBAND_COUNT_PTR     ((reg8 *) Motor_1_PWM_10_PWMUDB_sDB3_AsyncCtl_dbctrlreg__CONTROL_REG)
        #define Motor_1_PWM_10_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Motor_1_PWM_10_DEADBAND_COUNT_SHIFT) 
        /* As defined by the verilog implementation of the Control Register */
        #define Motor_1_PWM_10_DEADBAND_COUNT_SHIFT   0x00u 
    #endif /* (Motor_1_PWM_10_UsingFixedFunction) */
#endif /* (Motor_1_PWM_10_DeadBandMode == Motor_1_PWM_10__B_PWM__DBM_256_CLOCKS) */



#if (Motor_1_PWM_10_UsingFixedFunction)
    #define Motor_1_PWM_10_STATUS                (*(reg8 *) Motor_1_PWM_10_PWMHW__SR0)
    #define Motor_1_PWM_10_STATUS_PTR            ((reg8 *) Motor_1_PWM_10_PWMHW__SR0)
    #define Motor_1_PWM_10_STATUS_MASK           (*(reg8 *) Motor_1_PWM_10_PWMHW__SR0)
    #define Motor_1_PWM_10_STATUS_MASK_PTR       ((reg8 *) Motor_1_PWM_10_PWMHW__SR0)
    #define Motor_1_PWM_10_CONTROL               (*(reg8 *) Motor_1_PWM_10_PWMHW__CFG0)
    #define Motor_1_PWM_10_CONTROL_PTR           ((reg8 *) Motor_1_PWM_10_PWMHW__CFG0)    
    #define Motor_1_PWM_10_CONTROL2              (*(reg8 *) Motor_1_PWM_10_PWMHW__CFG1)    
    #if(CY_PSOC3 || CY_PSOC5LP)
        #define Motor_1_PWM_10_CONTROL3              (*(reg8 *) Motor_1_PWM_10_PWMHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Motor_1_PWM_10_GLOBAL_ENABLE         (*(reg8 *) Motor_1_PWM_10_PWMHW__PM_ACT_CFG)
    #define Motor_1_PWM_10_GLOBAL_ENABLE_PTR       ( (reg8 *) Motor_1_PWM_10_PWMHW__PM_ACT_CFG)
    #define Motor_1_PWM_10_GLOBAL_STBY_ENABLE      (*(reg8 *) Motor_1_PWM_10_PWMHW__PM_STBY_CFG)
    #define Motor_1_PWM_10_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) Motor_1_PWM_10_PWMHW__PM_STBY_CFG)
  
  
    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define Motor_1_PWM_10_BLOCK_EN_MASK          Motor_1_PWM_10_PWMHW__PM_ACT_MSK
    #define Motor_1_PWM_10_BLOCK_STBY_EN_MASK     Motor_1_PWM_10_PWMHW__PM_STBY_MSK 
    /* Control Register definitions */
    #define Motor_1_PWM_10_CTRL_ENABLE_SHIFT      0x00u
    
    #if(CY_PSOC5A)
        #define Motor_1_PWM_10_CTRL_CMPMODE1_SHIFT    0x01u   /* As defined by Register map as MODE_CFG bits in CFG1*/
    #endif /* (CY_PSOC5A) */
    #if(CY_PSOC3 || CY_PSOC5LP)
        #define Motor_1_PWM_10_CTRL_CMPMODE1_SHIFT    0x04u  /* As defined by Register map as MODE_CFG bits in CFG2*/
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    
    #define Motor_1_PWM_10_CTRL_DEAD_TIME_SHIFT   0x06u   /* As defined by Register map */
    /* Fixed Function Block Only CFG register bit definitions */
    #define Motor_1_PWM_10_CFG0_MODE              0x02u   /*  Set to compare mode */
    /* #define Motor_1_PWM_10_CFG0_ENABLE            0x01u */  /* Enable the block to run */
    #define Motor_1_PWM_10_CFG0_DB                0x20u   /* As defined by Register map as DB bit in CFG0 */

    /* Control Register Bit Masks */
    #define Motor_1_PWM_10_CTRL_ENABLE            (uint8)((uint8)0x01u << Motor_1_PWM_10_CTRL_ENABLE_SHIFT)
    #define Motor_1_PWM_10_CTRL_RESET             (uint8)((uint8)0x01u << Motor_1_PWM_10_CTRL_RESET_SHIFT)
    #define Motor_1_PWM_10_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Motor_1_PWM_10_CTRL_CMPMODE2_SHIFT)
    #if(CY_PSOC5A)
        #define Motor_1_PWM_10_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Motor_1_PWM_10_CTRL_CMPMODE1_SHIFT)
    #endif /* (CY_PSOC5A) */
    #if(CY_PSOC3 || CY_PSOC5LP)
        #define Motor_1_PWM_10_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Motor_1_PWM_10_CTRL_CMPMODE1_SHIFT)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    
    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Motor_1_PWM_10_CTRL2_IRQ_SEL_SHIFT    0x00u       
    #define Motor_1_PWM_10_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << Motor_1_PWM_10_CTRL2_IRQ_SEL_SHIFT)  
    
    /* Status Register Bit Locations */
    #define Motor_1_PWM_10_STATUS_TC_SHIFT            0x07u   /* As defined by Register map as TC in SR0 */
    #define Motor_1_PWM_10_STATUS_CMP1_SHIFT          0x06u   /* As defined by the Register map as CAP_CMP in SR0 */
    
    /* Status Register Interrupt Enable Bit Locations */
    #define Motor_1_PWM_10_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)    
    #define Motor_1_PWM_10_STATUS_TC_INT_EN_MASK_SHIFT            (Motor_1_PWM_10_STATUS_TC_SHIFT - 4u)
    #define Motor_1_PWM_10_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)  
    #define Motor_1_PWM_10_STATUS_CMP1_INT_EN_MASK_SHIFT          (Motor_1_PWM_10_STATUS_CMP1_SHIFT - 4u)
    
    /* Status Register Bit Masks */
    #define Motor_1_PWM_10_STATUS_TC              (uint8)((uint8)0x01u << Motor_1_PWM_10_STATUS_TC_SHIFT)
    #define Motor_1_PWM_10_STATUS_CMP1            (uint8)((uint8)0x01u << Motor_1_PWM_10_STATUS_CMP1_SHIFT)
    
    /* Status Register Interrupt Bit Masks*/
    #define Motor_1_PWM_10_STATUS_TC_INT_EN_MASK              (uint8)((uint8)Motor_1_PWM_10_STATUS_TC >> 4u)
    #define Motor_1_PWM_10_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)Motor_1_PWM_10_STATUS_CMP1 >> 4u)
    
    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP*/
    #define Motor_1_PWM_10_RT1_SHIFT             0x04u
    #define Motor_1_PWM_10_RT1_MASK              (uint8)((uint8)0x03u << Motor_1_PWM_10_RT1_SHIFT)/* Sync TC and CMP bit masks */
    #define Motor_1_PWM_10_SYNC                  (uint8)((uint8)0x03u << Motor_1_PWM_10_RT1_SHIFT)
    #define Motor_1_PWM_10_SYNCDSI_SHIFT         0x00u
    #define Motor_1_PWM_10_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << Motor_1_PWM_10_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    #define Motor_1_PWM_10_SYNCDSI_EN            (uint8)((uint8)0x0Fu << Motor_1_PWM_10_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    

#else
    #define Motor_1_PWM_10_STATUS                (*(reg8 *) Motor_1_PWM_10_PWMUDB_sSTSReg_nrstSts_stsreg__STATUS_REG )
    #define Motor_1_PWM_10_STATUS_PTR            ((reg8 *) Motor_1_PWM_10_PWMUDB_sSTSReg_nrstSts_stsreg__STATUS_REG )
    #define Motor_1_PWM_10_STATUS_MASK           (*(reg8 *) Motor_1_PWM_10_PWMUDB_sSTSReg_nrstSts_stsreg__MASK_REG)
    #define Motor_1_PWM_10_STATUS_MASK_PTR       ((reg8 *) Motor_1_PWM_10_PWMUDB_sSTSReg_nrstSts_stsreg__MASK_REG)
    #define Motor_1_PWM_10_STATUS_AUX_CTRL       (*(reg8 *) Motor_1_PWM_10_PWMUDB_sSTSReg_nrstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Motor_1_PWM_10_CONTROL               (*(reg8 *) Motor_1_PWM_10_PWMUDB_sCTRLReg_AsyncCtl_ctrlreg__CONTROL_REG)
    #define Motor_1_PWM_10_CONTROL_PTR           ((reg8 *) Motor_1_PWM_10_PWMUDB_sCTRLReg_AsyncCtl_ctrlreg__CONTROL_REG)
    
    
    /***********************************
    *          Constants
    ***********************************/

    /* Control Register definitions */
    #define Motor_1_PWM_10_CTRL_ENABLE_SHIFT      0x07u
    #define Motor_1_PWM_10_CTRL_RESET_SHIFT       0x06u
    #define Motor_1_PWM_10_CTRL_CMPMODE2_SHIFT    0x03u
    #define Motor_1_PWM_10_CTRL_CMPMODE1_SHIFT    0x00u
    #define Motor_1_PWM_10_CTRL_DEAD_TIME_SHIFT   0x00u   /* No Shift Needed for UDB block */
    /* Control Register Bit Masks */
    #define Motor_1_PWM_10_CTRL_ENABLE            (uint8)((uint8)0x01u << Motor_1_PWM_10_CTRL_ENABLE_SHIFT)
    #define Motor_1_PWM_10_CTRL_RESET             (uint8)((uint8)0x01u << Motor_1_PWM_10_CTRL_RESET_SHIFT)
    #define Motor_1_PWM_10_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Motor_1_PWM_10_CTRL_CMPMODE2_SHIFT)
    #define Motor_1_PWM_10_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Motor_1_PWM_10_CTRL_CMPMODE1_SHIFT) 
    
    /* Status Register Bit Locations */
    #define Motor_1_PWM_10_STATUS_KILL_SHIFT          0x05u
    #define Motor_1_PWM_10_STATUS_FIFONEMPTY_SHIFT    0x04u
    #define Motor_1_PWM_10_STATUS_FIFOFULL_SHIFT      0x03u  
    #define Motor_1_PWM_10_STATUS_TC_SHIFT            0x02u
    #define Motor_1_PWM_10_STATUS_CMP2_SHIFT          0x01u
    #define Motor_1_PWM_10_STATUS_CMP1_SHIFT          0x00u
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Motor_1_PWM_10_STATUS_KILL_INT_EN_MASK_SHIFT          Motor_1_PWM_10_STATUS_KILL_SHIFT          
    #define Motor_1_PWM_10_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    Motor_1_PWM_10_STATUS_FIFONEMPTY_SHIFT    
    #define Motor_1_PWM_10_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      Motor_1_PWM_10_STATUS_FIFOFULL_SHIFT        
    #define Motor_1_PWM_10_STATUS_TC_INT_EN_MASK_SHIFT            Motor_1_PWM_10_STATUS_TC_SHIFT            
    #define Motor_1_PWM_10_STATUS_CMP2_INT_EN_MASK_SHIFT          Motor_1_PWM_10_STATUS_CMP2_SHIFT          
    #define Motor_1_PWM_10_STATUS_CMP1_INT_EN_MASK_SHIFT          Motor_1_PWM_10_STATUS_CMP1_SHIFT   
    /* Status Register Bit Masks */
    #define Motor_1_PWM_10_STATUS_KILL            (uint8)((uint8)0x00u << Motor_1_PWM_10_STATUS_KILL_SHIFT )
    #define Motor_1_PWM_10_STATUS_FIFOFULL        (uint8)((uint8)0x01u << Motor_1_PWM_10_STATUS_FIFOFULL_SHIFT)
    #define Motor_1_PWM_10_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << Motor_1_PWM_10_STATUS_FIFONEMPTY_SHIFT)
    #define Motor_1_PWM_10_STATUS_TC              (uint8)((uint8)0x01u << Motor_1_PWM_10_STATUS_TC_SHIFT)
    #define Motor_1_PWM_10_STATUS_CMP2            (uint8)((uint8)0x01u << Motor_1_PWM_10_STATUS_CMP2_SHIFT) 
    #define Motor_1_PWM_10_STATUS_CMP1            (uint8)((uint8)0x01u << Motor_1_PWM_10_STATUS_CMP1_SHIFT)
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Motor_1_PWM_10_STATUS_KILL_INT_EN_MASK            Motor_1_PWM_10_STATUS_KILL
    #define Motor_1_PWM_10_STATUS_FIFOFULL_INT_EN_MASK        Motor_1_PWM_10_STATUS_FIFOFULL
    #define Motor_1_PWM_10_STATUS_FIFONEMPTY_INT_EN_MASK      Motor_1_PWM_10_STATUS_FIFONEMPTY
    #define Motor_1_PWM_10_STATUS_TC_INT_EN_MASK              Motor_1_PWM_10_STATUS_TC
    #define Motor_1_PWM_10_STATUS_CMP2_INT_EN_MASK            Motor_1_PWM_10_STATUS_CMP2
    #define Motor_1_PWM_10_STATUS_CMP1_INT_EN_MASK            Motor_1_PWM_10_STATUS_CMP1
                                                          
    /* Datapath Auxillary Control Register definitions */
    #define Motor_1_PWM_10_AUX_CTRL_FIFO0_CLR     0x01u
    #define Motor_1_PWM_10_AUX_CTRL_FIFO1_CLR     0x02u
    #define Motor_1_PWM_10_AUX_CTRL_FIFO0_LVL     0x04u
    #define Motor_1_PWM_10_AUX_CTRL_FIFO1_LVL     0x08u
    #define Motor_1_PWM_10_STATUS_ACTL_INT_EN_MASK  0x10u /* As defined for the ACTL Register */
#endif /* Motor_1_PWM_10_UsingFixedFunction */

#endif  /* CY_PWM_Motor_1_PWM_10_H */


/* [] END OF FILE */
