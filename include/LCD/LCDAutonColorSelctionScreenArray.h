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

namespace TRL {
	class LCDAutonColorSelectionScreenArray : public LCDScreenArray {
	private:
		LCDAutonScreenArray* screenArr;
		void initArrayScreens();
	public:
		LCDAutonColorSelectionScreenArray();
		LCDAutonColorSelectionScreenArray(LCDMenuScreen* homeScreen, LCDAutonScreenArray* screenArr);
		~LCDAutonColorSelectionScreenArray() {}

		LCDMenuScreen* getArrayStartScreen();
	};

	class LCDAutonColorSelctionScreen : public LCDSelectionScreen<AllianceColor> {
	private:
		LCDAutonScreenArray* screenArr;
	public:
		LCDAutonColorSelctionScreen();
		LCDAutonColorSelctionScreen(AllianceColor color, LCDAutonScreenArray* screenArr);
		virtual ~LCDAutonColorSelctionScreen();

		LCDMenuScreen* onShortCenterButtonPress();

		static Array<LCDMenuScreen*> getAutonColorSelctionScreens();
	};

}
#endif /* LCDAUTONCOLORSELCTIONSCREENARRAY_H_ */
