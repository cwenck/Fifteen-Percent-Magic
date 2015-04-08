/*
 * Sonar.cpp
 *
 *  Created on: Apr 3, 2015
 *      Author: cwenck
 */

#include "Sensors/Sonar.h"

namespace TRL {

Sonar::Sonar() : Sensor(){
	this->inputPort = NoDigitalInput;
	this->outputPort = NoDigitalInput;
	this->unit = CM;
	this->behavior = ReturnLowValue;
	prosSonar = 0;
}

Sonar::Sonar(DigitalPort yellowInputPort, DigitalPort orangeOutputPort) : Sensor(yellowInputPort, orangeOutputPort){
	this->inputPort = yellowInputPort;
	this->outputPort = orangeOutputPort;
	this->unit = CM;
	this->behavior = ReturnLowValue;
	prosSonar = ultrasonicInit(outputPort, inputPort);
	SensorRegistry::registerSensor(this);
}

Sonar::~Sonar() {
	//Nothing needs to be done when destroying this object
}

bool Sonar::destroy() {
	ultrasonicShutdown(prosSonar);
	bool inputSuccess = SensorRegistry::deleteRegistryEntry(inputPort);
	bool outputSuccess = SensorRegistry::deleteRegistryEntry(outputPort);
	return inputSuccess && outputSuccess;
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

SensorType Sonar::getSensorType() {
	return SonarSensorType;
}

string Sonar::getSensorName(){
	return "Sonar";
}

} /* namespace TRL */
