################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include hal/UltrasonicSensor/subdir.mk
-include hal/DcMotor/subdir.mk
-include hal/Buzzer/subdir.mk
-include drivers/subdir.mk
-include Third_Party/FreeRTOS/org/Source/portable/MemMang/subdir.mk
-include Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM3/subdir.mk
-include Third_Party/FreeRTOS/org/Source/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
F103C8.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
F103C8.list \

OBJCOPY_BIN += \
F103C8.bin \


# All Target
all: F103C8.elf secondary-outputs

# Tool invocations
F103C8.elf: $(OBJS) $(USER_OBJS) C:\Users\musta\STM32CubeIDE\workspace_1.4.0\F103C8\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc  -gdwarf-2 -o "F103C8.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\musta\STM32CubeIDE\workspace_1.4.0\F103C8\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="F103C8.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

F103C8.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "F103C8.list"
	@echo 'Finished building: $@'
	@echo ' '

F103C8.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "F103C8.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
