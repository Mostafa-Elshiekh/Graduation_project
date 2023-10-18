/*
 * DcMotor.h
 *
 *  Created on: Oct 7, 2021
 *      Author: Mostafa Mahmoud Elshiekh
 */

#ifndef INCLUDE_DCMOTOR_H_
#define INCLUDE_DCMOTOR_H_

#include "STM32_F103C6.h"
#include "STM32F103C6_GPIO_DRIVERS.h"
#include "Timer.h"

#define THE_LEFT_MOTOR        1
#define THE_RIGHT_MOTOR       2

#define Forward               1
#define Backwards             0


void Motor1_Init(void);
void Motor2_Init(void);
void DC_Motor(int NumMotor , int Direction , int Speed);


void WheelChair_Forward(int Speed);
void WheelChair_Stop(void);
void WheelChair_Backward(int Speed);
void WheelChair_Right(void);
void WheelChair_Left(void);



#endif /* INCLUDE_DCMOTOR_H_ */
