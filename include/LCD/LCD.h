/*
 * LCD.h
 *
 *  Created on: Apr 2, 2015
 *      Author: guywenck
 */

#ifndef LCD_H_
#define LCD_H_

#include "../TRL/TRL_BaseIncludes.h"

//LCD Special Character Constants
#define LCD_DOWN_TRIANGLE_ARROW 0xF5
#define LCD_LEFT_TRIANGLE_ARROW 0xF7
#define LCD_RIGHT_TRIANGLE_ARROW 0xF6

#define LCD_LEFT_DOUBLE_ARROW 0xBB
#define LCD_RIGHT_DOUBLE_ARROW 0xBC

#define LCD_UP_ARROW 0xC5
#define LCD_DOWN_ARROW 0xC6
#define LCD_RIGHT_ARROW 0xC7
#define LCD_LEFT_ARROW 0xC8

namespace TRL {

	class LCD {
	private:
		LCDPort port;

		PROS_File getFileFromPort();
	public:
		LCD();
		LCD(LCDPort port);
		virtual ~LCD();

		static LCD instance;
		static void initStatics();

		bool isLeftButtonPressed();
		bool isCenterButtonPressed();
		bool isRightButtonPressed();

		bool isOnlyLeftButtonPressed();
		bool isOnlyCenterButtonPressed();
		bool isOnlyRightButtonPressed();

		LCD* setPort(LCDPort port);

		LCD* setBacklight(bool backlight);
		LCD* enableBacklight();
		LCD* disableBacklight();

		LCD* clear();

		LCD* displayString(short line, const string text);
		LCD* displayFormattedString(short line, const string formatString, ...);
		LCD* displayCenteredString(short line, const string text);
		LCD* displayFormattedCenteredString(short line,
				const string formatString, ...);

		LCD* displayHorizontalNavigation(short line, string leftNavigationLabel, string rightNavigationLabel);
		LCD* displayLeftNavigation(short line, string leftNavigationLabel);
		LCD* displayRightNavigation(short line, string rightNavigationLabel);
		LCD* displayDownNavigation(short line, string labelText);

		LCD* displayMainBatteryStatus(short line);
	};

}

#endif /* LCD_H_ */
