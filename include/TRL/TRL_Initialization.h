/*
 * Terminator_Robotics_Library_Initilization.h
 *
 *  Created on: Jan 29, 2015
 *      Author: guywenck
 */

#ifndef TERMINATOR_ROBOTICS_LIBRARY_INITILIZATION_H_
#define TERMINATOR_ROBOTICS_LIBRARY_INITILIZATION_H_

//Include All Files Of the Library So Only This File Needs To Be Linked To main.h
#include "TRL_BaseInitialization.h"

#include "Motor.h"
#include "Controller.h"
#include "LCD.h"

//Sensor Includes
#include "Sensor.h"
#include "AnalogSensor.h"
#include "LightSensor.h"
#include "LineSensor.h"
#include "GenericEncoder.h"
#include "QuadratureEncoder.h"
#include "DigitalSwitch.h"
#include "Sonar.h"



#include "PID.h"
#include "Robot.h"
#include "AutonomousRoutines.h"

namespace TRL{
	void initializeLibrary();
}

#endif /* TERMINATOR_ROBOTICS_LIBRARY_INITILIZATION_H_ */
