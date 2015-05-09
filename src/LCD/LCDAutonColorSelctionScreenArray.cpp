/*
 * LCDAutonColorSelctionScreen.cpp
 *
 *  Created on: May 7, 2015
 *      Author: guywenck
 */

#include "LCD/LCDAutonColorSelctionScreenArray.h"

namespace TRL {

///////////////////////////////////////////
//START LCDAutonColorSelectionScreenArray//
///////////////////////////////////////////
LCDAutonColorSelectionScreenArray::LCDAutonColorSelectionScreenArray() :
		LCDScreenArray() {
	screenArr = NULL;
}

LCDAutonColorSelectionScreenArray::LCDAutonColorSelectionScreenArray(
		LCDMenuScreen* homeScreen, LCDAutonScreenArray* screenArr) :
		LCDScreenArray() {
	this->screenArr = screenArr;
	generateArray(homeScreen, true);
}

void LCDAutonColorSelectionScreenArray::initArrayScreens() {
	this->reinitWithNewSize(2);
	this->at(0) = new LCDAutonColorSelctionScreen(RED, screenArr);
	this->at(1) = new LCDAutonColorSelctionScreen(BLUE, screenArr);
}

LCDAutonColorSelctionScreen::LCDAutonColorSelctionScreen() {
	screenArr = NULL;
}

LCDMenuScreen* LCDAutonColorSelectionScreenArray::getArrayStartScreen() {
	return this->at(0);
}

/////////////////////////////////////////
//END LCDAutonColorSelectionScreenArray//
/////////////////////////////////////////

LCDAutonColorSelctionScreen::LCDAutonColorSelctionScreen(AllianceColor color,
		LCDAutonScreenArray* screenArr) :
		LCDSelectionScreen<AllianceColor>(color) {
	setSelectionDisplayName(getStringForAllianceColor(color));
	this->screenArr = screenArr;
}

LCDAutonColorSelctionScreen::~LCDAutonColorSelctionScreen() {
}

LCDMenuScreen* LCDAutonColorSelctionScreen::onShortCenterButtonPress() {
	screenArr->setAllianceColor(selectionReturnValue);
	if (screenArr != NULL && screenArr->size() != 0) {
		return screenArr->getArrayStartScreen();
	} else {
		return enterScreen;
	}
}

} /* namespace TRL */
