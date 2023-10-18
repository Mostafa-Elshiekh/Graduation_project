/*
 * UltrasonicSensor.h
 *
 *  Created on: MARC 21, 2022
 *      Author: Mostafa Mahmoud Elshiekh
 */

#ifndef INCLUDE_ULTRASONICSENSOR_H_
#define INCLUDE_ULTRASONICSENSOR_H_

#include "STM32F103C8_GPIO_DRIVER.h"
#include "STM32_F103C8_TIMER_DRIVER.h"


//Ultersonic Pins
#define Ultrasonic_Triger_Pin                 GPIO_PIN_12
#define Ultrasonic_Echo_Pin                   GPIO_PIN_13
#define Ultrasonic_PORT                       GPIOB
#define Sound_Speed                           34500


/* ==============================================================
 *              APIs Supported by "HAL ULTRASONIC_SENSOR DRIVER"
 * ===============================================================*/
void Ultrasonic_GPIO_Init(void);
void Ultrasonic_Trigger(void);
int Ultrasonic_Calculate_Distance(float Tim_count);
int Ultrasonic_Read(void);


#endif /* INCLUDE_ULTRASONICSENSOR_H_ */
