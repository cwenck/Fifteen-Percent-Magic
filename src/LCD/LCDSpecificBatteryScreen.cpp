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

void LCDSpecificBatteryScreen::display(LCD* lcd) {
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

LCDSpecificBatteryScreen** LCDSpecificBatteryScreen::getSpecificBatteryScreens(
		LCDMenuScreen* homeScreen, bool loopScreens) {
	int size = 3;
	LCDSpecificBatteryScreen** screenPointers =
			new LCDSpecificBatteryScreen*[size];

	//Two for loops are needed so that the entire array can be initialized before
	//refrences to those elements are assigned
	for (int i = 0; i < size; i++) {
		screenPointers[i] = new LCDSpecificBatteryScreen();
	}
	for (int i = 0; i < size; i++) {
		if (loopScreens) {
			if (i == 0) {
				if (size == 1) {
					screenPointers[0]->setReferencedScreens(homeScreen,
							screenPointers[0], screenPointers[0],
							screenPointers[0]);
				} else {
					screenPointers[0]->setReferencedScreens(homeScreen,
							screenPointers[size - 1], screenPointers[0],
							screenPointers[1]);
				}
			} else if (i == (size - 1)) {
				screenPointers[i]->setReferencedScreens(homeScreen,
						screenPointers[i - 1], screenPointers[i],
						screenPointers[0]);
			} else {
				screenPointers[i]->setReferencedScreens(homeScreen,
						screenPointers[i - 1], screenPointers[i],
						screenPointers[i + 1]);
			}
		} else {
			if (i == 0) {
				if (size == 1) {
					screenPointers[0]->setReferencedScreens(homeScreen,
							screenPointers[0], screenPointers[0],
							screenPointers[0]);
				} else {
					screenPointers[0]->setReferencedScreens(homeScreen,
							screenPointers[0], screenPointers[0],
							screenPointers[1]);
				}
			} else if (i == (size - 1)) {
				screenPointers[i]->setReferencedScreens(homeScreen,
						screenPointers[i - 1], screenPointers[i],
						screenPointers[i]);
			} else {
				screenPointers[i]->setReferencedScreens(homeScreen,
						screenPointers[i - 1], screenPointers[i],
						screenPointers[i + 1]);
			}
		}
	}
	screenPointers[0]->setBattry(PrimaryBatteryType);
	screenPointers[1]->setBattry(BackupBatteryType);
	screenPointers[2]->setBattry(PowerExpanderBatteryType);
	return screenPointers;
}

} /* namespace TRL */
