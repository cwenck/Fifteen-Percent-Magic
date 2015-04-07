/*
 * LineSensor.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#include "TRL/LineSensor.h"

namespace TRL {

LineSensor::LineSensor() :
		AnalogSensor() {

}

LineSensor::LineSensor(AnalogPort port) :
		AnalogSensor(port, this) {

}

LineSensor::~LineSensor() {
}

SensorType LineSensor::getSensorType(){
	return LineSensorType;
}

string LineSensor::getSensorName(){
	return "Line Sensor";
}

} /* namespace TRL */
