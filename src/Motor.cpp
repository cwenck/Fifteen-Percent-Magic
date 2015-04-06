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
	this->offset = 0;
	this->encoder = NULL;
	this->location = UnspecifiedMotorLocation;
	this->motorName = MOTOR_NAME_NULL;
}

Motor::Motor(MotorPort port, MotorLocation location, string motorName) {
	this->reversed = false;
	this->port = port;
	this->speed = 0;
	this->offset = 0;
	this->encoder = NULL;
	this->location = location;
	this->motorName = motorName;
	MotorRegistry::registerMotor(this);
}

Motor::Motor(MotorPort port, MotorLocation location, string motorName,
		short offset) {
	this->reversed = false;
	this->port = port;
	this->speed = 0;
	this->offset = offset;
	this->encoder = NULL;
	this->location = location;
	this->motorName = motorName;
	MotorRegistry::registerMotor(this);
}

Motor::Motor(MotorPort port, MotorLocation location, string motorName,
		bool reversed) {
	this->port = port;
	this->reversed = reversed;
	this->speed = 0;
	this->offset = 0;
	this->encoder = NULL;
	this->location = location;
	this->motorName = motorName;
	MotorRegistry::registerMotor(this);
}

Motor::Motor(MotorPort port, MotorLocation location, string motorName,
		bool reversed, short offset) {
	this->port = port;
	this->reversed = reversed;
	this->speed = 0;
	this->offset = 0;
	this->encoder = NULL;
	this->location = location;
	this->motorName = motorName;
	MotorRegistry::registerMotor(this);
}

Motor::Motor(MotorPort port, MotorLocation location, string motorName,
		GenericEncoder* encoder, bool reversed) {
	this->port = port;
	this->reversed = reversed;
	this->speed = 0;
	this->offset = 0;
	this->encoder = encoder;
	this->location = location;
	this->motorName = motorName;
	MotorRegistry::registerMotor(this);
}

Motor::Motor(MotorPort port, MotorLocation location, string motorName,
		GenericEncoder* encoder, bool reversed, short offset) {
	this->port = port;
	this->reversed = reversed;
	this->speed = 0;
	this->offset = offset;
	this->encoder = encoder;
	this->location = location;
	this->motorName = motorName;
	MotorRegistry::registerMotor(this);
}

Motor::~Motor() {
	//Nothing needs to be done when destroying this object
}

bool Motor::removeFromRegistry(){
	return MotorRegistry::deleteRegistryEntry(this);
}

int Motor::addOffsetToSpeed(int speed) {
	int absSpeed = abs(speed);
	if (speed < 0) {
		return -(absSpeed + offset);
	} else {
		return (absSpeed + offset);
	}

}

void Motor::setPower(int motorSpeed) {
	if (port == MotorPort_NULL) {
		println(ERROR, "Motor", "setPower",
				"Can't power a motor without an assigned port.");
		return;
	}
	this->speed = addOffsetToSpeed(motorSpeed);

	if (!reversed) {
		motorSet(port, -speed);
	} else {
		motorSet(port, speed);
	}
}

void Motor::stop() {
	if (port == MotorPort_NULL) {
		println(ERROR, "Motor", "stop",
				"Can't stop a motor without an assigned port.");
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
	case LeftMotorLocation:
		return LeftSide;
	case RightMotorLocation:
		return RightSide;
	case FrontRightMotorLocation:
		return RightSide;
	case FrontLeftMotorLocation:
		return LeftSide;
	case BackRightMotorLocation:
		return RightSide;
	case BackLeftMotorLocation:
		return LeftSide;
	case CenterRightMotorLocation:
		return RightSide;
	case CenterLeftMotorLocation:
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
	for (int i = 1; i <= 10; i++) {
		motorSet(i, speed);
	}
}

void Motor::stopAll() {
	motorStopAll();
}

string Motor::getName() {
	return motorName;
}

}
