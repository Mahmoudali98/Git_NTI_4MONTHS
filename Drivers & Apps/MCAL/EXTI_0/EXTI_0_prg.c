#if 0
/*
 * EXTI_0_prg.c
 *
 *  Created on: Jun 16, 2023
 *      Author: Saif Elden
 */

#include <avr/delay.h>
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include"ERROR_STATE.h"
#include"MDIO_int.h"
#include"EXTI_0_priv.h"
#include"EXTI_0_config.h"
#include"EXTI_0_int.h"


void EXTI_0_voidInit(void)
{

#if EXTI_SENSE_MODE == EXTI_LOW_LEVEL
	CLR_BIT (MCCUR_REG,0) ; CLR_BIT (MCCUR_REG,1);

#elif EXTI_SENSE_MODE == EXTI_ON_CHANGE
	SET_BIT (MCCUR_REG,0) ; CLR_BIT (MCCUR_REG,1);

#elif EXTI_SENSE_MODE == EXTI_FALLING_EDGE
	CLR_BIT (MCCUR_REG,0) ; SET_BIT (MCCUR_REG,1);

#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
	SET_BIT (MCCUR_REG,0) ; SET_BIT (MCCUR_REG,1);

#endif


	CLR_BIT(GICR,6);
	SET_BIT(GIFR,6);  // clear the flag

}

#endif
