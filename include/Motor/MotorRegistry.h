/*
 * MotorRegistry.h
 *
 *  Created on: Apr 4, 2015
 *      Author: guywenck
 */

#ifndef MOTORREGISTRY_H_
#define MOTORREGISTRY_H_

#include "Motor.h"

namespace TRL {

	//This is needed since the motor hasn't actually been defined yet and is included after this class
	class Motor;

	class MotorRegistry {
	private:
		static Motor* motors[10];
	public:
		MotorRegistry();
		virtual ~MotorRegistry();

		static bool registerMotor(Motor* motor);

		static bool deleteRegistryEntry(MotorPort port);
		static bool deleteRegistryEntry(Motor* motor);

		static void printMotorRegistryEntry(MotorPort port);
		static void printMotorRegistry();

		//checks if the port is registered to a motor with the motor's name
		static bool isMotorRegistered(Motor* motor);

		//only checks if the port is registered to a motor
		static bool isMotorRegisteredToPort(MotorPort port);

		static short getNumberOfRegisteredMotors();

		//The full array of registered motors is returned
		//This is a copy of the array so it is readOnly(motors can't be added or removed from the registry)
		//but the motors are correct pointers so their information will update
		//and should be deleted with delete
		static Array<Motor*>* getRegisteredMotorsArray();
	};

}

#endif /* MOTORREGISTRY_H_ */
