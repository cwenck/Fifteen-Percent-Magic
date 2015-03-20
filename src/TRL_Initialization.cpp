/*
 * TRL_Initialization.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: guywenck
 */

#include "TRL/TRL_Initialization.h"

namespace TRL {

void initializeLibrary(){
	Robot::mainController = Controller(Main_Controller);
	Robot::partnerController = Controller(Partner_Controller);
	Robot::instance = Robot();
	AutonomousRoutines::instance = AutonomousRoutines();
}

}
