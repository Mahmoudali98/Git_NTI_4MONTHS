/*
 * HBUZZ_prg.c
 *
 *  Created on: May 31, 2023
 *      Author: Saif Elden
 */


#include <avr/delay.h>
#include"STD_TYPES.h"
#include"ERROR_STATE.h"
#include"MDIO_int.h"
#include"HBUZZ_priv.h"
#include"HBUZZ_config.h"
#include"HBUZZ_int.h"

ErrorState_t HBUZZ_Init(void)
{
	ErrorState_t Local_State = SUCCESS;
	MDIO_voidsetPinDirection(HBUZZ_PIN, OUTPUT);
	return Local_State;
}

ErrorState_t HBUZZ_SetON(void)
{
	ErrorState_t Local_State = SUCCESS;
	MDIO_voidsetPinValue(HBUZZ_PIN, HIGH);
	return Local_State;
}
ErrorState_t HBUZZ_SetOFF(void)
{
	ErrorState_t Local_State = SUCCESS;
	MDIO_voidsetPinValue(HBUZZ_PIN, LOW);
	return Local_State;
}
ErrorState_t HBUZZ_Once(void)
{
	ErrorState_t Local_State = SUCCESS;
	MDIO_voidsetPinValue(HBUZZ_PIN, HIGH);
	_delay_ms(HBUZZ_PERIOD);
	MDIO_voidsetPinValue(HBUZZ_PIN, LOW);
	return Local_State;
}
