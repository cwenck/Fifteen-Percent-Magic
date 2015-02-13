/*
 * Sensor.h
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#ifndef SENSOR_H_
#define SENSOR_H_

namespace TRL {

	typedef enum _DigitalPort {
		Digital_1 = 1,
		Digital_2 = 2,
		Digital_3 = 3,
		Digital_4 = 4,
		Digital_5 = 5,
		Digital_6 = 6,
		Digital_7 = 7,
		Digital_8 = 8,
		Digital_9 = 9,
		Digital_10 = 10,
		Digital_11 = 11,
		Digital_12 = 12
	}DigitalPort;

	typedef enum _AnalogPort
	{
		Analog_1 = 1,
		Analog_2 = 2,
		Analog_3 = 3,
		Analog_4 = 4,
		Analog_5 = 5,
		Analog_6 = 6,
		Analog_7 = 7,
		Analog_8 = 8
	} AnalogPort;

	class Sensor {
	public:
		Sensor();
		virtual ~Sensor();

		virtual int getValue() = 0;
	};
}
#endif /* SENSOR_H_ */
