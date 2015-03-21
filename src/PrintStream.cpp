/*
 * PrintStream.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: guywenck
 */

#include "TRL/PrintStream.h"

namespace TRL {

//Max length is 255 characters
void print(MessageStatusIndicator indicator, string sender, string formatString,
		...) {
	short maxSize = 255;
	short len = strlen(formatString);

	if (maxSize > len) {
		printf("[Error] String exceeds max print() length of 255 characters.");
		return;
	}

	char line_chars[maxSize + 1];

	va_list arg;
	va_start(arg, formatString);
	{
		vsnprintf(line_chars, 255, formatString, arg);
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
	printf(sender);
	printf("] ");
	printf(line_chars);
}

//Max length is 255 characters
void println(MessageStatusIndicator indicator, string sender,
		string formatString, ...) {
	short maxSize = 255;
	short len = strlen(formatString);

	if (maxSize > len) {
		printf(
				"[Error] String exceeds max println() length of 255 characters.");
		return;
	}

	char line_chars[maxSize + 1];

	va_list arg;
	va_start(arg, formatString);
	{
		vsnprintf(line_chars, 255, formatString, arg);
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
	printf(sender);
	printf("] ");
	printf(line_chars);
	printf("\n\r");
}

} /* namespace TRL */
