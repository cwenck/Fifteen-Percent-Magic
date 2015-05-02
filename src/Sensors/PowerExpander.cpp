/*
 * PowerExpander.cpp
 *
 *  Created on: May 1, 2015
 *      Author: guywenck
 */

#include "Sensors/PowerExpander.h"

namespace TRL {

PowerExpander::PowerExpander() :
		AnalogSensor() {

}

PowerExpander::PowerExpander(AnalogPort port) :
		AnalogSensor(port, this) {

}

PowerExpander::~PowerExpander() {
}

float PowerExpander::getVoltage() {
	if (POWER_EXPANDER_DIVISOR_1 != 0 && POWER_EXPANDER_DIVISOR_2 != 0) {
		return getValue() / (POWER_EXPANDER_DIVISOR_2 * 4);
	}
	println(ERROR, "PowerExpander", "getVoltage",
			"One of the Power Expander Divisors is 0. Please Correct.");
	return -1;
}

SensorType PowerExpander::getSensorType() {
	return PowerExpanderSensorType;
}

string PowerExpander::getSensorName() {
	return "Power Expander";
}

} /* namespace TRL */
