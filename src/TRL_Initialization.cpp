/*
 * TRL_Initialization.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: guywenck
 */

#include "TRL/TRL_Initialization.h"

namespace TRL {

void initializeLibrary() {
	Robot::initStatics();
	AutonomousRoutines::initStatics();
	LCD::initStatics();
}

}
