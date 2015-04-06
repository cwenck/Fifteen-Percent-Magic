/*
 * Potentiometer.cpp
 *
 *  Created on: Apr 2, 2015
 *      Author: guywenck
 */

#include "TRL/Potentiometer.h"

namespace TRL {

Potentiometer::Potentiometer() :
		AnalogSensor() {
	numSelections = -1;
}

Potentiometer::Potentiometer(AnalogPort port) :
		AnalogSensor(port, PotentiometerSensorType) {
	numSelections = -1;
}

Potentiometer::~Potentiometer() {
}

void Potentiometer::disablePotentiometerSelections() {
	numSelections = -1;
}

bool Potentiometer::arePotentiometerSelectionsDisabled() {
	if (numSelections == -1) {
		return true;
	}
	return false;
}

bool Potentiometer::arePotentiometerSelectionsEnabled() {
	return !arePotentiometerSelectionsDisabled();
}

short Potentiometer::getCurrentPotentiometerSelection() {
	if (arePotentiometerSelectionsDisabled()) {
		return -1;
	}

	float selectionRange = (MAX_POTENTIOMETER_READING / numSelections);
	for (int i = 1; i <= numSelections; i++) {
		if (((selectionRange * (i - 1)) <= getValue())
				&& ((selectionRange * i) >= getValue())) {
			return i;
		}
	}
	return -1;

}

bool Potentiometer::isSelectionActive(int selectionNumber) {
	if (getCurrentPotentiometerSelection() == selectionNumber) {
		return true;
	}
	return false;
}

bool Potentiometer::isSelectionInactive(int selectionNumber) {
	return !isSelectionActive(selectionNumber);
}
} /* namespace TRL */
