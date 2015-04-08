/*
 * LibraryFixes.h
 *
 *  Created on: Feb 7, 2015
 *      Author: guywenck
 */

#ifndef LIBRARYFIXES_H_
#define LIBRARYFIXES_H_

#include <API.h>

extern "C" {
	int vsnprintf (char * s, size_t n, const char * format, va_list arg );
	extern void* __dso_handle;
}

int snprintf(char * s, size_t n, const char * format, ...);

//Enable the use of new and delete
void* operator new(size_t);
void* operator new[](size_t);
void operator delete(void* ptr);
void operator delete[](void* ptr);

#endif /* LIBRARYFIXES_H_ */
