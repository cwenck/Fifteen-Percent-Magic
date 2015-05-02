/*
 * LCDSpecificBatteryScreen.cpp
 *
 *  Created on: Apr 8, 2015
 *      Author: cwenck
 */

#include "LCD/LCDSpecificBatteryScreen.h"

namespace TRL {

LCDSpecificBatteryScreen::LCDSpecificBatteryScreen() {
	this->battery = PrimaryBatteryType;
}

LCDSpecificBatteryScreen::~LCDSpecificBatteryScreen() {
}

void LCDSpecificBatteryScreen::setBattry(BatteryType type) {
	this->battery = type;
}

void LCDSpecificBatteryScreen::display() {
	lcd->clear();
	switch (battery) {
		case PrimaryBatteryType:
			lcd->displayCenteredString(1, "Primary");
			lcd->displayFormattedCenteredString(2, "%.2fV",
					getPrimaryBatteryPower());
			return;
		case BackupBatteryType:
			lcd->displayCenteredString(1, "Backup");
			lcd->displayFormattedCenteredString(2, "%.2fV",
					getBackupBatteryPower());
			return;
		case PowerExpanderBatteryType:
			lcd->displayCenteredString(1, "Power Expander");
		if (Port::getAnalogPortFromUniversalPort(
				SensorList::powerExpander->getMainPort()) == NoAnalogInput) {
			lcd->displayFormattedCenteredString(2, "0.00V");
		} else {
			lcd->displayFormattedCenteredString(2, "%.2fV",
					SensorList::powerExpander->getVoltage());
		}
			return;
	}
}
/*
 * Get the specific battery screens for use in the LCDMenuHandler
 *
 * The array of LCDSpecificBatteryScreens needs to be deteted with delete[] array
 * but so does the array of actual objects so you ALSO need to do delete[] array[0]
 *
 * @param homeScreen the screen you want these specific screens to go to when you hold down the center button
 * @param loopScreens do you want the screens to loop or end once the end of the array is reached
 */

Array<LCDSpecificBatteryScreen*>* LCDSpecificBatteryScreen::getSpecificBatteryScreens(
		LCDMenuScreen* homeScreen, bool loopScreens) {
	Array<LCDSpecificBatteryScreen*>* screens = new Array<
			LCDSpecificBatteryScreen*>(3);

	//Two for loops are needed so that the entire array can be initialized before
	//refrences to those elements are assigned
	for (int i = 0; i < screens->size(); i++) {
		screens->at(i) = new LCDSpecificBatteryScreen();
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

	screens->at(0)->setBattry(PrimaryBatteryType);
	screens->at(1)->setBattry(BackupBatteryType);
	screens->at(2)->setBattry(PowerExpanderBatteryType);

	return screens;
}

} /* namespace TRL */
