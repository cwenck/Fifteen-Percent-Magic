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

	class Button : public TRL::Sensor {
	private:
		UniversalPort port;
	public:
		Button();
		virtual ~Button();

		void setPort(AnalogPort port);
		void setPort(DigitalPort port);
	};
}

#endif /* BUTTON_H_ */
