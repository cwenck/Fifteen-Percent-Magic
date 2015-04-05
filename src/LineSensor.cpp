/*
 * LineSensor.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#include "TRL/LineSensor.h"

namespace TRL {

LineSensor::LineSensor() : AnalogSensor() {

}

LineSensor::LineSensor(AnalogPort port) :
		AnalogSensor(port, LineSensorType) {

}

LineSensor::~LineSensor() {
}

} /* namespace TRL */
