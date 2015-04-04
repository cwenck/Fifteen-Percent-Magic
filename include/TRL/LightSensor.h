/*
 * LightSensor.h
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#ifndef LIGHTSENSOR_H_
#define LIGHTSENSOR_H_

#include "TRL_BaseInitialization.h"

namespace TRL {

	class LightSensor {
	private:
		AnalogPort port;
	public:
		LightSensor();
		LightSensor(AnalogPort port);
		virtual ~LightSensor();
	};

}

#endif /* LIGHTSENSOR_H_ */
