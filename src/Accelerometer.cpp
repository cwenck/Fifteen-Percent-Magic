/*
 * Accelerometer.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: guywenck
 */

#include "TRL/Accelerometer.h"

namespace TRL {

Accelerometer::Accelerometer() {
	this->axis = UnsetAxis;
}

Accelerometer::Accelerometer(AnalogPort port, Axis axis) :
		AnalogSensor(port, AccelerometerSensorType) {
	this->axis = axis;
}

Axis Accelerometer::getAxis() {
	return axis;
}
} /* namespace TRL */
