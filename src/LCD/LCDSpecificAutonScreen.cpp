/*
 * LCDSpecificAutonScreen.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: guywenck
 */

#include "LCD/LCDSpecificAutonScreen.h"

namespace TRL {

LCDSpecificAutonScreen::LCDSpecificAutonScreen() {
	this->routine = NULL;
	actionScreen = NULL;
}

LCDSpecificAutonScreen::LCDSpecificAutonScreen(AutonRoutine* routine) {
	this->routine = routine;
	actionScreen = new LCDAutonActionScreen();
}

LCDSpecificAutonScreen::~LCDSpecificAutonScreen() {
	if (actionScreen != NULL) {
		delete actionScreen;
	}
}

void LCDSpecificAutonScreen::setRoutine(AutonRoutine* routine) {
	this->routine = routine;
	actionScreen->setRoutine(routine);
}

void LCDSpecificAutonScreen::display() {
	lcd->displayCenteredString(1, routine->getRoutineName());
	lcd->displayHorizontalNavigation(2, "Prev", "Next");
}

Array<LCDSpecificAutonScreen*>* LCDSpecificAutonScreen::getSpecificAutonScreens(
		LCDMenuScreen* homeScreen, bool loopScreens, AllianceColor color,
		RobotStartLocation location) {
	//TODO finish getSpecificAutonScreens function


	/*

//	Array<AutonRoutin*>* allRoutines = AutonRegistry::g
	Array<LCDSpecificAutonScreen*>* screens = new Array<
			LCDSpecificAutonScreen*>();

	//Two for loops are needed so that the entire array can be initialized before
	//refrences to those elements are assigned
	for (int i = 0; i < screens->size(); i++) {
		screens->at(i) = new LCDSpecificSensorScreen(sensors->at(i));
	}

	for (int i = 0; i < screens->size(); i++) {
		if (loopScreens) {
			if (i == 0) {
				if (screens->size() == 1) {
					screens->at(0)->setReferencedScreens(homeScreen,
							screens->at(0), screens->at(0), screens->at(0));
				} else {
					screens->at(0)->setReferencedScreens(homeScreen,
							screens->at(screens->size() - 1), screens->at(0),
							screens->at(1));
				}
			} else if (i == (screens->size() - 1)) {
				screens->at(i)->setReferencedScreens(homeScreen,
						screens->at(i - 1), screens->at(i), screens->at(0));
			} else {
				screens->at(i)->setReferencedScreens(homeScreen,
						screens->at(i - 1), screens->at(i), screens->at(i + 1));
			}
		} else {
			if (i == 0) {
				if (screens->size() == 1) {
					screens->at(0)->setReferencedScreens(homeScreen,
							screens->at(0), screens->at(0), screens->at(0));
				} else {
					screens->at(0)->setReferencedScreens(homeScreen,
							screens->at(0), screens->at(0), screens->at(1));
				}
			} else if (i == (screens->size() - 1)) {
				screens->at(i)->setReferencedScreens(homeScreen,
						screens->at(i - 1), screens->at(i), screens->at(i));
			} else {
				screens->at(i)->setReferencedScreens(homeScreen,
						screens->at(i - 1), screens->at(i), screens->at(i + 1));
			}
		}
	}

	return screens;
	*/
	return NULL;
}

} /* namespace TRL */
