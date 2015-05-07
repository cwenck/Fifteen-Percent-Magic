/*
 * LCDMainMotorScreen.cpp
 *
 *  Created on: May 1, 2015
 *      Author: guywenck
 */

#include "LCD/LCDMainMotorScreen.h"

namespace TRL {

LCDMainMotorScreen::LCDMainMotorScreen() {

}

LCDMainMotorScreen::~LCDMainMotorScreen() {
}

void LCDMainMotorScreen::display(){
	lcd->displayHorizontalNavigation(1, "Sensor", "Battery");
	lcd->displayDownNavigation(2, "Motors");
}

} /* namespace TRL */
