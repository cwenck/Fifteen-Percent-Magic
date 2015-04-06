/*
 * Gyroscope.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: guywenck
 */

#include "TRL/Gyroscope.h"

namespace TRL {

Gyroscope::Gyroscope() {
	this->port = NoAnalogInput;
	this->degreesRotated = 0;
}

Gyroscope::Gyroscope(AnalogPort port) {
	this->port = port;
	this->degreesRotated = 0;
	PortRegistry::registerPort(port, GyroscopeSensorType);
	gyroHandle = gyroInit(Port::getAnalogPortNumber(port),
			DEFAULT_GYRO_MULTIPLIER);
}

//The multiplier impacts how many degress are reported by the gyro for a full rotation
//positive values will increase the number of degrees reported for a fixed actual rotation,
//while negative values will decrease the number of degrees reported
//min value of -DEFAULT_GYRO_MULTIPLIER
Gyroscope::Gyroscope(AnalogPort port, int multiplier) {
	this->port = port;
	this->degreesRotated = 0;
	PortRegistry::registerPort(port, GyroscopeSensorType);
	if (abs(multiplier) < DEFAULT_GYRO_MULTIPLIER) {
		println(WARNING, "Gyroscope", "Gyroscope",
				"The multiplier value of %d was less than the minimum value of -%d. The gyroscope is being initialized with the default multiplier value.",
				multiplier, DEFAULT_GYRO_MULTIPLIER);
		gyroHandle = gyroInit(Port::getAnalogPortNumber(port),
				DEFAULT_GYRO_MULTIPLIER);
	} else {
		int realMultiplier = multiplier + DEFAULT_GYRO_MULTIPLIER;
		gyroHandle = gyroInit(Port::getAnalogPortNumber(port), realMultiplier);
	}
}

Gyroscope::~Gyroscope() {
	// TODO Auto-generated destructor stub
}

bool Gyroscope::destroy() {
	gyroShutdown(gyroHandle);
	return PortRegistry::deleteRegistryEntry(port);
}

int Gyroscope::getValue() {
	return gyroGet(gyroHandle);
}

SensorType getSensorType() {
	return GyroscopeSensorType;
}

} /* namespace TRL */
