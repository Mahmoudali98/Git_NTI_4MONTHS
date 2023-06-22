/*
 * MTIMER_1_int.h
 *
 *  Created on: Jun 19, 2023
 *      Author: Saif Elden
 */

#ifndef MTIMER_1_MTIMER_1_INT_H_
#define MTIMER_1_MTIMER_1_INT_H_

void Timer1_voidInit(void);
void Timer1_voidSetCompChA(u16 Copy_u16Value);
void TIMER1_voidSetPreLoad(u8 u8_CopyPreLoad);
void TIMER1_u8SetCallBack (void(*Copy_pvCallBackFunc)(void));
/*u8 Timer1_u8TCNT0GetValue(void);*/
void Timer1_voidOCR0SetValue(u8 Copy_OCR0Val);

void Timer1_voidSetDutyCycle (u8 Copy_DutyCycleVal);
void Timer1_voidSetDutyCycleADC (u8 Copy_DutyCycleValADC);


#endif /* MTIMER_1_MTIMER_1_INT_H_ */
