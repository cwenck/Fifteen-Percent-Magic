/*
 * MotorRegistry.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: guywenck
 */

#include "TRL/MotorRegistry.h"

namespace TRL {

MotorRegistry::MotorRegistry() {
	// TODO Auto-generated constructor stub

}

MotorRegistry::~MotorRegistry() {
	// TODO Auto-generated destructor stub
}

bool MotorRegistry::registerMotor(MotorPort port, string motorName) {
	if (port == MotorPort_NULL) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to register motor.");
		println(ERROR, "MotorRegistry", "registerMotor",
				"Motor port not assigned.");
		return false;
	}

	int index = port - 1;
	if (motorNames[index] == MOTOR_NAME_NULL) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to register motor.");
		println(ERROR, "MotorRegistry", "registerMotor",
				"Motor port already taken.");
		return false;
	}
	motorNames[index] = motorName;
	return true;
}

bool MotorRegistry::registerMotor(Motor &motor) {
	if (motor.getPort() == MotorPort_NULL) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to register motor.");
		println(ERROR, "MotorRegistry", "registerMotor",
				"Motor port not assigned.");
		return false;
	}

	int index = motor.getPort() - 1;
	if (motorNames[index] == MOTOR_NAME_NULL) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to register motor.");
		println(ERROR, "MotorRegistry", "registerMotor",
				"Motor port already taken.");
		return false;
	}
	motorNames[index] = motor.getName();
	return true;
}

bool MotorRegistry::deleteRegistryEntry(MotorPort port) {
	if (port == MotorPort_NULL) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to register motor.");
		println(ERROR, "MotorRegistry", "registerMotor",
				"Motor port not assigned.");
		return false;
	}

	int index = port - 1;
	if (motorNames[index] == MOTOR_NAME_NULL) {
		println(WARNING, "MotorRegistry", "deleteRegistryEntry",
				"Motor was never registered to port %d.", port);
		return false;
	}

	motorNames[index] = MOTOR_NAME_NULL;
	return true;
}

void MotorRegistry::printMotorRegistryEntry(MotorPort port) {
	int index = port - 1;
	print("MotorPort_%d ", port);
	if (motorNames[index] == MOTOR_NAME_NULL) {
		println("Not Registered");
	} else {
		println(motorNames[index]);
	}
}

void MotorRegistry::printMotorRegistry() {
	for (int port = 1; port <= 10; port++) {
		printMotorRegistryEntry((MotorPort) port);
	}
}

} /* namespace TRL */
