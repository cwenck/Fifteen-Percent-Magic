/*
 * Controller.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#include "TRL/Controller.h"

namespace TRL {

Controller::Controller(){
	this->type = Normal_Controller;
	this->shiftKey = Shift_NoInput;
}

Controller::Controller(ControllerType type) {
	this->type = type;
	this->shiftKey = Shift_NoInput;
}

Controller::Controller(ControllerType type, ControllerShiftInput shiftKey){
	this->type = type;
	this->shiftKey = shiftKey;
}

Controller::~Controller(){
//	Destructor
}

void Controller::setShiftKey(ControllerShiftInput input){
	shiftKey = input;
}

bool Controller::isShifted() {
	ControllerInput shift = (ControllerInput) ((int) shiftKey);
	if(getValue(shift) != 0){
		return true;
	} else {
		return false;
	}
}

int Controller::getValue(ControllerInput in) {
	char channel = 0;
	char btn = 0;
	char controllerNum = (int) type;

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
	}
	if (channel == 1 || channel == 2 || channel == 3 || channel == 4) {
		return joystickGetAnalog(controllerNum, channel);
	} else {
		if (joystickGetDigital(controllerNum, channel, btn)) {
			return 1;
		} else {
			return 0;
		}
	}
}

} /* namespace TRL */
