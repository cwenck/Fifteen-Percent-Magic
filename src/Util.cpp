/*
 * Util.cpp
 *
 *  Created on: Apr 2, 2015
 *      Author: guywenck
 */

#include "TRL/Util.h"

namespace TRL {

float getMainBatteryPower() {
	return ((float) powerLevelMain()) / 1000.0f;
}

} /* namespace TRL */
