/*
 * LCDAutonColorSelctionScreen.h
 *
 *  Created on: May 7, 2015
 *      Author: guywenck
 */

#ifndef LCDAUTONCOLORSELCTIONSCREEN_H_
#define LCDAUTONCOLORSELCTIONSCREEN_H_

#include "LCDChildMenuScreenIncludes.h"
#include "LCDAutonScreenArray.h"

namespace TRL {
	class LCDAutonColorSelctionScreen : public LCDSelectionScreen<AllianceColor> {
	private:
		AllianceColor tempAllianceColor;
	public:
		LCDAutonColorSelctionScreen();
		LCDAutonColorSelctionScreen(AllianceColor color);
		virtual ~LCDAutonColorSelctionScreen();

		LCDMenuScreen* onShortCenterButtonPress();

		static Array<LCDMenuScreen*> getAutonColorSelctionScreens();
	};
}
#endif /* LCDAUTONCOLORSELCTIONSCREEN_H_ */
