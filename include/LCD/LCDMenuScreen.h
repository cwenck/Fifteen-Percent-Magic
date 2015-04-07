/*
 * LCDMenuScreen.h
 *
 *  Created on: Apr 6, 2015
 *      Author: guywenck
 */

#ifndef LCDMENUSCREEN_H_
#define LCDMENUSCREEN_H_

#include "../TRL/TRL_BaseInitialization.h"
#include "LCD.h"

#define NO_SCREEN 0

namespace TRL {
	class LCDMenuScreen {
	protected:
		LCDMenuScreen* homeScreen;
		LCDMenuScreen* leftScreen;
		LCDMenuScreen* enterScreen;
		LCDMenuScreen* rightScreen;
	public:
		LCDMenuScreen();
		virtual ~LCDMenuScreen();

		void setReferencedScreens(LCDMenuScreen* homeScreen, LCDMenuScreen* leftScreen, LCDMenuScreen* enterScreen, LCDMenuScreen* rightScreen);

		bool hasLeftScreen();
		bool hasEnterScreen();
		bool hasRightScreen();

		LCDMenuScreen* getLeftScreen();
		LCDMenuScreen* getEnterScreen();
		LCDMenuScreen* getRightScreen();

		virtual void display(LCD* lcd) = 0;

		//return this if you wish to stay on the current menu screen
		//override these functions in the child class to alter their functionality
		//they will automatically get called by the LCDMenuHandler Class
		LCDMenuScreen* onShortLeftButtonPress();
		LCDMenuScreen* onShortCenterButtonPress();
		LCDMenuScreen* onShortRightButtonPress();

		LCDMenuScreen* onLongLeftButtonPress();
		LCDMenuScreen* onLongCenterButtonPress();
		LCDMenuScreen* onLongRightButtonPress();
	};
}

#endif /* LCDMENUSCREEN_H_ */
