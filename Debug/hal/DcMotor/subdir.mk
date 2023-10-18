################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/DcMotor/DcMotor.c 

OBJS += \
./hal/DcMotor/DcMotor.o 

C_DEPS += \
./hal/DcMotor/DcMotor.d 


# Each subdirectory must supply rules for building sources it contributes
hal/DcMotor/DcMotor.o: ../hal/DcMotor/DcMotor.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Config" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM3" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/include" -I../Inc -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/hal/include" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hal/DcMotor/DcMotor.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

