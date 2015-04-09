/*
 * LCDSensorMainScreen.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: cwenck
 */

#include "LCD/LCDMainSensorScreen.h"

namespace TRL {

LCDMainSensorScreen::LCDMainSensorScreen() {

}

LCDMainSensorScreen::~LCDMainSensorScreen() {
}

void LCDMainSensorScreen::display(LCD* lcd) {
	lcd->displayHorizontalNavigation(1, "Auton", "Battery");
	lcd->displayDownNavigation(2, "Sensors");
}

} /* namespace TRL */
