/*
 * HPB_prg.c
 *
 *  Created on: May 30, 2023
 *      Author: Saif Elden
 */

#include <avr/delay.h>
#include"STD_TYPES.h"
#include"ERROR_STATE.h"
#include"MDIO_int.h"
#include"HPB_priv.h"
#include"HPB_config.h"
#include"HPB_int.h"

ErrorState_t HPB_enInit(const PB_t * ptrPB)

{
	ErrorState_t Local_enState= SUCCESS;
	if(ptrPB->PushButtonID>=1 && ptrPB->PushButtonID<=4)
	{
		MDIO_voidsetPinDirection(ptrPB->PushButtonPin, INPUT);

		#if(KIT_TYPE == SIM_KIT)
			MDIO_voidsetPinValue(ptrPB->PushButtonPin, HIGH);
		#endif
	}
	else
	{
		Local_enState = OUT_OF_RANGE_ERR;
	}

	return Local_enState;
}

ErrorState_t HPB_enRead(const PB_t * ptrPB,PBState_t  * ptrPBState    )
{
	ErrorState_t  Local_enState = SUCCESS;
	u8 Local_u8PinRead = PB_RELEASED;
	// first read
	MDIO_voidgetPinValue(ptrPB->PushButtonPin, &Local_u8PinRead); // 0
	if(Local_u8PinRead == PB_PRESSED)
	{
		// for debouncing
		_delay_ms(20);
		// Second Read
		MDIO_voidgetPinValue(ptrPB->PushButtonPin, &Local_u8PinRead);//1
		if(Local_u8PinRead == PB_PRESSED)
		{
			// for Single Press
			while(Local_u8PinRead == PB_PRESSED)
			{
				MDIO_voidgetPinValue(ptrPB->PushButtonPin, &Local_u8PinRead);

			}
			*ptrPBState = PB_PRESSED;
		}// if second read
		else
		{
			*ptrPBState = PB_RELEASED;
		}
	}// if first read
	else
	{
		*ptrPBState = PB_RELEASED;
	}
	return Local_enState;
}


u8 HPB_enRead2(u8 copy_PinID)
{

	u8 Value = PB_RELEASED;
	// first read
	MDIO_voidgetPinValue(copy_PinID, &Value); // 0
	if(Value == PB_PRESSED)
	{
		// for debouncing
		_delay_ms(20);
		// Second Read
		MDIO_voidgetPinValue(copy_PinID, &Value);//1
		if(Value == PB_PRESSED)
		{
			// for Single Press
			while(Value == PB_PRESSED)
			{
				MDIO_voidgetPinValue(copy_PinID, &Value);
			}
			Value = PB_PRESSED;
		}// if second read
		else
		{
			Value = PB_RELEASED;
		}
	}// if first read
	else
	{
		Value = PB_RELEASED;
	}
	return Value;
}
