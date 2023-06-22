/*
 * HBUZZ_int.h
 *
 *  Created on: May 31, 2023
 *      Author: Saif Elden
 */
#include"ERROR_STATE.h"
#ifndef HBUZZ_HBUZZ_INT_H_
#define HBUZZ_HBUZZ_INT_H_


ErrorState_t HBUZZ_Init(void); //set direction
ErrorState_t HBUZZ_SetON(void);
ErrorState_t HBUZZ_SetOFF(void);
ErrorState_t HBUZZ_Once(void);
ErrorState_t HBUZZ_Toggle(void);

#endif /* HBUZZ_HBUZZ_INT_H_ */
