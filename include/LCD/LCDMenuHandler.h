/*
 * LCDMenuHandler.h
 *
 *  Created on: Apr 6, 2015
 *      Author: guywenck
 */

#ifndef LCDMENUHANDLER_H_
#define LCDMENUHANDLER_H_

#include "../TRL/TRL_BaseInitialization.h"
#include "LCD_Includes.h"


#define LCD_LONG_PRESS_TIME_MILLIS 1000

namespace TRL {
//CRASHES AFTER ROUGHLY 3 MINUTES OF THE CORTEX BEING ON
//DOESN't AUTO RESET AFTER
//THINKING IT IS RUNNING OUT OF FREE MEMEMORY
//First CRASH 190000ms delay 20ms
//Second CRASH 56000ms delay 0ms
//Third CRASH
	class LCDMenuHandler {
	private:
		//List of all screens. They should all be pointers
		void initScreens();
		void initScreenRelationships(LCD *lcd);
		LCDMainAutonScreen* mainAutonScreen;
		LCDMainBatteryScreen* mainBatteryScreen;
		LCDMainSensorScreen* mainSensorScreen;

		//////////////////////////////////
		//Don't touch anthing below here//
		//////////////////////////////////

		LCD* lcd;
		LCDMenuScreen* currentScreen;

		bool running;
		TaskHandle taskHandle;
		static void run(void* nothingPassed);


		bool wasLeftPressed;
		bool isLeftPressed;
		bool wasLeftLongPressed;
		bool isLeftLongPressed;
		bool wasLeftJustNowLongPressed;
		bool wasShortLeftJustReleased;
		bool wasLongLeftJustReleased;
		int leftPressedAt;

		bool wasCenterPressed;
		bool isCenterPressed;
		bool wasCenterLongPressed;
		bool isCenterLongPressed;
		bool wasCenterJustNowLongPressed;
		bool wasShortCenterJustReleased;
		bool wasLongCenterJustReleased;
		int centerPressedAt;

		bool wasRightPressed;
		bool isRightPressed;
		bool wasRightLongPressed;
		bool isRightLongPressed;
		bool wasRightJustNowLongPressed;
		bool wasShortRightJustReleased;
		bool wasLongRightJustReleased;
		int rightPressedAt;

		void updateLCDButtonPresses();

	public:
		LCDMenuHandler();
		virtual ~LCDMenuHandler();

		//this will run in its own task
		void start(LCD* lcd);
		void stop();

		//this must be static for it to run in a task

	};
}

#endif /* LCDMENUHANDLER_H_ */
