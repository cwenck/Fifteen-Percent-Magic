/*
 * LCD.cpp
 *
 *  Created on: Apr 2, 2015
 *      Author: guywenck
 */

#include "TRL/LCD.h"

namespace TRL {

LCD LCD::instance;

LCD::LCD() {
	this->port = NoLCD;
}

LCD::LCD(LCDPort port) {
	this->port = port;
}

LCD::~LCD() {
	// TODO Auto-generated destructor stub
}

void LCD::initStatics(){
	lcdInit(uart1);
	lcdInit(uart2);
	instance = LCD(UART_1);
}

PROS_File LCD::getFileFromPort() {
	switch (port) {
	case UART_1:
		return uart1 ;
	case UART_2:
		return uart2 ;
	default:
		println(WARNING, "LCD", "getFileFromPort",
				"LCD port isn't set. Can't retrieve PROS file for LCD");
		return 0;
	}
}

LCD* LCD::setPort(LCDPort port){
	this->port = port;
	return this;
}

bool LCD::isLeftButtonPressed() {
	int btns = lcdReadButtons(getFileFromPort());
	return (btns & LCD_BTN_LEFT) != 0;
}

bool LCD::isCenterButtonPressed() {
	int btns = lcdReadButtons(getFileFromPort());
	return (btns & LCD_BTN_CENTER) != 0;
}

bool LCD::isRightButtonPressed() {
	int btns = lcdReadButtons(getFileFromPort());
	return (btns & LCD_BTN_RIGHT) != 0;
}

LCD* LCD::setBacklight(bool backlight){
	lcdSetBacklight(getFileFromPort(), backlight);
	return this;
}

LCD* LCD::enableBacklight(){
	lcdSetBacklight(getFileFromPort(), true);
	return this;
}

LCD* LCD::disableBacklight(){
	lcdSetBacklight(getFileFromPort(), false);
	return this;
}

LCD* LCD::clear(){
	lcdClear(getFileFromPort());
	return this;
}

LCD* LCD::displayCenteredString(short line, const string text) {
	const unsigned char line_size = 16;
	int size = 0;
	for (const char *cursor = text; *cursor != NULL; cursor++) {
		size++;
	}
	if (size >= 16) {
		lcdSetText(getFileFromPort(), line, text);
	} else {
		int extraSpace = line_size - size;
		int sideSpace = extraSpace / 2;
		char line_chars[16];
		char *linePointer = &line_chars[0];
		for (int i = 0; i < sideSpace; i++) {
			*linePointer = ' ';
			linePointer++;
		}

		int textSize = 0;
		for (const char *cursor = text; *cursor != NULL; cursor++) {
			*linePointer = *cursor;
			textSize++;
			linePointer++;
		}
		for (int i = textSize + sideSpace; i < 16; i++) {
			line_chars[i] = ' ';
		}
		lcdSetText(getFileFromPort(), line, line_chars);
	}
	return this;
}

LCD* LCD::displayFormattedCenteredString(short line,
		const string formatString, ...) {
	int size = 0;
	for (const char *cursor = formatString; *cursor != NULL; cursor++) {
		size++;
	}
	char line_chars[17];

	va_list arg;

	va_start(arg, formatString);
	{
		vsnprintf(line_chars, 16, formatString, arg);
	}
	va_end(arg);
	displayCenteredString(line, line_chars);
	return this;
}

LCD* LCD::displayBatteryStatus() {
	displayFormattedCenteredString(1, "Main: %.2fV", getMainBatteryPower());
	return this;
}

} /* namespace TRL */
