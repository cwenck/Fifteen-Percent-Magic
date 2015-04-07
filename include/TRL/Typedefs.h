/*
 * EnumeratedTypes.h
 *
 *  Created on: Feb 7, 2015
 *      Author: guywenck
 */

#ifndef ENUMERATEDTYPES_H_
#define ENUMERATEDTYPES_H_

#include <API.h>

//wrapper type for strings in c
typedef const char* string;

#define UNIVERSAL_PORT_NULL -1
typedef short UniversalPort;

//types that are wrappers for default pros types are prefixed with "PROS_"
typedef void* PROS_Encoder;
typedef FILE* PROS_File;
typedef Ultrasonic PROS_Sonar;
typedef Gyro PROS_Gyro;

#endif /* ENUMERATEDTYPES_H_ */
