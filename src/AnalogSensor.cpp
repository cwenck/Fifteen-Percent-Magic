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
}

AnalogSensor::AnalogSensor(AnalogPort port){
	this->port = port;
	Port::configurePort(AnalogInputPort, port);
	PortRegistry::registerPort(port, getSensorType());
}

AnalogSensor::~AnalogSensor() {
	PortRegistry::deleteRegistryEntry(port);
}

int AnalogSensor::getValue(){
	return Port::getAnalogValue(port);
}

} /* namespace TRL */
