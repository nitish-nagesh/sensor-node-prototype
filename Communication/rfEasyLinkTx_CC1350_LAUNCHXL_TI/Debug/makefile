################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/Users/User/CCS9.0.1.00004_win64/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS

GEN_OPTS__FLAG := --cmd_file="configPkg/compiler.opt"
GEN_CMDS__FLAG := -l"configPkg/linker.cmd"

ORDERED_OBJS += \
"./CC1350_LAUNCHXL.obj" \
"./ccfg.obj" \
"./rfEasyLinkTx.obj" \
"./wsnQueue.obj" \
"./easylink/EasyLink.obj" \
"./smartrf_settings/smartrf_settings.obj" \
"./smartrf_settings/smartrf_settings_predefined.obj" \
"../CC1350_LAUNCHXL.cmd" \
$(GEN_CMDS__FLAG) \
-l"/products/cc13xxware_2_04_03_17272/driverlib/bin/ccs/driverlib.lib" \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include easylink/subdir_vars.mk
-include smartrf_settings/subdir_vars.mk
-include subdir_rules.mk
-include easylink/subdir_rules.mk
-include smartrf_settings/subdir_rules.mk
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
rfEasyLinkTx_CC1350_LAUNCHXL_TI.out \

EXE_OUTPUTS__QUOTED += \
"rfEasyLinkTx_CC1350_LAUNCHXL_TI.out" \

BIN_OUTPUTS += \
rfEasyLinkTx_CC1350_LAUNCHXL_TI.hex \

BIN_OUTPUTS__QUOTED += \
"rfEasyLinkTx_CC1350_LAUNCHXL_TI.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "rfEasyLinkTx_CC1350_LAUNCHXL_TI.out"

# Tool invocations
rfEasyLinkTx_CC1350_LAUNCHXL_TI.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"C:/Users/User/CCS9.0.1.00004_win64/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi -z -m"rfEasyLinkTx_CC1350_LAUNCHXL_TI.map" --heap_size=0 --stack_size=256 -i"C:/Users/User/CCS9.0.1.00004_win64/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS/lib" -i"C:/Users/User/CCS9.0.1.00004_win64/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="rfEasyLinkTx_CC1350_LAUNCHXL_TI_linkInfo.xml" --rom_model -o "rfEasyLinkTx_CC1350_LAUNCHXL_TI.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

rfEasyLinkTx_CC1350_LAUNCHXL_TI.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"C:/Users/User/CCS9.0.1.00004_win64/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS/bin/armhex" --memwidth=8 --romwidth=8 --intel -o "rfEasyLinkTx_CC1350_LAUNCHXL_TI.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "CC1350_LAUNCHXL.obj" "ccfg.obj" "rfEasyLinkTx.obj" "wsnQueue.obj" "easylink\EasyLink.obj" "smartrf_settings\smartrf_settings.obj" "smartrf_settings\smartrf_settings_predefined.obj" 
	-$(RM) "CC1350_LAUNCHXL.d" "ccfg.d" "rfEasyLinkTx.d" "wsnQueue.d" "easylink\EasyLink.d" "smartrf_settings\smartrf_settings.d" "smartrf_settings\smartrf_settings_predefined.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

