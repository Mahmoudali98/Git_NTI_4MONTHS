/*
 * MADC_int.h
 *
 *  Created on: Jun 17, 2023
 *      Author: Saif Elden
 */

#ifndef MADC_MADC_INT_H_
#define MADC_MADC_INT_H_


void ADC_voidInit(void);
void ADC_voidStart(void);
void ADC_voidSelectChannel(u8 Copy_u8Channel);
u8 ADC_u8GetChacnnelReading (void);
u16 Analog_Value(u16 Digital_Value);
u16 ADC_Result();

#if 0
void ADC_Init(void);
void ADC_Enable(void);
void ADC_Disable(void);
void ADC_Start(u8 Channel);
u16 ADC_Result(void);
u16 Analog_Value(u16 Digital_Value);
#endif
#endif /* MADC_MADC_INT_H_ */
