/*
 * Bumper.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: guywenck
 */

#include "TRL/Bumper.h"

namespace TRL {

Bumper::Bumper() :
		DigitalSwitch() {

}

Bumper::Bumper(AnalogPort port) :
		DigitalSwitch(port, BumperSensorType) {

}

Bumper::Bumper(DigitalPort port) :
		DigitalSwitch(port, BumperSensorType) {

}

Bumper::~Bumper() {

}

} /* namespace TRL */
