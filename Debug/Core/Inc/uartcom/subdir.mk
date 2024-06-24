################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/uartcom/uartcom.c 

OBJS += \
./Core/Inc/uartcom/uartcom.o 

C_DEPS += \
./Core/Inc/uartcom/uartcom.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/uartcom/%.o Core/Inc/uartcom/%.su Core/Inc/uartcom/%.cyclo: ../Core/Inc/uartcom/%.c Core/Inc/uartcom/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-uartcom

clean-Core-2f-Inc-2f-uartcom:
	-$(RM) ./Core/Inc/uartcom/uartcom.cyclo ./Core/Inc/uartcom/uartcom.d ./Core/Inc/uartcom/uartcom.o ./Core/Inc/uartcom/uartcom.su

.PHONY: clean-Core-2f-Inc-2f-uartcom

