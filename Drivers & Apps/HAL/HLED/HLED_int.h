/*
 * LED_int.h
 *
 *  Created on: May 29, 2023
 *      Author: Saif Elden
 */

#ifndef HLED_HLED_INT_H_
#define HLED_HLED_INT_H_
#include "STD_TYPES.h"
#include "ERROR_STATE.h"

#define HLED_RED_ID		1
#define HLED_BLUE_ID	2
#define HLED_GRN_ID		3
#define HLED_YEL_ID		4




ErrorState_t HLED_enInit(u8 copy_u8LedId); //set direction
ErrorState_t HLED_enSetON(u8 copy_u8LedId); //led on
ErrorState_t HLED_enSetOFF(u8 copy_u8LedId); //led off
ErrorState_t HLED_enToggle(u8 copy_u8LedId); // toggle led


#endif /* HLED_HLED_INT_H_ */
