/*
 * Buzzer.h
 *
 *  Created on: Mar 7, 2022
 *      Author: Mostafa Mahmoud Elshiekh
 */



#ifndef INCLUDE_BUZZER_H_
#define INCLUDE_BUZZER_H_

#include "STM32_F103C6.h"
#include "STM32F103C6_GPIO_DRIVERS.h"
#include "stdbool.h"

#define Buzzer_PORTx       GPIOB
#define Buzzer_PINx        GPIO_PIN_4

void Buzzer_Init();
void Buzzer_Alarm(bool State);


#endif /* INCLUDE_BUZZER_H_ */
