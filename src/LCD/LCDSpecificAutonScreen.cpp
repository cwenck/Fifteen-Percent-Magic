/*
 * LCDSpecificAutonScreen.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: guywenck
 */

#include "LCD/LCDSpecificAutonScreen.h"

namespace TRL {

AllianceColor LCDSpecificAutonScreen::currentlySelectedColor;
RobotStartLocation LCDSpecificAutonScreen::currentlySelectedStartLocation;

LCDSpecificAutonScreen::LCDSpecificAutonScreen() {
	this->routine = NULL;
	this->actionScreen = NULL;
}

LCDSpecificAutonScreen::LCDSpecificAutonScreen(AutonRoutine* routine) {
	this->routine = routine;
	this->actionScreen = new LCDAutonActionScreen();
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
	lcd->displayDownNavigation(2, "Options");
}

void LCDSpecificAutonScreen::setAllianceColor(AllianceColor color){
	currentlySelectedColor = color;
}

void LCDSpecificAutonScreen::setRobotStartLocation(RobotStartLocation location){
	currentlySelectedStartLocation = location;
}

Array<LCDSpecificAutonScreen*>* LCDSpecificAutonScreen::getSpecificAutonScreens(
		LCDMenuScreen* homeScreen, bool loopScreens, bool returnAllScreens) {

	if (returnAllScreens) {
		Array<AutonRoutine*>* allRoutines = AutonRegistry::getRoutines();
		Array<LCDSpecificAutonScreen*>* screens = new Array<
				LCDSpecificAutonScreen*>(allRoutines->size());

		//Two for loops are needed so that the entire array can be initialized before
		//refrences to those elements are assigned
		for (int i = 0; i < screens->size(); i++) {
			screens->at(i) = new LCDSpecificAutonScreen(allRoutines->at(i));
		}

		for (int i = 0; i < screens->size(); i++) {
			if (loopScreens) {
				if (i == 0) {
					if (screens->size() == 1) {
						screens->at(0)->setReferencedScreens(homeScreen,
								screens->at(0), screens->at(0), screens->at(0));
					} else {
						screens->at(0)->setReferencedScreens(homeScreen,
								screens->at(screens->size() - 1),
								screens->at(0), screens->at(1));
					}
				} else if (i == (screens->size() - 1)) {
					screens->at(i)->setReferencedScreens(homeScreen,
							screens->at(i - 1), screens->at(i), screens->at(0));
				} else {
					screens->at(i)->setReferencedScreens(homeScreen,
							screens->at(i - 1), screens->at(i),
							screens->at(i + 1));
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
							screens->at(i - 1), screens->at(i),
							screens->at(i + 1));
				}
			}
		}

		return screens;
	}
	return getSpecificAutonScreens(homeScreen, loopScreens);
}

Array<LCDSpecificAutonScreen*>* LCDSpecificAutonScreen::getSpecificAutonScreens(
		LCDMenuScreen* homeScreen, bool loopScreens, AllianceColor color,
		RobotStartLocation location) {

	Array<AutonRoutine*>* allRoutines = AutonRegistry::getRoutines(color,
			location);
	Array<LCDSpecificAutonScreen*>* screens =
			new Array<LCDSpecificAutonScreen*>(allRoutines->size());

	//Two for loops are needed so that the entire array can be initialized before
	//refrences to those elements are assigned
	for (int i = 0; i < screens->size(); i++) {
		screens->at(i) = new LCDSpecificAutonScreen(allRoutines->at(i));
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
}

Array<LCDSpecificAutonScreen*>* LCDSpecificAutonScreen::getSpecificAutonScreens(
		LCDMenuScreen* homeScreen, bool loopScreens) {
	return getSpecificAutonScreens(homeScreen, loopScreens,
			currentlySelectedColor, currentlySelectedStartLocation);
}

} /* namespace TRL */
