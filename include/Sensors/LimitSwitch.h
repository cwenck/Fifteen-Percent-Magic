/*
 * LimitSwitch.h
 *
 *  Created on: Apr 5, 2015
 *      Author: guywenck
 */

#ifndef LIMITSWITCH_H_
#define LIMITSWITCH_H_

#include "../TRL/TRL_BaseIncludes.h"
#include "DigitalSwitch.h"

namespace TRL {
	class LimitSwitch : public DigitalSwitch {
	public:
		LimitSwitch();
		LimitSwitch(AnalogPort port);
		LimitSwitch(DigitalPort port);
		virtual ~LimitSwitch();

		SensorType getSensorType();
		string getSensorName();
	};
}

#endif /* LIMITSWITCH_H_ */
