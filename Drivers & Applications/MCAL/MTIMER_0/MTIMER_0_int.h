/*
 * MTIMER_0_int.h
 *
 *  Created on: Jun 18, 2023
 *      Author: Saif Elden
 */

#ifndef MTIMER_0_MTIMER_0_INT_H_
#define MTIMER_0_MTIMER_0_INT_H_





void TIMER0_voidInit(void);
void TIMER0_voidSetPreLoad(u8 u8_CopyPreLoad);
void TIMER0_u8SetCallBack (void(*Copy_pvCallBackFunc)(void));
/*u8 Timer0_u8TCNT0GetValue(void);*/
void Timer0_voidOCR0SetValue(u8 Copy_OCR0Val);

void Timer0_voidSetDutyCycle (u8 Copy_DutyCycleVal);
void Timer0_voidSetDutyCycleADC (u8 Copy_DutyCycleValADC);
#endif /* MTIMER_0_MTIMER_0_INT_H_ */
