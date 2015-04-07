/*
 * LCDMainBatteryScreen.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: cwenck
 */

#include "LCD/LCDMainBatteryScreen.h"

namespace TRL {

LCDMainBatteryScreen::LCDMainBatteryScreen() {
}

LCDMainBatteryScreen::~LCDMainBatteryScreen() {
}

void LCDMainBatteryScreen::display(LCD* lcd){
	lcd->displayHorizontalNavigation(1, "Sensor", "Auton");
	lcd->displayDownNavigation(2, "Battery");
}

} /* namespace TRL */
