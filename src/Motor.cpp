/*
 * Motor.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: guywenck
 */

#include "TRL/Motor.h"

namespace TRL {

Motor::Motor() {
	this->port = MotorPort_NULL;
	this->reversed = false;
	this->speed = 0;
	this->encoder = NULL;
	this->location = NullMotorLocation;
}

Motor::Motor(MotorPort port, MotorLocation location) {
	this->reversed = false;
	this->port = port;
	this->speed = 0;
	this->encoder = NULL;
	this->location = location;
}

Motor::Motor(MotorPort port, MotorLocation location, bool reversed) {
	this->port = port;
	this->reversed = reversed;
	this->speed = 0;
	this->encoder = NULL;
	this->location = location;
}

Motor::Motor(MotorPort port, MotorLocation location, GenericEncoder* encoder,
		bool reversed) {
	this->port = port;
	this->reversed = reversed;
	this->speed = 0;
	this->encoder = encoder;
	this->location = location;
}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

void Motor::setPower(int motorSpeed) {
	if (port == MotorPort_NULL) {
		printf("Motor port not assigned to motor.\n\r");
		return;
	}
	speed = motorSpeed;
	if (!reversed) {
		motorSet(port, -speed);
	} else {
		motorSet(port, speed);
	}
}

void Motor::stop() {
	if (port == MotorPort_NULL) {
		printf("Motor port not assigned to motor.\n\r");
		return;
	}
	motorStop(port);
}

MotorPort Motor::getPort() {
	return port;
}

GenericEncoder* Motor::getEncoder() {
	return encoder;
}

MotorLocation Motor::getLocation() {
	return location;
}

MotorLocationSide Motor::getLocationSide() {
	switch (location) {
	case Left:
		return LeftSide;
	case Right:
		return RightSide;
	case FrontRight:
		return RightSide;
	case FrontLeft:
		return LeftSide;
	case BackRight:
		return RightSide;
	case BackLeft:
		return LeftSide;
	case CenterRight:
		return RightSide;
	case CenterLeft:
		return LeftSide;
	default:
		return NoSide;
	}
}

void Motor::reverseDirection() {
	printf("%d : ", reversed);
	reversed = !reversed;
	printf("%d\n\r", reversed);
}

void Motor::setAllPower(int speed) {
	for (int i = 1; i < 10; i++) {
		motorSet(i, speed);
	}
}

void Motor::stopAll() {
	motorStopAll();
}

}
