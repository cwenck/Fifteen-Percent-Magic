/*
 * LCDSpecificAutonScreen.h
 *
 *  Created on: Apr 19, 2015
 *      Author: guywenck
 */

#ifndef LCDSPECIFICAUTONSCREEN_H_
#define LCDSPECIFICAUTONSCREEN_H_

#include "LCDChildMenuScreenIncludes.h"
#include "LCDAutonActionScreen.h"
#include "../Robot/AutonRegistry.h"
#include "../Robot/AutonRoutine.h"


namespace TRL {

	class LCDSpecificAutonScreen : LCDMenuScreen{
	private:
		AutonRoutine* routine;
		LCDAutonActionScreen* actionScreen;
	public:
		LCDSpecificAutonScreen();
		virtual ~LCDSpecificAutonScreen();

		void display();
		void setRoutine(AutonRoutine* routine);

		static LCDSpecificAutonScreen** getSpecificAutonScreens(LCDMenuScreen* homeScreen, bool loopScreens);
	};

}

#endif /* LCDSPECIFICAUTONSCREEN_H_ */
