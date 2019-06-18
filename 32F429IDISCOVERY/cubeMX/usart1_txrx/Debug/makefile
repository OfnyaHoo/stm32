################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECOUTPUTBUILDVAR += \
EXECUTABLES \


# All Target
all: usart1_txrx.elf secondary-outputs

# Tool invocations
usart1_txrx.elf: $(OBJS) $(USER_OBJS)
	arm-atollic-eabi-gcc -o "usart1_txrx.elf" $(OBJS) $(USER_OBJS) $(LIBS) -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T"../STM32F429ZI_FLASH.ld" -specs=nosys.specs -static -u_printf_float "-Wl,-Map=usart1_txrx.map" -Wl,--gc-sections -Wl,--defsym=malloc_getpagesize_P=0x80 -Wl,--start-group -lc -lm -Wl,--end-group -specs=nano.specs
	$(MAKE) --no-print-directory post-build

EXECUTABLES: usart1_txrx.elf $(EXECUTABLES)
	"C:\Program Files (x86)\Atollic\TrueSTUDIO for STM32 9.3.0\ide\jre\bin\java" -jar "C:\Program Files (x86)\Atollic\TrueSTUDIO for STM32 9.3.0\Tools\arm-atollic-reports.jar" sizeinfo list usart1_txrx.elf

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(SECOUTPUTBUILDVAR)$(OBJS)$(C_DEPS) usart1_txrx.elf
	-@echo ' '

post-build:
	-arm-atollic-eabi-objcopy.exe -O ihex "usart1_txrx.elf" "usart1_txrx.hex"
	-@echo ' '

secondary-outputs: $(SECOUTPUTBUILDVAR)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
