################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c 

OBJS += \
./Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.o 

C_DEPS += \
./Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Source/Templates/%.o Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Source/Templates/%.su Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Source/Templates/%.cyclo: ../Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Source/Templates/%.c Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Source/Templates/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -c -I../Inc -I"C:/Users/kaush/OneDrive/Documents/GitHub/stm32f407_baremetal_development/stm32f407_baremetal_drivers/Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/kaush/OneDrive/Documents/GitHub/stm32f407_baremetal_development/stm32f407_baremetal_drivers/Src/chip_headers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-chip_headers-2f-CMSIS-2f-Device-2f-ST-2f-STM32F4xx-2f-Source-2f-Templates

clean-Src-2f-chip_headers-2f-CMSIS-2f-Device-2f-ST-2f-STM32F4xx-2f-Source-2f-Templates:
	-$(RM) ./Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.cyclo ./Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.d ./Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.o ./Src/chip_headers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.su

.PHONY: clean-Src-2f-chip_headers-2f-CMSIS-2f-Device-2f-ST-2f-STM32F4xx-2f-Source-2f-Templates

