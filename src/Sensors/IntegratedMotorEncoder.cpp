/*
 * IntegratedMotorEncoder.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: guywenck
 */

#include "Sensors/IntegratedMotorEncoder.h"

namespace TRL {

int IntegratedMotorEncoder::numberInitialized;

IntegratedMotorEncoder::IntegratedMotorEncoder() {
	this->port = NoIntegratedEncoderInput;
}

IntegratedMotorEncoder::IntegratedMotorEncoder(IntegratedEncoderPort port) {
	if (numberInitialized == 0) {
		initAllIntegratedEncoders();
	}
	if (port < numberInitialized) {
		this->port = port;
	} else {
		println(ERROR, "IntegratedMotorEncoder", "IntegratedMotorEncoder",
				"IME not initialized. The encoder at the specified port was never initialized.");
	}
}

IntegratedMotorEncoder::~IntegratedMotorEncoder() {
}

int IntegratedMotorEncoder::initAllIntegratedEncoders() {
	println("start");
	if (numberInitialized != 0) {
		imeShutdown();
		delay(250);
	}
	numberInitialized = imeInitializeAll();
	println("end");
	return numberInitialized;
}

float IntegratedMotorEncoder::getRPM(MotorGearing gearing) {
	int rawValue;
	imeGetVelocity((int) port, &rawValue);
	switch (gearing) {
	case TorqueGearing:
		return (float) rawValue / 39.2f;
	case SpeedGearing:
		return (float) rawValue / 24.5f;
	case TurboGearing:
		return (float) rawValue / 16.33125f;
	default:
		println(ERROR, "IntegratedMotorEncoder", "getRPM",
				"This should never get called");
		return 0;
	}
}

int IntegratedMotorEncoder::getValue() {
	int rawValue;
	imeGet((int) port, &rawValue);
	return rawValue;
}

EncoderType IntegratedMotorEncoder::getEncoderType() {
	return IntegratedEncoderType;
}

SensorType IntegratedMotorEncoder::getSensorType() {
	return IntegratedMotorEncoderSensorType;
}

string IntegratedMotorEncoder::getSensorName() {
	return "Integrated Motor Encoder";
}

} /* namespace TRL */
