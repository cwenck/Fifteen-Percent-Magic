/*
 * AnalogSensor.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#include "TRL/AnalogSensor.h"

namespace TRL {

AnalogSensor::AnalogSensor() {
	this->port = NoAnalogInput;
	this->type = NullSensorType;
}

AnalogSensor::AnalogSensor(AnalogPort port, SensorType type){
	this->port = port;
	this->type = type;
	Port::configurePort(AnalogInputPort, port);
	PortRegistry::registerPort(port, type);
}

AnalogSensor::~AnalogSensor() {
	PortRegistry::deleteRegistryEntry(port);
}

int AnalogSensor::getValue(){
	return Port::getAnalogValue(port);
}

SensorType AnalogSensor::getSensorType(){
	return type;
}

} /* namespace TRL */
