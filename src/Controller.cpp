/*
 * Controller.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#include "TRL/Controller.h"

namespace TRL {

////////////////////////////////
//CONSTRUCTORS AND DESTRUCTORS//
////////////////////////////////

Controller::Controller() {
	this->masterShiftKey = ShiftBtn_None;
	this->slaveShiftKey = ShiftBtn_None;
	this->masterLeftStickDeadzoneMagnitude = 0;
	this->masterRightStickDeadzoneMagnitude = 0;
	this->slaveLeftStickDeadzoneMagnitude = 0;
	this->slaveRightStickDeadzoneMagnitude = 0;
}

Controller::~Controller() {
//	Destructor
}

////////////////////////////////
//GENERAL CONTROLLER FUNCTIONS//
////////////////////////////////
bool Controller::isInputInactive(ControllerInput in) {
	return (getValue(in) == 0);
}

bool Controller::isInputActive(ControllerInput in) {
	return !isInputInactive(in);
}

int Controller::getRawValue(ControllerInput in) {
	bool isAnalog = false;
	char channel = 0;
	char btn = 0;
	char controllerNum = getInputControllerNumber(in);

	in = convertControllerInputToNonShiftedVariant(in);

	//Controller number is set earlier so this simply allows less cases in the switch statement
	in = convertControllerInputToMasterVariant(in);

	switch (in) {
	case Btn5U:
		channel = 5;
		btn = JOY_UP;
		break;
	case Btn6U:
		channel = 6;
		btn = JOY_UP;
		break;
	case Btn7U:
		channel = 7;
		btn = JOY_UP;
		break;
	case Btn8U:
		channel = 8;
		btn = JOY_UP;
		break;
	case Btn5D:
		channel = 5;
		btn = JOY_DOWN;
		break;
	case Btn6D:
		channel = 6;
		btn = JOY_DOWN;
		break;
	case Btn7D:
		channel = 7;
		btn = JOY_DOWN;
		break;
	case Btn8D:
		channel = 8;
		btn = JOY_DOWN;
		break;
	case Btn7L:
		channel = 7;
		btn = JOY_LEFT;
		break;
	case Btn8L:
		channel = 8;
		btn = JOY_LEFT;
		break;
	case Btn7R:
		channel = 7;
		btn = JOY_RIGHT;
		break;
	case Btn8R:
		channel = 8;
		btn = JOY_RIGHT;
		break;
	case Ch1:
		channel = 1;
		isAnalog = true;
		break;
	case Ch2:
		channel = 2;
		isAnalog = true;
		break;
	case Ch3:
		channel = 3;
		isAnalog = true;
		break;
	case Ch4:
		channel = 4;
		isAnalog = true;
		break;
	case Accel_X:
		channel = ACCEL_X;
		isAnalog = true;
		break;
	case Accel_Y:
		channel = ACCEL_Y;
		isAnalog = true;
		break;
	default:
		println(ERROR, "Controller", "getRawValue",
				"INPUT#:%d This should never get called.", in);
		return 0;
	}
	if (isAnalog) {
		return joystickGetAnalog(controllerNum, channel);
	} else {
		if (joystickGetDigital(controllerNum, channel, btn)) {
			return 1;
		} else {
			return 0;
		}
	}
}

int Controller::getValue(ControllerInput in) {
	int value = 0;

	if (isControllerShifted(getInputControllerType(in))
			&& isShiftedInputType(in)) {
		value = getRawValue(in);
	} else if (!isControllerShifted(getInputControllerType(in))
			&& !isShiftedInputType(in)) {
		value = getRawValue(in);
	} else {
		value = 0;
	}

	if (getControllerInputType(in) == JOYSTICK) {
		ControllerStickSide joystickSide = getJoystickSide(in);
		switch (joystickSide) {
		case LEFT_JOYSTICK:
			if (abs(value) < abs(masterLeftStickDeadzoneMagnitude)) {
				return 0;
			} else {
				return value;
			}
		case RIGHT_JOYSTICK:
			if (abs(value) < abs(masterRightStickDeadzoneMagnitude)) {
				return 0;
			} else {
				return value;
			}
		default:
			println(ERROR, "Controller", "getValue",
					"This should never get called.");
			return 0;
		}
		println(ERROR, "Controller", "getValue",
				"This should never get called.");
		return 0;
	} else {
		return value;
	}
}

///////////////////////////////
//JOYSTICK DEADZONE FUNCTIONS//
///////////////////////////////

void Controller::setLeftStickDeadzone(ControllerType type, short deadzone) {
	switch (type) {
	case MASTER_CONTROLLER:
		this->masterLeftStickDeadzoneMagnitude = abs(deadzone);
		return;
	case SLAVE_CONTROLLER:
		this->slaveLeftStickDeadzoneMagnitude = abs(deadzone);
		return;
	}
}

void Controller::setRightStickDeadzone(ControllerType type, short deadzone) {
	switch (type) {
	case MASTER_CONTROLLER:
		this->masterRightStickDeadzoneMagnitude = abs(deadzone);
		return;
	case SLAVE_CONTROLLER:
		this->slaveRightStickDeadzoneMagnitude = abs(deadzone);
		return;
	}
}

void Controller::setJoystickDeadzone(ControllerType type, short deadzone) {
	setLeftStickDeadzone(type, deadzone);
	setRightStickDeadzone(type, deadzone);
}

///////////////////
//SHIFT FUNCTIONS//
///////////////////

void Controller::setShiftKey(ControllerType type, ControllerShiftButton input) {
	switch (type) {
	case MASTER_CONTROLLER:
		masterShiftKey = input;
		return;
	case SLAVE_CONTROLLER:
		slaveShiftKey = input;
		return;
	}
}

bool Controller::isControllerShifted(ControllerType type) {
	ControllerShiftButton shiftKey = ShiftBtn_None;
	switch (type) {
	case MASTER_CONTROLLER:
		shiftKey = masterShiftKey;
		break;
	case SLAVE_CONTROLLER:
		shiftKey = slaveShiftKey;
		break;
	}

	if ((int) shiftKey == (int) ShiftBtn_None) {
		return false;
	}

	if (getRawValue(getControllerInputForShiftBtn(type, shiftKey)) == 1) {
		return true;
	}
	return false;
}

bool Controller::isShiftedInputType(ControllerInput in) {
	//check ShiftedInput on master controller and slave controller
	if ((in >= ShiftedInput_Btn5U) && (in <= ShiftedInput_Accel_Y)) {
		return true;
	} else if ((in >= Partner_ShiftedInput_Btn5U)
			&& (in <= Partner_ShiftedInput_Accel_Y)) {
		return true;
	}
	return false;
}

bool Controller::isNonShiftedInputType(ControllerInput in) {
	return !isShiftedInputType(in);
}

bool Controller::isSlaveControllerInput(ControllerInput in) {
	in = convertControllerInputToNonShiftedVariant(in);
	if ((in >= Partner_Btn5U) && (in <= Partner_Accel_Y)) {
		return true;
	}
	return false;
}

bool Controller::isMasterControllerInput(ControllerInput in) {
	return !isSlaveControllerInput(in);
}

ControllerInput Controller::convertControllerInputToNonShiftedVariant(
		ControllerInput in) {
	if (isShiftedInputType(in)) {
		int shiftOffset = NUMBER_NON_SHIFTED_INPUTS;
		return (ControllerInput) (in - shiftOffset);
	} else {
		return in;
	}
}

ControllerInput Controller::convertControllerInputToShiftedVariant(
		ControllerInput in) {
	if (isNonShiftedInputType(in)) {
		int shiftOffset = NUMBER_NON_SHIFTED_INPUTS
		;
		return (ControllerInput) (in + shiftOffset);
	} else {
		return in;
	}
}

ControllerInput Controller::convertControllerInputToMasterVariant(
		ControllerInput in) {
	int controllerOffset = 2 * NUMBER_NON_SHIFTED_INPUTS
	;
	if (isSlaveControllerInput(in)) {
		return (ControllerInput) (in - controllerOffset);
	} else {
		return in;
	}
}

ControllerInput Controller::convertControllerInputToSlaveVariant(
		ControllerInput in) {
	int controllerOffset = 2 * NUMBER_NON_SHIFTED_INPUTS
	;
	if (isMasterControllerInput(in)) {
		return (ControllerInput) (in + controllerOffset);
	} else {
		return in;
	}
}

ControllerInput Controller::convertControllerInputToType(ControllerType type,
		ControllerInput in) {
	switch (type) {
	case MASTER_CONTROLLER:
		return convertControllerInputToMasterVariant(in);
	case SLAVE_CONTROLLER:
		return convertControllerInputToSlaveVariant(in);
	default:
		println(ERROR, "Controller", "convertControllerInputToType",
				"This should never get called.");
		return in;
	}
}

ControllerInput Controller::getControllerInputForShiftBtn(ControllerType type,
		ControllerShiftButton shiftBtn) {
	ControllerInput input = (ControllerInput) ((int) shiftBtn);
	return convertControllerInputToType(type, input);
}

//////////////////////////////////////////
//CONTROLLER INPUT INFROMATION FUNCTIONS//
//////////////////////////////////////////

ControllerInputType Controller::getControllerInputType(ControllerInput in) {
	in = convertControllerInputToNonShiftedVariant(in);
	if (in < Ch1) {
		return BUTTON;
	} else if (in > Ch4) {
		return ACCEL;
	} else {
		return JOYSTICK;
	}
}

ControllerStickSide Controller::getJoystickSide(ControllerInput in) {
	in = convertControllerInputToNonShiftedVariant(in);
	switch (in) {
	case Ch1:
		return RIGHT_JOYSTICK;
	case Ch2:
		return RIGHT_JOYSTICK;
	case Ch3:
		return LEFT_JOYSTICK;
	case Ch4:
		return LEFT_JOYSTICK;
	default:
		return NULL_JOYSTICK;
	}
}

ControllerType Controller::getInputControllerType(ControllerInput in) {
	if (isMasterControllerInput(in)) {
		return MASTER_CONTROLLER;
	} else {
		return SLAVE_CONTROLLER;
	}
}

int Controller::getInputControllerNumber(ControllerInput in) {
	if (isMasterControllerInput(in)) {
		return MASTER_CONTROLLER;
	} else {
		return SLAVE_CONTROLLER;
	}
}

} /* namespace TRL */
