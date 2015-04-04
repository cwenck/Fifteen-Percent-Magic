/*
 * Sonar.cpp
 *
 *  Created on: Apr 3, 2015
 *      Author: cwenck
 */

#include "TRL/Sonar.h"

namespace TRL {

Sonar::Sonar() {
	this->inputPort = NoDigitalInput;
	this->outputPort = NoDigitalInput;
	this->unit = CM;
	this->behavior = ReturnLowValue;
	prosSonar = 0;
}

Sonar::Sonar(DigitalPort yellowInputPort, DigitalPort orangeOutputPort) {
	this->inputPort = yellowInputPort;
	this->outputPort = orangeOutputPort;
	this->unit = CM;
	this->behavior = ReturnLowValue;
	prosSonar = ultrasonicInit(outputPort, inputPort);
	PortRegistry::registerPort(inputPort, SonarSensorType);
	PortRegistry::registerPort(outputPort, SonarSensorType);
}

Sonar::~Sonar() {
	ultrasonicShutdown(prosSonar);
	PortRegistry::deleteRegistryEntry(inputPort);
	PortRegistry::deleteRegistryEntry(outputPort);
}

//reads 200 if the value is undefined
//either there is something right against it or there no object within its range
//returns -1 if something goes wrong. should never happen
int Sonar::getValue() {
	switch (unit) {
	case CM:
		return getValueInCM();
	case INCH:
		return getValueInInches();
	default:
		println(ERROR, "Sonar", "getValue", "This should never get called");
		return -1;
	}
}

int Sonar::getValueInCM() {
	int value = ultrasonicGet(prosSonar);
	if (value == 0) {
		switch (behavior) {
		case ReturnHighValue:
			return SONAR_MAX_CM;
		case ReturnLowValue:
			return 0;
		}
	}
	return value;
}

int Sonar::getValueInInches() {
	float cmValue = (float) getValueInCM();
	float inchValue = (cmValue / 2.54f);
	return (int) inchValue;
}

Sonar* Sonar::setUndefinedReturnBehavior(UnefinedBehavior behavior) {
	this->behavior = behavior;
	return this;
}

Sonar* Sonar::setUnit(SonarUnit unit) {
	this->unit = unit;
	return this;
}

} /* namespace TRL */
