/*
 * AnalogSensor.h
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#ifndef ANALOGSENSOR_H_
#define ANALOGSENSOR_H_

#include "TRL_BaseInitialization.h"
#include "Sensor.h"

namespace TRL {

	class AnalogSensor : public TRL::Sensor {
	protected:
		AnalogPort port;
	public:
		AnalogSensor();
		AnalogSensor(AnalogPort port);
		virtual ~AnalogSensor();
		virtual SensorType getSensorType() = 0;
		int getValue();
	};
}

#endif /* ANALOGSENSOR_H_ */
