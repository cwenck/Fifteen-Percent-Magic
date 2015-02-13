/*
 * Button.h
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "Sensor.h"

namespace TRL {

	class Button : public TRL::Sensor {
	public:
		Button();
		virtual ~Button();
	};
}

#endif /* BUTTON_H_ */
