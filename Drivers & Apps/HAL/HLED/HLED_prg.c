/*
 * HLED_prg.c
 *
 *  Created on: May 29, 2023
 *      Author: Saif Elden
 */
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MDIO_int.h"

#include "../HLED/HLED_config.h"
#include "../HLED/HLED_int.h"
#include "../HLED/HLED_priv.h"


ErrorState_t HLED_enInit(u8 copy_u8LedId)
{
	ErrorState_t Local_State = SUCCESS;
	switch (copy_u8LedId)
	{
	case HLED_RED_ID :
		MDIO_voidsetPinDirection(HLED_RED_LED_PIN, OUTPUT);
		break;
	case HLED_BLUE_ID	:
		MDIO_voidsetPinDirection(HLED_BLUE_LED_PIN, OUTPUT);
		break;
	case HLED_GRN_ID:
		MDIO_voidsetPinDirection(HLED_GRN_LED_PIN, OUTPUT);
		break;
	case HLED_YEL_ID:
			MDIO_voidsetPinDirection(HLED_YEL_LED_PIN, OUTPUT);
			break;
	default :
		Local_State = OUT_OF_RANGE_ERR;
		break;
	}
	return Local_State;
}
ErrorState_t HLED_enSetON(u8 copy_u8LedId)
{
	ErrorState_t Local_State = SUCCESS;
		switch (copy_u8LedId)
		{
		case HLED_RED_ID :
#if(HLED_RED_LED_DIR == HLED_LED_FORWARD)
			MDIO_voidsetPinValue(HLED_RED_LED_PIN, HIGH);
#elif(HLED_RED_LED_DIR == HLED_LED_REVERSE)
			MDIO_voidsetPinValue(HLED_RED_LED_PIN, LOW);
#else
#error ("Wrong led Red Direction")
#endif
			break;
		case HLED_BLUE_ID:
#if(HLED_BLUE_LED_DIR == HLED_LED_FORWARD)
			MDIO_voidsetPinValue(HLED_BLUE_LED_PIN, HIGH);
#elif(HLED_BLUE_LED_DIR == HLED_LED_REVERSE)
			MDIO_voidsetPinValue(HLED_BLUE_LED_PIN, LOW);
#else
#error ("Wrong led Blue Direction")
#endif

			break;
		case HLED_GRN_ID:
#if(HLED_GRN_LED_DIR == HLED_LED_FORWARD)
			MDIO_voidsetPinValue(HLED_GRN_LED_PIN, HIGH);
#elif(HLED_GRN_LED_DIR == HLED_LED_REVERSE)
			MDIO_voidsetPinValue(HLED_GRN_LED_PIN, LOW);
#else
#error ("Wrong led Green Direction")
#endif

			break;

		case HLED_YEL_ID:
#if(HLED_YEL_LED_DIR == HLED_LED_FORWARD)
			MDIO_voidsetPinValue(HLED_YEL_LED_PIN, HIGH);
#elif(HLED_YEL_LED_DIR == HLED_LED_REVERSE)
			MDIO_voidsetPinValue(HLED_YEL_LED_PIN, LOW);
#else
#error ("Wrong led Yellow Direction")
#endif

			break;

		default :
			Local_State = OUT_OF_RANGE_ERR;
			break;
		}
		return Local_State;

}
ErrorState_t HLED_enSetOFF(u8 copy_u8LedId)
{
	ErrorState_t Local_State = SUCCESS;
		switch (copy_u8LedId)
		{
		case HLED_RED_ID :
#if(HLED_RED_LED_DIR == HLED_LED_FORWARD)
			MDIO_voidsetPinValue(HLED_RED_LED_PIN, LOW);
#elif(HLED_RED_LED_DIR == HLED_LED_REVERSE)
			MDIO_voidsetPinValue(HLED_RED_LED_PIN, HIGH);
#else
#error ("Wrong led Red Direction")
#endif
			break;
		case HLED_BLUE_ID:
#if(HLED_BLUE_LED_DIR == HLED_LED_FORWARD)
			MDIO_voidsetPinValue(HLED_BLUE_LED_PIN, LOW);
#elif(HLED_BLUE_LED_DIR == HLED_LED_REVERSE)
			MDIO_voidsetPinValue(HLED_BLUE_LED_PIN, HIGH);
#else
#error ("Wrong led Blue Direction")
#endif

			break;
		case HLED_GRN_ID:
#if(HLED_GRN_LED_DIR == HLED_LED_FORWARD)
			MDIO_voidsetPinValue(HLED_GRN_LED_PIN, LOW);
#elif(HLED_GRN_LED_DIR == HLED_LED_REVERSE)
			MDIO_voidsetPinValue(HLED_GRN_LED_PIN, HIGH);
#else
#error ("Wrong led Green Direction")
#endif

			break;

		case HLED_YEL_ID:
#if(HLED_YEL_LED_DIR == HLED_LED_FORWARD)
			MDIO_voidsetPinValue(HLED_YEL_LED_PIN, LOW);
#elif(HLED_YEL_LED_DIR == HLED_LED_REVERSE)
			MDIO_voidsetPinValue(HLED_YEL_LED_PIN, HIGH);
#else
#error ("Wrong led Yellow Direction")
#endif

			break;

		default :
			Local_State = OUT_OF_RANGE_ERR;
			break;
		}
		return Local_State;

}
ErrorState_t HLED_enToggle(u8 copy_u8LedId)
{
	ErrorState_t Local_State = SUCCESS;
 switch(copy_u8LedId)
 {
  case HLED_RED_ID :
	  MDIO_voidTogglePinValue(HLED_RED_LED_PIN);
	 break;
  case HLED_BLUE_ID :
	  MDIO_voidTogglePinValue(HLED_BLUE_LED_PIN);
 	 break;
  case HLED_GRN_ID :
	  MDIO_voidTogglePinValue(HLED_GRN_LED_PIN);
 	 break;
  case HLED_YEL_ID :
  	  MDIO_voidTogglePinValue(HLED_YEL_LED_PIN);
   	 break;
  default :
 			Local_State = OUT_OF_RANGE_ERR;
 			break;
 }
 		return Local_State;

}
