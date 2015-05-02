/*
 * Controller.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#include "TRL/Controller.h"

namespace TRL {
//////////////////////////
//CONTROLLER STICK START//
//////////////////////////

ControllerStick* ControllerStick::leftMaster;
ControllerStick* ControllerStick::rightMaster;
ControllerStick* ControllerStick::leftSlave;
ControllerStick* ControllerStick::rightSlave;

ControllerStick* ControllerStick::shiftedLeftMaster;
ControllerStick* ControllerStick::shiftedRightMaster;
ControllerStick* ControllerStick::shiftedLeftSlave;
ControllerStick* ControllerStick::shiftedRightSlave;

void ControllerStick::initStatics() {
	leftMaster = new ControllerStick(Controller::instance, Ch4, Ch3);
	rightMaster = new ControllerStick(Controller::instance, Ch1, Ch2);
	leftSlave = new ControllerStick(Controller::instance, Partner_Ch4,
			Partner_Ch3);
	rightSlave = new ControllerStick(Controller::instance, Partner_Ch1,
			Partner_Ch2);

	shiftedLeftMaster = new ControllerStick(Controller::instance,
			ShiftedInput_Ch4, ShiftedInput_Ch3);
	shiftedRightMaster = new ControllerStick(Controller::instance,
			ShiftedInput_Ch1, ShiftedInput_Ch2);
	shiftedLeftSlave = new ControllerStick(Controller::instance,
			Partner_ShiftedInput_Ch4, Partner_ShiftedInput_Ch3);
	shiftedRightSlave = new ControllerStick(Controller::instance,
			Partner_ShiftedInput_Ch1, Partner_ShiftedInput_Ch2);
}

ControllerStick::ControllerStick(Controller* controller,
		ControllerInput xChannel, ControllerInput yChannel) {
	this->controller = controller;
	this->xCh = xChannel;
	this->yCh = yChannel;
}

float ControllerStick::getStickAngle() {
	int y = controller->getValue(yCh);
	int x = controller->getValue(xCh);

	float angle = (atan2(y, x) * 180 / (PI)) - 90;

	if (angle < -180) {
		angle += 360;
	}
	angle *= -1;
	return angle;
}

int ControllerStick::getX() {
	return controller->getValue(xCh);
}

int ControllerStick::getY() {
	return controller->getValue(yCh);
}

ControllerType ControllerStick::getControllerType() {
	if (this == leftMaster || this == rightMaster || this == leftSlave
			|| this == rightSlave) {
		return MASTER_CONTROLLER;
	} else {
		return SLAVE_CONTROLLER;
	}
}

ControllerType ControllerStick::getControllerType(ControllerStick* stick) {
	if (stick == leftMaster || stick == rightMaster || stick == leftSlave
			|| stick == rightSlave) {
		return MASTER_CONTROLLER;
	} else {
		return SLAVE_CONTROLLER;
	}
}

ControllerStick* ControllerStick::getCorrespondingStickForControllerType(
		ControllerType type) {
	if (this->getControllerType() == type) {
		return this;
	} else {
		if (this == leftMaster) {
			return leftSlave;
		} else if (this == rightMaster) {
			return rightSlave;
		} else if (this == leftSlave) {
			return leftMaster;
		} else if (this == rightSlave) {
			return rightMaster;
		} else if (this == shiftedLeftMaster) {
			return shiftedLeftSlave;
		} else if (this == shiftedRightMaster) {
			return shiftedRightSlave;
		} else if (this == shiftedLeftSlave) {
			return shiftedLeftMaster;
		} else if (this == shiftedRightSlave) {
			return shiftedRightMaster;
		} else {
			println(ERROR, "ControllerStick",
					"getCorrespondingStickForControllerType",
					"This should never get called.");
			return NULL;
		}
	}
}

ControllerStick* ControllerStick::getCorrespondingStickForControllerType(
		ControllerType type, ControllerStick* stick) {
	if (stick->getControllerType() == type) {
		return stick;
	} else {
		if (stick == leftMaster) {
			return leftSlave;
		} else if (stick == rightMaster) {
			return rightSlave;
		} else if (stick == leftSlave) {
			return leftMaster;
		} else if (stick == rightSlave) {
			return rightMaster;
		} else if (stick == shiftedLeftMaster) {
			return shiftedLeftSlave;
		} else if (stick == shiftedRightMaster) {
			return shiftedRightSlave;
		} else if (stick == shiftedLeftSlave) {
			return shiftedLeftMaster;
		} else if (stick == shiftedRightSlave) {
			return shiftedRightMaster;
		} else {
			println(ERROR, "ControllerStick",
					"getCorrespondingStickForControllerType",
					"This should never get called.");
			return NULL;
		}
	}
}

////////////////////////
//CONTROLLER STICK END//
////////////////////////

////////////////////
//CONTROLLER START//
////////////////////

Controller* Controller::instance;

void Controller::initInstance() {
	instance = new Controller();
	ControllerStick::initStatics();
}

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

	ControllerType type = getInputControllerType(in);

	if (getControllerInputType(in) == JOYSTICK) {
		ControllerStickSide joystickSide = getJoystickSide(in);
		switch (type) {
		case MASTER_CONTROLLER:
			switch (joystickSide) {
			case LEFT_JOYSTICK:
				if (abs(value) <= abs(masterLeftStickDeadzoneMagnitude)) {
					return 0;
				} else {
					return value;
				}
			case RIGHT_JOYSTICK:
				if (abs(value) <= abs(masterRightStickDeadzoneMagnitude)) {
					return 0;
				} else {
					return value;
				}
			default:
				println(ERROR, "Controller", "getValue",
						"This should never get called.");
				return 0;
			}
			break;
		case SLAVE_CONTROLLER:
			switch (joystickSide) {
			case LEFT_JOYSTICK:
				if (abs(value) <= abs(slaveLeftStickDeadzoneMagnitude)) {
					return 0;
				} else {
					return value;
				}
			case RIGHT_JOYSTICK:
				if (abs(value) <= abs(slaveRightStickDeadzoneMagnitude)) {
					return 0;
				} else {
					return value;
				}
			default:
				println(ERROR, "Controller", "getValue",
						"This should never get called.");
				return 0;
			}
			break;
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
		int shiftOffset = NUMBER_NON_SHIFTED_INPUTS;
		return (ControllerInput) (in + shiftOffset);
	} else {
		return in;
	}
}

ControllerInput Controller::convertControllerInputToMasterVariant(
		ControllerInput in) {
	int controllerOffset = 2 * NUMBER_NON_SHIFTED_INPUTS;
	if (isSlaveControllerInput(in)) {
		return (ControllerInput) (in - controllerOffset);
	} else {
		return in;
	}
}

ControllerInput Controller::convertControllerInputToSlaveVariant(
		ControllerInput in) {
	int controllerOffset = 2 * NUMBER_NON_SHIFTED_INPUTS;
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
	in = convertControllerInputToMasterVariant(in);
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
	in = convertControllerInputToMasterVariant(in);
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
