/*
 * Buzzer.c
 *
 *  Created on: Mar 7, 2022
 *      Author: musta
 */

#include "Buzzer.h"

void Buzzer_Init()
{
	//BUZZER AS ALRARM WHEN DESTANCE
	GPIO_Pin_Configure_t PinCfg1;
	PinCfg1.GPIO_Pin_Number=Buzzer_PINx;
	PinCfg1.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	PinCfg1.GPIO_OUTPUT_SPEED=GPIO_SPEED_10M;
	MCAL_GPIO_Init(Buzzer_PORTx, &PinCfg1);
	MCAL_GPIO_WritePin(Buzzer_PORTx,Buzzer_PINx, 0);

}
void Buzzer_Alarm(bool State)
{
	if(State == true)
	{
		MCAL_GPIO_WritePin(Buzzer_PORTx, Buzzer_PINx, 1);
	}
	else if(State==false)
	{
		MCAL_GPIO_WritePin(Buzzer_PORTx,Buzzer_PINx, 0);
	}
}
