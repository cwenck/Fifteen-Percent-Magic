/*
 * LCDAutonLocationSelctionScreenArray.cpp
 *
 *  Created on: May 9, 2015
 *      Author: guywenck
 */

#include "LCD/LCDAutonLocationSelctionScreenArray.h"

namespace TRL {

LCDAutonLocationSelctionScreenArray::LCDAutonLocationSelctionScreenArray() {
	this->autonScreenArr = NULL;
}

LCDAutonLocationSelctionScreenArray::LCDAutonLocationSelctionScreenArray(
		LCDMenuScreen* homeScreen,
		LCDAutonScreenArray* autonScreenArr) {
	this->autonScreenArr = autonScreenArr;
	generateArray(homeScreen, true);
}

void LCDAutonLocationSelctionScreenArray::initArrayScreens() {
	reinitWithNewSize(2);
	this->at(0) = new LCDAutonLocationSelctionIndexScreen(INNER_TILE,
			autonScreenArr);
	this->at(1) = new LCDAutonLocationSelctionIndexScreen(OUTER_TILE,
			autonScreenArr);
}

LCDMenuScreen* LCDAutonLocationSelctionScreenArray::getArrayStartScreen(){
	return this->at(0);
}

////////////////////////////////////////////
//END LCDAutonLocationSelctionScreenArray//
////////////////////////////////////////////

LCDAutonLocationSelctionIndexScreen::LCDAutonLocationSelctionIndexScreen() {
	this->autonScreenArr = NULL;
}

LCDAutonLocationSelctionIndexScreen::LCDAutonLocationSelctionIndexScreen(
		RobotStartLocation location, LCDAutonScreenArray* autonScreenArr) :
		LCDSelectionScreen(location) {
	this->autonScreenArr = autonScreenArr;
	setSelectionDisplayName(getStringForRobotStartLocation(location));
}

LCDMenuScreen* LCDAutonLocationSelctionIndexScreen::onShortCenterButtonPress() {
	autonScreenArr->setRobotStartLocation(selectionReturnValue);
	if (autonScreenArr->size() != 0) {
		return autonScreenArr->getArrayStartScreen();
	} else {
		return enterScreen;
	}
}

} /* namespace TRL */
