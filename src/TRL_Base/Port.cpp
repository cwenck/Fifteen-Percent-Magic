/*
 * Port.cpp
 *
 *  Created on: Apr 2, 2015
 *      Author: guywenck
 */

#include "TRL/Port.h"

namespace TRL {

Port::Port() {
}

Port::~Port() {
	// TODO Auto-generated destructor stub
}

UniversalPort Port::getUniversalPortNumber(AnalogPort port) {
	switch (port) {
	case Analog_1:
		return 13;
	case Analog_2:
		return 14;
	case Analog_3:
		return 15;
	case Analog_4:
		return 16;
	case Analog_5:
		return 17;
	case Analog_6:
		return 18;
	case Analog_7:
		return 19;
	case Analog_8:
		return 20;
	default:
		println(ERROR, "Port", "getUniversalPortNumber",
				"This statement should never get called.");
		return -1;
	}
}

UniversalPort Port::getUniversalPortNumber(DigitalPort port) {
	switch (port) {
	case Digital_1:
		return 1;
	case Digital_2:
		return 2;
	case Digital_3:
		return 3;
	case Digital_4:
		return 4;
	case Digital_5:
		return 5;
	case Digital_6:
		return 6;
	case Digital_7:
		return 7;
	case Digital_8:
		return 8;
	case Digital_9:
		return 9;
	case Digital_10:
		return 10;
	case Digital_11:
		return 11;
	case Digital_12:
		return 12;
	default:
		println(ERROR, "Port", "getUniversalPortNumber",
				"This statement should never get called.");
		return -1;
	}
}

bool Port::isPortDigitalType(UniversalPort port) {
	if ((port >= 1) && (port <= 12)) {
		return true;
	}
	return false;
}

bool Port::isPortAnalogType(UniversalPort port) {
	if (((port >= 13) && (port <= 20))) {
		return true;
	}
	return false;
}

short Port::getAnalogPortNumber(AnalogPort port) {
	switch (port) {
	case Analog_1:
		return 1;
	case Analog_2:
		return 2;
	case Analog_3:
		return 3;
	case Analog_4:
		return 4;
	case Analog_5:
		return 5;
	case Analog_6:
		return 6;
	case Analog_7:
		return 7;
	case Analog_8:
		return 8;
	default:
		println(ERROR, "Port", "getUniversalPortNumber",
				"This statement should never get called.");
		return -1;
	}
}
short Port::getAnalogPortNumber(UniversalPort port) {
	if (isPortAnalogType(port)) {
		return port - 12;
	}
	return NULL_UNIVERSAL_PORT;
}

short Port::getDigitalPortNumber(DigitalPort port) {
	switch (port) {
	case Digital_1:
		return 1;
	case Digital_2:
		return 2;
	case Digital_3:
		return 3;
	case Digital_4:
		return 4;
	case Digital_5:
		return 5;
	case Digital_6:
		return 6;
	case Digital_7:
		return 7;
	case Digital_8:
		return 8;
	case Digital_9:
		return 9;
	case Digital_10:
		return 10;
	case Digital_11:
		return 11;
	case Digital_12:
		return 12;
	default:
		println(ERROR, "Port", "getUniversalPortNumber",
				"This statement should never get called.");
		return -1;
	}
}

short Port::getDigitalPortNumber(UniversalPort port) {
	if (isPortDigitalType(port)) {
		return port;
	}
	return NULL_UNIVERSAL_PORT;
}

PortType Port::getPortType(UniversalPort port) {
	if (isPortAnalogType(port)) {
		return AnalogPortType;
	} else if (isPortDigitalType(port)) {
		return DigitalPortType;
	} else {
		return OtherPortType;
	}
}

bool Port::isPortInactive(AnalogPort port) {
	int value = getAnalogValue(port);
	if (value > 1000) {
		return true;
	} else {
		return false;
	}
}

bool Port::isPortInactive(DigitalPort port) {
	return digitalRead(getUniversalPortNumber(port));
}

bool Port::isPortInactive(UniversalPort port) {
	PortType type = getPortType(port);
	bool value;
	switch(type){
	case AnalogPortType:
		value = isPortInactive(getAnalogPortFromUniversalPort(port));
		return value;
	case DigitalPortType:
		return digitalRead(port);
	case OtherPortType:
		return digitalRead(port);
	}
	return -1;
}

bool Port::isPortActive(AnalogPort port) {
	return !isPortInactive(port);
}

bool Port::isPortActive(DigitalPort port) {
	return !isPortInactive(port);
}

bool Port::isPortActive(UniversalPort port) {
	return !isPortInactive(port);
}

int Port::getAnalogValue(AnalogPort port){
	return analogRead(getAnalogPortNumber(port));
}

//returns -1 if the port isn't analog
int Port::getAnalogValue(UniversalPort port){
	if(isPortAnalogType(port)){
		return analogRead(getAnalogPortNumber(port));
	}
	return -1;
}

void Port::configurePort(PortConfig config, UniversalPort port) {
	switch (config) {
	case DigitalInputPort:
		pinMode(port, INPUT);
		return;
	case AnalogInputPort:
		if (isPortAnalogType(port)) {
			pinMode(port, INPUT_ANALOG);
		}
		return;
	case OutputPort:
		pinMode(port, OUTPUT);
		return;
	}
}

void Port::configurePort(PortConfig config, DigitalPort port) {
	configurePort(config, getUniversalPortNumber(port));
}

void Port::configurePort(PortConfig config, AnalogPort port){
	configurePort(config, getUniversalPortNumber(port));
}

AnalogPort Port::getAnalogPortFromUniversalPort(UniversalPort port){
	if(isPortAnalogType(port)){
		return (AnalogPort) getAnalogPortNumber(port);
	}
	return NoAnalogInput;
}

DigitalPort Port::getDigitalPortFromUniversalPort(UniversalPort port){
	if(isPortDigitalType(port)){
		return (DigitalPort) getDigitalPortNumber(port);
	}
	return NoDigitalInput;
}

} /* namespace TRL */
