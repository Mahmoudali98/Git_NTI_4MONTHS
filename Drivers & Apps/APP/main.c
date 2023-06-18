/*
 * main.c
 *
 *  Created on: Jun 10, 2023
 *      Author: Saif Elden
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#include "HKEYPAD_int.h"
#include "HLED_int.h"
#include "HBUZZ_int.h"
#include "HPB_int.h"
#include "HSSD2_int.h"
#include "MEXTI_int.h"
#include "MADC_int.h"
#include "MTIMER_0_int.h"


#if 0
void main(void)
{

	LCD_voidInit();
	HKEYPAD_enInit();
	HLED_enInit(HLED_BLUE_ID);
	HBUZZ_Init();
	HKEYPAD_voidcheckPassword2();

	HKEYPAD_voidcheckPassword();
while(1)
{


}

}
#endif

#if 0
void increment (void)
{

	PBState_t state = PB_RELEASED;
	HSSD2_enInit();
	PB_t PB1 ={1,PD7};
	HPB_enInit(&PB1);
	u8 counter = 0;  // counter for the seven segment

	HPB_enRead(&PB1, &state);

	if(state==PB_PRESSED)
	{
		counter ++;
		HSSD2_enDisplayIntegerNumber(counter);
	}
}


void toggle_led(void)
{
	HLED_enInit(HLED_GRN_ID);
	HLED_enSetON(HLED_GRN_ID);
	_delay_ms(1000);
	HLED_enSetOFF(HLED_GRN_ID);
	_delay_ms(1000);
	HLED_enSetON(HLED_GRN_ID);
	_delay_ms(1000);
}


int main(void)
{

	GIE_voidEnable();
	EXTI_voidInit();
	MDIO_voidsetPinDirection(PD2, INPUT);
	MDIO_voidsetPinValue(PD2, HIGH);	//internal pull up
	MEXTI_voidEnableInterrupt(EXTI_LINE0);
	EXTI_voidSetCallBack(toggle_led,EXTI_LINE0);

while(1);

return 0;
}
#endif

#if 0
int main(void)
{
	u8 Local_u8ADCReading;
	DIO_voidSetPortDirection(PORTA, INPUT);

while(1)
{
	Local_u8ADCReading = ADC_u8GetChacnnelReading(0);
	LCD_voidWriteString(Local_u8ADCReading);

}

return 0;
}
#endif

/* ADC with polling*/
#if 0
int main(void)
{
	LCD_voidInit();
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);
	ADC_Init();
	ADC_Enable();
	u16 Digital;
	u16 Analog=0;
	u16 Analog_prev=0;
	while(1)
	{
		ADC_Start(0);
		Digital=ADC_Result();
		Analog=Analog_Value(Digital);
		if(Analog!=Analog_prev)
		{
			LCD_voidClear();
			LCD_voidWriteNumber(Analog);
			Analog_prev=Analog;
		}
		else
		{
			//Do Nothing
		}
		_delay_ms(500);
	}
}
#endif

#if 0
int main(void)
{
	LCD_voidInit();
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);
	ADC_Init();
	ADC_Enable();
	u16 Digital;
	u16 Analog=0;
	u16 Analog_prev=0;
	while(1)
	{
		ADC_Start(0);
		Digital=ADC_Result();
		Analog=Analog_Value(Digital);
		if(Analog!=Analog_prev)
		{
			LCD_voidClear();
			LCD_voidWriteNumber(Analog);
			Analog_prev=Analog;
		}
		else
		{
			//Do Nothing
		}
		_delay_ms(500);
	}
}
#endif
/* ADC with Interrupt*/
#if 0
void get_reading()
{

}

int main(void)
{
	LCD_voidInit();
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);
	ADC_Init();
	ADC_Enable();
	u16 Digital;
	u16 Analog=0;
	u16 Analog_prev=0;
	set_call_back(fn_ptr)
	while(1)
	{
		ADC_Start(0);
		Digital=ADC_Result();
		Analog=Analog_Value(Digital);
		if(Analog!=Analog_prev)
		{
			LCD_voidClear();
			LCD_voidWriteNumber(Analog);
			Analog_prev=Analog;
		}
		else
		{
			//Do Nothing
		}
		_delay_ms(500);
	}
}
#endif

/*Timer 0 Normal Mode Applications*/
void LED(void)
{

		static u8 Local_u8Counter =0;
		Local_u8Counter++;
		if(Local_u8Counter==62)
		{
			HLED_enToggle(HLED_BLUE_ID);
			Local_u8Counter=0;
			TIMER0_voidPreLoad(247); //TCNT0_REG=247;
		}

}


int main()
{
	HLED_enInit(HLED_BLUE_ID);
	TIMER0_voidInit();
	TIMER0_u8SetCallBack(LED);
	GIE_voidEnable();
	while (1)
	{

	}
}
