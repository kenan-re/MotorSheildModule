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

void main()
{
    Motor_1_Init();
    Motor_1_Start();
 //  Motor_1_Enable();
//   Motor_1_Init();
//   Motor_1_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
/*    PWM_1_Init();
    PWM_2_Init();
    PWM_3_Init();
    PWM_4_Init();
    PWM_5_Init();
    PWM_6_Init();
    PWM_7_Init();
    PWM_8_Init();*/
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
