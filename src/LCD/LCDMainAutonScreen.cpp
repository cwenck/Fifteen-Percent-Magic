/*
 * LCDHomeScreen.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: guywenck
 */

#include "LCD/LCDMainAutonScreen.h"

namespace TRL {

LCDMainAutonScreen::LCDMainAutonScreen() {
}

LCDMainAutonScreen::~LCDMainAutonScreen() {
}

void LCDMainAutonScreen::display(LCD* lcd) {
	lcd->displayHorizontalNavigation(1, "Battery", "Sensor");
	lcd->displayDownNavigation(2, "Autonomous");
}

} /* namespace TRL */
