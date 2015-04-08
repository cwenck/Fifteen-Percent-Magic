/*
 * Encoder.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: guywenck
 */

#include "Sensors/GenericEncoder.h"

namespace TRL {

GenericEncoder::GenericEncoder() {
}

GenericEncoder::GenericEncoder(DigitalPort top, DigitalPort bottom) : Sensor(top, bottom){
}

GenericEncoder::~GenericEncoder() {
	// TODO Auto-generated destructor stub
}

} /* namespace TRL */
