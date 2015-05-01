/*
 * LCDMainMotorScreen.cpp
 *
 *  Created on: May 1, 2015
 *      Author: guywenck
 */

#include "LCD/LCDMainMotorScreen.h"

namespace TRL {

LCDMainMotorScreen::LCDMainMotorScreen() {
	// TODO Auto-generated constructor stub

}

LCDMainMotorScreen::~LCDMainMotorScreen() {
	// TODO Auto-generated destructor stub
}

void LCDMainMotorScreen::display(){
	lcd->displayHorizontalNavigation(1, "Sensor", "Battery");
	lcd->displayDownNavigation(2, "Motors");
}

} /* namespace TRL */
