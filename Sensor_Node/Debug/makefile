################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./I2C.obj" \
"./MPU6050.obj" \
"./main.obj" \
"./msp430_spi.obj" \
"./msprf24.obj" \
"../lnk_msp430g2553.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
MPU6050_Sensor_Node.out \

EXE_OUTPUTS__QUOTED += \
"MPU6050_Sensor_Node.out" \

BIN_OUTPUTS += \
MPU6050_Sensor_Node.hex \

BIN_OUTPUTS__QUOTED += \
"MPU6050_Sensor_Node.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "MPU6050_Sensor_Node.out"

# Tool invocations
MPU6050_Sensor_Node.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: MSP430 Linker'
	"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS/bin/cl430" -vmsp --use_hw_mpy=none --advice:power=all --define=__MSP430G2553__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number -z -m"MPU6050_Sensor_Node.map" --heap_size=80 --stack_size=80 -i"D:/ti/ccs1210/ccs/ccs_base/msp430/include" -i"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS/lib" -i"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="MPU6050_Sensor_Node_linkInfo.xml" --use_hw_mpy=none --rom_model -o "MPU6050_Sensor_Node.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

MPU6050_Sensor_Node.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: MSP430 Hex Utility'
	"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS/bin/hex430" --memwidth=8 --romwidth=8 --diag_wrap=off -o "MPU6050_Sensor_Node.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "I2C.obj" "MPU6050.obj" "main.obj" "msp430_spi.obj" "msprf24.obj" 
	-$(RM) "I2C.d" "MPU6050.d" "main.d" "msp430_spi.d" "msprf24.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

