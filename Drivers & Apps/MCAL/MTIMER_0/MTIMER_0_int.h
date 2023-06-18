/*
 * MTIMER_0_int.h
 *
 *  Created on: Jun 18, 2023
 *      Author: Saif Elden
 */

#ifndef MTIMER_0_MTIMER_0_INT_H_
#define MTIMER_0_MTIMER_0_INT_H_


#define TCNT0_REG		*((volatile u8*)0x52) //read data in timer/counter mode



void TIMER0_voidInit(void);
void TIMER0_voidPreLoad(u8_CopyPreLoad);
void TIMER0_u8SetCallBack (void(*Copy_pvCallBackFunc)(void));



#endif /* MTIMER_0_MTIMER_0_INT_H_ */
