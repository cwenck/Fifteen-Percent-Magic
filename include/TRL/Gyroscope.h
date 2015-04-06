/*
 * Gyroscope.h
 *
 *  Created on: Apr 5, 2015
 *      Author: guywenck
 */

#ifndef GYROSCOPE_H_
#define GYROSCOPE_H_

#include "TRL_BaseInitialization.h"
#include "Sensor.h"

//This number is straight from the PROS documentation for gyroInit()
#define DEFAULT_GYRO_MULTIPLIER 196

//NOTE: The gyroscope should not be in motion when initialized

namespace TRL {
	class Gyroscope : public Sensor {
	private:
		AnalogPort port;
		PROS_Gyro gyroHandle;

		//positive is Counter-Clockwise
		//negative is Clockwise
		//Same as with the trig unit circle
		int degreesRotated;
		//TODO implement a task to track the degrees the gyro rotates

	public:
		Gyroscope();
		Gyroscope(AnalogPort port);
		Gyroscope(AnalogPort port, int multiplier);
		virtual ~Gyroscope();

		bool destroy();

		int getValue();
		SensorType getSensorType();
	};
}

#endif /* GYROSCOPE_H_ */
