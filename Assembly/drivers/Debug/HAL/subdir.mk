################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/I2C_Slave_EEPROM.c \
../HAL/Keypad.c \
../HAL/LCD.c 

OBJS += \
./HAL/I2C_Slave_EEPROM.o \
./HAL/Keypad.o \
./HAL/LCD.o 

C_DEPS += \
./HAL/I2C_Slave_EEPROM.d \
./HAL/Keypad.d \
./HAL/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/I2C_Slave_EEPROM.o: ../HAL/I2C_Slave_EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/include" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/portable/GCC/ARM_CM3" -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc/LIB" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/I2C_Slave_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/Keypad.o: ../HAL/Keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/include" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/portable/GCC/ARM_CM3" -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc/LIB" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/include" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/portable/GCC/ARM_CM3" -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc/LIB" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

