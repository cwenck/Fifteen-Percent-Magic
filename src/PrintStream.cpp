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
	delay(2);
	print("[");
	switch (indicator) {
	case ERROR:
		print("ERROR");
		break;
	case WARNING:
		print("WARNING");
		break;
	case DEBUG:
		print("DEBUG");
		break;
	case LOG:
		print("LOG");
		break;
	}
	print("] [");
	print(className);
	print("::");
	print(functionName);
	print("()] ");
	delay(2);
	print(line_chars);
	delay(6);

}


//Note using ::functionName() uses the function from the global namespace
void print(string text){
	::print(text);
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
	delay(2);
	print("[");
	switch (indicator) {
	case ERROR:
		print("ERROR");
		break;
	case WARNING:
		print("WARNING");
		break;
	case DEBUG:
		print("DEBUG");
		break;
	case LOG:
		print("LOG");
		break;
	}
	print("] [");
	print(className);
	print("::");
	print(functionName);
	print("()] ");
	delay(2);
	print(line_chars);
	print("\n\r");
	delay(6);
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

	delay(2);
	print(line_chars);
	print("\n\r");
	delay(6);
}

} /* namespace TRL */
