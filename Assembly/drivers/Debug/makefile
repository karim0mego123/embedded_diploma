################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stm32f103c6_Drivers/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include HAL/subdir.mk
-include FreeRtos/portable/MemMang/subdir.mk
-include FreeRtos/portable/GCC/ARM_CM3/subdir.mk
-include FreeRtos/subdir.mk
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
drivers.axf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
drivers.list \

OBJCOPY_HEX += \
drivers.hex \

OBJCOPY_BIN += \
drivers.bin \


# All Target
all: drivers.axf secondary-outputs

# Tool invocations
drivers.axf: $(OBJS) $(USER_OBJS) C:\Users\karim\Desktop\Embedded_system_diploma\embedded_diploma\embedded_diploma\Peripherals\drivers\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "drivers.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\karim\Desktop\Embedded_system_diploma\embedded_diploma\embedded_diploma\Peripherals\drivers\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="drivers.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

drivers.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "drivers.list"
	@echo 'Finished building: $@'
	@echo ' '

drivers.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "drivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

drivers.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "drivers.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
