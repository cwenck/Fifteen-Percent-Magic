/*
 * Button.h
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "TRL_BaseInitialization.h"
#include "Sensor.h"


namespace TRL {

	class DigitalSwitch : Sensor {
	private:
		UniversalPort port;
	public:
		DigitalSwitch();
		DigitalSwitch(AnalogPort port);
		DigitalSwitch(DigitalPort port);
		virtual ~DigitalSwitch();

		UniversalPort getPort();
		void setPort(AnalogPort port);
		void setPort(DigitalPort port);

		int getValue();
		SensorType getSensorType();
	};
}

#endif /* BUTTON_H_ */
