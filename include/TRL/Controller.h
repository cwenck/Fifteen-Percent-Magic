/*
 * Controller.h
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "TRL_BaseInitialization.h"

#define NUMBER_NON_SHIFTED_INPUTS 18;

namespace TRL {
class Controller {
	private:
		ControllerType type;
		ControllerShiftInput shiftKey;
		short leftStickDeadzoneMagnitude;
		short rightStickDeadzoneMagnitude;
	public:
		//CONSTRUCTORS AND DESTRUCTOR//
		Controller();
		Controller(ControllerType type);
		Controller(ControllerType type, short leftStickDeadzoneMagnitude, short rightStickDeadzoneMagnitude);
		Controller(ControllerType type, ControllerShiftInput shiftKey);
		Controller(ControllerType type, ControllerShiftInput shiftKey, short leftStickDeadzoneMagnitude, short rightStickDeadzoneMagnitude);
		virtual ~Controller();

		//GENERAL CONTROLLER FUNCTIONS//
		bool isInputInactive(ControllerInput in);
		bool isInputActive(ControllerInput in);

		int getRawValue(ControllerInput in);
		int getValue(ControllerInput in);

		//DEADZONE FUNCTIONS//
		void setLeftStickDeadzone(short deadzone);
		void setRightStickDeadzone(short deadzone);
		void setJoystickDeadzone(short deadzone);

		//SHIFT FUNCTIONS//
		void setShiftKey(ControllerShiftInput input);
		bool isControllerShifted(); //returns true if the controller's shift button is pressed
		bool isShiftedInputType(ControllerInput in);
		ControllerInput convertControllerInputToNonShiftedVariant(ControllerInput in);

		//CONTROLLER INPUT INFO FUNCTIONS//
		ControllerInputType getControllerInputType(ControllerInput in);
		ControllerStickSide getJoystickSide(ControllerInput in);
		int getControllerNumber();


	};
}
#endif /* CONTROLLER_H_ */
