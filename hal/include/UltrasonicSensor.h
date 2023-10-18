/*
 * UltrasonicSensor.h
 *
 *  Created on: Oct 7, 2021
 *      Author: Mostafa Elshiekh
 */

#ifndef INCLUDE_ULTRASONICSENSOR_H_
#define INCLUDE_ULTRASONICSENSOR_H_

#include "STM32_F103C6.h"
#include "STM32F103C6_GPIO_DRIVERS.h"
#include "LCD_ME.h"
#include "Timer.h"
#include "DcMotor.h"

//Ultersonic Pins
#define Ultrasonic_Triger_Pin                 GPIO_PIN_12
#define Ultrasonic_Echo_Pin                   GPIO_PIN_13
#define Ultrasonic_PORT                       GPIOB
#define Sound_Speed                           34500

void Ultrasonic_GPIO_Init(void);
void Ultrasonic_Trigger(void);
int Ultrasonic_Calculate_Distance(float Tim_count);
int Ultrasonic_Read(void);


#endif /* INCLUDE_ULTRASONICSENSOR_H_ */
