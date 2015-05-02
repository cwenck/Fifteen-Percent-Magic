/*
 * AnalogSensor.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#include "Sensors/AnalogSensor.h"

namespace TRL {

AnalogSensor::AnalogSensor() :
		Sensor() {
	this->port = NoAnalogInput;
}

AnalogSensor::AnalogSensor(AnalogPort port, Sensor* childSensor) :
		Sensor(port) {
	this->port = port;
	if (port != NoAnalogInput) {
		Port::configurePort(AnalogInputPort, port);
		SensorRegistry::registerSensor(childSensor);
	}
}

AnalogSensor::~AnalogSensor() {
	//Nothing needs to be done when destroying this object
}

bool AnalogSensor::destory() {
	return SensorRegistry::deleteRegistryEntry(port);
}

int AnalogSensor::getValue() {
	if (port != NoAnalogInput) {
		return Port::getAnalogValue(port);
	} else {
		println(WARNING, "AnalogSensor", "getValue",
				"No Analog Input set to get the value from.");
		return -1;
	}
}

} /* namespace TRL */
