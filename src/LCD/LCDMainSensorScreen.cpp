/*
 * LCDSensorMainScreen.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: cwenck
 */

#include "LCD/LCDMainSensorScreen.h"

namespace TRL {

LCDMainSensorScreen::LCDMainSensorScreen() {
	// TODO Auto-generated constructor stub

}

LCDMainSensorScreen::~LCDMainSensorScreen() {
	// TODO Auto-generated destructor stub
}

void LCDMainSensorScreen::display(LCD* lcd) {
	lcd->displayHorizontalNavigation(1, "Auton", "Battery");
	lcd->displayDownNavigation(2, "Sensors");
}

} /* namespace TRL */
