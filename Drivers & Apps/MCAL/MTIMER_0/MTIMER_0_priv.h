/*
 * MTIMER_0_priv.h
 *
 *  Created on: Jun 18, 2023
 *      Author: Saif Elden
 */

#ifndef MTIMER_0_MTIMER_0_PRIV_H_
#define MTIMER_0_MTIMER_0_PRIV_H_
/*
typedef struct
{
	u8 CS0	 : 3;
	u8 WGM01 : 1;
	u8 COM0  : 2;
	u8 WGM01 : 1;
	u8 FOC0  : 1;
}TCCR0_REG;
*/


#define NORMAL_MODE 		1
#define CTC_MODE 			2
#define PWM_MODE 			3

#define NO_CLOCK			0

#define NO_PRE_SCALE		1
#define PRE_SCALE_8			2
#define PRE_SCALE_64		3
#define PRE_SCALE_256		4
#define PRE_SCALE_1024		5



#define TCCR0_REG		*((volatile u8*)0x53)
#define TCCR0_WGM00			6
#define TCCR0_WGM01			3
#define TCCR0_CS02			2
#define TCCR0_CS01			1
#define TCCR0_CS00			0


#define OCR0_REG		*((volatile u8*)0x5C) //read data in compare mode
#define TIMSK_REG		*((volatile u8*)0x59) // timer interrupt
#define TIMSK_TOV0				0				// overflow flag in interrupt reg
#define	TIMSK_OCIE0				1				// CTC flag in interrupt reg
#define TIFR_REG		*((volatile u8*)0x58) //interrupt flag register






#endif /* MTIMER_0_MTIMER_0_PRIV_H_ */
