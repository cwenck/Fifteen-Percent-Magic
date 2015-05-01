/*
 * LCDSpecificAutonScreen.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: guywenck
 */

#include "LCD/LCDSpecificAutonScreen.h"

namespace TRL {

LCDSpecificAutonScreen::LCDSpecificAutonScreen() {
	routine = NULL;
	actionScreen = new LCDAutonActionScreen();
}

LCDSpecificAutonScreen::~LCDSpecificAutonScreen() {
	delete actionScreen;
}

void LCDSpecificAutonScreen::setRoutine(AutonRoutine* routine){
	this->routine = routine;
	actionScreen->setRoutine(routine);
}

void LCDSpecificAutonScreen::display(){
	lcd->displayCenteredString(1, routine->getRoutineName());
	lcd->displayHorizontalNavigation(2, "Prev", "Next");
}



} /* namespace TRL */
