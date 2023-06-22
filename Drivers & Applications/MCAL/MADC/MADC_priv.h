/*
 * MADC_priv.h
 *
 *  Created on: Jun 17, 2023
 *      Author: Saif Elden
 */

#ifndef MADC_MADC_PRIV_H_
#define MADC_MADC_PRIV_H_


#define ADMUX_REG 			*((volatile u8*)0x27)		//ADC multiplexer selection register
#define ADMUX_REFS1			7							//Reference selection bit 1
#define ADMUX_REFS0			6							//Reference selection bit 0
#define ADMUX_ADLAR			5							//ADC left adjust result




#define ADCSRA_REG 			*((volatile u8*)0x26)	//ADC control and status register A
#define ADCSRA_ADEN			7						//ADC Enable
#define ADCSRA_ADSC			6						//Start conversion
#define ADCSRA_ADATE		5						//Auto trigger enable
#define ADCSRA_ADIF			4						// interrupt flag
#define ADCSRA_ADIE			3						// interrupt enable
#define ADCSRA_ADPS2		2						// ؛prescaler bit 2
#define ADCSRA_ADPS1		1						// prescaler bit 1
#define ADCSRA_ADPS0	 	0						// prescaler bit 2


#define ADCH_REG 			*((volatile u8*)0x25)	//ADC high register
#define ADCL_REG 			*((volatile u16*)0x24)	//ADC low register


#if 0
#define ADMUX		*((volatile u8*) (0x27))
#define ADCSRA		*((volatile u8*) (0x26))
#define ADCH		*((volatile u8*) (0x25))
#define ADCL		*((volatile u8*) (0x24))
#define ADC_Data	*((volatile u16*) (0x24))
#define SFIOR		*((volatile u8*) (0x50))

void ADC_Init();
void ADC_Enable(void);
void ADC_Disable(void);

void ADC_Start(u8 Channel);
u16 ADC_Result();
u16 Analog_Value(u16 Analog_Value);

#endif
#endif /* MADC_MADC_PRIV_H_ */
