/*
 * PrintStream.h
 *
 *  Created on: Mar 18, 2015
 *      Author: guywenck
 */

#ifndef PRINTSTREAM_H_
#define PRINTSTREAM_H_

#include "Typedefs.h"
#include "LibraryFixes.h"
#include <stdarg.h>
#include <string.h>
#include <API.h>

#define PRINT_FORMAT_FILL_BUFFE_CHARS 100

namespace TRL {

	typedef enum _MessageStatusIndicator {
		ERROR,
		WARNING,
		DEBUG,
		LOG
	}MessageStatusIndicator;

	void print(MessageStatusIndicator indicator, string className, string functionName,string formatString, ...);

	//This is the fastest print statement since no formatting needs to be done
	void print(string text);
	//if you need this equivelent with formatting use the PROS function printf(string formatString, ...)

	void println(MessageStatusIndicator indicator, string className, string functionName, string formatString, ...);
	void println(string formatString, ...);
}

#endif /* PRINTSTREAM_H_ */
