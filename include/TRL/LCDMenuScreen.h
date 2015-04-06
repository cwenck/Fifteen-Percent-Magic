/*
 * LCDMenuScreen.h
 *
 *  Created on: Apr 6, 2015
 *      Author: guywenck
 */

#ifndef LCDMENUSCREEN_H_
#define LCDMENUSCREEN_H_

#include "TRL_BaseInitialization.h"
#include "LCD.h"

#define NO_SCREEN 0

namespace TRL {
	class LCDMenuScreen {
	public:
		LCDMenuScreen();
		LCDMenuScreen(LCDMenuScreen* leftScreen, LCDMenuScreen* enterScreen, LCDMenuScreen* rightScreen);
		virtual ~LCDMenuScreen();

		virtual void display(LCD* lcd) = 0;
	};
}

#endif /* LCDMENUSCREEN_H_ */
