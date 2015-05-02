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

void LCDSpecificSensorScreen::display() {
	lcd->displayCenteredString(1, sensor->getSensorName());
	string portName = Port::getShortPortName(sensor->getMainPort());
	lcd->displayFormattedString(2, "%s:%d", portName, sensor->getValue());
	delete[] portName;
}

/*
 * Get the specific sensor screens for use in the LCDMenuHandler
 *
 * The array of LCDSpecificSensorScreens needs to be deleted with delete array
 *
 * @param homeScreen the screen you want these specific screens to go to when you hold down the center button
 * @param loopScreens do you want the screens to loop or end once the end of the array is reached
 */
Array<LCDSpecificSensorScreen*>* LCDSpecificSensorScreen::getSpecificSensorScreens(
		LCDMenuScreen* homeScreen, bool loopScreens) {

	Array<Sensor*>* sensors =
			SensorRegistry::getRegisteredSensorsArrayWithoutDuplicates();
	Array<LCDSpecificSensorScreen*>* screens = new Array<
			LCDSpecificSensorScreen*>(sensors->size());

	//Two for loops are needed so that the entire array can be initialized before
	//refrences to those elements are assigned
	for (int i = 0; i < screens->size(); i++) {
		screens->at(i) = new LCDSpecificSensorScreen(sensors->at(i));
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

	delete sensors;
	return screens;
}
} /* namespace TRL */
