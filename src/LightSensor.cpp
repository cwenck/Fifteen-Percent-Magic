/*
s * LightSensor.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#include "TRL/LightSensor.h"

namespace TRL {

LightSensor::LightSensor() {
	port = NoAnalogInput;
}

LightSensor::LightSensor(AnalogPort port){
	this->port = port;
	PortRegistry::registerPort(port, LightSensorType);
}

LightSensor::~LightSensor() {
	PortRegistry::deleteRegistryEntry(port);
}



} /* namespace TRL */
