/*
 * Dc_MOTOR_DRIVER.h
 *
 *  Created on: MARCH 16, 2022
 *      Author: Mostafa Mahmoud Elshiekh
 */

#ifndef INCLUDE_DC_MOTOR_H_
#define INCLUDE_DC_MOTOR_H_

#include "STM32_F103C8.h"
#include "STM32F103C8_GPIO_DRIVER.h"
#include "STM32F103C8_TIMER_DRIVER.h"



#define THE_LEFT_MOTOR        1
#define THE_RIGHT_MOTOR       2

#define Forward               1
#define Backward              0


/* ==============================================================
 *              APIs Supported by "HAL DC_MOTOR DRIVER"
 * ===============================================================*/
void DC_Motor1_Init(void);
void DC_Motor2_Init(void);
void DC_Motor(int NumMotor , int Direction , int Speed);


void WheelChair_Forward(int Speed);
void WheelChair_Stop(void);
void WheelChair_Backward(int Speed);
void WheelChair_Right(void);
void WheelChair_Left(void);



#endif /* INCLUDE_DC_MOTOR_H_ */
