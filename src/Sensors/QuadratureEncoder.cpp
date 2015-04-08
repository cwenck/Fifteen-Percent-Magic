/*
 * QuadratureEncoder.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: cwenck
 */

#include "TRL/QuadratureEncoder.h"

namespace TRL {

QuadratureEncoder::QuadratureEncoder(DigitalPort top, DigitalPort bottom) :
		GenericEncoder(top, bottom) {
	if ((top == 10) || (bottom == 10)) {
		println(ERROR, "QuadratureEncoder", "QuadratureEncoder",
				"The Quadrature Encoder will not function if either wire is plugged into port 10.");
		println(ERROR, "QuadratureEncoder", "QuadratureEncoder",
				"The encoder will NOT be initialized.");
		return;
	}
	this->top = top;
	this->bottom = bottom;
	this->inverted = false;
	//the original pros functions are never reversed
	this->encoder = encoderInit((int) top, int(bottom), false);
	if (this->encoder == NULL) {
		println(ERROR, "QuadratureEncoder", "QuadratureEncoder",
				"An encoder using the same ports has already been initialized.");
		println(ERROR, "QuadratureEncoder", "QuadratureEncoder",
				"The encoder will NOT be initialized.");
		return;
	}
	SensorRegistry::registerSensor(this);
}

QuadratureEncoder::QuadratureEncoder(DigitalPort top, DigitalPort bottom,
		bool inverted) :
		GenericEncoder(top, bottom) {
	if ((top == 10) || (bottom == 10)) {
		println(ERROR, "QuadratureEncoder", "QuadratureEncoder",
				"The Quadrature Encoder will not function if either wire is plugged into port 10.");
		println(ERROR, "QuadratureEncoder", "QuadratureEncoder",
				"The encoder will NOT be initialized.");
		return;
	}
	this->top = top;
	this->bottom = bottom;
	this->inverted = inverted;
	//the original pros functions are never reversed
	this->encoder = encoderInit((int) top, int(bottom), false);
	if (this->encoder == NULL) {
		println(ERROR, "QuadratureEncoder", "QuadratureEncoder",
				"An encoder using the same ports has already been initialized.");
		println(ERROR, "QuadratureEncoder", "QuadratureEncoder",
				"The encoder will NOT be initialized.");
		return;
	}
	SensorRegistry::registerSensor(this);
}

QuadratureEncoder::~QuadratureEncoder() {
	//Nothing needs to be done when destroying this object
}

bool QuadratureEncoder::destroy() {
	encoderShutdown(encoder);
	bool topSuccess = SensorRegistry::deleteRegistryEntry(top);
	bool bottomSuccess = SensorRegistry::deleteRegistryEntry(bottom);
	return topSuccess && bottomSuccess;
}

int QuadratureEncoder::getValue() {
	if (!inverted) {
		return encoderGet(encoder);
	} else {
		return -encoderGet(encoder);
	}
}

void QuadratureEncoder::resetValue() {
	encoderReset(encoder);
}

EncoderType QuadratureEncoder::getEncoderType() {
	return QuadratureEncoderType;
}

SensorType QuadratureEncoder::getSensorType() {
	return QuadratureEncoderSensorType;
}

string QuadratureEncoder::getSensorName() {
	return "Quad Encoder";
}

}
