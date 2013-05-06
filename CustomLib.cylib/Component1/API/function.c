/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <device.h>

void `$INSTANCE_NAME`_Enable()
{
    uint8 val;
    
	val = `$INSTANCE_NAME`_Status_Reg_1_Read();
    if((val & 2) == 0) {
        if(`$Step_Pattern` == 1) {
            `$INSTANCE_NAME`_PWM_1_Enable();
            `$INSTANCE_NAME`_PWM_2_Enable();
            `$INSTANCE_NAME`_PWM_3_Enable();
            `$INSTANCE_NAME`_PWM_4_Enable();
        } else if(`$Step_Pattern` == 2) {
            `$INSTANCE_NAME`_PWM_9_Enable();
            `$INSTANCE_NAME`_PWM_10_Enable();
            `$INSTANCE_NAME`_PWM_11_Enable();
            `$INSTANCE_NAME`_PWM_12_Enable();
            }
    } else {
        if(`$Step_Pattern` == 1) {
            `$INSTANCE_NAME`_PWM_5_Enable();
            `$INSTANCE_NAME`_PWM_6_Enable();
            `$INSTANCE_NAME`_PWM_7_Enable();
            `$INSTANCE_NAME`_PWM_8_Enable();
        } else if(`$Step_Pattern` == 2) {
            `$INSTANCE_NAME`_PWM_13_Enable();
            `$INSTANCE_NAME`_PWM_14_Enable();
            `$INSTANCE_NAME`_PWM_15_Enable();
            `$INSTANCE_NAME`_PWM_16_Enable();
            }
    }
}

void `$INSTANCE_NAME`_Init()
{
    if(`$Step_Type` == 1) {
        //Set the PWM's to single step
        
        }
    if(`$Step_Pattern` == 0) {
    //FULL STEP
    
    } else if (`$Step_Pattern` == 2) {
    //HALF STEP
    
    }

    `$INSTANCE_NAME`_PWM_1_Init();
    `$INSTANCE_NAME`_PWM_2_Init();
    `$INSTANCE_NAME`_PWM_3_Init();
    `$INSTANCE_NAME`_PWM_4_Init();
    `$INSTANCE_NAME`_PWM_5_Init();
    `$INSTANCE_NAME`_PWM_6_Init();
    `$INSTANCE_NAME`_PWM_7_Init();
    `$INSTANCE_NAME`_PWM_8_Init();
    `$INSTANCE_NAME`_PWM_9_Init();
    `$INSTANCE_NAME`_PWM_10_Init();
    `$INSTANCE_NAME`_PWM_11_Init();
    `$INSTANCE_NAME`_PWM_12_Init();
    `$INSTANCE_NAME`_PWM_13_Init();
    `$INSTANCE_NAME`_PWM_14_Init();
    `$INSTANCE_NAME`_PWM_15_Init();
    `$INSTANCE_NAME`_PWM_16_Init();
}

void `$INSTANCE_NAME`_Start()
{
    uint8 val;
	
	val = `$INSTANCE_NAME`_Status_Reg_1_Read();
    if((val & 2) == 0) {
            if(`$Step_Pattern` == 1) {
                 `$INSTANCE_NAME`_PWM_1_Start();
                 `$INSTANCE_NAME`_PWM_2_Start();
                 `$INSTANCE_NAME`_PWM_3_Start();
                 `$INSTANCE_NAME`_PWM_4_Start();
                 } else if (`$Step_Pattern` == 2) {
                 `$INSTANCE_NAME`_PWM_9_Start();
                 `$INSTANCE_NAME`_PWM_10_Start();
                 `$INSTANCE_NAME`_PWM_11_Start();
                 `$INSTANCE_NAME`_PWM_12_Start();
                 }
                    
    } else {
            if(`$Step_Pattern` == 1) {
                 `$INSTANCE_NAME`_PWM_5_Start();
                 `$INSTANCE_NAME`_PWM_6_Start();
                 `$INSTANCE_NAME`_PWM_7_Start();
                 `$INSTANCE_NAME`_PWM_8_Start();
            } else if (`$Step_Pattern` == 2) {
                 `$INSTANCE_NAME`_PWM_13_Start();
                 `$INSTANCE_NAME`_PWM_14_Start();
                 `$INSTANCE_NAME`_PWM_15_Start();
                 `$INSTANCE_NAME`_PWM_16_Start();
                 }
    }
}

void `$INSTANCE_NAME`_Stop()
{
    uint8 val;
	
	val = `$INSTANCE_NAME`_Status_Reg_1_Read();
    if((val & 2) == 0) {
          if(`$Step_Pattern` == 1) {
            `$INSTANCE_NAME`_PWM_1_Stop();
            `$INSTANCE_NAME`_PWM_2_Stop();
            `$INSTANCE_NAME`_PWM_3_Stop();
            `$INSTANCE_NAME`_PWM_4_Stop();
          } else if (`$Step_Pattern` == 2) {
                 `$INSTANCE_NAME`_PWM_9_Stop();
                 `$INSTANCE_NAME`_PWM_10_Stop();
                 `$INSTANCE_NAME`_PWM_11_Stop();
                 `$INSTANCE_NAME`_PWM_12_Stop();
          }  
    } else {
          if(`$Step_Pattern` == 1) {
                `$INSTANCE_NAME`_PWM_5_Stop();
                `$INSTANCE_NAME`_PWM_6_Stop();
                `$INSTANCE_NAME`_PWM_7_Stop();
                `$INSTANCE_NAME`_PWM_8_Stop();
          } else if (`$Step_Pattern` == 2) {
                 `$INSTANCE_NAME`_PWM_13_Stop();
                 `$INSTANCE_NAME`_PWM_14_Stop();
                 `$INSTANCE_NAME`_PWM_15_Stop();
                 `$INSTANCE_NAME`_PWM_16_Stop();
          }  
    }
}

void `$INSTANCE_NAME`_SetDirection(uint8 direction)
{	
    uint8 val;

    val = `$INSTANCE_NAME`_Control_Reg_1_Read();
    if (direction) {
	    `$INSTANCE_NAME`_Control_Reg_1_Write(val | 0x02);
    } else {
        `$INSTANCE_NAME`_Control_Reg_1_Write(val & ~0x02);
    }
}

void `$INSTANCE_NAME`_Reset()
{	
    uint8 val;
    
    val = `$INSTANCE_NAME`_Control_Reg_1_Read();
	`$INSTANCE_NAME`_Control_Reg_1_Write(val | 0x04);
    `$INSTANCE_NAME`_Control_Reg_1_Write(val & ~0x04);
}

/* [] END OF FILE */
