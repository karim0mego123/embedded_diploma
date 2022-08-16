################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
TOGGLE_BIt.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
TOGGLE_BIt.list \

OBJCOPY_HEX += \
TOGGLE_BIt.hex \

OBJCOPY_BIN += \
TOGGLE_BIt.bin \


# All Target
all: TOGGLE_BIt.elf secondary-outputs

# Tool invocations
TOGGLE_BIt.elf: $(OBJS) $(USER_OBJS) C:\Users\karim\Desktop\stm\ workspace\TOGGLE_BIt\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "TOGGLE_BIt.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\karim\Desktop\stm workspace\TOGGLE_BIt\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="TOGGLE_BIt.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

TOGGLE_BIt.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "TOGGLE_BIt.list"
	@echo 'Finished building: $@'
	@echo ' '

TOGGLE_BIt.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "TOGGLE_BIt.hex"
	@echo 'Finished building: $@'
	@echo ' '

TOGGLE_BIt.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "TOGGLE_BIt.bin"
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
