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

bool Port::isUniversalPortNumberDigitalType(UniversalPort port) {
	if ((port >= 1) && (port <= 12)) {
		return true;
	}
	return false;
}

bool Port::isUniversalPortNumberAnalogType(UniversalPort port) {
	if ((port >= 13) && (port <= 20)) {
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
	if (isUniversalPortNumberAnalogType(port)) {
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
	if (isUniversalPortNumberDigitalType(port)) {
		return port;
	}
	return NULL_UNIVERSAL_PORT;
}

} /* namespace TRL */
