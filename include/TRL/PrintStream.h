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

namespace TRL {

	typedef enum _MessageStatusIndicator {
		ERROR,
		WARNING,
		DEBUG,
		LOG
	}MessageStatusIndicator;

	void print(MessageStatusIndicator indicator, string className, string functionName,string formatString, ...);
	void print(string formatString, ...);

	void println(MessageStatusIndicator indicator, string className, string functionName, string formatString, ...);
	void println(string formatString, ...);
}

#endif /* PRINTSTREAM_H_ */
