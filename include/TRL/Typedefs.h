/*
 *
 *  Created on: Feb 7, 2015
 *      Author: guywenck
 */

#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

#include <API.h>

//wrapper type for strings in c
typedef const char* string;

typedef void (*VoidFunctionPtr)(void);

typedef short UniversalPort;

//types that are wrappers for default pros types are prefixed with "PROS_"
typedef void* PROS_Encoder;
typedef FILE* PROS_File;
typedef Ultrasonic PROS_Sonar;
typedef Gyro PROS_Gyro;

#endif /* TYPEDEFS_H_ */
