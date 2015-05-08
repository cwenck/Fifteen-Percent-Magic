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

	class LCDSpecificAutonScreen : public LCDMenuScreen {
	private:
		static AllianceColor currentlySelectedColor;
		static RobotStartLocation currentlySelectedStartLocation;

		AutonRoutine* routine;
		LCDAutonActionScreen* actionScreen;

		static Array<LCDSpecificAutonScreen*>* getSpecificAutonScreens(LCDMenuScreen* homeScreen, bool loopScreens, AllianceColor color, RobotStartLocation location);
	public:
		LCDSpecificAutonScreen();
		LCDSpecificAutonScreen(AutonRoutine* routine);
		virtual ~LCDSpecificAutonScreen();

		void display();
		void setRoutine(AutonRoutine* routine);

		static void setAllianceColor(AllianceColor color);
		static void setRobotStartLocation(RobotStartLocation location);

		static Array<LCDSpecificAutonScreen*>* getSpecificAutonScreens(LCDMenuScreen* homeScreen, bool loopScreens, bool returnAllScreens);
		static Array<LCDSpecificAutonScreen*>* getSpecificAutonScreens(LCDMenuScreen* homeScreen, bool loopScreens);
	};

}

#endif /* LCDSPECIFICAUTONSCREEN_H_ */
