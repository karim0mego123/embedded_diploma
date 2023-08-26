################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRtos/portable/MemMang/heap_4.c 

OBJS += \
./FreeRtos/portable/MemMang/heap_4.o 

C_DEPS += \
./FreeRtos/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRtos/portable/MemMang/heap_4.o: ../FreeRtos/portable/MemMang/heap_4.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/include" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/portable/GCC/ARM_CM3" -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc/LIB" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRtos/portable/MemMang/heap_4.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

