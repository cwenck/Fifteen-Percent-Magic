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
 * Get the specific sensor screens for use in the LCDMenuHandler
 *
 * The array of LCDSpecificSensorScreens needs to be deteted with delete[] array
 * but so does the array of actual objects so you ALSO need to do delete[] array[0]
 *
 * @param homeScreen the screen you want these specific screens to go to when you hold down the center button
 * @param loopScreens do you want the screens to loop or end once the end of the array is reached
 */
LCDSpecificSensorScreen** LCDSpecificSensorScreen::getSpecificSensorScreens(
		LCDMenuScreen* homeScreen, bool loopScreens) {
	int size = SensorRegistry::getNumberOfRegisteredSensorsWithoutDuplicates();
	Sensor** sensors =
			SensorRegistry::getRegisteredSensorsArrayWithoutDuplicates();
	LCDSpecificSensorScreen** screenPointers =
			new LCDSpecificSensorScreen*[size];
	//Two for loops are needed so that the entire array can be initialized before
	//refrences to those elements are assigned
	for (int i = 0; i < size; i++) {
		screenPointers[i] = new LCDSpecificSensorScreen(sensors[i]);
	}
	for (int i = 0; i < size; i++) {
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
	return screenPointers;
}
} /* namespace TRL */
