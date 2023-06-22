/*
 * MEXTI_prg.c
 *
 *  Created on: Jun 15, 2023
 *      Author: Saif Elden
 */

#include <avr/delay.h>
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include"ERROR_STATE.h"
#include"MDIO_int.h"
#include"MEXTI_priv.h"
#include"MEXTI_config.h"
#include"MEXTI_int.h"

/*
 * Global Pointer to Function => Carry the Adress of ISR function in the main
 * Hint: I Made An Array of Pointers to carry EXTI 0,1,2 according to its index
 */

void static (*EXTI_CallBack[3]) (void) = { NULL };


/*
 *Intialization of the External Interrupt
 **/

/*
 * Pre-Build Configuration
 **/

void EXTI_voidInit(void)
{
#ifdef EXTI_LINE
	/*	Check for EXT1 line	*/
	#if EXTI_LINE ==EXTI_LINE1
	/* 	Check if Sense Mode		*/
		#if EXTI_SENSE_MODE == EXTI_LOW_LEVEL
			CLR_BIT (MCCUR_REG,2) ; CLR_BIT (MCCUR_REG,3);
		#elif EXTI_SENSE_MODE == EXTI_ON_CHANGE
			SET_BIT (MCCUR_REG,2) ; CLR_BIT (MCCUR_REG,3);
		#elif EXTI_SENSE_MODE == EXTI_FALLING_EDGE
			CLR_BIT (MCCUR_REG,2) ; SET_BIT (MCCUR_REG,3);
		#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
			SET_BIT (MCCUR_REG,2) ; SET_BIT (MCCUR_REG,3);

		#endif


	#elif EXTI_LINE ==	EXTI_LINE0
		#if EXTI_SENSE_MODE == EXTI_LOW_LEVEL
			CLR_BIT (MCCUR_REG,0) ; CLR_BIT (MCCUR_REG,1);
		#elif EXTI_SENSE_MODE == EXTI_ON_CHANGE
			SET_BIT (MCCUR_REG,0) ; CLR_BIT (MCCUR_REG,1);
		#elif EXTI_SENSE_MODE == EXTI_FALLING_EDGE
			CLR_BIT (MCCUR_REG,0) ; SET_BIT (MCCUR_REG,1);
		#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
			SET_BIT (MCCUR_REG,0) ; SET_BIT (MCCUR_REG,1);

		#endif

	#elif EXTI_LINE == EXTI_LINE2

		#if EXTI_SENSE_MODE == EXTI_FALLING_EDGE
			CLR_BIT (MCUCSR_REG,6) ;
		#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
			SET_BIT (MCUCSR_REG,6) ;
		#endif
	#endif
#endif
}
void GIE_voidEnable(void)
{
	SET_BIT(SREG_REG,7);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG_REG,7);
}


/*
 * Post-Build Configuration
 **/


void EXTI_voidSetSignalLatch (u8 Copy_u8SenseMode,u8 Copy_u8Line)
{
	if((Copy_u8Line>=EXTI_LINE0) && (Copy_u8Line<=EXTI_LINE1))
	{
		Copy_u8Line = (6 - Copy_u8Line)* -2;

	switch (Copy_u8SenseMode)
	{
	case EXTI_LOW_LEVEL : CLR_BIT(MCCUR_REG,Copy_u8Line); CLR_BIT(MCCUR_REG,Copy_u8Line + 1); break;
	case EXTI_ON_CHANGE : SET_BIT(MCCUR_REG,Copy_u8Line); CLR_BIT(MCCUR_REG,Copy_u8Line + 1); break;
	case EXTI_FALLING_EDGE : CLR_BIT(MCCUR_REG,Copy_u8Line); SET_BIT(MCCUR_REG,Copy_u8Line + 1); break;
	case EXTI_RISING_EDGE : SET_BIT(MCCUR_REG,Copy_u8Line); SET_BIT(MCCUR_REG,Copy_u8Line + 1); break;
	}
	}
	else
	{
	switch (Copy_u8SenseMode)
	{
	case EXTI_FALLING_EDGE : CLR_BIT(MCUCSR_REG,6); break;
	case EXTI_RISING_EDGE  : SET_BIT(MCUCSR_REG,6); break;
	}
	}


}


ErrorState_t MEXTI_voidDsiableInterrupt (u8 Copy_u8Line)
{
	ErrorState_t Local_State = SUCCESS;
	switch(Copy_u8Line)
	{
	case EXTI_LINE0:
		CLR_BIT( GCIR_REG , (Copy_u8Line+6));		//bit 6
	break;
	case EXTI_LINE1:
		CLR_BIT( GCIR_REG , (Copy_u8Line+5));		//bit 7
	break;
	case EXTI_LINE2:
		CLR_BIT( GCIR_REG , (Copy_u8Line+4));		//bit 5
	break;
	default:
		Local_State = OUT_OF_RANGE_ERR;
		break;

	}

	return Local_State;
}

ErrorState_t MEXTI_voidEnableInterrupt (u8 Copy_u8Line)
{
	ErrorState_t Local_State = SUCCESS;
	switch(Copy_u8Line)
	{
	case EXTI_LINE0:
		SET_BIT( GCIR_REG , (Copy_u8Line+6));		//bit 6
	break;
	case EXTI_LINE1:
		SET_BIT( GCIR_REG , (Copy_u8Line+5));		//bit 7
	break;
	case EXTI_LINE2:
		SET_BIT( GCIR_REG , (Copy_u8Line+4));		//bit 5
	break;
	default:
		Local_State = OUT_OF_RANGE_ERR;
		break;
	}

	return Local_State;
}

void EXTI_voidClearFlag (u8 Copy_u8Line)
{
	SET_BIT(GIFR_REG,Copy_u8Line);
}

void EXTI_voidGetFlag (u8 Copy_u8Line)
{
	GET_BIT(GIFR_REG,Copy_u8Line);
}


/*
 * Set Call Back Function
 **/

void EXTI_voidSetCallBack (void (*Copy_pvoidCallBack) (void),u8 Copy_u8EXTILine)
		{
			if(Copy_pvoidCallBack!= NULL)
			{
				EXTI_CallBack[Copy_u8EXTILine]=Copy_pvoidCallBack;
			}
		}

/*
 * ISR --> Implementation
 *
 **/


void __vector_1(void)__attribute__((signal,used)); //attribute so the linker doesn't make optimization on the function
void __vector_1(void)
{
	if(EXTI_CallBack[0] != NULL)
	{
		EXTI_CallBack[0] ();  // call the global pointer to function
		EXTI_voidClearFlag(EXTI_LINE0+6);
	}
}

void __vector_2(void)__attribute__((signal,used));
void __vector_2(void)
{
	if(EXTI_CallBack[1] != NULL)
	{
		EXTI_CallBack[1] ();  // call the global pointer to function
		EXTI_voidClearFlag(EXTI_LINE1+5);
	}
}

void __vector_3(void)__attribute__((signal,used));
void __vector_3(void)
{
	if(EXTI_CallBack[2] != NULL)
	{
		EXTI_CallBack[2] ();  // call the global pointer to function
		EXTI_voidClearFlag(EXTI_LINE2+4);
	}
}
