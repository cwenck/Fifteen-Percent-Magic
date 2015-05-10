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

void LCDAutonScreenArray::initArrayScreens() {
	Array<AutonRoutine*>* allRoutines;
	if (returnAllScreens) {
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
	generateArray();
}

void LCDAutonScreenArray::setRobotStartLocation(RobotStartLocation location) {
	currentlySelectedStartLocation = location;
	generateArray();
}

void LCDAutonScreenArray::shouldArrayGenerateAllScreens(
		bool shouldGenerateAllScreens) {
	this->returnAllScreens = shouldGenerateAllScreens;
}

LCDMenuScreen* LCDAutonScreenArray::getArrayStartScreen() {
	return this->at(0);
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
	this->actionScreen = new LCDAutonActionScreen(routine);
	this->actionScreen->setReferencedScreens(homeScreen, actionScreen,
			actionScreen, actionScreen);
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

void LCDAutonArrayIndexScreen::setDisplayLCD(LCD* lcd) {
	this->lcd = lcd;
	this->actionScreen->setDisplayLCD(lcd);
}

void LCDAutonArrayIndexScreen::setReferencedScreens(LCDMenuScreen* homeScreen,
		LCDMenuScreen* leftScreen, LCDMenuScreen* enterScreen,
		LCDMenuScreen* rightScreen){
	this->homeScreen = homeScreen;
	this->actionScreen->setHomeScreen(homeScreen);
	this->leftScreen = leftScreen;
	this->enterScreen = enterScreen;
	this->rightScreen = rightScreen;
}

void LCDAutonArrayIndexScreen::setHomeScreen(LCDMenuScreen* homeScreen) {
	this->homeScreen = homeScreen;
	this->actionScreen->setHomeScreen(homeScreen);
}

LCDMenuScreen* LCDAutonArrayIndexScreen::onShortCenterButtonPress() {
	return actionScreen;
}
} /* namespace TRL */
