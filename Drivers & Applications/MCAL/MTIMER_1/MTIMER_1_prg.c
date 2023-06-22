/*
 * MTIMER_1_prg.c
 *
 *  Created on: Jun 19, 2023
 *      Author: Saif Elden
 */




#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include"MTIMER_1_int.h"
#include"MTIMER_1_priv.h"
#include"MTIMER_1_config.h"
#include"MTIMER_1_int.h"

void Timer1_voidInit(void)
{
	/*Set on top Clear on compare*/
	SET_BIT(TCCR1A_REG,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A_REG,TCCR1A_COM1A0);

	/*Mode 14 in waveform generation mode*/
	//Fast PWM
	CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);
	SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
	SET_BIT(TCCR1B_REG,TCCR1B_WGM12);
	SET_BIT(TCCR1B_REG,TCCR1B_WGM13);

	/*Set ICR1 to required top value of 20000*/
	ICR1_REG=20000;

	/*Set prescaler to divide by 8*/
	CLR_BIT(TCCR1B_REG,TCCR1B_CS10);
	SET_BIT(TCCR1B_REG,TCCR1B_CS11);
	CLR_BIT(TCCR1B_REG,TCCR1B_CS12);

	/* Initial Value for Timer1 */
		TCNT1_REG = 0;


}

void Timer1_voidSetCompChA(u16 Copy_u16Value)
{
	OCR1A_REG=Copy_u16Value;
}
#if 0
void TIMER1_voidInit(void)
{
	/*Fast PWM Mode	with ICR1 top */
	CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);
	SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
}
void TIMER1_voidSetPreLoad(u8 u8_CopyPreLoad)
{

}
void TIMER1_u8SetCallBack (void(*Copy_pvCallBackFunc)(void))
{

}
/*u8 Timer1_u8TCNT0GetValue(void);*/
void Timer1_voidOCR0SetValue(u8 Copy_OCR0Val)
{

}

void Timer1_voidSetDutyCycle (u8 Copy_DutyCycleVal)
{

}
void Timer1_voidSetDutyCycleADC (u8 Copy_DutyCycleValADC)
{

}
#endif
