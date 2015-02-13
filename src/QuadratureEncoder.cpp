/*
 * QuadratureEncoder.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: cwenck
 */

#include "TRL/QuadratureEncoder.h"

namespace TRL {

QuadratureEncoder::QuadratureEncoder(DigitalPort top, DigitalPort bottom) {
	if ((top == 10) || (bottom == 10)) {
		printf("[Warning] The Quadrature Encoder will not function if either wire is plugged into port 10.\n\r");
		printf("\t The encoder will remain uninitialized");
		return;
	}
	this->top = top;
	this->bottom = bottom;
	this->inverted = false;
	//the original pros functions are never reversed
	this->encoder = encoderInit((int) top, int(bottom), false);
	if(this->encoder == NULL){
		printf("[Warning] An encoder using the same ports has already been initialized. Please choose different ports.\n\r");
	}
}

QuadratureEncoder::QuadratureEncoder::QuadratureEncoder(DigitalPort top,
		DigitalPort bottom, bool inverted) {
	if ((top == 10) || (bottom == 10)) {
		printf("[Error] The Quadrature Encoder will not function if either wire is plugged into port 10.\n\r");
		printf("\t The encoder will remain uninitialized");
		return;
	}
	this->top = top;
	this->bottom = bottom;
	this->inverted = inverted;
	//the original pros functions are never reversed
	this->encoder = encoderInit((int) top, int(bottom), false);
	if(this->encoder == NULL){
		printf("[Warning] An encoder using the same ports has already been initialized. Please choose different ports.\n\r");
	}
}

QuadratureEncoder::~QuadratureEncoder() {
// TODO Auto-generated destructor stub
}

int QuadratureEncoder::getValue() {
	if (!inverted) {
		return encoderGet(encoder);
	} else {
		return -encoderGet(encoder);
	}
}

void QuadratureEncoder::shutdown() {
	encoderShutdown(encoder);
}

void QuadratureEncoder::resetValue() {
	encoderReset(encoder);
}

EncoderType QuadratureEncoder::getType() {
	return QUAD_ENCODER_TYPE;
}
}
