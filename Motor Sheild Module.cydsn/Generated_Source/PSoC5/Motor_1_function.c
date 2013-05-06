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

void Motor_1_Enable()
{
    uint8 val;
    
	val = Motor_1_Status_Reg_1_Read();
    if((val & 2) == 0) {
        if(1 == 1) {
            Motor_1_PWM_1_Enable();
            Motor_1_PWM_2_Enable();
            Motor_1_PWM_3_Enable();
            Motor_1_PWM_4_Enable();
        } else if(1 == 2) {
            Motor_1_PWM_9_Enable();
            Motor_1_PWM_10_Enable();
            Motor_1_PWM_11_Enable();
            Motor_1_PWM_12_Enable();
            }
    } else {
        if(1 == 1) {
            Motor_1_PWM_5_Enable();
            Motor_1_PWM_6_Enable();
            Motor_1_PWM_7_Enable();
            Motor_1_PWM_8_Enable();
        } else if(1 == 2) {
            Motor_1_PWM_13_Enable();
            Motor_1_PWM_14_Enable();
            Motor_1_PWM_15_Enable();
            Motor_1_PWM_16_Enable();
            }
    }
}

void Motor_1_Init()
{
    if(1 == 1) {
        //Set the PWM's to single step
        
        }
    if(1 == 0) {
    //FULL STEP
    
    } else if (1 == 2) {
    //HALF STEP
    
    }

    Motor_1_PWM_1_Init();
    Motor_1_PWM_2_Init();
    Motor_1_PWM_3_Init();
    Motor_1_PWM_4_Init();
    Motor_1_PWM_5_Init();
    Motor_1_PWM_6_Init();
    Motor_1_PWM_7_Init();
    Motor_1_PWM_8_Init();
    Motor_1_PWM_9_Init();
    Motor_1_PWM_10_Init();
    Motor_1_PWM_11_Init();
    Motor_1_PWM_12_Init();
    Motor_1_PWM_13_Init();
    Motor_1_PWM_14_Init();
    Motor_1_PWM_15_Init();
    Motor_1_PWM_16_Init();
}

void Motor_1_Start()
{
    uint8 val;
	
	val = Motor_1_Status_Reg_1_Read();
    if((val & 2) == 0) {
            if(1 == 1) {
                 Motor_1_PWM_1_Start();
                 Motor_1_PWM_2_Start();
                 Motor_1_PWM_3_Start();
                 Motor_1_PWM_4_Start();
                 } else if (1 == 2) {
                 Motor_1_PWM_9_Start();
                 Motor_1_PWM_10_Start();
                 Motor_1_PWM_11_Start();
                 Motor_1_PWM_12_Start();
                 }
                    
    } else {
            if(1 == 1) {
                 Motor_1_PWM_5_Start();
                 Motor_1_PWM_6_Start();
                 Motor_1_PWM_7_Start();
                 Motor_1_PWM_8_Start();
            } else if (1 == 2) {
                 Motor_1_PWM_13_Start();
                 Motor_1_PWM_14_Start();
                 Motor_1_PWM_15_Start();
                 Motor_1_PWM_16_Start();
                 }
    }
}

void Motor_1_Stop()
{
    uint8 val;
	
	val = Motor_1_Status_Reg_1_Read();
    if((val & 2) == 0) {
          if(1 == 1) {
            Motor_1_PWM_1_Stop();
            Motor_1_PWM_2_Stop();
            Motor_1_PWM_3_Stop();
            Motor_1_PWM_4_Stop();
          } else if (1 == 2) {
                 Motor_1_PWM_9_Stop();
                 Motor_1_PWM_10_Stop();
                 Motor_1_PWM_11_Stop();
                 Motor_1_PWM_12_Stop();
          }  
    } else {
          if(1 == 1) {
                Motor_1_PWM_5_Stop();
                Motor_1_PWM_6_Stop();
                Motor_1_PWM_7_Stop();
                Motor_1_PWM_8_Stop();
          } else if (1 == 2) {
                 Motor_1_PWM_13_Stop();
                 Motor_1_PWM_14_Stop();
                 Motor_1_PWM_15_Stop();
                 Motor_1_PWM_16_Stop();
          }  
    }
}

void Motor_1_SetDirection(uint8 direction)
{	
    uint8 val;

    val = Motor_1_Control_Reg_1_Read();
    if (direction) {
	    Motor_1_Control_Reg_1_Write(val | 0x02);
    } else {
        Motor_1_Control_Reg_1_Write(val & ~0x02);
    }
}

void Motor_1_Reset()
{	
    uint8 val;
    
    val = Motor_1_Control_Reg_1_Read();
	Motor_1_Control_Reg_1_Write(val | 0x04);
    Motor_1_Control_Reg_1_Write(val & ~0x04);
}

/* [] END OF FILE */
