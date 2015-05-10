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

	class LCDAutonScreenArray : public LCDScreenArray {
	private:
		AllianceColor currentlySelectedColor;
		RobotStartLocation currentlySelectedStartLocation;

		bool returnAllScreens;

		void initArrayScreens();
	public:
		LCDAutonScreenArray();
		LCDAutonScreenArray(LCDMenuScreen* homeScreen, bool loopScreens);
		LCDAutonScreenArray(LCDMenuScreen* homeScreen, bool loopScreens, bool shouldGenerateAllScreens);
		~LCDAutonScreenArray() {}

		void setAllianceColor(AllianceColor color);
		void setRobotStartLocation(RobotStartLocation location);

		void shouldArrayGenerateAllScreens(bool shouldGenerateAllScreens);
		LCDMenuScreen* getArrayStartScreen();
	};

	class LCDAutonArrayIndexScreen : public LCDMenuScreen {
	private:

		AutonRoutine* routine;
		LCDAutonActionScreen* actionScreen;

	public:
		LCDAutonArrayIndexScreen();
		LCDAutonArrayIndexScreen(AutonRoutine* routine);
		virtual ~LCDAutonArrayIndexScreen();

		void display();
		void setRoutine(AutonRoutine* routine);

		void setDisplayLCD(LCD* lcd);
		void setReferencedScreens(LCDMenuScreen* homeScreen, LCDMenuScreen* leftScreen, LCDMenuScreen* enterScreen, LCDMenuScreen* rightScreen);
		void setHomeScreen(LCDMenuScreen* homeScreen);


		LCDMenuScreen* onShortCenterButtonPress();
	};

}

#endif /* LCDSPECIFICAUTONSCREEN_H_ */
