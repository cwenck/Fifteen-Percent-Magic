/*
 * LCDAutonColorSelctionScreen.h
 *
 *  Created on: May 7, 2015
 *      Author: guywenck
 */

#ifndef LCDAUTONCOLORSELCTIONSCREENARRAY_H_
#define LCDAUTONCOLORSELCTIONSCREENARRAY_H_

#include "LCDChildMenuScreenIncludes.h"
#include "LCDAutonScreenArray.h"
#include "LCDAutonLocationSelctionScreenArray.h"

namespace TRL {
	class LCDAutonColorSelectionScreenArray : public LCDScreenArray {
	private:
		LCDAutonScreenArray* autonScreenArr;
		LCDAutonLocationSelctionScreenArray* autonLocArr;
		void initArrayScreens();
	public:
		LCDAutonColorSelectionScreenArray();
		LCDAutonColorSelectionScreenArray(LCDMenuScreen* homeScreen, LCDAutonScreenArray* autonScreenArr, LCDAutonLocationSelctionScreenArray* autonLocArr);
		~LCDAutonColorSelectionScreenArray() {}

		LCDMenuScreen* getArrayStartScreen();
	};

	class LCDAutonColorSelctionScreen : public LCDSelectionScreen<AllianceColor> {
	private:
		LCDAutonScreenArray* autonScreenArr;
		LCDAutonLocationSelctionScreenArray* autonLocArr;
	public:
		LCDAutonColorSelctionScreen();
		LCDAutonColorSelctionScreen(AllianceColor color, LCDAutonScreenArray* autonScreenArr, LCDAutonLocationSelctionScreenArray* autonLocArr);
		virtual ~LCDAutonColorSelctionScreen() {}

		LCDMenuScreen* onShortCenterButtonPress();

		static Array<LCDMenuScreen*> getAutonColorSelctionScreens();
	};

}
#endif /* LCDAUTONCOLORSELCTIONSCREENARRAY_H_ */
