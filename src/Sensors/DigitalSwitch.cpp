/*
 * Button.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#include "Sensors/DigitalSwitch.h"

namespace TRL {

DigitalSwitch::DigitalSwitch() :
		Sensor() {
	this->port = UNIVERSAL_UNKNOWN_PORT;
}

DigitalSwitch::DigitalSwitch(AnalogPort port, Sensor* childSensor) :
		Sensor(port) {
	this->port = Port::getUniversalPortNumber(port);
	Port::configurePort(DigitalInputPort, port);
	SensorRegistry::registerSensor(childSensor);
}

DigitalSwitch::DigitalSwitch(DigitalPort port, Sensor* childSensor) :
		Sensor(port) {
	this->port = Port::getUniversalPortNumber(port);
	Port::configurePort(DigitalInputPort, port);
	SensorRegistry::registerSensor(childSensor);
}

DigitalSwitch::~DigitalSwitch() {
	//Nothing needs to be done when destroying this object
}

bool DigitalSwitch::destroy() {
	return SensorRegistry::deleteRegistryEntry(port);
}

void DigitalSwitch::setPort(AnalogPort port) {
	this->port = Port::getUniversalPortNumber(port);
}

void DigitalSwitch::setPort(DigitalPort port) {
	this->port = Port::getUniversalPortNumber(port);
}

UniversalPort DigitalSwitch::getPort() {
	return port;
}

int DigitalSwitch::getValue() {
	return Port::isPortActive(port);
}

} /* namespace TRL */
