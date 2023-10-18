/*
 * DcMotor.c
 *
 *  Created on: MARCH 17, 2022
 *      Author: Mostafa Mahmoud Elshiekh
 */

#include "DcMotor.h"

void Motor1_Init()
{
	GPIO_Pin_Configure_t PinCinfg;

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_14;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, & PinCinfg);


	PinCinfg.GPIO_Pin_Number=GPIO_PIN_15;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, & PinCinfg);

}
void Motor1_Forward(void)
{
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);//IN1
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);//IN2
}

void Motor1_Backward(void)
{
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//IN1
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//IN2
}

void Motor1_Stop(void)
{
	Timer1_PWM1_Set_Value(PWM_TIM_0);
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//IN1
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);//IN2
}


void Motor2_Init()
{
	GPIO_Pin_Configure_t PinCinfg;

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_7;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, & PinCinfg);


	PinCinfg.GPIO_Pin_Number=GPIO_PIN_8;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, & PinCinfg);

}
void Motor2_Forward(void)
{
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);//IN1
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 1);//IN2
}

void Motor2_Backward(void)
{
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);//IN1
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 0);//IN2
}

void Motor2_Stop(void)
{
	Timer1_PWM2_Set_Value(PWM_TIM_0);
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);//IN1
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 0);//IN2
}



void DC_Motor(int NumMotor , int Direction , int Speed)
{
	/*=========================Motor 1==============================*/
	if(NumMotor == THE_LEFT_MOTOR)//Motor 1
	{
		if(Direction == Forward)
		{
			Timer1_PWM1_Set_Value(Speed);
			Motor1_Forward();
		}
		if(Direction==Backwards)
		{
			Timer1_PWM1_Set_Value(Speed);
			Motor1_Backward();
		}

	}

	/*=========================Motor 2==============================*/

	if(NumMotor == THE_RIGHT_MOTOR)//Motor 1
	{
		if(Direction == Forward)
		{
			Timer1_PWM2_Set_Value(Speed);
			Motor2_Forward();
		}
		if(Direction==Backwards)
		{
			Timer1_PWM2_Set_Value(Speed);
			Motor2_Backward();
		}
	}

}


/*=========================WheeelChair==============================*/

void WheelChair_Forward(int Speed)
{
	DC_Motor(THE_LEFT_MOTOR,Forward,Speed);
	DC_Motor(THE_RIGHT_MOTOR,Forward,Speed);
}

void WheelChair_Stop(void)
{
	Motor1_Stop();
	Motor2_Stop();
}

void WheelChair_Backward(int Speed)
{
	DC_Motor(THE_LEFT_MOTOR,Backwards,Speed);
	DC_Motor(THE_RIGHT_MOTOR,Backwards,Speed);
}
