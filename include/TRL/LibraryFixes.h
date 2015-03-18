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
	extern int __dso_handle;
}

#endif /* LIBRARYFIXES_H_ */
