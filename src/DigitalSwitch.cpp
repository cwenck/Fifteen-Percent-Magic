/*
 * Button.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#include "TRL/DigitalSwitch.h"

namespace TRL {

DigitalSwitch::DigitalSwitch() {
	this->port = NULL_UNIVERSAL_PORT;
}

DigitalSwitch::DigitalSwitch(AnalogPort port){
	this->port = Port::getUniversalPortNumber(port);
	Port::configurePort(DigitalInputPort, port);
	PortRegistry::registerPort(port, DigitalSwitchSensorType);
}

DigitalSwitch::DigitalSwitch(DigitalPort port){
	this->port = Port::getUniversalPortNumber(port);
	Port::configurePort(DigitalInputPort, port);
	PortRegistry::registerPort(port, DigitalSwitchSensorType);
}

DigitalSwitch::~DigitalSwitch() {
	//Nothing needs to be done when destroying this object
}

bool DigitalSwitch::removeFromRegistry(){
	return PortRegistry::deleteRegistryEntry(port);
}

void DigitalSwitch::setPort(AnalogPort port){
	this->port = Port::getUniversalPortNumber(port);
}

void DigitalSwitch::setPort(DigitalPort port){
	this->port = Port::getUniversalPortNumber(port);
}

UniversalPort DigitalSwitch::getPort(){
	return port;
}

int DigitalSwitch::getValue(){
	return Port::isPortActive(port);
}

SensorType DigitalSwitch::getSensorType(){
	return DigitalSwitchSensorType;
}

} /* namespace TRL */
