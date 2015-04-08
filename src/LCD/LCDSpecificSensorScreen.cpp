/*
 * LCDSpecificSensorScreen.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: cwenck
 */

#include "LCD/LCDSpecificSensorScreen.h"

namespace TRL {

LCDSpecificSensorScreen::LCDSpecificSensorScreen() {
	this->sensor = NULL;
}

LCDSpecificSensorScreen::LCDSpecificSensorScreen(Sensor* sensor) {
	this->sensor = sensor;
}

LCDSpecificSensorScreen::~LCDSpecificSensorScreen() {
	println("Destroyed screen with sensor %s", sensor->getSensorName());
}

void LCDSpecificSensorScreen::setSensor(Sensor* sensor) {
	this->sensor = sensor;
}

void LCDSpecificSensorScreen::display(LCD* lcd) {
	lcd->displayCenteredString(1, sensor->getSensorName());
	string portName = Port::getShortPortName(sensor->getMainPort());
	lcd->displayFormattedString(2, "%s:%d", portName, sensor->getValue());
	delete[] portName;
}

/*
 * Make sure you delete the array after you are done using it with delete[]
 */
LCDSpecificSensorScreen** LCDSpecificSensorScreen::getSpecificSensorScreens(
		LCDMenuScreen* homeScreen, bool loopScreens) {
	int size = SensorRegistry::getNumberOfRegisteredSensorsWithoutDuplicates();
	Sensor** sensors =
			SensorRegistry::getRegisteredSensorsArrayWithoutDuplicates();
	LCDSpecificSensorScreen* screenArray = new LCDSpecificSensorScreen[size];
	LCDSpecificSensorScreen** screenPointers =
			new LCDSpecificSensorScreen*[size];
	for (int i = 0; i < size; i++) {
		screenPointers[i] = &screenArray[i];
		screenPointers[i]->setSensor(sensors[i]);
		if (loopScreens) {
			//Sensor Specific screens loop
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
			//Sensor Specific screens don't loop
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
	delete[] sensors;
	//The other two arrays are intentionally not deleted as they need
	//to bre refrenced outside the function
	return screenPointers;
}

void LCDSpecificSensorScreen::printRefrences() {
	println("This:%d :: %d %d %d %d", this, homeScreen, leftScreen, enterScreen,
			rightScreen);
}

} /* namespace TRL */
