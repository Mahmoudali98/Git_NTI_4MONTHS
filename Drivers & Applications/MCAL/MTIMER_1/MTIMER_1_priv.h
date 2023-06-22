/*
 * MTIMER_1_priv.h
 *
 *  Created on: Jun 19, 2023
 *      Author: Saif Elden
 */

#ifndef MTIMER_1_MTIMER_1_PRIV_H_
#define MTIMER_1_MTIMER_1_PRIV_H_


#define TCCR1A_REG  *((volatile u8* ) 0x4F)
//COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10
#define TCCR1A_COM1A1	7
#define TCCR1A_COM1A0	6
#define TCCR1A_COM1B1	5
#define TCCR1A_COM1B0	4
#define TCCR1A_FOC1A	3
#define TCCR1A_FOC1B 	2
#define TCCR1A_WGM11	1
#define TCCR1A_WGM10 	0


#define TCNT1L_REG  *((volatile u8* ) 0x4C
#define TCNT1H_REG  *((volatile u8* ) 0x4E) //Timer/Counter1)
#define TCNT1_REG  *((volatile u16* ) 0x4E)

#define TCCR1B_REG  *((volatile u8* ) 0x4D)
// COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10
#define TCCR1B_WGM12	4
#define TCCR1B_WGM13	5
#define TCCR1B_CS10		0
#define TCCR1B_CS11		1
#define TCCR1B_CS12		2

#define OCR1A_REGL *((volatile u8* ) 0x4A)
#define OCR1AH_REG *((volatile u8* ) 0x4B)
#define OCR1A_REG *((volatile u16* ) 0x4B)


#define ICR1_REG   *((volatile u16* ) 0x46)


#endif /* MTIMER_1_MTIMER_1_PRIV_H_ */
