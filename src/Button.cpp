/*
 * Button.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#include "TRL/Button.h"

namespace TRL {

Button::Button() {
	this->port = NULL_UNIVERSAL_PORT;
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

void Button::setPort(AnalogPort port){
	this->port = Port::getUniversalPortNumber(port);
}

void Button::setPort(DigitalPort port){
	this->port = Port::getUniversalPortNumber(port);
}

} /* namespace TRL */
