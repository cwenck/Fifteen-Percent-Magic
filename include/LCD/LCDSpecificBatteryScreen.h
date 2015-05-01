/*
 * LCDSpecificBatteryScreen.h
 *
 *  Created on: Apr 8, 2015
 *      Author: cwenck
 */

#ifndef LCDSPECIFICBATTERYSCREEN_H_
#define LCDSPECIFICBATTERYSCREEN_H_

#include "LCDChildMenuScreenIncludes.h"

namespace TRL {

	class LCDSpecificBatteryScreen : public LCDMenuScreen {
	private:
		BatteryType battery;
	public:
		LCDSpecificBatteryScreen();
		virtual ~LCDSpecificBatteryScreen();

		void setBattry(BatteryType type);
		void display();

		static LCDSpecificBatteryScreen** getSpecificBatteryScreens(LCDMenuScreen* homeScreen, bool loopScreens);
	};

}

#endif /* LCDSPECIFICBATTERYSCREEN_H_ */
