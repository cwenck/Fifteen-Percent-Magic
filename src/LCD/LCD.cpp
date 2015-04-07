/*
 * LCD.cpp
 *
 *  Created on: Apr 2, 2015
 *      Author: guywenck
 */

#include "LCD/LCD.h"

namespace TRL {

LCD LCD::instance;

LCD::LCD() {
	this->port = NoLCD;
}

LCD::LCD(LCDPort port) {
	this->port = port;
}

LCD::~LCD() {
}

void LCD::initStatics() {
	lcdInit(uart1 );
	lcdInit(uart2 );
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

LCD* LCD::setPort(LCDPort port) {
	this->port = port;
	return this;
}

bool LCD::isLeftButtonPressed() {
	int btns = lcdReadButtons(getFileFromPort());
	return (btns & LCD_BTN_LEFT) != 0;
}

bool LCD::isOnlyLeftButtonPressed() {
	int btns = lcdReadButtons(getFileFromPort());
	return (btns == LCD_BTN_LEFT);
}

bool LCD::isCenterButtonPressed() {
	int btns = lcdReadButtons(getFileFromPort());
	return (btns & LCD_BTN_CENTER) != 0;
}

bool LCD::isOnlyCenterButtonPressed() {
	int btns = lcdReadButtons(getFileFromPort());
	return (btns == LCD_BTN_CENTER);
}

bool LCD::isRightButtonPressed() {
	int btns = lcdReadButtons(getFileFromPort());
	return (btns & LCD_BTN_RIGHT) != 0;
}

bool LCD::isOnlyRightButtonPressed() {
	int btns = lcdReadButtons(getFileFromPort());
	return (btns == LCD_BTN_RIGHT);
}

LCD* LCD::setBacklight(bool backlight) {
	lcdSetBacklight(getFileFromPort(), backlight);
	return this;
}

LCD* LCD::enableBacklight() {
	lcdSetBacklight(getFileFromPort(), true);
	return this;
}

LCD* LCD::disableBacklight() {
	lcdSetBacklight(getFileFromPort(), false);
	return this;
}

LCD* LCD::clear() {
	lcdClear(getFileFromPort());
	return this;
}

LCD* LCD::displayString(short line, const string text) {
	lcdSetText(getFileFromPort(), line, text);
	return this;
}

LCD* LCD::displayFormattedString(short line, const string formatString, ...) {
	int size = 0;
	for (const char *cursor = formatString; *cursor != NULL; cursor++) {
		size++;
	}
	char line_chars[17];

	va_list arg;

	va_start(arg, formatString);
	{
		vsnprintf(line_chars, 17, formatString, arg);
	}
	va_end(arg);

	lcdSetText(getFileFromPort(), line, line_chars);
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
		char line_chars[17];
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
		line_chars[16] = '\0';
		lcdSetText(getFileFromPort(), line, line_chars);
	}
	return this;
}

LCD* LCD::displayFormattedCenteredString(short line, const string formatString,
		...) {
	int size = 0;
	for (const char *cursor = formatString; *cursor != NULL; cursor++) {
		size++;
	}
	char line_chars[17];

	va_list arg;

	va_start(arg, formatString);
	{
		vsnprintf(line_chars, 17, formatString, arg);
	}
	va_end(arg);
	displayCenteredString(line, line_chars);
	return this;
}

LCD* LCD::displayHorizontalNavigation(short line, string leftNavigationLabel,
		string rightNavigationLabel) {
	bool leftShortLabelNeedsMemFreed = false;
	bool rightShortLabelNeedsMemFreed = false;

	int leftLabelLength = strlen(leftNavigationLabel);
	int rightLabelLength = strlen(rightNavigationLabel);
	int totalLen = leftLabelLength + rightLabelLength;

	string shortenedLeftNavLabel;
	string shortenedRightNavLabel;
	int shortenedLength;

	//There are 16 chars on one LCD line
	//two of which will be occupied by arrows and there needs to be at least one space between the labels
	if (totalLen >= 14) {
		if (leftLabelLength >= 7) {
			leftShortLabelNeedsMemFreed = true;
			strsub(&shortenedLeftNavLabel, leftNavigationLabel, 0, 6);
		} else {
			shortenedLeftNavLabel = leftNavigationLabel;
		}

		if (rightLabelLength >= 7) {
			rightShortLabelNeedsMemFreed = true;
			strsub(&shortenedRightNavLabel, rightNavigationLabel, 0, 6);
		} else {
			shortenedRightNavLabel = rightNavigationLabel;
		}
	} else {
		shortenedLeftNavLabel = leftNavigationLabel;
		shortenedRightNavLabel = rightNavigationLabel;
	}

	shortenedLength = strlen(shortenedLeftNavLabel)
			+ strlen(shortenedRightNavLabel);

	int spacingLength = 14 - shortenedLength;
	char* spacing = (char*) allocateStringForNumberOfChars(spacingLength);
	for (int i = 0; i < spacingLength; i++) {
		spacing[i] = ' ';
	}
	spacing[spacingLength] = '\0';

	displayFormattedString(line, "%c%s%s%s%c", LCD_LEFT_TRIANGLE_ARROW,
			shortenedLeftNavLabel, spacing, shortenedRightNavLabel,
			LCD_RIGHT_TRIANGLE_ARROW);

	if (leftShortLabelNeedsMemFreed) {
		delete[] shortenedLeftNavLabel;
	}
	if (rightShortLabelNeedsMemFreed) {
		delete[] shortenedLeftNavLabel;
	}
	delete[] spacing;
	return this;
}

LCD* LCD::displayLeftNavigation(short line, string leftNavigationLabel) {
	bool leftShortLabelNeedsMemFreed = false;

	int leftLabelLength = strlen(leftNavigationLabel);

	string shortenedLeftNavLabel;
	int shortenedLength;

	//There are 16 chars on one LCD line
	//two of which will be occupied by arrows and there needs to be at least one space between the labels
	if (leftLabelLength >= 16) {
		leftShortLabelNeedsMemFreed = true;
		strsub(&shortenedLeftNavLabel, leftNavigationLabel, 0, 15);
	} else {
		shortenedLeftNavLabel = leftNavigationLabel;
	}

	shortenedLength = strlen(shortenedLeftNavLabel);

	int spacingLength = 15 - shortenedLength;
	char* spacing = (char*) allocateStringForNumberOfChars(spacingLength);
	for (int i = 0; i < spacingLength; i++) {
		spacing[i] = ' ';
	}
	spacing[spacingLength] = '\0';

	displayFormattedString(line, "%c%s%s%", LCD_LEFT_TRIANGLE_ARROW,
			shortenedLeftNavLabel, spacing);

	if (leftShortLabelNeedsMemFreed) {
		delete[] shortenedLeftNavLabel;
	}
	delete[] spacing;
	return this;
}

LCD* LCD::displayRightNavigation(short line, string rightNavigationLabel) {
	bool rightShortLabelNeedsMemFreed = false;

	int rightLabelLength = strlen(rightNavigationLabel);

	string shortenedRightNavLabel;
	int shortenedLength;

	//There are 16 chars on one LCD line
	//two of which will be occupied by arrows and there needs to be at least one space between the labels
	if (rightLabelLength >= 16) {
		rightShortLabelNeedsMemFreed = true;
		strsub(&shortenedRightNavLabel, rightNavigationLabel, 0, 15);
	} else {
		shortenedRightNavLabel = rightNavigationLabel;
	}

	shortenedLength = strlen(shortenedRightNavLabel);

	int spacingLength = 15 - shortenedLength;
	char* spacing = (char*) allocateStringForNumberOfChars(spacingLength);
	for (int i = 0; i < spacingLength; i++) {
		spacing[i] = ' ';
	}
	spacing[spacingLength] = '\0';

	displayFormattedString(line, "%s%s%c", spacing, shortenedRightNavLabel,
			LCD_RIGHT_TRIANGLE_ARROW);

	if (rightShortLabelNeedsMemFreed) {
		delete[] shortenedRightNavLabel;
	}
	delete[] spacing;
	return this;
}

LCD* LCD::displayDownNavigation(short line, string labelText) {
	bool shortLabelTextNeedsMemFreed = false;
	string shortenedLabelText;
	int len = strlen(labelText);
	if (len > 14) {
		strsub(&shortenedLabelText, labelText, 0, 14);
	} else {
		shortenedLabelText = labelText;
	}
	displayFormattedCenteredString(line, "%c%s%c", LCD_DOWN_TRIANGLE_ARROW,
			shortenedLabelText, LCD_DOWN_TRIANGLE_ARROW);
	if (shortLabelTextNeedsMemFreed) {
		delete[] shortenedLabelText;
	}
	return this;
}

LCD* LCD::displayMainBatteryStatus(short line) {
	displayFormattedCenteredString(line, "Main: %.2fV", getMainBatteryPower());
	return this;
}

} /* namespace TRL */
