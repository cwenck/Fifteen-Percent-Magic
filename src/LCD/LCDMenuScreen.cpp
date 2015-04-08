/*
 * LCDMenuScreen.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: guywenck
 */

#include "LCD/LCDMenuScreen.h"

namespace TRL {

LCDMenuScreen::LCDMenuScreen() {
	this->homeScreen = NO_SCREEN;
	this->leftScreen = NO_SCREEN;
	this->enterScreen = NO_SCREEN;
	this->rightScreen = NO_SCREEN;
}

LCDMenuScreen::~LCDMenuScreen() {

}

void LCDMenuScreen::setReferencedScreens(LCDMenuScreen* homeScreen,
		LCDMenuScreen* leftScreen, LCDMenuScreen* enterScreen,
		LCDMenuScreen* rightScreen) {
	this->homeScreen = homeScreen;
	this->leftScreen = leftScreen;
	this->enterScreen = enterScreen;
	this->rightScreen = rightScreen;
}

bool LCDMenuScreen::hasLeftScreen() {
	if (leftScreen == NO_SCREEN) {
		return false;
	}
	return true;
}

bool LCDMenuScreen::hasEnterScreen() {
	if (enterScreen == NO_SCREEN) {
		return false;
	}
	return true;
}

bool LCDMenuScreen::hasRightScreen() {
	if (rightScreen == NO_SCREEN) {
		return false;
	}
	return true;
}



LCDMenuScreen* LCDMenuScreen::getLeftScreen() {
	return leftScreen;
}

LCDMenuScreen* LCDMenuScreen::getEnterScreen() {
	return enterScreen;
}

LCDMenuScreen* LCDMenuScreen::getRightScreen() {
	return rightScreen;
}

LCDMenuScreen* LCDMenuScreen::onShortLeftButtonPress() {
	return leftScreen;
}

LCDMenuScreen* LCDMenuScreen::onShortCenterButtonPress() {
	return enterScreen;
}

LCDMenuScreen* LCDMenuScreen::onShortRightButtonPress() {
	return rightScreen;
}

LCDMenuScreen* LCDMenuScreen::onLongLeftButtonPress() {
	return leftScreen;
}

LCDMenuScreen* LCDMenuScreen::onLongCenterButtonPress() {
	return homeScreen;
}

LCDMenuScreen* LCDMenuScreen::onLongRightButtonPress() {
	return rightScreen;
}

void LCDMenuScreen::printRefrences() {
	println("This:%d :: %d %d %d %d", this, homeScreen, leftScreen, enterScreen,
			rightScreen);
}

} /* namespace TRL */
