

#include "STM32_F103C6.h"
#include "STM32F103C6_GPIO_DRIVERS.h"
#include "Timer.h"
#include "UltrasonicSensor.h"
#include "DcMotor.h"
#include "STM32F103C6_USART_DRIVERS.h"
#include "Buzzer.h"
#include "string.h"
#include "stdbool.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"



/*Directions Commands Which Will Be Recived From Frist ECU(Master)*/
/*========================================================*/
#define FORWARD      'W'
#define RIGHT        'D'
#define LEFT     	 'A'
#define BACKWARD 	 'S'
#define STOP     	 'O'
/*========================================================*/

/*Speeds Commands Which Will Be Recived from First ECU(Master)*/
/*========================================================*/
#define SPEED_0     PWM_TIM_0
#define SPEED_10    PWM_TIM_10
#define SPEED_20    PWM_TIM_20
#define SPEED_30    PWM_TIM_30
#define SPEED_40    PWM_TIM_40
#define SPEED_50    PWM_TIM_50
#define SPEED_60    PWM_TIM_60
#define SPEED_75    PWM_TIM_75
#define SPEED_80    PWM_TIM_80
#define SPEED_90    PWM_TIM_90
/*========================================================*/
#define AsciiToInt(Ascii) Ascii-48
#define DELLAY_STEP 40




/*=================Globale Variables=====================*/
float const SPEED_ARRAY[12]={SPEED_0,SPEED_10,
		SPEED_20,SPEED_30,SPEED_40,
		SPEED_50,SPEED_60,SPEED_75,
		SPEED_80,SPEED_90};

volatile uint8_t UART_MESSAGE[3];
volatile uint16_t Raspberry_CMD =0;

int gDistance=0;
int g_FRONT_DISTANCE=0;
int g_CRNT_SPED_INDX=0;
int Prevus_Speed_INDEX=0;
int Prevus_DIR_INDEX=0;



/*=================Fanctions Prototype=====================*/
void Raspberry_CMDS_CallBack(void);/*Call Back For UART*/
void Led_Alarm(bool State);




/*================TASKS HANDELS===============*/
TaskHandle_t xUltrasonicHandle = NULL ;
TaskHandle_t xWheelChair_ForwardHandle = NULL ;
TaskHandle_t xWheelChair_BackwardHandle = NULL ;
TaskHandle_t xWheelChair_StopHandle = NULL ;
TaskHandle_t xWheelChair_RightHandle = NULL ;
TaskHandle_t xWheelChair_LeftHandle = NULL ;
TaskHandle_t xWheelChair_WhichCommands = NULL ;




/*===============Tasks Prototype===============*/
void vUltrasonic_Handler(void* params);
void vWheelChair_Forward_Handler(void* params);
void vWheelChair_Backward_Handler(void* params);
void vWheelChair_Stop_Handler(void* params);
void vWheelChair_Right_Handler(void* params);
void xWheelChair_Left_Handler(void* params);
void vxWheelChair_WhichCommands_Handler(void* params);



int main(void)
{
	RCC_GPIOA_CLOCK_EN();
	RCC_GPIOB_CLOCK_EN();
	RCC_GPIOC_CLOCK_EN();
	RCC_AFIO_CLOCK_EN();



	//==========================UART2 INIT=============================//
	/* PA2  ->TX
	 * PA3 ->RX
	 * PA0 ->CTS
	 * PA1 ->RTS*/
	USART_Config uartCFG;
	uartCFG.BaudRate = USART_BaudRate_115200;
	uartCFG.HW_FlowCtrl = USART_HW_FlowCtrl_NONE;
	uartCFG.IRQ_Enable = USART_IRQ_Enable_RXNE;
	uartCFG.P_IRQ_Call_Back = Raspberry_CMDS_CallBack;
	uartCFG.Parity = USART_Parity_NONE;
	uartCFG.PayLoad_Length = USART_PayLoad_Length_8B;
	uartCFG.StopBits = USART_StopBits_1;
	uartCFG.USART_MODE = USART_MODE_RX_AND_TX;
	MCAL_UART_INIT(USART2, &uartCFG);
	MCAL_UART_GPIO_Set_Pins(USART2);
	//================================================================//


	Ultrasonic_GPIO_Init();
	Motor1_Init();
	Motor2_Init();
	Timer1_Init_PWM();//PWM
	Timer2_init(); //for delay
	Timer3_init();//for ultersonic

    Buzzer_Init();

	//LED AS ALRARM WHEN DESTANCE <=40CM
	GPIO_Pin_Configure_t PinCfg;
	PinCfg.GPIO_Pin_Number=GPIO_PIN_11;
	PinCfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);


	//Infrared Sensor to detecte the closed object
	GPIO_Pin_Configure_t PinCfg_Infrared;
	PinCfg_Infrared.GPIO_Pin_Number=GPIO_PIN_10;
	PinCfg_Infrared.GPIO_MODE=GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(GPIOB, &PinCfg_Infrared);
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);

	//Led To Indicate Forward
	GPIO_Pin_Configure_t PinCfg_Forward;
	PinCfg_Forward.GPIO_Pin_Number=GPIO_PIN_13;
	PinCfg_Forward.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	PinCfg_Forward.GPIO_OUTPUT_SPEED=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOC, &PinCfg_Forward);
	MCAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);



    /*===============Tasks Creation===============*/
	xTaskCreate(vUltrasonic_Handler ,"Ultrasonic" ,configMINIMAL_STACK_SIZE,NULL ,5,&xUltrasonicHandle) ;

	xTaskCreate(vWheelChair_Forward_Handler ,"WheelChairForward" ,configMINIMAL_STACK_SIZE,NULL ,4,&xWheelChair_ForwardHandle) ;
	vTaskSuspend(xWheelChair_ForwardHandle);


	xTaskCreate(vWheelChair_Backward_Handler,"WheelChairBackward",configMINIMAL_STACK_SIZE,NULL ,2,&xWheelChair_BackwardHandle) ;
	vTaskSuspend(xWheelChair_BackwardHandle);

	xTaskCreate(vWheelChair_Stop_Handler ,"WheelChairStop",configMINIMAL_STACK_SIZE,NULL ,3 ,&xWheelChair_StopHandle) ;
	vTaskSuspend(xWheelChair_StopHandle);


	xTaskCreate(vxWheelChair_WhichCommands_Handler ,"WheelChairStop",configMINIMAL_STACK_SIZE,NULL ,1 ,&xWheelChair_WhichCommands) ;



	/*xTaskCreate(vWheelChair_Right_Handler ,"WheelChairRight" ,configMINIMAL_STACK_SIZE,NULL ,2,&xWheelChairRightHandle) ;
	xTaskCreate(xWheelChair_Left_Handler ,"WheelChairLeft" ,configMINIMAL_STACK_SIZE,NULL ,2,&xWheelChairLeftHandle) ;*/

	vTaskStartScheduler() ;

	while(1)
	{

	}

	return 0;

}


void Raspberry_CMDS_CallBack(void)
{

	MCAL_UART_RECEIVE_DATA(USART2, &Raspberry_CMD, disable);
	MCAL_UART_SEND_DATA(USART2, &Raspberry_CMD, enable);

	//Direction
	if(Raspberry_CMD=='W' || Raspberry_CMD=='S' || Raspberry_CMD=='A' || Raspberry_CMD=='D' || Raspberry_CMD=='O')
	{
		UART_MESSAGE[0]=Raspberry_CMD;
	}
	//Speed
	else if((AsciiToInt(Raspberry_CMD))>=0 && (AsciiToInt(Raspberry_CMD))<10)
	{
		UART_MESSAGE[1]=Raspberry_CMD;
	}

}



void Led_Alarm(bool State)
{
	if(State == true)
	{
		MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_11,0);
		dms(5);
		MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);
		dms(5);
	}
	else if(State==false)
	{
		MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);
	}
}

/*======================System Tasks========================*/

void vUltrasonic_Handler(void* params)
{
	while(1)
	{
		Ultrasonic_Trigger();
		//g_FRONT_DISTANCE = Ultrasonic_Read();
		g_FRONT_DISTANCE =50;
		dms(10);

		if(g_FRONT_DISTANCE <40  && Prevus_DIR_INDEX==FORWARD)
		{
			Buzzer_Alarm(true);
			Led_Alarm(true);
			for(g_CRNT_SPED_INDX=Prevus_Speed_INDEX; g_CRNT_SPED_INDX>=0;g_CRNT_SPED_INDX--)
			{
				WheelChair_Forward(SPEED_ARRAY[g_CRNT_SPED_INDX]);
				dms(DELLAY_STEP);
			}
			Prevus_Speed_INDEX=0;
		}
		else
		{
			Buzzer_Alarm(false);
			Led_Alarm(false);
			MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_0,0);
		}

		vTaskDelay(60);
	}
}

void vxWheelChair_WhichCommands_Handler(void* params)
{
	while(1)
	{
		if(UART_MESSAGE[0] == FORWARD && UART_MESSAGE[1]!=0)
		{
			//should make vWheelChair_Forward_Handler active
			vTaskResume(xWheelChair_ForwardHandle);

		}
		else if(UART_MESSAGE[0] == BACKWARD && UART_MESSAGE[1]!=0)
		{
			//should make vWheelChair_Backward_Handler active
			vTaskResume(xWheelChair_BackwardHandle);

		}
		else if(UART_MESSAGE[0] == STOP)
		{
			//should make vWheelChair_Stop_Handler active
			vTaskResume(xWheelChair_StopHandle);

		}
		vTaskDelay(20);
	}
}


void vWheelChair_Forward_Handler(void* params)
{
	while(1)
	{
		if(Prevus_DIR_INDEX == BACKWARD)
		{
			//First Go To Stop State
			for(g_CRNT_SPED_INDX=Prevus_Speed_INDEX;g_CRNT_SPED_INDX>=0;g_CRNT_SPED_INDX--)
			{
				WheelChair_Backward(SPEED_ARRAY[g_CRNT_SPED_INDX]);
				dms(DELLAY_STEP);
			}
		}

		if(Prevus_Speed_INDEX==AsciiToInt(UART_MESSAGE[1]))
		{
			WheelChair_Forward(SPEED_ARRAY[AsciiToInt(UART_MESSAGE[1])]);
		}
		else if(AsciiToInt(UART_MESSAGE[1])>Prevus_Speed_INDEX)
		{
			for(g_CRNT_SPED_INDX=Prevus_Speed_INDEX; g_CRNT_SPED_INDX< AsciiToInt(UART_MESSAGE[1]) ;g_CRNT_SPED_INDX++)
			{
				WheelChair_Forward(SPEED_ARRAY[g_CRNT_SPED_INDX]);
				dms(DELLAY_STEP);
			}
		}
		else if(AsciiToInt(UART_MESSAGE[1])<Prevus_Speed_INDEX)
		{
			for(g_CRNT_SPED_INDX=Prevus_Speed_INDEX; g_CRNT_SPED_INDX>AsciiToInt(UART_MESSAGE[1]) ;g_CRNT_SPED_INDX--)
			{
				WheelChair_Forward(SPEED_ARRAY[g_CRNT_SPED_INDX]);
				dms(DELLAY_STEP);
			}
		}

		Prevus_Speed_INDEX = AsciiToInt(UART_MESSAGE[1]);
		Prevus_DIR_INDEX = UART_MESSAGE[0];
		UART_MESSAGE[0]=0;
		UART_MESSAGE[1]=0;
		vTaskSuspend(xWheelChair_ForwardHandle);
	}
}




void vWheelChair_Backward_Handler(void* params)
{
	while(1)
	{
		if(Prevus_DIR_INDEX == FORWARD)
		{
			//First Go To Stop State
			for(g_CRNT_SPED_INDX=Prevus_Speed_INDEX;g_CRNT_SPED_INDX>=0;g_CRNT_SPED_INDX--)
			{
				WheelChair_Forward(SPEED_ARRAY[g_CRNT_SPED_INDX]);
				dms(DELLAY_STEP);
			}
		}

		//Second Go To Backword State
		if(Prevus_Speed_INDEX==AsciiToInt(UART_MESSAGE[1]))
		{
			WheelChair_Backward(SPEED_ARRAY[AsciiToInt(UART_MESSAGE[1])]);
		}
		else if(AsciiToInt(UART_MESSAGE[1])>Prevus_Speed_INDEX)
		{
			for(g_CRNT_SPED_INDX=Prevus_Speed_INDEX; g_CRNT_SPED_INDX< AsciiToInt(UART_MESSAGE[1]) ;g_CRNT_SPED_INDX++)
			{
				WheelChair_Backward(SPEED_ARRAY[g_CRNT_SPED_INDX]);
				dms(DELLAY_STEP);
			}
		}
		else if(AsciiToInt(UART_MESSAGE[1])<Prevus_Speed_INDEX)
		{
			for(g_CRNT_SPED_INDX=Prevus_Speed_INDEX; g_CRNT_SPED_INDX>AsciiToInt(UART_MESSAGE[1]) ;g_CRNT_SPED_INDX--)
			{
				WheelChair_Backward(SPEED_ARRAY[g_CRNT_SPED_INDX]);
				dms(DELLAY_STEP);
			}
		}
		Prevus_Speed_INDEX = AsciiToInt(UART_MESSAGE[1]);
		Prevus_DIR_INDEX = UART_MESSAGE[0];
		UART_MESSAGE[0]=0;
		UART_MESSAGE[1]=0;
		vTaskSuspend(xWheelChair_BackwardHandle);
	}
}



void vWheelChair_Stop_Handler(void* params)
{
	while(1)
	{
		if(Prevus_DIR_INDEX==FORWARD)
		{
			for(g_CRNT_SPED_INDX=Prevus_Speed_INDEX; g_CRNT_SPED_INDX>=0;g_CRNT_SPED_INDX--)
			{
				WheelChair_Forward(SPEED_ARRAY[g_CRNT_SPED_INDX]);
				dms(DELLAY_STEP);
			}
		}
		if(Prevus_DIR_INDEX==BACKWARD)
		{
			for(g_CRNT_SPED_INDX=Prevus_Speed_INDEX; g_CRNT_SPED_INDX>=0;g_CRNT_SPED_INDX--)
			{
				WheelChair_Backward(SPEED_ARRAY[g_CRNT_SPED_INDX]);
				dms(DELLAY_STEP);
			}
		}

		Prevus_Speed_INDEX=0;
		Prevus_DIR_INDEX=STOP;
		UART_MESSAGE[0]=0;
		UART_MESSAGE[1]=0;
		vTaskSuspend(xWheelChair_StopHandle);
	}
}



void vWheelChair_Right_Handler(void* params)
{
	while(1)
	{


		vTaskDelay(20);
	}
}




void xWheelChair_Left_Handler(void* params)
{
	while(1)
	{


		vTaskDelay(20);
	}
}




























