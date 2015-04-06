/*
 * MotorRegistry.h
 *
 *  Created on: Apr 4, 2015
 *      Author: guywenck
 */

#ifndef MOTORREGISTRY_H_
#define MOTORREGISTRY_H_

#include "TRL_BaseInitialization.h"
#include "Motor.h"

namespace TRL {

	//This is needed since the motor hasn't actually been defined yet and is included after this class
	class Motor;

	class MotorRegistry {
	private:
		static string motorNames[10];
	public:
		MotorRegistry();
		virtual ~MotorRegistry();

		static bool registerMotor(MotorPort port, string motorName);
		static bool registerMotor(Motor* motor);

		static bool deleteRegistryEntry(MotorPort port);
		static bool deleteRegistryEntry(Motor* motor);

		static void printMotorRegistryEntry(MotorPort port);
		static void printMotorRegistry();

		//checks if the port is registered to a motor with the motor's name
		static bool isMotorRegistered(Motor* motor);

		//only checks if the port is registered to a motor
		static bool isMotorRegisteredToPort(MotorPort port);
	};

}

#endif /* MOTORREGISTRY_H_ */
