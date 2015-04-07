/*
 * Accelerometer.h
 *
 *  Created on: Apr 6, 2015
 *      Author: guywenck
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#include "TRL_BaseInitialization.h"
#include "AnalogSensor.h"

namespace TRL {
	class Accelerometer : public AnalogSensor {
	private:
		Axis axis;
	public:
		Accelerometer();
		Accelerometer(AnalogPort port, Axis axis);

		Axis getAxis();
		SensorType getSensorType();
		string getSensorName();
	};
}

#endif /* ACCELEROMETER_H_ */
