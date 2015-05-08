/*
 * LCDAutonColorSelctionScreen.cpp
 *
 *  Created on: May 7, 2015
 *      Author: guywenck
 */

#include "LCD/LCDAutonColorSelctionScreen.h"

namespace TRL {

LCDAutonColorSelctionScreen::LCDAutonColorSelctionScreen() {
	tempAllianceColor = RED;
}

LCDAutonColorSelctionScreen::LCDAutonColorSelctionScreen(AllianceColor color) :
		LCDSelectionScreen<AllianceColor>(&tempAllianceColor, color) {
	setSelectionDisplayName(getStringForAllianceColor(color));
}

LCDAutonColorSelctionScreen::~LCDAutonColorSelctionScreen() {
}

LCDMenuScreen* LCDAutonColorSelctionScreen::onShortCenterButtonPress() {
	(*returnLocation) = selectionReturnValue;
	LCDSpecificAutonScreen::setAllianceColor(selectionReturnValue);
	return enterScreen;
}
} /* namespace TRL */
