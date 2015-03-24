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
	this->type = Master_Controller;
	this->shiftKey = ShiftBtn_None;
	this->leftStickDeadzoneMagnitude = 0;
	this->rightStickDeadzoneMagnitude = 0;
}

Controller::Controller(ControllerType type) {
	this->type = type;
	this->shiftKey = ShiftBtn_None;
	this->leftStickDeadzoneMagnitude = 0;
	this->rightStickDeadzoneMagnitude = 0;
}
Controller::Controller(ControllerType type, short leftStickDeadzoneMagnitude,
		short rightStickDeadzoneMagnitude) {
	this->type = type;
	this->shiftKey = ShiftBtn_None;
	this->leftStickDeadzoneMagnitude = abs(leftStickDeadzoneMagnitude);
	this->rightStickDeadzoneMagnitude = abs(rightStickDeadzoneMagnitude);
}

Controller::Controller(ControllerType type, ControllerShiftInput shiftKey) {
	this->type = type;
	this->shiftKey = shiftKey;
	this->leftStickDeadzoneMagnitude = 0;
	this->rightStickDeadzoneMagnitude = 0;
}

Controller::Controller(ControllerType type, ControllerShiftInput shiftKey,
		short leftStickDeadzoneMagnitude, short rightStickDeadzoneMagnitude) {
	this->type = type;
	this->shiftKey = shiftKey;
	this->leftStickDeadzoneMagnitude = abs(leftStickDeadzoneMagnitude);
	this->rightStickDeadzoneMagnitude = abs(rightStickDeadzoneMagnitude);
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
	char channel = 0;
	char btn = 0;
	char controllerNum = (int) type;

	in = convertControllerInputToNonShiftedVariant(in);

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
		break;
	case Ch2:
		channel = 2;
		break;
	case Ch3:
		channel = 3;
		break;
	case Ch4:
		channel = 4;
		break;
	case Accel_X:
		channel = ACCEL_X;
		break;
	case Accel_y:
		channel = ACCEL_Y;
		break;
	default:
		println(ERROR, "Controller", "getRawValue",
				"This should never get called.");
		return 0;
	}
	if (channel
			== 1|| channel == 2 || channel == 3 || channel == 4 || ACCEL_X || ACCEL_Y) {
		return joystickGetAnalog(controllerNum,channel);
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
	if (isControllerShifted() && isShiftedInputType(in)) {
		value = getRawValue(in);
	} else if (!isControllerShifted() && !isShiftedInputType(in)) {
		value = getRawValue(in);
	} else {
		value = 0;
	}

	if (getControllerInputType(in) == JOYSTICK) {
		ControllerStickSide joystickSide = getJoystickSide(in);
		switch (joystickSide) {
		case LEFT_JOYSTICK:
			if (abs(value) < abs(leftStickDeadzoneMagnitude)) {
				return 0;
			} else {
				return value;
			}
		case RIGHT_JOYSTICK:
			if (abs(value) < abs(rightStickDeadzoneMagnitude)) {
				return 0;
			} else {
				return value;
			}
		case NULL_JOYSTICK:
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

void Controller::setLeftStickDeadzone(short deadzone) {
	this->leftStickDeadzoneMagnitude = abs(deadzone);
}

void Controller::setRightStickDeadzone(short deadzone) {
	this->rightStickDeadzoneMagnitude = abs(deadzone);
}

void Controller::setJoystickDeadzone(short deadzone){
	setLeftStickDeadzone(deadzone);
	setRightStickDeadzone(deadzone);
}

///////////////////
//SHIFT FUNCTIONS//
///////////////////

void Controller::setShiftKey(ControllerShiftInput input) {
	shiftKey = input;
}

bool Controller::isControllerShifted() {
	ControllerInput shift = (ControllerInput) ((int) shiftKey);
	if (getValue(shift) != 0) {
		return true;
	} else {
		return false;
	}
}

bool Controller::isShiftedInputType(ControllerInput in) {
	if (((int) in <= (int) ShiftedInput_Ch4)
			&& ((int) in >= (int) ShiftedInput_Btn5U)) {
		return true;
	} else if (((int) in <= (int) Ch4) && ((int) in >= (int) Btn5U)) {
		return false;
	}
	return false;
}

ControllerInput Controller::convertControllerInputToNonShiftedVariant(
		ControllerInput in) {
	if (isShiftedInputType(in)) {
		int shiftOffset = NUMBER_NON_SHIFTED_INPUTS
		;
		return (ControllerInput) ((int) in - shiftOffset);
	} else {
		return in;
	}
}

//////////////////////////////////////////
//CONTROLLER INPUT INFROMATION FUNCTIONS//
//////////////////////////////////////////

ControllerInputType Controller::getControllerInputType(ControllerInput in) {
	if (in < Ch1) {
		return BUTTON;
	} else {
		return JOYSTICK;
	}
}

ControllerStickSide Controller::getJoystickSide(ControllerInput in) {
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

} /* namespace TRL */
