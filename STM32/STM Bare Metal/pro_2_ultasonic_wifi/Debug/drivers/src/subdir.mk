################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/esp8266.c \
../drivers/src/gpio.c \
../drivers/src/rcc.c \
../drivers/src/system_stm32l4xx.c \
../drivers/src/systick.c \
../drivers/src/timer_ic.c \
../drivers/src/ultrasonic.c \
../drivers/src/usart.c 

OBJS += \
./drivers/src/esp8266.o \
./drivers/src/gpio.o \
./drivers/src/rcc.o \
./drivers/src/system_stm32l4xx.o \
./drivers/src/systick.o \
./drivers/src/timer_ic.o \
./drivers/src/ultrasonic.o \
./drivers/src/usart.o 

C_DEPS += \
./drivers/src/esp8266.d \
./drivers/src/gpio.d \
./drivers/src/rcc.d \
./drivers/src/system_stm32l4xx.d \
./drivers/src/systick.d \
./drivers/src/timer_ic.d \
./drivers/src/ultrasonic.d \
./drivers/src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o drivers/src/%.su drivers/src/%.cyclo: ../drivers/src/%.c drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DSTM32L476RGTx -c -I../Inc -I"C:/Users/pavan/Documents/STM Bare Metal/pro_2_ultasonic_wifi/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-src

clean-drivers-2f-src:
	-$(RM) ./drivers/src/esp8266.cyclo ./drivers/src/esp8266.d ./drivers/src/esp8266.o ./drivers/src/esp8266.su ./drivers/src/gpio.cyclo ./drivers/src/gpio.d ./drivers/src/gpio.o ./drivers/src/gpio.su ./drivers/src/rcc.cyclo ./drivers/src/rcc.d ./drivers/src/rcc.o ./drivers/src/rcc.su ./drivers/src/system_stm32l4xx.cyclo ./drivers/src/system_stm32l4xx.d ./drivers/src/system_stm32l4xx.o ./drivers/src/system_stm32l4xx.su ./drivers/src/systick.cyclo ./drivers/src/systick.d ./drivers/src/systick.o ./drivers/src/systick.su ./drivers/src/timer_ic.cyclo ./drivers/src/timer_ic.d ./drivers/src/timer_ic.o ./drivers/src/timer_ic.su ./drivers/src/ultrasonic.cyclo ./drivers/src/ultrasonic.d ./drivers/src/ultrasonic.o ./drivers/src/ultrasonic.su ./drivers/src/usart.cyclo ./drivers/src/usart.d ./drivers/src/usart.o ./drivers/src/usart.su

.PHONY: clean-drivers-2f-src

