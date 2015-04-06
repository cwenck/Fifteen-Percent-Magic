/*
 * LimitSwitch.h
 *
 *  Created on: Apr 5, 2015
 *      Author: guywenck
 */

#ifndef LIMITSWITCH_H_
#define LIMITSWITCH_H_

#include "TRL_BaseInitialization.h"
#include "DigitalSwitch.h"

namespace TRL {
	class LimitSwitch : public DigitalSwitch {
	public:
		LimitSwitch();
		LimitSwitch(AnalogPort port);
		LimitSwitch(DigitalPort port);
		virtual ~LimitSwitch();
	};
}

#endif /* LIMITSWITCH_H_ */