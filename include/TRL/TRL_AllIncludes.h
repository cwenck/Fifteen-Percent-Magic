/*
 * Terminator_Robotics_Library_Initilization.h
 *
 *  Created on: Jan 29, 2015
 *      Author: guywenck
 */

#ifndef TERMINATOR_ROBOTICS_LIBRARY_INCLUDES_H_
#define TERMINATOR_ROBOTICS_LIBRARY_INCLUDES_H_

//Include All Files Of the Library So Only This File Needs To Be Linked To main.h

//List of Primitive includes that don't require any classes from this list
//These all all found in this folder
#include "TRL_BaseIncludes.h"

//LCD includes
#include "../LCD/LCD_Includes.h"

//Sensor Includes
#include "../Sensors/Sensor_Includes.h"

//Motor Includes
#include "../Motor/Motor_Includes.h"

//Above classes of library classes
//Classes for altering the behavior of this particular robot

#include "../Robot/Robot_Includes.h"

namespace TRL{
	void trlInitializeLibrary();
}

#endif /* TERMINATOR_ROBOTICS_LIBRARY_INCLUDES_H_ */
