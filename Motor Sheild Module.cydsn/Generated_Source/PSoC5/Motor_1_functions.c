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

/* Motor_1_Init:
 * Initializes all PWM's inside the motor module.
*/
void Motor_1_Init()
{
    uint8 val;
    val = Motor_1_Status_Reg_1_Read();
    if ((val & 1) == 0) {
    Motor_1_PWM_1_Init();
    Motor_1_PWM_2_Init();
    Motor_1_PWM_3_Init();
    Motor_1_PWM_4_Init();
    } else {
    Motor_1_PWM_5_Init();
    Motor_1_PWM_6_Init();
    Motor_1_PWM_7_Init();
    Motor_1_PWM_8_Init();
    }
}

/* Motor_1_Start:
 * Initializes all PWM's inside the motor module.
*/
void Motor_1_Start()
{
    uint8 val;
    val = Motor_1_Status_Reg_1_Read();
    if ((val & 1) == 0) {
        Motor_1_PWM_1_Start();
        Motor_1_PWM_2_Start();
        Motor_1_PWM_3_Start();
        Motor_1_PWM_4_Start();
    } else {
        Motor_1_PWM_5_Start();
        Motor_1_PWM_6_Start();
        Motor_1_PWM_7_Start();
        Motor_1_PWM_8_Start();
    }
}

/* Motor_1_Stop:
 * Stops all PWM's inside the motor module.
*/
void Motor_1_Stop()
{
    Motor_1_PWM_1_Stop();
    Motor_1_PWM_2_Stop();
    Motor_1_PWM_3_Stop();
    Motor_1_PWM_4_Stop();
    Motor_1_PWM_5_Stop();
    Motor_1_PWM_6_Stop();
    Motor_1_PWM_7_Stop();
    Motor_1_PWM_8_Stop();
}

/* Motor_1_Enable:
 * Sets enable for all PWM's inside the motor module.
*/
void Motor_1_Enable()
{
    uint8 val;
    val = Motor_1_Status_Reg_1_Read();
    
    Motor_1_Control_Reg_1_Write(val | 2);
}

/* Motor_1_Reset:
 * Resets all PWM's inside the motor module.
*/
void Motor_1_Reset()
{
    Motor_1_Stop();
    Motor_1_Start();
}

/* Motor_1_SetDirection:
 * Sets direction for all PWM's inside the motor module.
*/
void Motor_1_SetDirection(uint8 Direction)
{
    uint8 val;

    val = Motor_1_Status_Reg_1_Read();
    Motor_1_Control_Reg_1_Write(val | Direction);
}
/* [] END OF FILE */
