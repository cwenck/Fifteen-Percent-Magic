/*
 * PrintStream.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: guywenck
 */

#include "TRL/PrintStream.h"

namespace TRL {

//Max length is 255 characters
void print(MessageStatusIndicator indicator, string className,
		string functionName, string formatString, ...) {
	short maxSize = 255;
	short len = strlen(formatString);

	if (len > maxSize) {
		printf("[Error] String exceeds max print() length of 255 characters.\n\r");
		return;
	}

	char line_chars[maxSize + 1];

	va_list arg;
	va_start(arg, formatString);
	{
		vsnprintf(line_chars, maxSize, formatString, arg);
	}
	va_end(arg);

	//print prefix
	printf("[");
	switch (indicator) {
	case ERROR:
		printf("ERROR");
		break;
	case WARNING:
		printf("WARNING");
		break;
	case DEBUG:
		printf("DEBUG");
		break;
	case LOG:
		printf("LOG");
		break;
	}
	printf("] [");
	printf(className);
	printf("::");
	printf(functionName);
	printf("()] ");
	printf(line_chars);
}

//Max length is 255 characters
void println(MessageStatusIndicator indicator, string className,
		string functionName, string formatString, ...) {
	short maxSize = 255;
	short len = strlen(formatString);

	if (len > maxSize) {
		printf(
				"[Error] String exceeds max println() length of 255 characters.\n\r");
		return;
	}

	char line_chars[maxSize + 1];

	va_list arg;
	va_start(arg, formatString);
	{
		vsnprintf(line_chars, maxSize, formatString, arg);
	}
	va_end(arg);

	//print prefix
	printf("[");
	switch (indicator) {
	case ERROR:
		printf("ERROR");
		break;
	case WARNING:
		printf("WARNING");
		break;
	case DEBUG:
		printf("DEBUG");
		break;
	case LOG:
		printf("LOG");
		break;
	}
	printf("] [");
	printf(className);
	printf("::");
	printf(functionName);
	printf("()] ");
	printf(line_chars);
	printf("\n\r");
}

} /* namespace TRL */
