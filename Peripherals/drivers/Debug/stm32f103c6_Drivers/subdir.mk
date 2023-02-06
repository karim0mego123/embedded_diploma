################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_Drivers/EXTI.c \
../stm32f103c6_Drivers/GPIO.c 

OBJS += \
./stm32f103c6_Drivers/EXTI.o \
./stm32f103c6_Drivers/GPIO.o 

C_DEPS += \
./stm32f103c6_Drivers/EXTI.d \
./stm32f103c6_Drivers/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_Drivers/EXTI.o: ../stm32f103c6_Drivers/EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/karim/Desktop/STM_WorkSpace/drivers/HAL/inc" -I"C:/Users/karim/Desktop/STM_WorkSpace/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_Drivers/EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_Drivers/GPIO.o: ../stm32f103c6_Drivers/GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/karim/Desktop/STM_WorkSpace/drivers/HAL/inc" -I"C:/Users/karim/Desktop/STM_WorkSpace/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_Drivers/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

