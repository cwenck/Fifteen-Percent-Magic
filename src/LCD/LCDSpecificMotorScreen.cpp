/*
 * LCDSpecificMotorScreen.cpp
 *
 *  Created on: May 1, 2015
 *      Author: guywenck
 */

#include "LCD/LCDSpecificMotorScreen.h"

namespace TRL {

LCDSpecificMotorScreen::LCDSpecificMotorScreen() {
	motor = NULL;
}

LCDSpecificMotorScreen::LCDSpecificMotorScreen(Motor* motor) {
	this->motor = motor;
}

LCDSpecificMotorScreen::~LCDSpecificMotorScreen() {
}

void LCDSpecificMotorScreen::display() {
	lcd->displayCenteredString(1, motor->getName());
	lcd->displayFormattedCenteredString(2, "Port:%d Pow:%d", motor->getPort(), motor->getRawPower());
}

void LCDSpecificMotorScreen::setMotor(Motor* motor) {
	this->motor = motor;
}

Array<LCDSpecificMotorScreen*>* LCDSpecificMotorScreen::getSpecificMotorScreens(
		LCDMenuScreen* homeScreen, bool loopScreens) {

	Array<Motor*>* registeredMotors = MotorRegistry::getRegisteredMotorsArray();
	Array<LCDSpecificMotorScreen*>* screens =
			new Array<LCDSpecificMotorScreen*>(registeredMotors->size());

	for (int i = 0; i < registeredMotors->size(); i++) {
		screens->at(i) = new LCDSpecificMotorScreen(registeredMotors->at(i));
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

	delete registeredMotors;
	return screens;
}

} /* namespace TRL */
