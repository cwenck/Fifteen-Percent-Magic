/*
 * AutonActionScreen.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: guywenck
 */

#include "LCD/LCDAutonActionScreen.h"

namespace TRL {

void LCDAutonActionScreen::setRoutine(AutonRoutine* routine){
	this->routine = routine;
}

void LCDAutonActionScreen::display() {
	lcd->displayCenteredString(1, routine->getRoutineName());
	lcd->displayDownNavigation(2, "Run");
}

LCDMenuScreen* LCDAutonActionScreen::onShortCenterButtonPress(){

	return this;
}

} /* namespace TRL */
