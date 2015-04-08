/*
 * AnalogSensor.h
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#ifndef ANALOGSENSOR_H_
#define ANALOGSENSOR_H_

#include "../TRL/TRL_BaseIncludes.h"
#include "SensorRegistry.h"
#include "Sensor.h"

namespace TRL {

	class AnalogSensor : public Sensor {
	protected:
		AnalogPort port;
	public:
		AnalogSensor();
		AnalogSensor(AnalogPort port, Sensor* childSensor);
		virtual ~AnalogSensor();
		
		bool destory();

		int getValue();
		virtual SensorType getSensorType() = 0;
		virtual string getSensorName() = 0;
	};
}

#endif /* ANALOGSENSOR_H_ */
