################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRtos/croutine.c \
../FreeRtos/event_groups.c \
../FreeRtos/list.c \
../FreeRtos/queue.c \
../FreeRtos/stream_buffer.c \
../FreeRtos/tasks.c \
../FreeRtos/timers.c 

OBJS += \
./FreeRtos/croutine.o \
./FreeRtos/event_groups.o \
./FreeRtos/list.o \
./FreeRtos/queue.o \
./FreeRtos/stream_buffer.o \
./FreeRtos/tasks.o \
./FreeRtos/timers.o 

C_DEPS += \
./FreeRtos/croutine.d \
./FreeRtos/event_groups.d \
./FreeRtos/list.d \
./FreeRtos/queue.d \
./FreeRtos/stream_buffer.d \
./FreeRtos/tasks.d \
./FreeRtos/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRtos/croutine.o: ../FreeRtos/croutine.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/include" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/portable/GCC/ARM_CM3" -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc/LIB" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRtos/croutine.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRtos/event_groups.o: ../FreeRtos/event_groups.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/include" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/portable/GCC/ARM_CM3" -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc/LIB" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRtos/event_groups.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRtos/list.o: ../FreeRtos/list.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/include" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/portable/GCC/ARM_CM3" -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc/LIB" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRtos/list.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRtos/queue.o: ../FreeRtos/queue.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/include" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/portable/GCC/ARM_CM3" -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc/LIB" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRtos/queue.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRtos/stream_buffer.o: ../FreeRtos/stream_buffer.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/include" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/portable/GCC/ARM_CM3" -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc/LIB" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRtos/stream_buffer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRtos/tasks.o: ../FreeRtos/tasks.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/include" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/portable/GCC/ARM_CM3" -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc/LIB" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRtos/tasks.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRtos/timers.o: ../FreeRtos/timers.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/include" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/FreeRtos/portable/GCC/ARM_CM3" -I../Inc -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc/LIB" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/HAL/inc" -I"C:/Users/karim/Desktop/Embedded_system_diploma/embedded_diploma/embedded_diploma/Peripherals/drivers/stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRtos/timers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

