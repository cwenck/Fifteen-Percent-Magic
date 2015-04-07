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
		DigitalSwitch(port, this) {

}

Bumper::Bumper(DigitalPort port) :
		DigitalSwitch(port, this) {

}

Bumper::~Bumper() {

}

SensorType Bumper::getSensorType(){
	return BumperSensorType;
}

string Bumper::getSensorName(){
	return "Bumper";
}

} /* namespace TRL */
