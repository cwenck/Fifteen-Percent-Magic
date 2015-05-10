/*
 * AutonomusRoutines.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: cwenck
 */

#include "Robot/AutonFunctions.h"

namespace TRL {

/*
 * These names don't need to be pretty you will never be actually calling them yourself
 * Pointers to these functions will be passed to the AutonRoutine class which will then call
 * the appropriate one for you.
 */

void AutonFunctions::redAuton() {
	println("Red Auton Executing");
	delay(10000);
}

void AutonFunctions::blueAuton() {
	println("Blue Auton Executing");
	delay(10000);
}

} /* namespace TRL */
