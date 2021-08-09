################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/BLE/BLE.cpp 

OBJS += \
./Core/BLE/BLE.o 

CPP_DEPS += \
./Core/BLE/BLE.d 


# Each subdirectory must supply rules for building sources it contributes
Core/BLE/BLE.o: ../Core/BLE/BLE.cpp Core/BLE/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"/home/msm/STM32CubeIDE/workspace_1.6.1/BLE/Core/BLE" -I"/home/msm/STM32CubeIDE/workspace_1.6.1/BLE/Core/UART" -I"/home/msm/STM32CubeIDE/workspace_1.6.1/BLE/Core/LED" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Core/BLE/BLE.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

