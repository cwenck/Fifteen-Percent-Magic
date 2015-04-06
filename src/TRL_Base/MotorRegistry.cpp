/*
 * MotorRegistry.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: guywenck
 */

#include "TRL/MotorRegistry.h"

namespace TRL {

string MotorRegistry::motorNames[10] = { MOTOR_NAME_NULL, MOTOR_NAME_NULL,
		MOTOR_NAME_NULL, MOTOR_NAME_NULL, MOTOR_NAME_NULL, MOTOR_NAME_NULL,
		MOTOR_NAME_NULL, MOTOR_NAME_NULL, MOTOR_NAME_NULL, MOTOR_NAME_NULL };

MotorRegistry::MotorRegistry() {
	//Nothing needs to be done since this is a static only class
}

MotorRegistry::~MotorRegistry() {
	//Nothing needs to be done since this is a static only class
}

bool MotorRegistry::registerMotor(MotorPort port, string motorName) {
	if (port == MotorPort_NULL) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to register motor. Motor port not assigned.");
		return false;
	}

	int index = port - 1;
	if (strcmp(motorNames[index], MOTOR_NAME_NULL) == 0) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to register motor [%s]. Motor port already taken.",
				"motorName");
		return false;
	}
	motorNames[index] = motorName;
	return true;
}

bool MotorRegistry::registerMotor(Motor* motor) {
	if (motor->getPort() == MotorPort_NULL) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to register motor. Motor port not assigned.");
		return false;
	}

	int index = motor->getPort() - 1;
	if (strcmp(motorNames[index], MOTOR_NAME_NULL) != 0) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to register motor [%s]. Motor port already taken.",
				motor->getName());
		return false;
	}
	motorNames[index] = motor->getName();
//	println(LOG, "MotorRegistry", "registerMotor", "Motor %s registered to port %d.", motor->getName(), motor->getPort());
	return true;
}

bool MotorRegistry::deleteRegistryEntry(MotorPort port) {
	if (port == MotorPort_NULL) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to delete motor registry entry. Motor port not assigned.");
		return false;
	}

	int index = port - 1;
	if (strcmp(motorNames[index], MOTOR_NAME_NULL) == 0) {
		println(WARNING, "MotorRegistry", "deleteRegistryEntry",
				"Motor was never registered to port %d.", port);
		return false;
	}

	motorNames[index] = MOTOR_NAME_NULL;
	return true;
}

bool MotorRegistry::deleteRegistryEntry(Motor* motor) {
	return deleteRegistryEntry(motor->getPort());
}

void MotorRegistry::printMotorRegistryEntry(MotorPort port) {
	int index = port - 1;
	printf("MotorPort_%d: ", port);
	if (strcmp(motorNames[index], MOTOR_NAME_NULL) == 0) {
		println("Not Registered");
	} else {
		println(motorNames[index]);
	}
}

void MotorRegistry::printMotorRegistry() {
	delay(5);
	println("|------------------------------|");
	delay(5);
	println("|        MOTOR REGISTRY        |");
	delay(5);
	println("|------------------------------|");
	for (int port = 1; port <= 10; port++) {
		delay(5);
		printMotorRegistryEntry((MotorPort) port);
		delay(5);
	}
	println("================================");
	delay(5);
}

bool MotorRegistry::isMotorRegistered(Motor* motor) {
	int index = motor->getPort() - 1;
	if (strcmp(motorNames[index], motor->getName()) == 0) {
		return true;
	} else {
		return false;
	}
}

bool MotorRegistry::isMotorRegisteredToPort(MotorPort port) {
	int index = port - 1;
	if (strcmp(motorNames[index], MOTOR_NAME_NULL) == 0) {
		return false;
	} else {
		return true;
	}
}

} /* namespace TRL */
