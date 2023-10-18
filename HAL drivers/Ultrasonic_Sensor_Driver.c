/*
 * Ultrasonic_Sensor_Driver.c
 *
 *  Created on: MARCH 22, 2022
 *      Author: Mostafa Elshiekh
 */

#include "Ultrasonic_Sensor_Driver.h"


int flag=0;
int distance=0;
int static count=0;

/**=================================================================
 * @Fn -                    -Ultrasonic_GPIO_Init
 * @brief -                 -Initialize the Ultrasonic_PORT PINs
 * @param [in] -            -void
 * @retval -                -none
 */
/**================================================================= */
void Ultrasonic_GPIO_Init(void)
{

	GPIO_Pin_Configure_t PinCinfgUltrasonic;

	//Make Ultrasonic_Triger_Pin As Output
	PinCinfgUltrasonic.GPIO_Pin_Number=Ultrasonic_Triger_Pin;
	PinCinfgUltrasonic.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfgUltrasonic.GPIO_OUTPUT_SPEED=GPIO_SPEED_10M;
	MCAL_GPIO_Init(Ultrasonic_PORT, & PinCinfgUltrasonic);

	//Make Ultrasonic_Echo_Pin As Input
	PinCinfgUltrasonic.GPIO_Pin_Number=Ultrasonic_Echo_Pin;
	PinCinfgUltrasonic.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(Ultrasonic_PORT, & PinCinfgUltrasonic);
}

/**=================================================================
 * @Fn -                    -Ultrasonic_Trigger
 * @brief -                 -Initialize the GPIOx PINy according specified parameters in PinConfig
 * @param [in] -            -GPIOx : where x can be (A..E depending on device used)
 * @param [in] -            -PinConfig pointer to a GPIO_PinConfig_t structure that contains
 * @retval -                -none
 * note -                   -stmf103c6 MCU has GPIO A,B,C,D,E Modules
 *                           but LQFP48 Package has only GPIO A,B, Part of C/D exported external pins
 */
/**================================================================= */

void Ultrasonic_Trigger(void)
{
	MCAL_GPIO_WritePin(Ultrasonic_PORT, Ultrasonic_Triger_Pin, 1);
	delay_us(10);
	MCAL_GPIO_WritePin(Ultrasonic_PORT, Ultrasonic_Triger_Pin, 0);
	delay_us(1000);
}

int Ultrasonic_Calculate_Distance(float Tim_count)
{
	float Distance ;
	float Time_Sec=0;

	Time_Sec = ((float)Tim_count/1000); //The time with sec
	Distance = (Time_Sec*Sound_Speed*0.5); //to make distance with CM

	return Distance;
}

int Ultrasonic_Read(void)
{
	if(MCAL_GPIO_Read_Pin(Ultrasonic_PORT, Ultrasonic_Echo_Pin)==GPIO_PIN_TRUE)
	{
		TIM3_CNT =0; //TO ENSURE THE COUNTER START WITH ZERO VALUE
		Count_Start_Vlaue=TIM3_CNT;
		flag=1;
	}

	while(MCAL_GPIO_Read_Pin(Ultrasonic_PORT, Ultrasonic_Echo_Pin)==GPIO_PIN_TRUE);
	Count_End_Vlaue=TIM3_CNT;

	if(flag==1)
	{

		Puls_width = (float)(Count_End_Vlaue-Count_Start_Vlaue)/1000;
		distance = Ultrasonic_Calculate_Distance(Puls_width)+9;
	}

	return distance;
}
