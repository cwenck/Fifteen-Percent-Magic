/*
 * AnalogSensor.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#include "Sensors/AnalogSensor.h"

namespace TRL {

AnalogSensor::AnalogSensor() : Sensor(){
	this->port = NoAnalogInput;
}

AnalogSensor::AnalogSensor(AnalogPort port, Sensor* childSensor) :
		Sensor(port) {
	this->port = port;
	Port::configurePort(AnalogInputPort, port);
	SensorRegistry::registerSensor(childSensor);
}

AnalogSensor::~AnalogSensor() {
	//Nothing needs to be done when destroying this object
}

bool AnalogSensor::destory() {
	return SensorRegistry::deleteRegistryEntry(port);
}

int AnalogSensor::getValue() {
	return Port::getAnalogValue(port);
}

} /* namespace TRL */
