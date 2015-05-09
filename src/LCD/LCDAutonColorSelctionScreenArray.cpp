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
	this->autonScreenArr = NULL;
	this->autonLocArr = NULL;
}

LCDAutonColorSelectionScreenArray::LCDAutonColorSelectionScreenArray(
		LCDMenuScreen* homeScreen, LCDAutonScreenArray* autonScreenArr,
		LCDAutonLocationSelctionScreenArray* autonLocArr) :
		LCDScreenArray() {
	this->autonScreenArr = autonScreenArr;
	this->autonLocArr = autonLocArr;
	generateArray(homeScreen, true);
}

void LCDAutonColorSelectionScreenArray::initArrayScreens() {
	this->reinitWithNewSize(2);
	this->at(0) = new LCDAutonColorSelctionScreen(RED, autonScreenArr, autonLocArr);
	this->at(1) = new LCDAutonColorSelctionScreen(BLUE, autonScreenArr, autonLocArr);
}

LCDMenuScreen* LCDAutonColorSelectionScreenArray::getArrayStartScreen() {
	return this->at(0);
}

/////////////////////////////////////////
//END LCDAutonColorSelectionScreenArray//
/////////////////////////////////////////

LCDAutonColorSelctionScreen::LCDAutonColorSelctionScreen() {
	this->autonScreenArr = NULL;
	this->autonLocArr = NULL;
}

LCDAutonColorSelctionScreen::LCDAutonColorSelctionScreen(AllianceColor color,
		LCDAutonScreenArray* autonScreenArr,
		LCDAutonLocationSelctionScreenArray* autonLocArr) :
		LCDSelectionScreen<AllianceColor>(color) {
	setSelectionDisplayName(getStringForAllianceColor(color));
	this->autonScreenArr = autonScreenArr;
	this->autonLocArr = autonLocArr;
}

LCDMenuScreen* LCDAutonColorSelctionScreen::onShortCenterButtonPress() {
	autonScreenArr->setAllianceColor(selectionReturnValue);

	if (autonLocArr->size() != 0) {
		return autonLocArr->getArrayStartScreen();
	} else {
		return enterScreen;
	}
}

} /* namespace TRL */
