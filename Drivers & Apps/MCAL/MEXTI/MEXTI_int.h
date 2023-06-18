/*
 * MEXTI_int.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Saif Elden
 */

#ifndef MEXTI_MEXTI_INT_H_
#define MEXTI_MEXTI_INT_H_


#define EXTI_LINE0		0		//6
#define EXTI_LINE1		2		//7
#define EXTI_LINE2		1		//5

#define EXTI_FALLING_EDGE	0
#define EXTI_RISING_EDGE	1
#define EXTI_LOW_LEVEL		2
#define EXTI_ON_CHANGE		3

#define NULL				0


void EXTI_voidInit(void);
void GIE_voidEnable(void);
void GIE_voidDisable(void);
void EXTI_voidSetSignalLatch (u8 Copy_u8SenseMode,u8 Copy_u8Line);
ErrorState_t MEXTI_voidDsiableInterrupt (u8 Copy_u8Line);
ErrorState_t MEXTI_voidEnableInterrupt (u8 Copy_u8Line);
void EXTI_voidClearFlag (u8 Copy_u8Line);
void EXTI_voidGetFlag (u8 Copy_u8Line);
void EXTI_voidSetCallBack (void (*Copy_pvoidCallBack) (void),u8 Copy_u8EXTILine);


#endif /* MEXTI_MEXTI_INT_H_ */
