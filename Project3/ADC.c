/*
 * ADC.c
 *
 *  Created on: Oct 8, 2022
 *      Author: abdoa
 */
#include"std_types.h"
#include "ADC.h"
#include "common_macros.h"
#include "avr/io.h"


void ADC_init(const ADC_ConfigType * Config_Ptr)

{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 01 to choose AVCC = 5v as reference voltage
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADC_Prescaler prescaler = Config_Ptr->prescaler;
	ADC_ReferenceVolatge  ref_volt = Config_Ptr->ref_volt ;

	ADMUX = (ADMUX & 0x3f)|(ref_volt<<6);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 111 to choose ADC_Clock = F_CPU/128 = 16Mhz/128 = 125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADEN);
	ADCSRA = (ADCSRA & 0xf8)| (prescaler);
}


uint16 ADC_readChannel(uint8 channel_num){

	ADMUX = (ADMUX & 0XE0)|(channel_num & 0X07); /*0XE0 to Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADCSRA|=1<<ADSC;
	while(!BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
