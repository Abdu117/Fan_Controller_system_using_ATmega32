################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO/ADC.c \
../GPIO/App.c \
../GPIO/DcMotor.c \
../GPIO/LCD.c \
../GPIO/Timer0.c \
../GPIO/gpio.c \
../GPIO/lm35_sensor.c 

OBJS += \
./GPIO/ADC.o \
./GPIO/App.o \
./GPIO/DcMotor.o \
./GPIO/LCD.o \
./GPIO/Timer0.o \
./GPIO/gpio.o \
./GPIO/lm35_sensor.o 

C_DEPS += \
./GPIO/ADC.d \
./GPIO/App.d \
./GPIO/DcMotor.d \
./GPIO/LCD.d \
./GPIO/Timer0.d \
./GPIO/gpio.d \
./GPIO/lm35_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO/%.o: ../GPIO/%.c GPIO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


