/*
 * LCDAutonLocationSelctionScreenArray.h
 *
 *  Created on: May 9, 2015
 *      Author: guywenck
 */

#ifndef LCDAUTONLOCATIONSELCTIONSCREENARRAY_H_
#define LCDAUTONLOCATIONSELCTIONSCREENARRAY_H_

#include "LCDChildMenuScreenIncludes.h"
#include "LCDAutonScreenArray.h"

namespace TRL {
	class LCDAutonLocationSelctionScreenArray : public LCDScreenArray {
	private:
		LCDAutonScreenArray* autonScreenArr;

		void initArrayScreens();
	public:
		LCDAutonLocationSelctionScreenArray();
		LCDAutonLocationSelctionScreenArray(LCDMenuScreen* homeScreen, LCDAutonScreenArray* autonScreenArr);
		virtual ~LCDAutonLocationSelctionScreenArray(){}

		LCDMenuScreen* getArrayStartScreen();
	};

	class LCDAutonLocationSelctionIndexScreen : public LCDSelectionScreen<RobotStartLocation> {
	private:
		LCDAutonScreenArray* autonScreenArr;
	public:
		LCDAutonLocationSelctionIndexScreen();
		LCDAutonLocationSelctionIndexScreen(RobotStartLocation location, LCDAutonScreenArray* autonScreenArr);
		virtual ~LCDAutonLocationSelctionIndexScreen(){}

		LCDMenuScreen* onShortCenterButtonPress();
	};
}

#endif /* LCDAUTONLOCATIONSELCTIONSCREENARRAY_H_ */
