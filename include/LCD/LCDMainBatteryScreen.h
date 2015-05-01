/*
 * LCDMainBatteryScreen.h
 *
 *  Created on: Apr 7, 2015
 *      Author: cwenck
 */

#ifndef LCDMAINBATTERYSCREEN_H_
#define LCDMAINBATTERYSCREEN_H_

#include "LCDChildMenuScreenIncludes.h"

namespace TRL {
	class LCDMainBatteryScreen : public LCDMenuScreen {
	public:
		LCDMainBatteryScreen();
		virtual ~LCDMainBatteryScreen();

		void display();
	};
}

#endif /* LCDMAINBATTERYSCREEN_H_ */
