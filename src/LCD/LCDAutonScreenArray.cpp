/*
 * LCDSpecificAutonScreen.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: guywenck
 */

#include "LCD/LCDAutonScreenArray.h"

namespace TRL {

/////////////////////////////
//START LCDAutonScreenArray//
/////////////////////////////

LCDAutonScreenArray::LCDAutonScreenArray() :
		LCDScreenArray() {
	returnAllScreens = false;
	currentlySelectedColor = RED;
	currentlySelectedStartLocation = OUTER_TILE;
}

LCDAutonScreenArray::LCDAutonScreenArray(LCDMenuScreen* homeScreen,
		bool loopScreens) :
		LCDScreenArray() {
	this->returnAllScreens = false;
	this->currentlySelectedColor = RED;
	this->currentlySelectedStartLocation = OUTER_TILE;
	generateArray(homeScreen, loopScreens);
}

LCDAutonScreenArray::LCDAutonScreenArray(LCDMenuScreen* homeScreen,
		bool loopScreens, bool shouldGenerateAllScreens) :
		LCDScreenArray() {
	this->returnAllScreens = shouldGenerateAllScreens;
	this->currentlySelectedColor = RED;
	this->currentlySelectedStartLocation = OUTER_TILE;
	generateArray(homeScreen, loopScreens);
}

void LCDAutonScreenArray::populateArrayWithScreens() {
	Array<AutonRoutine*>* allRoutines;
	if (!returnAllScreens) {
		allRoutines = AutonRegistry::getRoutines();
	} else {
		allRoutines = AutonRegistry::getRoutines(currentlySelectedColor,
				currentlySelectedStartLocation);
	}

	reinitWithNewSize(allRoutines->size());

	//Two for loops are needed so that the entire array can be initialized before
	//refrences to those elements are assigned
	for (int i = 0; i < this->size(); i++) {
		this->at(i) = new LCDAutonArrayIndexScreen(allRoutines->at(i));
	}
	delete allRoutines;
}

void LCDAutonScreenArray::setAllianceColor(AllianceColor color) {
	currentlySelectedColor = color;
}

void LCDAutonScreenArray::setRobotStartLocation(RobotStartLocation location) {
	currentlySelectedStartLocation = location;
}

void LCDAutonScreenArray::shouldArrayGenerateAllScreens(
		bool shouldGenerateAllScreens) {
	this->returnAllScreens = shouldGenerateAllScreens;
}

///////////////////////////
//END LCDAutonScreenArray//
///////////////////////////

LCDAutonArrayIndexScreen::LCDAutonArrayIndexScreen() {
	this->routine = NULL;
	this->actionScreen = NULL;
}

LCDAutonArrayIndexScreen::LCDAutonArrayIndexScreen(AutonRoutine* routine) {
	this->routine = routine;
	this->actionScreen = new LCDAutonActionScreen();
}

LCDAutonArrayIndexScreen::~LCDAutonArrayIndexScreen() {
	if (actionScreen != NULL) {
		delete actionScreen;
	}
}

void LCDAutonArrayIndexScreen::setRoutine(AutonRoutine* routine) {
	this->routine = routine;
	actionScreen->setRoutine(routine);
}

void LCDAutonArrayIndexScreen::display() {
	lcd->displayCenteredString(1, routine->getRoutineName());
	lcd->displayDownNavigation(2, "Options");
}

//Array<LCDAutonArrayIndexScreen*>* LCDAutonArrayIndexScreen::getSpecificAutonScreens(
//		LCDMenuScreen* homeScreen, bool loopScreens, bool returnAllScreens) {
//
//	if (returnAllScreens) {
//		Array<AutonRoutine*>* allRoutines = AutonRegistry::getRoutines();
//		Array<LCDAutonArrayIndexScreen*>* screens = new Array<
//				LCDAutonArrayIndexScreen*>(allRoutines->size());
//
//		//Two for loops are needed so that the entire array can be initialized before
//		//refrences to those elements are assigned
//		for (int i = 0; i < screens->size(); i++) {
//			screens->at(i) = new LCDAutonArrayIndexScreen(allRoutines->at(i));
//		}
//
//		for (int i = 0; i < screens->size(); i++) {
//			if (loopScreens) {
//				if (i == 0) {
//					if (screens->size() == 1) {
//						screens->at(0)->setReferencedScreens(homeScreen,
//								screens->at(0), screens->at(0), screens->at(0));
//					} else {
//						screens->at(0)->setReferencedScreens(homeScreen,
//								screens->at(screens->size() - 1),
//								screens->at(0), screens->at(1));
//					}
//				} else if (i == (screens->size() - 1)) {
//					screens->at(i)->setReferencedScreens(homeScreen,
//							screens->at(i - 1), screens->at(i), screens->at(0));
//				} else {
//					screens->at(i)->setReferencedScreens(homeScreen,
//							screens->at(i - 1), screens->at(i),
//							screens->at(i + 1));
//				}
//			} else {
//				if (i == 0) {
//					if (screens->size() == 1) {
//						screens->at(0)->setReferencedScreens(homeScreen,
//								screens->at(0), screens->at(0), screens->at(0));
//					} else {
//						screens->at(0)->setReferencedScreens(homeScreen,
//								screens->at(0), screens->at(0), screens->at(1));
//					}
//				} else if (i == (screens->size() - 1)) {
//					screens->at(i)->setReferencedScreens(homeScreen,
//							screens->at(i - 1), screens->at(i), screens->at(i));
//				} else {
//					screens->at(i)->setReferencedScreens(homeScreen,
//							screens->at(i - 1), screens->at(i),
//							screens->at(i + 1));
//				}
//			}
//		}
//
//		return screens;
//	}
//	return getSpecificAutonScreens(homeScreen, loopScreens);
//}
//
//Array<LCDAutonArrayIndexScreen*>* LCDAutonArrayIndexScreen::getSpecificAutonScreens(
//		LCDMenuScreen* homeScreen, bool loopScreens, AllianceColor color,
//		RobotStartLocation location) {
//
//	Array<AutonRoutine*>* allRoutines = AutonRegistry::getRoutines(color,
//			location);
//	Array<LCDAutonArrayIndexScreen*>* screens =
//			new Array<LCDAutonArrayIndexScreen*>(allRoutines->size());
//
//	//Two for loops are needed so that the entire array can be initialized before
//	//refrences to those elements are assigned
//	for (int i = 0; i < screens->size(); i++) {
//		screens->at(i) = new LCDAutonArrayIndexScreen(allRoutines->at(i));
//	}
//
//	for (int i = 0; i < screens->size(); i++) {
//		if (loopScreens) {
//			if (i == 0) {
//				if (screens->size() == 1) {
//					screens->at(0)->setReferencedScreens(homeScreen,
//							screens->at(0), screens->at(0), screens->at(0));
//				} else {
//					screens->at(0)->setReferencedScreens(homeScreen,
//							screens->at(screens->size() - 1), screens->at(0),
//							screens->at(1));
//				}
//			} else if (i == (screens->size() - 1)) {
//				screens->at(i)->setReferencedScreens(homeScreen,
//						screens->at(i - 1), screens->at(i), screens->at(0));
//			} else {
//				screens->at(i)->setReferencedScreens(homeScreen,
//						screens->at(i - 1), screens->at(i), screens->at(i + 1));
//			}
//		} else {
//			if (i == 0) {
//				if (screens->size() == 1) {
//					screens->at(0)->setReferencedScreens(homeScreen,
//							screens->at(0), screens->at(0), screens->at(0));
//				} else {
//					screens->at(0)->setReferencedScreens(homeScreen,
//							screens->at(0), screens->at(0), screens->at(1));
//				}
//			} else if (i == (screens->size() - 1)) {
//				screens->at(i)->setReferencedScreens(homeScreen,
//						screens->at(i - 1), screens->at(i), screens->at(i));
//			} else {
//				screens->at(i)->setReferencedScreens(homeScreen,
//						screens->at(i - 1), screens->at(i), screens->at(i + 1));
//			}
//		}
//	}
//
//	return screens;
//}
//
//Array<LCDAutonArrayIndexScreen*>* LCDAutonArrayIndexScreen::getSpecificAutonScreens(
//		LCDMenuScreen* homeScreen, bool loopScreens) {
//	return getSpecificAutonScreens(homeScreen, loopScreens,
//			currentlySelectedColor, currentlySelectedStartLocation);
//}

} /* namespace TRL */
