################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_Drivers/EXTI.c \
../stm32f103c6_Drivers/GPIO.c \
../stm32f103c6_Drivers/RCC.c \
../stm32f103c6_Drivers/UART.c 

OBJS += \
./stm32f103c6_Drivers/EXTI.o \
./stm32f103c6_Drivers/GPIO.o \
./stm32f103c6_Drivers/RCC.o \
./stm32f103c6_Drivers/UART.o 

C_DEPS += \
./stm32f103c6_Drivers/EXTI.d \
./stm32f103c6_Drivers/GPIO.d \
./stm32f103c6_Drivers/RCC.d \
./stm32f103c6_Drivers/UART.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_Drivers/EXTI.o: ../stm32f103c6_Drivers/EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_Drivers/EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_Drivers/GPIO.o: ../stm32f103c6_Drivers/GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_Drivers/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_Drivers/RCC.o: ../stm32f103c6_Drivers/RCC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_Drivers/RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_Drivers/UART.o: ../stm32f103c6_Drivers/UART.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_Drivers/UART.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

