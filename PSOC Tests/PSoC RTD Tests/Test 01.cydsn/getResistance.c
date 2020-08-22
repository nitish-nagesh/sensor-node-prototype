/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "getResistance.h"
#include "removeOffsetNoise.h"

/*******************************************************************************
*  Function Name: MeasureRefResVoltage
********************************************************************************
* Summary:
* This functions returns the voltage across the reference resistor. 
*
* Parameters:
* none
*
* Return: 
* reference voltage in ADC counts

* Theory:
* A current is passed through the reference resistor and the voltage across it 
* is measured. Offset is measured and subtracted from this voltage. An IIR filter 
* is also applied on this voltage.
*
* Side Effects:
* None
*******************************************************************************/
int32 MeasureRefResVoltage()
{
	/* Voltage read across reference resistor in ADC counts */
	int32 rtdRefResult = 0;
	
	
	/* Filtered value for reference voltage measurement */
	int32 filRtdRefResult = 0;
	
	/* Offset counts */
	int32 zeroCurrentOffset = 0;
	
	/* Select the right current Mux and ADC Mux Channels */
	CurrentMux_FastSelect(REF_IDAC_CHANNEL);
	ADCMux_FastSelect(REF_CHANNEL);
	
	/* Configure the IDAC to source 1 mA */
	IDAC_SetValue(125);
		
	/* Read voltage across reference resistor */
	ADC_StartConvert();

	ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
	rtdRefResult = ADC_GetResult32();
		

	
	/* Get the offset voltage */
	zeroCurrentOffset = GetOffset();
		
	/* Get CDS difference */
	rtdRefResult = rtdRefResult - zeroCurrentOffset; 

	/* Filter signal */
	filRtdRefResult = FilterSignal(rtdRefResult, REF_RES);
	
	return filRtdRefResult;
}
/*******************************************************************************
*  Function Name: GetRTDRes
********************************************************************************
* Summary:
* This function measures the voltage across the RTD resistance.   
*
* Parameters:
* int32 vRef - reference voltage in ADC counts
*
* Return: 
* int32 rtdRes - RTD resistance in milliohms

* Theory:
* A current is passed through the reference resistor and the voltage across it 
* is measured. Offset is measured and subtracted from this voltage. An IIR filter 
* is also applied on this voltage.
*
* Side Effects:
* None
*******************************************************************************/
int32 GetRTDRes(int32 vRef)
{
	/* Voltage read across RTD sensor in ADC counts */
	int32 rtdResult = 0;
	
	/* Filtered value for RTD sensor voltage measurement */
	int32 filRtdResult;
	
	/* RTD resistance */
	int32 rtdRes = 0;
	
	/* Offset counts */
	int32 zeroCurrentOffset = 0;
    
	
	/* Set the IDAC to pass 1 mA */
	IDAC_SetValue(125);
	
	/* Select the right current Mux and ADC Mux Channels */
	CurrentMux_FastSelect(RTD_IDAC_CHANNEL);
	ADCMux_FastSelect(RTD_CHANNEL);
		
	/* Read voltage across RTD */
	ADC_StartConvert();
	ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
	rtdResult = ADC_GetResult32();

		
	/* Read zero current voltage across RTD sensor resistor */
	zeroCurrentOffset = GetOffset();
	
	/* Get CDS difference */
	rtdResult = rtdResult - zeroCurrentOffset; 
	
	/* Filter signal */
	filRtdResult = FilterSignal(rtdResult, RTD);
	
	/* Find RTD resistance in milliohms */
    /* To save precision we need to cast the numerator to a float*/
	rtdRes =  (int32)(((float)filRtdResult / vRef) * REF_RESISTOR);
	
	return rtdRes;
}

/* [] END OF FILE */


/* [] END OF FILE */
