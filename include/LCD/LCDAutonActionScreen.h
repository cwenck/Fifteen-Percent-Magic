/*
 * AutonActionScreen.h
 *
 *  Created on: Apr 19, 2015
 *      Author: guywenck
 */

#ifndef LCDAUTONACTIONSCREEN_H_
#define LCDAUTONACTIONSCREEN_H_

#include "LCDChildMenuScreenIncludes.h"
#include "../Robot/AutonRoutine.h"

namespace TRL {
	class LCDAutonActionScreen : public LCDMenuScreen {
	private:
		AutonRoutine* routine;

		bool running;
	public:
		LCDAutonActionScreen();
		LCDAutonActionScreen(AutonRoutine* routine);
		virtual ~LCDAutonActionScreen() {}

		void setRoutine(AutonRoutine* rountine);

		void display();

		LCDMenuScreen* onShortCenterButtonPress();
	};
}
#endif /* LCDAUTONACTIONSCREEN_H_ */
