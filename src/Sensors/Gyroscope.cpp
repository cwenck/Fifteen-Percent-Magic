/*
 * Gyroscope.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: guywenck
 */

#include "TRL/Gyroscope.h"

namespace TRL {

Gyroscope::Gyroscope() : Sensor(){
	this->port = NoAnalogInput;
	this->gyroHandle = 0;
}

Gyroscope::Gyroscope(AnalogPort port) :
		Sensor(port) {
	this->port = port;
	SensorRegistry::registerSensor(this);
	this->gyroHandle = gyroInit(Port::getAnalogPortNumber(port),
			DEFAULT_GYRO_MULTIPLIER);
}

//The multiplier impacts how many degrees are reported by the gyro for a full rotation
//positive values will increase the number of degrees reported for a fixed actual rotation,
//while negative values will decrease the number of degrees reported
//min value of -DEFAULT_GYRO_MULTIPLIER
Gyroscope::Gyroscope(AnalogPort port, int multiplier) :
		Sensor(port) {
	this->port = port;
	SensorRegistry::registerSensor(this);
	if (abs(multiplier) < DEFAULT_GYRO_MULTIPLIER) {
		println(WARNING, "Gyroscope", "Gyroscope",
				"The multiplier value of %d was less than the minimum value of -%d. The gyroscope is being initialized with the default multiplier value.",
				multiplier, DEFAULT_GYRO_MULTIPLIER);
		this->gyroHandle = gyroInit(Port::getAnalogPortNumber(port),
				DEFAULT_GYRO_MULTIPLIER);
	} else {
		int realMultiplier = multiplier + DEFAULT_GYRO_MULTIPLIER;
		this->gyroHandle = gyroInit(Port::getAnalogPortNumber(port),
				realMultiplier);
	}
}

bool Gyroscope::destroy() {
	gyroShutdown(gyroHandle);
	return SensorRegistry::deleteRegistryEntry(port);
}

/*
 * Gets the current gyro angle in degrees, rounded to the nearest degree.
 *
 * @return the signed and cumulative number of degrees rotated around the gyro's vertical axis since the last start or reset
 */
int Gyroscope::getValue() {
	return gyroGet(gyroHandle);
}

/*
 * Reset's the number of degree's the gyro reads to 0
 */
void Gyroscope::reset() {
	gyroReset(gyroHandle);
}

SensorType Gyroscope::getSensorType() {
	return GyroscopeSensorType;
}

string Gyroscope::getSensorName() {
	return "Gyroscope";
}

} /* namespace TRL */
