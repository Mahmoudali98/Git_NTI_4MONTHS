/*
 * MADC_prg.c
 *
 *  Created on: Jun 17, 2023
 *      Author: Saif Elden
 */

#include <avr/delay.h>
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include"ERROR_STATE.h"
#include"MDIO_int.h"
#include"MADC_priv.h"
#include"MADC_config.h"
#include"MADC_int.h"
#include"MEXTI_int.h"

void static (*ptr) (void) = NULL;


void ADC_voidInit(void)
{
	/*Disable ADC*/
	CLR_BIT(ADCSRA_REG,ADCSRA_ADEN);

	/*AVCC as reference voltage*/
	SET_BIT(ADMUX_REG,ADMUX_REFS0);
	CLR_BIT(ADMUX_REG,ADMUX_REFS1);

	/*Activate right adjustment result*/
	CLR_BIT(ADMUX_REG,ADMUX_ADLAR);
	ADC_voidSelectChannel(ADC_CHANNEL_SLELECT);

	/*Set pre-scaler 128*/
	SET_BIT(ADCSRA_REG,ADCSRA_ADPS0);
	SET_BIT(ADCSRA_REG,ADCSRA_ADPS1);
	SET_BIT(ADCSRA_REG,ADCSRA_ADPS2);

	/*clear source triggered*/
	CLR_BIT(ADCSRA_REG,ADCSRA_ADATE);
	CLR_BIT(ADCSRA_REG,ADCSRA_ADIE);

	/*Enable ADC*/
	SET_BIT(ADCSRA_REG,ADCSRA_ADEN);
}
void ADC_voidSelectChannel(u8 Copy_u8Channel)
{
	/*Clear the MUX bits in ADMUX Register*/
		ADMUX_REG&= 0b11100000;

		/*Set the required channel into the MUX bits*/
		ADMUX_REG|= Copy_u8Channel;
}
void ADC_voidStart(void)
{
	/*Start conversion*/
	SET_BIT(ADCSRA_REG,ADCSRA_ADSC);

}

u8 ADC_u8GetChacnnelReading (void)
{

	ADC_voidStart();


	/*Polling until the conversion compelete flag is set*/

	while((GET_BIT(ADCSRA_REG,ADCSRA_ADIF) == 0));

		/*clear the conversion complete flag*/
		SET_BIT(ADCSRA_REG,ADCSRA_ADIF);

		/*Return the reading*/

		return ADCL_REG + ADCH_REG;

}


u16 Analog_Value(u16 Digital_Value)
{
	u16 Analog;
	Analog=Digital_Value*(5000UL)/1024;
	return Analog;
}

u16 ADC_Result()
{
	return ADCH_REG;
}




#if 0
void ADC_Init(void)
{
	// Reference voltage is AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	// Right adjustment
	CLR_BIT(ADMUX,5);
	// Prescaler of 128
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
}
void ADC_Enable(void)
{
	SET_BIT(ADCSRA,7);

}

void ADC_Disable(void)
{
	CLR_BIT(ADCSRA,7);
}

void ADC_Start(u8 Channel)
{
	ADMUX&=0b11100000;
	ADMUX|=Channel;
	SET_BIT(ADCSRA,6);	//start conversion
	while(!GET_BIT(ADCSRA,4)); //bit 4 polling
}

u16 ADC_Result(void)
{
	return ADC_Data;
}

u16 Analog_Value(u16 Digital_Value)
{
	u16 Analog;
	Analog=Digital_Value*(5000UL)/1024;
	return Analog;
}

void ADC_Start_Interrupt(u8 Channel)
{

	ADMUX&=0b11100000;
	ADMUX|=Channel;
	SET_BIT(ADCSRA,6);	//Start conversion
	GIE_voidEnable(); 	//Activate the global interrupt
	SET_BIT(ADCSRA,3);	//Activate interrupt mode in ADC
}
void set_call_back (void (*fn_ptr)(void))
{
	if(fn_ptr != NULL)
		{
		ptr = fn_ptr ;
		}
}
void __vector_16(void)__attribute__((signal,used));
void __vector_16(void)
{
	if(ptr != NULL)
	{
		ptr();
	}
}
#endif
