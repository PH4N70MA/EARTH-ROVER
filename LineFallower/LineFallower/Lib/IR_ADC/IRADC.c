/*
 * IRADC.c
 *
 *  Author: alexg
 */ 

#include <avr/io.h>
#include <math.h>
#include "IRADC.h"

void ADC_init(void)
{
	ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); //ADC Enable, ADC Interrupt Enable, Prescaler 128
	ADMUX |= (1<<REFS0);  //AVCC with external capacitor at AREF pin
	PORTA = (1<<PA0);
}

uint16_t ADC_read(SensorPin channel)
{
	switch(channel)
	{
		case sensorOne:
		ADMUX &=~ 0x1F;
		break;
		case sensorTwo:
		ADMUX &=~ 0x1F;
		ADMUX |= (1<<MUX0);
		break;
		case sensorThree:
		ADMUX &=~ 0x1F;
		ADMUX |= (1<<MUX1);
		break;
		case sensorFour:
		ADMUX &=~ 0x1F;
		ADMUX |= (1<<MUX0)|(1<<MUX1);
		break;
		case sensorFive:
		ADMUX &=~ 0x1F;
		ADMUX |= (1<<MUX2);
		break;
	}
	ADCSRA |= (1<<ADSC);  //Start ADC Conversion
	while ((ADCSRA & (1<<ADSC)));  //Wait for ADC Conversion to complete
	return ADC;  //Return ADC value
}

float ADC_Filter(uint8_t precision, SensorPin channel)
{
	double value;
	double sum=0;
	for(int i=0;i<precision;i++)
	{
		value = ADC_read(channel);
		sum+=value;
	}
	return (sum/precision);
	};
