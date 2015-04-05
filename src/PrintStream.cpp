/*
 * PrintStream.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: guywenck
 */

#include "TRL/PrintStream.h"

namespace TRL {

void print(MessageStatusIndicator indicator, string className,
		string functionName, string formatString, ...) {
	short len = strlen(formatString);
	char line_chars[len + 1 + PRINT_FORMAT_FILL_BUFFE_CHARS];

	va_list arg;
	va_start(arg, formatString);
	{
		vsnprintf(line_chars, len + PRINT_FORMAT_FILL_BUFFE_CHARS, formatString, arg);
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

void print(string formatString, ...) {
	short len = strlen(formatString);
	char line_chars[len + 1 + PRINT_FORMAT_FILL_BUFFE_CHARS];

	va_list arg;
	va_start(arg, formatString);
	{
		vsnprintf(line_chars, len + PRINT_FORMAT_FILL_BUFFE_CHARS, formatString, arg);
	}
	va_end(arg);

	printf(line_chars);
}

void println(MessageStatusIndicator indicator, string className,
		string functionName, string formatString, ...) {
	short len = strlen(formatString);
	char line_chars[len + 1 + PRINT_FORMAT_FILL_BUFFE_CHARS];

	va_list arg;
	va_start(arg, formatString);
	{
		vsnprintf(line_chars, len + PRINT_FORMAT_FILL_BUFFE_CHARS, formatString, arg);
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

void println(string formatString, ...) {
	short len = strlen(formatString);
	char line_chars[len + 1 + PRINT_FORMAT_FILL_BUFFE_CHARS];

	va_list arg;
	va_start(arg, formatString);
	{
		vsnprintf(line_chars, len + PRINT_FORMAT_FILL_BUFFE_CHARS, formatString, arg);
	}
	va_end(arg);

	printf(line_chars);
	printf("\n\r");
}

} /* namespace TRL */
