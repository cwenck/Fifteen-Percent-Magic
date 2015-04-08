/*
 * Accelerometer.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: guywenck
 */

#include "Sensors/Accelerometer.h"

namespace TRL {

Accelerometer::Accelerometer() :
		AnalogSensor() {
	this->axis = UnsetAxis;
}

Accelerometer::Accelerometer(AnalogPort port, Axis axis) :
		AnalogSensor(port, this) {
	this->axis = axis;
}

Axis Accelerometer::getAxis() {
	return axis;
}

SensorType Accelerometer::getSensorType() {
	return AccelerometerSensorType;
}

string Accelerometer::getSensorName() {
	return "Accelerometer";
}

} /* namespace TRL */
