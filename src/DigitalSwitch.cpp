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
	this->type = NullSensorType;
}

DigitalSwitch::DigitalSwitch(AnalogPort port, SensorType type){
	this->port = Port::getUniversalPortNumber(port);
	this->type = type;
	Port::configurePort(DigitalInputPort, port);
	PortRegistry::registerPort(port, type);
}

DigitalSwitch::DigitalSwitch(DigitalPort port, SensorType type){
	this->port = Port::getUniversalPortNumber(port);
	this->type = type;
	Port::configurePort(DigitalInputPort, port);
	PortRegistry::registerPort(port, type);
}

DigitalSwitch::~DigitalSwitch() {
	//Nothing needs to be done when destroying this object
}

bool DigitalSwitch::destroy(){
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

} /* namespace TRL */
