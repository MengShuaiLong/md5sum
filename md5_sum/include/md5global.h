/* GLOBAL.H - RSAREF types and constants
*/

/* PROTOTYPES should be set to one if and only if the compiler supports
function argument prototyping.
The following makes PROTOTYPES default to 0 if it has not already
been defined with C compiler flags.
*/

#ifndef MD5_GLOBAL_H
#define MD5_GLOBAL_H

/* POINTER defines a generic pointer type */
typedef unsigned char *POINTER;

/* UINT2 defines a two byte word */
typedef unsigned short int UINT2;

/* UINT4 defines a four byte word */
// typedef unsigned long int UINT4;//64位系统时长度为8  需要改为下面的定义
typedef unsigned int UINT4;

#endif
