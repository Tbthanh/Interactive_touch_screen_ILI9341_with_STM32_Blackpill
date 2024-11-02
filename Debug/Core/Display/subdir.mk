################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Display/display.c 

C_DEPS += \
./Core/Display/display.d 

OBJS += \
./Core/Display/display.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Display/%.o Core/Display/%.su Core/Display/%.cyclo: ../Core/Display/%.c Core/Display/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Touch -I../Core/Images -I../Core/ILI9341 -I../Core/Icons -I../Core/Display -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Display

clean-Core-2f-Display:
	-$(RM) ./Core/Display/display.cyclo ./Core/Display/display.d ./Core/Display/display.o ./Core/Display/display.su

.PHONY: clean-Core-2f-Display

