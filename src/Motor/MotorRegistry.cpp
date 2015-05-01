/*
 * MotorRegistry.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: guywenck
 */

#include "Motor/MotorRegistry.h"

namespace TRL {

Motor* MotorRegistry::motors[10] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL };

MotorRegistry::MotorRegistry() {
	//Nothing needs to be done since this is a static only class
}

MotorRegistry::~MotorRegistry() {
	//Nothing needs to be done since this is a static only class
}

bool MotorRegistry::registerMotor(Motor* motor) {
	if (motor->getPort() == MotorPort_NULL) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to register motor. Motor port not assigned.");
		return false;
	}

	int index = motor->getPort() - 1;
	if (motors[index] != NULL) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to register motor [%s]. Motor port already taken.",
				motor->getName());
		return false;
	}
	motors[index] = motor;
	return true;
}

bool MotorRegistry::deleteRegistryEntry(MotorPort port) {
	if (port == MotorPort_NULL) {
		println(ERROR, "MotorRegistry", "registerMotor",
				"Failed to delete motor registry entry. Motor port not assigned.");
		return false;
	}

	int index = port - 1;
	if (motors[index] == NULL) {
		println(WARNING, "MotorRegistry", "deleteRegistryEntry",
				"Motor was never registered to port %d.", port);
		return false;
	}

	motors[index] = NULL;
	return true;
}

bool MotorRegistry::deleteRegistryEntry(Motor* motor) {
	return deleteRegistryEntry(motor->getPort());
}

void MotorRegistry::printMotorRegistryEntry(MotorPort port) {
	int index = port - 1;
	printf("MotorPort_%d: ", port);
	if (motors[index] == NULL) {
		println("Not Registered");
	} else {
		println(motors[index]->getName());
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
	if (motors[index] == motor) {
		return true;
	} else {
		return false;
	}
}

bool MotorRegistry::isMotorRegisteredToPort(MotorPort port) {
	int index = port - 1;
	if (motors[index] == NULL) {
		return false;
	} else {
		return true;
	}
}

short MotorRegistry::getNumberOfRegisteredMotors() {
	int num = 0;
	for (int i = 0; i < 10; i++) {
		if (motors[i] != NULL) {
			num++;
		}
	}
	return num;
}

Array<Motor*>* MotorRegistry::getRegisteredMotorsArray() {
	Array<Motor*>* registeredMotors = new Array<Motor*>(getNumberOfRegisteredMotors());
	int currentFillingIndex = 0;
	for (int i = 0; i < 10; i++) {
		if (motors[i] != NULL) {
			registeredMotors->at(currentFillingIndex) = motors[i];
			currentFillingIndex++;
		}
	}
	return registeredMotors;
}

} /* namespace TRL */
