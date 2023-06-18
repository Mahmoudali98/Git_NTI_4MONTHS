/*
 * MEXTI_priv.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Saif Elden
 */

#ifndef MEXTI_MEXTI_PRIV_H_
#define MEXTI_MEXTI_PRIV_H_

#define MCCUR_REG	*((volatile u8*)0x55)
#define MCUCSR_REG	*((volatile u8*)0x54)
#define GCIR_REG	*((volatile u8*)0x5B)
#define GIFR_REG	*((volatile u8*)0x5A)

#define SREG_REG	*((volatile u8*)0x5F)

#define NULL				0

#endif /* MEXTI_MEXTI_PRIV_H_ */
