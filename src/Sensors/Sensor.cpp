/*
 * Sensor.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#include "Sensors/Sensor.h"

namespace TRL {

Sensor::Sensor() {
	this->port_one = UNIVERSAL_PORT_NULL;
	this->port_two = UNIVERSAL_PORT_NULL;
	this->usesTwoPorts = false;
}

Sensor::Sensor(AnalogPort port) {
	this->port_one = Port::getUniversalPortNumber(port);
	this->port_two = UNIVERSAL_PORT_NULL;
	this->usesTwoPorts = false;
}

Sensor::Sensor(DigitalPort port) {
	this->port_one = Port::getUniversalPortNumber(port);
	this->port_two = UNIVERSAL_PORT_NULL;
	this->usesTwoPorts = false;
}

Sensor::Sensor(UniversalPort port) {
	this->port_one = port;
	this->port_two = UNIVERSAL_PORT_NULL;
	this->usesTwoPorts = false;
}

Sensor::Sensor(AnalogPort portOne, AnalogPort portTwo){
	this->port_one = Port::getUniversalPortNumber(portOne);
	this->port_two = Port::getUniversalPortNumber(portTwo);
	this->usesTwoPorts = true;
}

Sensor::Sensor(DigitalPort portOne, DigitalPort portTwo){
	this->port_one = Port::getUniversalPortNumber(portOne);
	this->port_two = Port::getUniversalPortNumber(portTwo);
	this->usesTwoPorts = true;
}

Sensor::Sensor(UniversalPort portOne, UniversalPort portTwo){
	this->port_one = portOne;
	this->port_two = portTwo;
	this->usesTwoPorts = true;
}


Sensor::~Sensor() {
}

UniversalPort Sensor::getMainPort() {
	return this->port_one;
}

UniversalPort Sensor::getSecondaryPort(){
	return this->port_two;
}

bool Sensor::isTwoPortSensor(){
	return usesTwoPorts;
}

} /* namespace TRL */
