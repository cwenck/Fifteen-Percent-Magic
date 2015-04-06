/*
 * LibraryFixes.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: guywenck
 */

#include "TRL/LibraryFixes.h"

extern "C" {

void* __dso_handle;

void __cxa_pure_virtual() {
	printf(
			"----------------------------------------------------------------------\n\r");
	printf(
			"[Error] Virtual Function Error! Stopping execution of the program.\n\r");
	printf(
			"\tCheck to make sure all virtual functions are defined in child classes.\n\r");
	printf(
			"----------------------------------------------------------------------\n\r");
	while (1) {
		delay(500);
	}
}

}
