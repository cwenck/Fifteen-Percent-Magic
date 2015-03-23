/*
 * Controller.h
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "TRL_BaseInitialization.h"

namespace TRL {
	class Controller {
	private:
		ControllerType type;
		ControllerShiftInput shiftKey;
		short leftStickDeadzoneMagnitude;
		short rightStickDeadzoneMagnitude;
	public:
		Controller();
		Controller(ControllerType type);
		Controller(ControllerType type, short leftStickDeadzoneMagnitude, short rightStickDeadzoneMagnitude);
		Controller(ControllerType type, ControllerShiftInput shiftKey);
		Controller(ControllerType type, ControllerShiftInput shiftKey, short leftStickDeadzoneMagnitude, short rightStickDeadzoneMagnitude);
		virtual ~Controller();
		int getRawValue(ControllerInput in);
		int getValue(ControllerInput in);
		ControllerInput convertControllerInputToNonShiftedVariant(ControllerInput in);
		bool isControllerShifted(); //returns true if the controller's shift button is pressed
		bool isShiftedInputType(ControllerInput in);
		void setShiftKey(ControllerShiftInput input);
		ControllerInputType getControllerInputType(ControllerInput in);

		//threshold is only used for joystick inputs
		bool isInputInactive(ControllerInput in);
		bool isInputInactive(ControllerInput in, short threshold);

		//threshold is only used for joystick inputs
		bool isInputActive(ControllerInput in);
		bool isInputActive(ControllerInput in, short threshold);
	};
}
#endif /* CONTROLLER_H_ */
