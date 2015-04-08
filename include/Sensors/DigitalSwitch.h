/*
 * Button.h
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../TRL/TRL_BaseIncludes.h"
#include "SensorRegistry.h"
#include "Sensor.h"


namespace TRL {

	class DigitalSwitch : public Sensor {
	private:
		UniversalPort port;
	public:
		DigitalSwitch();
		DigitalSwitch(AnalogPort port, Sensor* childSensor);
		DigitalSwitch(DigitalPort port, Sensor* childSensor);
		virtual ~DigitalSwitch();

		bool destroy();

		UniversalPort getPort();
		void setPort(AnalogPort port);
		void setPort(DigitalPort port);

		int getValue();
		virtual SensorType getSensorType() = 0;
		virtual string getSensorName() = 0;
	};
}

#endif /* BUTTON_H_ */
