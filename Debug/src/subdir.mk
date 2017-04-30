################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Driver.c \
../src/Runner.c \
../src/adc.c \
../src/delay.c \
../src/encoder.c \
../src/led.c \
../src/main.c \
../src/pid.c \
../src/pwm.c \
../src/sensor.c \
../src/stm32f4xx_it.c \
../src/syscalls.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/Controller.o \
./src/Driver.o \
./src/Runner.o \
./src/adc.o \
./src/delay.o \
./src/encoder.o \
./src/led.o \
./src/main.o \
./src/pid.o \
./src/pwm.o \
./src/sensor.o \
./src/stm32f4xx_it.o \
./src/syscalls.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/Controller.d \
./src/Driver.d \
./src/Runner.d \
./src/adc.d \
./src/delay.d \
./src/encoder.d \
./src/led.d \
./src/main.d \
./src/pid.d \
./src/pwm.d \
./src/sensor.d \
./src/stm32f4xx_it.d \
./src/syscalls.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F405RGTx -DSTM32F4 -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F40XX -DSTM32F40_41xxx -I"C:/Users/Austin/Desktop/Micromouse/inc" -I"C:/Users/Austin/Desktop/Micromouse/CMSIS/core" -I"C:/Users/Austin/Desktop/Micromouse/CMSIS/device" -I"C:/Users/Austin/Desktop/Micromouse/StdPeriph_Driver/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


