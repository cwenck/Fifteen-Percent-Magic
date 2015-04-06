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

	class AnalogSensor : public Sensor {
	protected:
		AnalogPort port;
		SensorType type;
	public:
		AnalogSensor();
		AnalogSensor(AnalogPort port, SensorType type);
		virtual ~AnalogSensor();
		
		bool removeFromRegistry();

		SensorType getSensorType();
		int getValue();
	};
}

#endif /* ANALOGSENSOR_H_ */
