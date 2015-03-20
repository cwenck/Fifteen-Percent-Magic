/*
 * Controller.h
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <API.h>

namespace TRL {
	typedef enum _ControllerInput {
		Btn5U = 1,
		Btn6U = 2,
		Btn7U = 3,
		Btn8U = 4,
		Btn5D = 5,
		Btn6D = 6,
		Btn7D = 7,
		Btn8D = 8,
		Btn7L = 9,
		Btn8L = 10,
		Btn7R = 11,
		Btn8R = 12,
		Ch1 = 13,
		Ch2 = 14,
		Ch3 = 15,
		Ch4 = 16,
	}ControllerInput;

	typedef enum _ControllerShiftInput {
		Shift_NoInput = 0,
		Shift_Btn5U = 1,
		Shift_Btn6U = 2,
		Shift_Btn7U = 3,
		Shift_Btn8U = 4,
		Shift_Btn5D = 5,
		Shift_Btn6D = 6,
		Shift_Btn7D = 7,
		Shift_Btn8D = 8,
		Shift_Btn7L = 9,
		Shift_Btn8L = 10,
		Shift_Btn7R = 11,
		Shift_Btn8R = 12,
	}ControllerShiftInput;

	typedef enum _ControllerType {
		Main_Controller = 1,
		Partner_Controller = 2
	}ControllerType;

	typedef enum _ControllerInputType{
		BUTTON,
		JOYSTICK
	}ControllerInputType;

	class Controller {
	private:
		ControllerType type;
		ControllerShiftInput shiftKey;
	public:
		Controller();
		Controller(ControllerType type);
		Controller(ControllerType type, ControllerShiftInput shiftKey);
		virtual ~Controller();
		int getValue(ControllerInput in);
		bool isShifted();
		void setShiftKey(ControllerShiftInput input);
		ControllerInputType getControllerInputType(ControllerInput in);
		bool isInputInactive(ControllerInput in);
		//threshold is only used for joystick inputs
		bool isInputInactive(ControllerInput in, short threshold);
	};
}
#endif /* CONTROLLER_H_ */
