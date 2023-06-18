/*
 * HPB_int.h
 *
 *  Created on: May 30, 2023
 *      Author: Saif Elden
 */

#ifndef HPB_HPB_INT_H_
#define HPB_HPB_INT_H_
#include"ERROR_STATE.h"
#include"MDIO_int.h"

/*
 * ENUMS
 * */

typedef enum
{
	PB1_ID =1,
	PB2_ID =2,
	PB3_ID =3,
	PB4_ID =4,
	PB5_ID =5,
	PB6_ID =6,
	PB7_ID =7
}PBID_t;


typedef enum
{
	PB_PRESSED = 0,
	PB_RELEASED = 1
}PBState_t;

typedef struct {
	PBID_t PushButtonID;
	Pin_t  PushButtonPin;
}PB_t;


/*
 * FUNCTIONS PROTOTYPES
 * */


ErrorState_t HPB_enInit(const PB_t * ptrPB);
ErrorState_t HPB_enRead(const PB_t * ptrPB,PBState_t * ptrPBState);

u8 HPB_enRead2(u8 copy_PinID);

#endif /* HPB_HPB_INT_H_ */
