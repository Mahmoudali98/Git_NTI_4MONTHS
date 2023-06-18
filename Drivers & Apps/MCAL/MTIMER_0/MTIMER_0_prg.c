/*
 * MTIMER_0_prg.c
 *
 *  Created on: Jun 18, 2023
 *      Author: Saif Elden
 */

#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include"MTIMER_0_int.h"
#include"MTIMER_0_priv.h"
#include"MTIMER_0_config.h"
#include"MTIMER_0_int.h"

static void (*TIMER0_pvCallBackFunc)(void)=NULL;


void TIMER0_voidInit(void)
{
	/*Normal Mode*/
#ifdef SELECT_MODE
	#if SELECT_MODE == NORMAL_MODE
	CLR_BIT(TCCR0_REG,TCCR0_WGM00);
	CLR_BIT(TCCR0_REG,TCCR0_WGM01);
	/*Normal mode interrupt enable*/
	SET_BIT(TIMSK_REG,TIMSK_TOV0);
	/*CTC Mode*/
	#elif SELECT_MODE == CTC_MODE
	CLR_BIT(TCCR0_REG,TCCR0_WGM00);
	SET_BIT(TCCR0_REG,TCCR0_WGM01);
	/*Normal mode interrupt enable*/
	SET_BIT(TIMSK_REG,TIMSK_OCIE0);
	/*PWM , PHASE CORRECT*/
	#elif SELECT_MODE == PWM_MODE
	SET_BIT(TCCR0_REG,TCCR0_WGM00);
	CLR_BIT(TCCR0_REG,TCCR0_WGM01);
#endif

/*pre-scaler 1024 */
#if PRE_SCALE_1024
	SET_BIT(TCCR0_REG,TCCR0_CS00);
	CLR_BIT(TCCR0_REG,TCCR0_CS01);
	SET_BIT(TCCR0_REG,TCCR0_CS02);
/*pre-scaler 256 */
#elif PRE_SCALE_256
	CLR_BIT(TCCR0_REG,TCCR0_CS00);
	CLR_BIT(TCCR0_REG,TCCR0_CS01);
	SET_BIT(TCCR0_REG,TCCR0_CS02);
/*pre-scaler 64 */
#elif PRE_SCALE_64
	SET_BIT(TCCR0_REG,TCCR0_CS00);
	SET_BIT(TCCR0_REG,TCCR0_CS01);
	CLR_BIT(TCCR0_REG,TCCR0_CS02);
/*pre-scaler 8 */
#elif PRE_SCALE_8
	CLR_BIT(TCCR0_REG,TCCR0_CS00);
	SET_BIT(TCCR0_REG,TCCR0_CS01);
	CLR_BIT(TCCR0_REG,TCCR0_CS02);
/*no pre scale */
#elif NO_PRE_SCALE
	SET_BIT(TCCR0_REG,TCCR0_CS00);
	CLR_BIT(TCCR0_REG,TCCR0_CS01);
	CLR_BIT(TCCR0_REG,TCCR0_CS02);
#endif


#endif
}

void TIMER0_voidPreLoad(u8_CopyPreLoad)
{
	/*Pre-load*/
	TCNT0_REG = u8_CopyPreLoad; //247 for 1024 pre scaler
}
void TIMER0_u8SetCallBack (void(*Copy_pvCallBackFunc)(void))
{
	if(Copy_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc= Copy_pvCallBackFunc;
	}
}

void __vector_11(void)__attribute__((signal,used));
void __vector_11(void)
{
	if(TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
