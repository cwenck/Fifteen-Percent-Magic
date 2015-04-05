/*
 * LineSensor.h
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#ifndef LINESENSOR_H_
#define LINESENSOR_H_

#include "TRL_BaseInitialization.h"
#include "AnalogSensor.h"

namespace TRL {

	class LineSensor : public AnalogSensor {
	public:
		LineSensor();
		LineSensor(AnalogPort port);
		virtual ~LineSensor();
	};
}

#endif /* LINESENSOR_H_ */
