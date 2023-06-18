/*
 * HKEYPAD_config.h
 *
 *  Created on: May 31, 2023
 *      Author: Saif Elden
 */

#ifndef HKEYPAD_HKEYPAD_CONFIG_H_
#define HKEYPAD_HKEYPAD_CONFIG_H_

//Please configure the PINS for the keypad


#define HKEYPAD_R0_PIN		PC5
#define HKEYPAD_R1_PIN		PC4
#define HKEYPAD_R2_PIN		PC3
#define HKEYPAD_R3_PIN		PC2

#define HKEYPAD_C0_PIN		PD7
#define HKEYPAD_C1_PIN		PD6
#define HKEYPAD_C2_PIN		PD5
#define HKEYPAD_C3_PIN		PD3


#define KIT_TYPE	SIM_KIT


/*
 *
 * Here you can choose the keypad mapping
 * */

#define HKEYPAD_KEYS		{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}


#endif /* HKEYPAD_HKEYPAD_CONFIG_H_ */
