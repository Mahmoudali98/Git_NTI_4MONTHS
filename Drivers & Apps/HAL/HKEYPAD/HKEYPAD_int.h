/*
 * HKEYPAD_int.h
 *
 *  Created on: May 31, 2023
 *      Author: Saif Elden
 */

#include "ERROR_STATE.h"

#ifndef HKEYPAD_HKEYPAD_INT_H_
#define HKEYPAD_HKEYPAD_INT_H_


#define HKEYPAD_NO_PRESSED_KEY 0xff

ErrorState_t HKEYPAD_enInit(void);
ErrorState_t HKEYPAD_enGetPressedKey(u8 * ptrKey);
u8 HKEYPAD_enGetPressedKey2(void);

/*
 * APPLICATIONS USING PUSH BUTTON
 * */

void HKEYPAD_voidcheckPassword(void);
void HKEYPAD_voidcheckPassword2(void);


#endif /* HKEYPAD_HKEYPAD_INT_H_ */
