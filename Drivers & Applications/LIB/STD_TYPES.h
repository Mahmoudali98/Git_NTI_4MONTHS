#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

/*
 * unSigned Data Types
 */
typedef unsigned char           u8;
typedef unsigned short int      u16;
typedef unsigned long int       u32;
typedef unsigned long long int  u64;

/*
 * signed Data Types
 */
typedef signed char             s8;
typedef signed short int        s16;
typedef signed long int         s32;
typedef signed long long int    s64;

/*
 * Floating point Types
 */
typedef float                   f32;
typedef double                  f64;

/*
 * Address NULL
 */



#define NULL_POINTER ( (void *) 0x00)

#define NULL					0

#define OK						0
#define NOK						1
#define NULL_PTR				2


#endif /* _STD_TYPES_H */
