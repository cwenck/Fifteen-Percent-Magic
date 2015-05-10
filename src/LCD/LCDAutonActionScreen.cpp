/*
 * AutonActionScreen.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: guywenck
 */

#include "LCD/LCDAutonActionScreen.h"

namespace TRL {

LCDAutonActionScreen::LCDAutonActionScreen() {
	this->routine = NULL;
	running = false;
}

LCDAutonActionScreen::LCDAutonActionScreen(AutonRoutine* routine) {
	this->routine = routine;
	running = false;
}

void LCDAutonActionScreen::setRoutine(AutonRoutine* routine) {
	this->routine = routine;
}

void LCDAutonActionScreen::display() {
	lcd->displayCenteredString(1, routine->getRoutineName());
	if (!routine->isRunning()) {
		lcd->displayDownNavigation(2, "Execute");
	} else {
		lcd->displayCenteredString(2, "Running...");
	}
}

LCDMenuScreen* LCDAutonActionScreen::onShortCenterButtonPress() {
	AutonRegistry::setActiveRoutine(routine);
	return this;
}

} /* namespace TRL */
