/*
 * Bumper.h
 *
 *  Created on: Apr 5, 2015
 *      Author: guywenck
 */

#ifndef BUMPER_H_
#define BUMPER_H_

#include "../TRL/TRL_BaseIncludes.h"
#include "DigitalSwitch.h"

namespace TRL {
	class Bumper : public DigitalSwitch {
	public:
		Bumper();
		Bumper(AnalogPort port);
		Bumper(DigitalPort port);
		virtual ~Bumper();

		SensorType getSensorType();
		string getSensorName();
	};
}
#endif /* BUMPER_H_ */
