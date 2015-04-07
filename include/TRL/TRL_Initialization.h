/*
 * Terminator_Robotics_Library_Initilization.h
 *
 *  Created on: Jan 29, 2015
 *      Author: guywenck
 */

#ifndef TERMINATOR_ROBOTICS_LIBRARY_INITILIZATION_H_
#define TERMINATOR_ROBOTICS_LIBRARY_INITILIZATION_H_

//Include All Files Of the Library So Only This File Needs To Be Linked To main.h

//List of Primitive includes that don't require any classes from this list
#include "TRL_BaseInitialization.h"

#include "MotorRegistry.h"
#include "Motor.h"
#include "Controller.h"

//LCD includes
#include "../LCD/LCD_Includes.h"

//Sensor Includes
#include "Sensor.h"
#include "AnalogSensor.h"
#include "LightSensor.h"
#include "LineSensor.h"
#include "GenericEncoder.h"
#include "QuadratureEncoder.h"
#include "Sonar.h"
#include "Gyroscope.h"
#include "DigitalSwitch.h"
#include "Bumper.h"

//PID
#include "PID.h"

//Above classes of library classes
//Classes for altering the behavior of this particular robot

#include "MotorAndSensorSetup.h"

#include "Robot.h"
#include "AutonomousRoutines.h"

namespace TRL{
	void trlInitializeLibrary();
}

#endif /* TERMINATOR_ROBOTICS_LIBRARY_INITILIZATION_H_ */
