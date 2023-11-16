/*
 * ADC.c
 *
 * Created: 11/13/2023 2:45:09 AM
 *  Author: VTE
 */ 
#include <avr/io.h>
#include "std_macros.h"
void ADC_vinit(void)
{
	SET_BIT(ADMUX,REFS0);  // for volt AREF (internal)
	SET_BIT(ADMUX,REFS1); 
	
	SET_BIT(ADMUX,MUX4); 
	
	SET_BIT(ADCSRA,ADEN);  // for enable
	
	SET_BIT(ADCSRA,ADPS2); // for clock 125k
	SET_BIT(ADCSRA,ADPS1);
}
unsigned short ADC_Read(void)
{
	unsigned short val;
	SET_BIT(ADCSRA,ADSC); // to start conversion
	while(IS_BIT_CLR(ADCSRA,ADIF)); 
	SET_BIT(ADCSRA,ADIF);
	val=ADCL;
	val|=(ADCH<<8);
	return val;
}