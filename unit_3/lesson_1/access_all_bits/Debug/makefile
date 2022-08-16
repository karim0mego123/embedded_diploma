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
ACCESS_ALL_BITS.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ACCESS_ALL_BITS.list \

OBJCOPY_BIN += \
ACCESS_ALL_BITS.bin \


# All Target
all: ACCESS_ALL_BITS.elf secondary-outputs

# Tool invocations
ACCESS_ALL_BITS.elf: $(OBJS) $(USER_OBJS) C:\Users\karim\Desktop\Embedded_system_diploma\Embedded_system_diploma\unit_3\lesson_1\access_all_bits\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "ACCESS_ALL_BITS.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\karim\Desktop\Embedded_system_diploma\Embedded_system_diploma\unit_3\lesson_1\access_all_bits\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ACCESS_ALL_BITS.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ACCESS_ALL_BITS.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ACCESS_ALL_BITS.list"
	@echo 'Finished building: $@'
	@echo ' '

ACCESS_ALL_BITS.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ACCESS_ALL_BITS.bin"
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
