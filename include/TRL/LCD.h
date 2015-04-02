/*
 * LCD.h
 *
 *  Created on: Apr 2, 2015
 *      Author: guywenck
 */

#ifndef LCD_H_
#define LCD_H_

#include "TRL_BaseInitialization.h"
#include "Util.h"

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

		void setPort(LCDPort port);

		bool isLeftButtonPressed();
		bool isCenterButtonPressed();
		bool isRightButtonPressed();
		void displayCenteredString(short line, const string text);
		void displayFormattedCenteredString(short line,
				const string formatString, ...);
		void displayBatteryStatus();
	};

}

#endif /* LCD_H_ */
