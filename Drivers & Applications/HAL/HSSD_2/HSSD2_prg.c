/*
 * HSSD2_prg.c
 *
 *  Created on: Jun 10, 2023
 *      Author: Saif Elden
 */

#include <avr/delay.h>
#include"STD_TYPES.h"
#include"ERROR_STATE.h"
#include"MDIO_int.h"
#include"HSSD2_priv.h"
#include"HSSD2_config.h"
#include"HSSD2_int.h"


ErrorState_t HSSD2_enInit(void)
{
	MDIO_voidsetPinDirection(HSSD2_A_PIN, OUTPUT);
	MDIO_voidsetPinDirection(HSSD2_B_PIN, OUTPUT);
	MDIO_voidsetPinDirection(HSSD2_C_PIN, OUTPUT);
	MDIO_voidsetPinDirection(HSSD2_D_PIN, OUTPUT);


	MDIO_voidsetPinDirection(HSSD_COMM1_PIN, OUTPUT);
	MDIO_voidsetPinDirection(HSSD_COMM2_PIN, OUTPUT);
	MDIO_voidsetPinDirection(HSSD_COMM3_PIN, INPUT);
	MDIO_voidsetPinDirection(HSSD_COMM4_PIN, INPUT);


	MDIO_voidsetPinValue(HSSD_COMM1_PIN, HIGH);		//OFF COMMON ANODE
	MDIO_voidsetPinValue(HSSD_COMM2_PIN, HIGH);		//OFF COMMON ANODE

/*
	MDIO_voidsetPinValue(HSSD_COMM3_PIN, HIGH);		//OFF COMMON ANODE
	MDIO_voidsetPinValue(HSSD_COMM4_PIN, HIGH);		//OFF COMMON ANODE
*/

	return SUCCESS;
}


ErrorState_t HSSD2_enDisplayIntegerNumber(u8 copy_u8Number) //00-99
{
	ErrorState_t Local_enState = SUCCESS;
	if(copy_u8Number > 99)
	{
		Local_enState = OUT_OF_RANGE_ERR;
	}
	else
	{ // <=99
		u8 Local_u8Uints = copy_u8Number % 10;
		u8 Local_u8Tens  = copy_u8Number / 10;
		u16 i;

		for(i=0;i<HSSD2_DISPLAY_TIME;i++)
		{
			switch(Local_u8Uints)
					{
					case 0 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_B_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_C_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 1 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_B_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_C_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 2 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_B_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_C_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 3 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_B_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_C_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 4 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_B_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_C_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 5 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_B_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_C_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 6 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_B_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_C_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 7 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_B_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_C_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 8 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_B_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_C_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_D_PIN, HIGH);

						break;
					case 9 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_B_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_C_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_D_PIN, HIGH);

						break;
					default : break;
					}//units switch
					//ENABLE DIGIT 1
					MDIO_voidsetPinValue(HSSD_COMM1_PIN, LOW);
					//DISABLE DIGIT 2
					MDIO_voidsetPinValue(HSSD_COMM2_PIN, HIGH);
					_delay_ms(1);
					//DISABLE DIGIT 1
					MDIO_voidsetPinValue(HSSD_COMM1_PIN, HIGH);


					switch(Local_u8Tens)
							{
					case 0 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_B_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_C_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 1 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_B_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_C_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 2 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_B_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_C_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 3 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_B_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_C_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 4 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_B_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_C_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 5 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_B_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_C_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 6 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_B_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_C_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 7 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_B_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_C_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_D_PIN, LOW);

						break;
					case 8 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_B_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_C_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_D_PIN, HIGH);

						break;
					case 9 :
						MDIO_voidsetPinValue(HSSD2_A_PIN, HIGH);
						MDIO_voidsetPinValue(HSSD2_B_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_C_PIN, LOW);
						MDIO_voidsetPinValue(HSSD2_D_PIN, HIGH);

						break;
					default : break;
							}
					//DISABLE DIGIT 1
					MDIO_voidsetPinValue(HSSD_COMM1_PIN, HIGH);
					//ENABLE DIGIT 2
					MDIO_voidsetPinValue(HSSD_COMM2_PIN, LOW);
					_delay_ms(1);
					MDIO_voidsetPinValue(HSSD_COMM2_PIN, HIGH);
		} //tens switch

	} //else
	return Local_enState;
}
