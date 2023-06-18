################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MEXTI/MEXTI_prg.c 

OBJS += \
./MCAL/MEXTI/MEXTI_prg.o 

C_DEPS += \
./MCAL/MEXTI/MEXTI_prg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MEXTI/%.o: ../MCAL/MEXTI/%.c MCAL/MEXTI/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\HAL\HLCD3" -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\MCAL\MTIMER_0" -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\LIB" -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\MCAL\MADC" -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\HAL\HSSD_2" -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\HAL\HPB" -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\MCAL\MEXTI" -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\HAL\HBUZZ" -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\HAL\HLED" -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\HAL\HKEYPAD" -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\MCAL\MDIO" -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\HAL\HKEYPAD" -I"C:\Users\Saif Elden\Desktop\AVR_Workspace\NTI_4MONTHS\MCAL\DIO" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


