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
		DigitalSwitch(port, LimitSwitchSensorType) {

}

LimitSwitch::LimitSwitch(DigitalPort port) :
		DigitalSwitch(port, LimitSwitchSensorType) {

}

LimitSwitch::~LimitSwitch() {
}

} /* namespace TRL */
