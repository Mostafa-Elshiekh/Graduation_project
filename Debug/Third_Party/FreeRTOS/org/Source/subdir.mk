################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_Party/FreeRTOS/org/Source/croutine.c \
../Third_Party/FreeRTOS/org/Source/event_groups.c \
../Third_Party/FreeRTOS/org/Source/list.c \
../Third_Party/FreeRTOS/org/Source/queue.c \
../Third_Party/FreeRTOS/org/Source/stream_buffer.c \
../Third_Party/FreeRTOS/org/Source/tasks.c \
../Third_Party/FreeRTOS/org/Source/timers.c 

OBJS += \
./Third_Party/FreeRTOS/org/Source/croutine.o \
./Third_Party/FreeRTOS/org/Source/event_groups.o \
./Third_Party/FreeRTOS/org/Source/list.o \
./Third_Party/FreeRTOS/org/Source/queue.o \
./Third_Party/FreeRTOS/org/Source/stream_buffer.o \
./Third_Party/FreeRTOS/org/Source/tasks.o \
./Third_Party/FreeRTOS/org/Source/timers.o 

C_DEPS += \
./Third_Party/FreeRTOS/org/Source/croutine.d \
./Third_Party/FreeRTOS/org/Source/event_groups.d \
./Third_Party/FreeRTOS/org/Source/list.d \
./Third_Party/FreeRTOS/org/Source/queue.d \
./Third_Party/FreeRTOS/org/Source/stream_buffer.d \
./Third_Party/FreeRTOS/org/Source/tasks.d \
./Third_Party/FreeRTOS/org/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Third_Party/FreeRTOS/org/Source/croutine.o: ../Third_Party/FreeRTOS/org/Source/croutine.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Config" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM3" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/include" -I../Inc -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/hal/include" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Third_Party/FreeRTOS/org/Source/croutine.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Third_Party/FreeRTOS/org/Source/event_groups.o: ../Third_Party/FreeRTOS/org/Source/event_groups.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Config" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM3" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/include" -I../Inc -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/hal/include" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Third_Party/FreeRTOS/org/Source/event_groups.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Third_Party/FreeRTOS/org/Source/list.o: ../Third_Party/FreeRTOS/org/Source/list.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Config" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM3" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/include" -I../Inc -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/hal/include" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Third_Party/FreeRTOS/org/Source/list.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Third_Party/FreeRTOS/org/Source/queue.o: ../Third_Party/FreeRTOS/org/Source/queue.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Config" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM3" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/include" -I../Inc -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/hal/include" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Third_Party/FreeRTOS/org/Source/queue.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Third_Party/FreeRTOS/org/Source/stream_buffer.o: ../Third_Party/FreeRTOS/org/Source/stream_buffer.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Config" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM3" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/include" -I../Inc -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/hal/include" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Third_Party/FreeRTOS/org/Source/stream_buffer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Third_Party/FreeRTOS/org/Source/tasks.o: ../Third_Party/FreeRTOS/org/Source/tasks.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Config" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM3" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/include" -I../Inc -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/hal/include" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Third_Party/FreeRTOS/org/Source/tasks.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Third_Party/FreeRTOS/org/Source/timers.o: ../Third_Party/FreeRTOS/org/Source/timers.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Config" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM3" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Third_Party/FreeRTOS/org/Source/include" -I../Inc -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/drivers/INC" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/hal/include" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/F103C8/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Third_Party/FreeRTOS/org/Source/timers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

