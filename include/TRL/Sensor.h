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
	protected:
		UniversalPort port_one;
		UniversalPort port_two;
		bool usesTwoPorts;
	public:
		Sensor();

		Sensor(AnalogPort port);
		Sensor(DigitalPort port);
		Sensor(UniversalPort port);

		Sensor(AnalogPort portOne, AnalogPort portTwo);
		Sensor(DigitalPort portOne, DigitalPort portTwo);
		Sensor(UniversalPort portOne, UniversalPort portTwo);

		virtual ~Sensor();

		virtual int getValue() = 0;
		virtual SensorType getSensorType() = 0;
		virtual string getSensorName() = 0;

		bool isTwoPortSensor();

		UniversalPort getMainPort();

		//Returns UNIVERSAL_SENSOR_NULL if this sensor doens't have a secondary port
		UniversalPort getSecondaryPort();
	};
}
#endif /* SENSOR_H_ */
