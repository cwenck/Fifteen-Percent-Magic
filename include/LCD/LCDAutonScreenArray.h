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

	class LCDAutonScreenArray : public LCDScreenArray{
	private:
		AllianceColor currentlySelectedColor;
		RobotStartLocation currentlySelectedStartLocation;

		bool returnAllScreens;

	public:
		LCDAutonScreenArray();
		LCDAutonScreenArray(LCDMenuScreen* homeScreen, bool loopScreens);
		LCDAutonScreenArray(LCDMenuScreen* homeScreen, bool loopScreens, bool shouldGenerateAllScreens);
		~LCDAutonScreenArray(){}

		void setAllianceColor(AllianceColor color);
		void setRobotStartLocation(RobotStartLocation location);

		void shouldArrayGenerateAllScreens(bool shouldGenerateAllScreens);
		void populateArrayWithScreens();
	};

	class LCDAutonArrayIndexScreen : public LCDMenuScreen {
	private:

		AutonRoutine* routine;
		LCDAutonActionScreen* actionScreen;

//		static Array<LCDAutonArrayIndexScreen*>* getSpecificAutonScreens(LCDMenuScreen* homeScreen, bool loopScreens, AllianceColor color, RobotStartLocation location);
	public:
		LCDAutonArrayIndexScreen();
		LCDAutonArrayIndexScreen(AutonRoutine* routine);
		virtual ~LCDAutonArrayIndexScreen();

		void display();
		void setRoutine(AutonRoutine* routine);

//		static void setAllianceColor(AllianceColor color);
//		static void setRobotStartLocation(RobotStartLocation location);

//		static Array<LCDAutonArrayIndexScreen*>* getSpecificAutonScreens(LCDMenuScreen* homeScreen, bool loopScreens, bool returnAllScreens);
//		static Array<LCDAutonArrayIndexScreen*>* getSpecificAutonScreens(LCDMenuScreen* homeScreen, bool loopScreens);
	};

}

#endif /* LCDSPECIFICAUTONSCREEN_H_ */
