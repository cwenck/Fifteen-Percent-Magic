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

	class MotorRegistry {
	private:
		static string motorNames[10];
	public:
		MotorRegistry();
		virtual ~MotorRegistry();

		static bool registerMotor(MotorPort port, string motorName);
		static bool registerMotor(Motor &motor);
		static bool deleteRegistryEntry(MotorPort port);

		static void printMotorRegistryEntry(MotorPort port);
		static void printMotorRegistry();
	};

}

#endif /* MOTORREGISTRY_H_ */
