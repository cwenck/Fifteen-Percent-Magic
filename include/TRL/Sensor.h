/*
 * Sensor.h
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include "TRL_BaseInitialization.h"

namespace TRL {

	class Sensor {
	public:
		Sensor();
		virtual ~Sensor();

		virtual int getValue() = 0;
		virtual SensorType getSensorType() = 0;
	};
}
#endif /* SENSOR_H_ */
