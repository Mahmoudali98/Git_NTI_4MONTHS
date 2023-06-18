/*
 * HKEYPAD_prg.c
 *
 *  Created on: May 31, 2023
 *      Author: Saif Elden
 */

#include <avr/delay.h>
#include"STD_TYPES.h"
#include"ERROR_STATE.h"
#include"MDIO_int.h"
#include"HKEYPAD_priv.h"
#include"HKEYPAD_config.h"
#include"HKEYPAD_int.h"
#include "LCD_interface.h"
#include "HLED_int.h"
#include "HBUZZ_int.h"

/*
 *
 * Main Functions For Keypad
 *
 * */


ErrorState_t HKEYPAD_enInit(void)
{
	// configure rows to be o/p
	MDIO_voidsetPinDirection(HKEYPAD_R0_PIN, OUTPUT);
	MDIO_voidsetPinDirection(HKEYPAD_R1_PIN, OUTPUT);
	MDIO_voidsetPinDirection(HKEYPAD_R2_PIN, OUTPUT);
	MDIO_voidsetPinDirection(HKEYPAD_R3_PIN, OUTPUT);

	// configure cols to be i/p
	MDIO_voidsetPinDirection(HKEYPAD_C0_PIN, INPUT);
	MDIO_voidsetPinDirection(HKEYPAD_C1_PIN, INPUT);
	MDIO_voidsetPinDirection(HKEYPAD_C2_PIN, INPUT);
	MDIO_voidsetPinDirection(HKEYPAD_C3_PIN, INPUT);

	// we can activate pull up resistors for the input pins by setting their port registers with high


	//intialize o/p (Rows -> High because zero is activing the row )
	MDIO_voidsetPinValue(HKEYPAD_R0_PIN, HIGH);
	MDIO_voidsetPinValue(HKEYPAD_R1_PIN, HIGH);
	MDIO_voidsetPinValue(HKEYPAD_R2_PIN, HIGH);
	MDIO_voidsetPinValue(HKEYPAD_R3_PIN, HIGH);

	// Activate internal pull up with cols
#if (KIT_TYPE == SIM_TYPE)
	MDIO_voidsetPinValue(HKEYPAD_C0_PIN, HIGH);
	MDIO_voidsetPinValue(HKEYPAD_C1_PIN, HIGH);
	MDIO_voidsetPinValue(HKEYPAD_C2_PIN, HIGH);
	MDIO_voidsetPinValue(HKEYPAD_C3_PIN, HIGH);
#endif
	return SUCCESS;
}
ErrorState_t HKEYPAD_enGetPressedKey(u8 * ptrKey)
{
	u8 Local_u8PressedKey= HKEYPAD_NO_PRESSED_KEY ;
	u8 Local_u8PinRead;
	u8 row_index;
	u8 col_index;
	u8 flag = 0;
	u8 Local_u8ArrKeys[4][4]= HKEYPAD_KEYS;
	u8 rowArr[]={HKEYPAD_R0_PIN,HKEYPAD_R1_PIN,HKEYPAD_R2_PIN,HKEYPAD_R3_PIN};
	u8 colArr[]={HKEYPAD_C0_PIN,HKEYPAD_C1_PIN,HKEYPAD_C2_PIN,HKEYPAD_C3_PIN};
	for(row_index= 0 ; row_index<=3 && flag ==0 ; row_index++ )
	{
		// output 0 (ground) on row (Activate row)
		MDIO_voidsetPinValue(rowArr[row_index],LOW);
		for(col_index= 0 ; col_index<=3 ; col_index++ )
		{
			//read Col
			MDIO_voidgetPinValue(colArr[col_index], &Local_u8PinRead);

			if(Local_u8PinRead == HKEYPAD_KEY_PRESSED)
				{
					// for debouncing
					_delay_ms(20);
					// Second Read
					MDIO_voidgetPinValue(colArr[col_index], &Local_u8PinRead); //1
					if(Local_u8PinRead == HKEYPAD_KEY_PRESSED)
					{
						// for Single Press
						while(Local_u8PinRead == HKEYPAD_KEY_PRESSED)
						{
							MDIO_voidgetPinValue(colArr[col_index], &Local_u8PinRead);
						}
						Local_u8PressedKey = Local_u8ArrKeys[row_index][col_index];
						flag = 1 ;
					}// if second read
					else
					{

					}
				}// if first read
				else
				{

				}
		} //INNER FOR COLS

		// output 1 on row (Deactivate row)
		MDIO_voidsetPinValue(rowArr[row_index],HIGH);

	} //OUTER FOR ROWS
	*ptrKey= Local_u8PressedKey;
	return SUCCESS;
}

u8 HKEYPAD_enGetPressedKey2(void)
{
	u8 Local_u8PressedKey= HKEYPAD_NO_PRESSED_KEY ;
	u8 Local_u8PinRead;
	u8 row_index;
	u8 col_index;
	u8 flag = 0;
	u8 Local_u8ArrKeys[4][4]= HKEYPAD_KEYS;
	u8 rowArr[]={HKEYPAD_R0_PIN,HKEYPAD_R1_PIN,HKEYPAD_R2_PIN,HKEYPAD_R3_PIN};
	u8 colArr[]={HKEYPAD_C0_PIN,HKEYPAD_C1_PIN,HKEYPAD_C2_PIN,HKEYPAD_C3_PIN};
	for(row_index= 0 ; row_index<=3 && flag ==0 ; row_index++ )
	{
		// output 0 (ground) on row (Activate row)
		MDIO_voidsetPinValue(rowArr[row_index],LOW);
		for(col_index= 0 ; col_index<=3 ; col_index++ )
		{
			//read Col
			MDIO_voidgetPinValue(colArr[col_index], &Local_u8PinRead);

			if(Local_u8PinRead == HKEYPAD_KEY_PRESSED)
				{
					// for debouncing
					_delay_ms(20);
					// Second Read
					MDIO_voidgetPinValue(colArr[col_index], &Local_u8PinRead); //1
					if(Local_u8PinRead == HKEYPAD_KEY_PRESSED)
					{
						// for Single Press
						while(Local_u8PinRead == HKEYPAD_KEY_PRESSED)
						{
							MDIO_voidgetPinValue(colArr[col_index], &Local_u8PinRead);
						}
						Local_u8PressedKey = Local_u8ArrKeys[row_index][col_index];
						flag = 1 ;
					}// if second read
					else
					{

					}
				}// if first read
				else
				{

				}
		} //INNER FOR COLS

		// output 1 on row (Deactivate row)
		MDIO_voidsetPinValue(rowArr[row_index],HIGH);

	} //OUTER FOR ROWS

	return Local_u8PressedKey;

}


/*
 *
 * Applications Functions
 *
 * */

void HKEYPAD_voidcheckPassword(void)
{
#define PASSWORD 1234
	{
		u8 tries = 0;
		u8 Local_u8Entry[11] = "Enter Pass" ;
		u8 Index = 0;
		u8 Local_u8Key = 0xFF ;
		u16 PassUser = 0;
		u8 hello[6]="hello";
		u8 wrong[7]="Wrong!";



		MDIO_voidsetPinDirection(PC6, OUTPUT);
		while(tries<3 && PassUser != PASSWORD)
		{
			LCD_voidWriteString(Local_u8Entry);
			LCD_voidGoToXY(1,0);

			for(Index =0 ;Index<4;Index++)
			{
				do
				{
					Local_u8Key = HKEYPAD_enGetPressedKey2() ;
				} while (Local_u8Key == 0xFF);
				LCD_voidWriteData('*');
				PassUser = (PassUser*10)+Local_u8Key ;
			}
			tries++ ;
			LCD_voidWriteCommand(0x01);
		}

		if(PassUser == PASSWORD)
		{
			LCD_voidWriteCommand(0x01);
			LCD_voidGoToXY(0,5);
			LCD_voidWriteString(hello);
		}
		else if (tries>=3)
		{
			LCD_voidWriteCommand(0x01);
			LCD_voidGoToXY(0,4);
			LCD_voidWriteString(wrong);
			MDIO_voidsetPinValue(PC6, HIGH);
		}

	}
}

void HKEYPAD_voidcheckPassword2(void)
{
//HKEYPAD_enInit();
//HLED_enInit(HLED_BLUE_ID);

u8 password[4]={'1','2','3','4'};
u8 check [4]={0};
u8 i,j;
u8 counter=0;

for(i=0;i<3;i++)  //number of password trials
	{
		for(j=0;j<4;j++)		//filling the checking array
			{

				if (check[j] != HKEYPAD_NO_PRESSED_KEY)
						{
							LCD_voidWriteCommand(0xc0); //setting DDRAM Postion
							check[j]= HKEYPAD_enGetPressedKey(check[j]);
							HKEYPAD_enGetPressedKey(check[j]);
							LCD_voidWriteData('*');
						}
			}
				if(password[0]==check[0] && password[1]==check[1] && password[2]==check[2] && password[3]==check[3])
				{
					HLED_enSetON(HLED_BLUE_ID);
					break;
				}
				else
				{
					counter++;
				}
	}
	if (counter==3)
		{
			HBUZZ_Once();
		}
		counter =	0 ;
}

