################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BSP/KEY/key1.cpp 

OBJS += \
./BSP/KEY/key1.o 

CPP_DEPS += \
./BSP/KEY/key1.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/KEY/%.o BSP/KEY/%.su BSP/KEY/%.cyclo: ../BSP/KEY/%.cpp BSP/KEY/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"P:/Project/Rosmsater/BSP" -I"P:/Project/Rosmsater/BSP/beep" -I"P:/Project/Rosmsater/BSP/KEY" -I"P:/Project/Rosmsater/BSP/LED" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-BSP-2f-KEY

clean-BSP-2f-KEY:
	-$(RM) ./BSP/KEY/key1.cyclo ./BSP/KEY/key1.d ./BSP/KEY/key1.o ./BSP/KEY/key1.su

.PHONY: clean-BSP-2f-KEY

