/*
 * TRL_Initialization.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: guywenck
 */

#include "TRL/TRL_AllIncludes.h"

namespace TRL {

void trlInitializeLibrary() {
	Controller::initInstance();
	Robot::initStatics();
	LCD::initStatics();
	AutonRegistry::initStatics();
	Setup::setupRobot();
}
}
