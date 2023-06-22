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
#include "HKEYPAD2_int.h"
#include "HLED_int.h"
#include "HBUZZ_int.h"
#include "HPB_int.h"
#include "HSSD2_int.h"
#include "MEXTI_int.h"
#include "MADC_int.h"
#include "MTIMER_0_int.h"
#include "MTIMER_1_int.h"

/* Check Passwordd for 3 times then */
#if 0

void main(void)
{

	LCD_voidInit();
	HKEYPAD_enInit();
	HLED_enInit(HLED_BLUE_ID);
	HBUZZ_Init();
	//HKEYPAD_voidcheckPassword2(); // Was Trying to make another method to make the check on password

	HKEYPAD_voidcheckPassword(); // Location in MADC_prg.c
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

#if 0
/*Timer 0 Normal Mode Applications*/
void LED(void)
{
		static u8 Local_u8Counter =0;
		Local_u8Counter++;
		if(Local_u8Counter==62)
		{
			HLED_enToggle(HLED_BLUE_ID);
			Local_u8Counter=0;
			TIMER0_voidSetPreLoad(247); //TCNT0_REG=247;
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
#endif

#if 0
/*Buzzer with PWM timer0 starting with 20% for PWM then 50% then 100% */

int main()
{
	HBUZZ_Init();
	TIMER0_voidInit();
	//TIMER0_u8SetCallBack(PWM_BUZZ);
	//GIE_voidEnable();
	DIO_voidSetPinDirection(PORTB_ID,PIN3, OUTPUT);
	while (1)
	{
		Timer0_voidSetDutyCycle(20);
		_delay_ms(1000);

		Timer0_voidSetDutyCycle(50);
		_delay_ms(1000);

		Timer0_voidSetDutyCycle(100);
		_delay_ms(1000);

	}
}

#endif


/*keypad buttons to change PWM and take the effect on the buzzer sound*/
#if 0
int main()
{
	u8 key;
	HKEYPAD_enInit();


	TIMER0_voidInit();
	//TIMER0_u8SetCallBack(PWM_BUZZ);
	//GIE_voidEnable();
	DIO_voidSetPinDirection(PORTB_ID,PIN3, OUTPUT);
	while (1)
	{
		key = HKEYPAD_enGetPressedKey2();
		if(key==1)
		{
			Timer0_voidSetDutyCycle(20);
			_delay_ms(1000);
		}
		else if(key==2)
		{
			Timer0_voidSetDutyCycle(50);
			_delay_ms(1000);
		}
		else if(key==3)
		{
			Timer0_voidSetDutyCycle(100);
			_delay_ms(1000);
		}


	}
	return 0;
}
#endif
/*another logic with changing in keypad configuration file to make array has the values of Duty Cycle for each button to change pwm*/
#if 0
int main()
{
	u8 key;
	HKEYPAD_enInit();
	TIMER0_voidInit();
	DIO_voidSetPinDirection(PORTB_ID,PIN3, OUTPUT);
	while (1)
	{
		key = HKEYPAD_enGetPressedKey2();
			Timer0_voidSetDutyCycle(key);
			_delay_ms(1000);
	}
	return 0;
}
#endif

#if 0
/*Change the duty cycle with the readings of adc and display it on LCD*/
int main(void)
{
	LCD_voidInit();
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);
	DIO_voidSetPinDirection(PORTC_ID, PIN6, PIN_OUTPUT);
	ADC_Init();
	ADC_Enable();
	u16 Digital;
	u16 Analog=0;
	u16 Analog_prev=0;
	TIMER0_voidInit();
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
			Timer0_voidSetDutyCycleADC(Analog);
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
	void Timer1_voidInit(void);
	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_OUTPUT);
	Timer1_voidSetCompChA(2);
	while(1)
	{

	}
}
#endif


/*Calculator*/
#if 0

u8 counter = 0;
u8 KpValue=255;                       //variable to store the pressed button for Keypad
u8 NumberOfDigit=0;                   //variable to calculate the number of digit of password
u8 Pasword[16];						 //array to store the password when set
u8 CheckPasword[16];					 //array to store the password when check
u8 Reset=1;

u8 FristNum[4];                       //Array to store the first number (Assuming the number of digits 4)
u8 SecondNum[4];						 //Array to store the Second number (Assuming the number of digits 4)

u16 calc_sum(  u8 a[],u8 b[],u8 n,u8 m);
u16 calc_sub(  u8 a[],u8 b[],u8 n,u8 m);
u16 calc_multi(u8 a[],u8 b[],u8 n,u8 m);
u16 calc_div(u8 a[],u8 b[],u8 n,u8 m);



int main()
{
			HLED_enInit(HLED_BLUE_ID);
			LCD_voidInit();
			KPD_voidInit();
	/*    loop for repeating the calculation    */
			while(1){
							LCD_voidGoToXY(2, 1);
							LCD_voidWriteString("calc is ready");
							_delay_ms(1000);
							LCD_voidClear();
							//KpValue == '\0';
							counter=0;
							u8 opration=0;


							/*    Getting The First Number    */
							while(1)
							{
								do{
									HLED_enSetON(HLED_BLUE_ID);
									KpValue = KPD_voidGetPressedKey();
									_delay_ms(200);
								}while(KpValue == '\0');
								if(KpValue == '+' || KpValue == '-' || KpValue == '/' || KpValue == '*'){
									opration = KpValue;
									LCD_voidGoToXY(1, counter+1);
									LCD_voidWriteData(KpValue);

									break;
								}
								FristNum[counter]=KpValue;
								counter++;
								LCD_voidGoToXY(1, counter);
								LCD_voidWriteNumber(KpValue);
							}
							u8 counter2=counter+1;
							u8 counter3=0;


							/*    Getting The Second Number    */
							while(1)
							{
								do{
									KpValue = KPD_voidGetPressedKey();
									_delay_ms(200);
								}while(KpValue == '\0');
								if(KpValue == '=' ){
									LCD_voidGoToXY(1, counter2+1);
									LCD_voidWriteData(KpValue);
									break;}
								SecondNum[counter3]=KpValue;
								counter2++;
								counter3++;
								LCD_voidGoToXY(1, counter2);
								LCD_voidWriteData(KpValue);
							}

							/*     switch which operation was Selected */
							switch(opration)
							{
								case '+':
								LCD_voidGoToXY(1, counter2+3);
								LCD_voidWriteData(calc_sum(FristNum,SecondNum,counter,counter3));
								break;
								case '-':
								LCD_voidGoToXY(1, counter2+3);
								LCD_voidWriteData(calc_sub(FristNum,SecondNum,counter,counter3));
								break;
								case '*':
								LCD_voidGoToXY(1, counter2+3);
								LCD_voidWriteData(calc_multi(FristNum,SecondNum,counter,counter3));
								break;
								case '/':
								LCD_voidGoToXY(1, counter2+3);
								LCD_voidWriteData(calc_div(FristNum,SecondNum,counter,counter3));
								break;
							}
							_delay_ms(3000);
							LCD_voidClear();
							}
}



u16 calc_sum(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{

		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1+num2);
}

u16 calc_sub(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1-num2);
}

u16 calc_multi(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1*num2);
}

u16 calc_div(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1/num2);
}
#endif


/*Keypad Applications
 *1- increment 7 seg
 *2- decrement 7 seg
 *3- buzzer toggle
 *4- led toggle
 **/
#if 0
int main()
{
	u8 key;
	u8 counter=0;
	HKEYPAD_enInit();
	HSSD2_enInit();
	HBUZZ_Init();
	HLED_enInit(HLED_BLUE_ID);

		while (1)
		{
			key = HKEYPAD_enGetPressedKey2();
			if(key==1)	//increment
			{
				counter++;
				HSSD2_enDisplayIntegerNumber(counter);
			}
			else if(key==2) //decrement
			{
				counter--;
				HSSD2_enDisplayIntegerNumber(counter);
			}
			else if(key==3)
			{
				HBUZZ_Toggle();
			}
			else if(key==4)
			{
				HLED_enToggle(HLED_BLUE_ID);
			}

	}
		return 0;
	}
#endif
#if 0
/*Change Character Status According to  LDR Readings */
int main(void)
{
	u8 HLCD_u8ExtraChar2[]=
	{
			0x0E,0x0A,0x0E,0x04,0x1F,0x04,0x0A,0x11
	};
	u8 HLCD_u8ExtraChar3[]=
	{
			 0x00,0x00,0x1D,0x17,0x1D,0x00,0x00,0x00
	};

	LCD_voidInit();
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);
	DIO_voidSetPinDirection(PORTC_ID, PIN6, PIN_OUTPUT);
	ADC_Init();
	ADC_Enable();
	u16 Digital;
	u16 Analog=0;
	u16 Analog_prev=0;
	TIMER0_voidInit();
	while(1)
	{
		LCD_voidGoToXY(0,1);

		ADC_Start(0);
		Digital=ADC_Result();
		Analog=Analog_Value(Digital);
		if(Analog!=Analog_prev)
		{
			if (Analog>=1500)
			{
			LCD_voidClear();
			//LCD_voidWriteNumber(Analog);
			Analog_prev=Analog;
			Timer0_voidSetDutyCycleADC(Analog);

			LCD_voidWriteSpecialCharToCGRAM(HLCD_u8ExtraChar2, 0, 2, 2);

			}
			else if (Analog<1700)
			{
			LCD_voidClear();
			//LCD_voidWriteNumber(Analog);
			Analog_prev=Analog;
			Timer0_voidSetDutyCycleADC(Analog);

			LCD_voidWriteSpecialCharToCGRAM(HLCD_u8ExtraChar3, 0, 0, 1);

			}
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
/*voltmeter */
int main ()
{
	ADC_voidInit();
	LCD_voidInit();
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);
	while (1)
	{
		_delay_ms(350);
		LCD_voidClear();
		u16 value = ADC_u8GetChacnnelReading(0);
		value = Analog_Value(value);

		LCD_voidGoToXY(0, 1);
		LCD_voidWriteNumber(value);
		LCD_voidGoToXY(0, 7);
		LCD_voidWriteString("mV");

	}
	return 0;
}

#endif
/*Ohmmeter on channel 0 on kit*/
#if 0
int main ()
{
	ADC_voidInit();
	LCD_voidInit();
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);
	while (1)
	{
		_delay_ms(350);
		LCD_voidClear();
		u32 value = ADC_u8GetChacnnelReading();
		value = Analog_Value(value);
		value = value *2 ;  //R2 = Vin*2

		LCD_voidGoToXY(0, 1);
		LCD_voidWriteNumber(value);
		LCD_voidGoToXY(0, 7);
		LCD_voidWriteString("Ohm");
	}
	return 0;
}
#endif

/*Degree With Celsius on channel 1 on kit*/
#if 0
int main ()
{
	ADC_voidInit();
	LCD_voidInit();
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);
	while (1)
	{
		_delay_ms(350);
		LCD_voidClear();
		u32 value = ADC_u8GetChacnnelReading();
		value = Analog_Value(value);
		value = value /10 ;  //Degree = Vin/10  every 10mV = 1 C
		LCD_voidGoToXY(0, 1);
		LCD_voidWriteNumber(value);
		LCD_voidGoToXY(0, 8);
		LCD_voidWriteString("C");
	}
	return 0;
}
#endif

/*Button to Start Timer from 5 to 0 then enable buzzer and another button to disable buzzer*/
int main ()
{
	while (1)
	{

	}
	return 0;
}
