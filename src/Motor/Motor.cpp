/*
 * Motor.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: guywenck
 */

#include "Motor/Motor.h"

namespace TRL {

Motor::Motor() {
	this->port = MotorPort_NULL;
	this->reversed = false;
	this->power = 0;
	this->rawPower = 0;
	this->powerPercent = 0;
	this->offset = 0;
	this->encoder = NULL;
	this->location = UnspecifiedMotorLocation;
	this->motorName = MOTOR_NAME_NULL;
}

Motor::Motor(MotorPort port, MotorLocation location, string motorName) {
	this->reversed = false;
	this->port = port;
	this->power = 0;
	this->rawPower = 0;
	this->powerPercent = 0;
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
	this->power = 0;
	this->rawPower = 0;
	this->powerPercent = 0;
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
	this->power = 0;
	this->rawPower = 0;
	this->powerPercent = 0;
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
	this->power = 0;
	this->rawPower = 0;
	this->powerPercent = 0;
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
	this->power = 0;
	this->rawPower = 0;
	this->powerPercent = 0;
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
	this->power = 0;
	this->rawPower = 0;
	this->powerPercent = 0;
	this->offset = offset;
	this->encoder = encoder;
	this->location = location;
	this->motorName = motorName;
	MotorRegistry::registerMotor(this);
}

Motor::~Motor() {
	//Nothing needs to be done when destroying this object
}

bool Motor::destroy() {
	return MotorRegistry::deleteRegistryEntry(this);
}

void Motor::setPower(int speed) {
	if (port == MotorPort_NULL) {
		println(ERROR, "Motor", "setPower",
				"Can't power a motor [%s] without an assigned port.", this->motorName);
		return;
	}

	this->rawPower = speed;

	if (!reversed) {
		motorSet(port, -speed);
	} else {
		motorSet(port, speed);
	}
}

void Motor::setAdjustedPower(int speed) {
	float percent = (float) speed / 127.f;
	setAdjustedPowerPercentage(percent);
}

void Motor::setAdjustedPowerPercentage(float percent) {
	float raw;
	bool negative = false;

	if (percent < 0) {
		negative = true;
		percent = -percent;
	}

	//add offset
	percent += ((float) offset / 127.f);

	if ((percent != 0) && (percent != 1)) {
		raw = (1142.960337f * pow(percent, 6))
				+ (-2020.933431f * pow(percent, 5))
				+ (953.2769417f * pow(percent, 4))
				+ (223.0240568f * pow(percent, 3))
				+ (-261.678053f * pow(percent, 2)) + (87.55209092f * percent)
				+ 1.736995488f;
	} else {
		raw = percent * 127;
	}

	if (negative) {
		raw = -raw;
	}

	this->power = (int) (127 * percent);
	this->powerPercent = percent;

	setPower((int) raw);
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
		return LeftMotorLocationSide;
	case RightMotorLocation:
		return RightMotorLocationSide;
	case FrontRightMotorLocation:
		return RightMotorLocationSide;
	case FrontLeftMotorLocation:
		return LeftMotorLocationSide;
	case BackRightMotorLocation:
		return RightMotorLocationSide;
	case BackLeftMotorLocation:
		return LeftMotorLocationSide;
	case CenterRightMotorLocation:
		return RightMotorLocationSide;
	case CenterLeftMotorLocation:
		return LeftMotorLocationSide;
	default:
		return NoSide;
	}
}

void Motor::reverseDirection() {
	printf("%d : ", reversed);
	reversed = !reversed;
	printf("%d\n\r", reversed);
}

void Motor::setAllRawPower(int speed) {
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
