/*
 * PowerExpander.h
 *
 *  Created on: May 1, 2015
 *      Author: guywenck
 */

#ifndef POWEREXPANDER_H_
#define POWEREXPANDER_H_

#include "../TRL/TRL_BaseIncludes.h"
#include "AnalogSensor.h"

#define POWER_EXPANDER_DIVISOR_1 45.6f
#define POWER_EXPANDER_DIVISOR_2 70.f

namespace TRL {
	class PowerExpander : public AnalogSensor {
	public:
		PowerExpander();
		PowerExpander(AnalogPort port);
		virtual ~PowerExpander();

		float getVoltage();

		SensorType getSensorType();
		string getSensorName();
	};
}

#endif /* POWEREXPANDER_H_ */
