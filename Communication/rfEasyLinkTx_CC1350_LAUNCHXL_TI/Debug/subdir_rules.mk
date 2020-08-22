################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/Users/User/CCS9.0.1.00004_win64/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="D:/Nitish/Nitish's Stuff_Dolly Laptop/Nitish's Stuff/MS in Germany/TU Munich MSPE/During Your Studies/Courses/Labs/Sensor Nodes Laboratory/Communication/rfEasyLinkTx_CC1350_LAUNCHXL_TI" --include_path="D:/Nitish/Nitish's Stuff_Dolly Laptop/Nitish's Stuff/MS in Germany/TU Munich MSPE/During Your Studies/Courses/Labs/Sensor Nodes Laboratory/Communication/rfEasyLinkTx_CC1350_LAUNCHXL_TI" --include_path="D:/Nitish/Nitish's Stuff_Dolly Laptop/Nitish's Stuff/MS in Germany/TU Munich MSPE/During Your Studies/Courses/Labs/Sensor Nodes Laboratory/Communication/rfEasyLinkTx_CC1350_LAUNCHXL_TI/easylink" --include_path="D:/Nitish/Nitish's Stuff_Dolly Laptop/Nitish's Stuff/MS in Germany/TU Munich MSPE/During Your Studies/Courses/Labs/Sensor Nodes Laboratory/Communication/rfEasyLinkTx_CC1350_LAUNCHXL_TI/smartrf_settings" --include_path="/products/cc13xxware_2_04_03_17272" --include_path="C:/Users/User/CCS9.0.1.00004_win64/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-797594785:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-797594785-inproc

build-797594785-inproc: ../rfExamples.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/Users/User/CCS9.0.1.00004_win64/xdctools_3_55_00_11_core/xs" --xdcpath="C:/Users/User/CCS9.0.1.00004_win64/ccs/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M3 -p ti.platforms.simplelink:CC1350F128 -r release -c "C:/Users/User/CCS9.0.1.00004_win64/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS" --compileOptions "-mv7M3 --code_state=16 --float_support=vfplib -me --include_path=\"D:/Nitish/Nitish's Stuff_Dolly Laptop/Nitish's Stuff/MS in Germany/TU Munich MSPE/During Your Studies/Courses/Labs/Sensor Nodes Laboratory/Communication/rfEasyLinkTx_CC1350_LAUNCHXL_TI\" --include_path=\"D:/Nitish/Nitish's Stuff_Dolly Laptop/Nitish's Stuff/MS in Germany/TU Munich MSPE/During Your Studies/Courses/Labs/Sensor Nodes Laboratory/Communication/rfEasyLinkTx_CC1350_LAUNCHXL_TI\" --include_path=\"D:/Nitish/Nitish's Stuff_Dolly Laptop/Nitish's Stuff/MS in Germany/TU Munich MSPE/During Your Studies/Courses/Labs/Sensor Nodes Laboratory/Communication/rfEasyLinkTx_CC1350_LAUNCHXL_TI/easylink\" --include_path=\"D:/Nitish/Nitish's Stuff_Dolly Laptop/Nitish's Stuff/MS in Germany/TU Munich MSPE/During Your Studies/Courses/Labs/Sensor Nodes Laboratory/Communication/rfEasyLinkTx_CC1350_LAUNCHXL_TI/smartrf_settings\" --include_path=\"/products/cc13xxware_2_04_03_17272\" --include_path=\"C:/Users/User/CCS9.0.1.00004_win64/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS/include\" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi  " "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-797594785 ../rfExamples.cfg
configPkg/compiler.opt: build-797594785
configPkg/: build-797594785


