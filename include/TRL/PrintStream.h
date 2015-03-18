/*
 * PrintStream.h
 *
 *  Created on: Mar 18, 2015
 *      Author: guywenck
 */

#ifndef PRINTSTREAM_H_
#define PRINTSTREAM_H_

#include<stdarg.h>

namespace TRL {

	typedef enum _MessageStatusIndicator {
		ERROR,
		WARNING,
		DEBUG,
		LOG
	}MessageStatusIndicator;

	void print(MessageStatusIndicator indicator, const char * sender, const char *formatString, ...);
	void println(MessageStatusIndicator indicator, const char * sender, const char *formatString, ...);

}

#endif /* PRINTSTREAM_H_ */
