/*
 * LimitSwitch.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: guywenck
 */

#include "TRL/LimitSwitch.h"

namespace TRL {

LimitSwitch::LimitSwitch() :
		DigitalSwitch() {

}

LimitSwitch::LimitSwitch(AnalogPort port) :
		DigitalSwitch(port, this) {

}

LimitSwitch::LimitSwitch(DigitalPort port) :
		DigitalSwitch(port, this) {

}

LimitSwitch::~LimitSwitch() {
}

SensorType LimitSwitch::getSensorType() {
	return LimitSwitchSensorType;
}
string LimitSwitch::getSensorName() {
	return "Limit Switch";
}

} /* namespace TRL */
