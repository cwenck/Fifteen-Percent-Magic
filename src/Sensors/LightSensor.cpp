/*
 s * LightSensor.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#include "TRL/LightSensor.h"

namespace TRL {

LightSensor::LightSensor() :
		AnalogSensor() {
}

LightSensor::LightSensor(AnalogPort port) :
		AnalogSensor(port, this) {
}

LightSensor::~LightSensor() {
}

SensorType LightSensor::getSensorType() {
	return LightSensorType;
}

string LightSensor::getSensorName() {
	return "Light Sensor";
}

} /* namespace TRL */
