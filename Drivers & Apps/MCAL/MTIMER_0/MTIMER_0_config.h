/*
 * MTIMER_0_config.h
 *
 *  Created on: Jun 18, 2023
 *      Author: Saif Elden
 */

#ifndef MTIMER_0_MTIMER_0_CONFIG_H_
#define MTIMER_0_MTIMER_0_CONFIG_H_

/*Select Mode
 *1- NORMAL_MODE
 *2- CTC_MODE
 *3- PWM_MODE
 **/

#define SELECT_MODE		CTC_MODE

/*
 *PRE_SCALE_MODE
 *1-NO_PRE_SCALE
 *2-PRE_SCALE_8
 *3-PRE_SCALE_64
 *4-PRE_SCALE_256
 *5-PRE_SCALE_1024
 *
 **/

#define SELECT_PRE_SCALE	PRE_SCALE_1024

#endif /* MTIMER_0_MTIMER_0_CONFIG_H_ */
