/*
 * AutonomusRoutineRegistry.cpp
 *
 *  Created on: Apr 8, 2015
 *      Author: guywenck
 */

#include "Robot/AutonRegistry.h"

namespace TRL {

VariableArray<AutonRoutine*>* AutonRegistry::routines;
AutonRoutine* AutonRegistry::robotRoutine;
AutonRoutine* AutonRegistry::activeRoutine;
AutonRoutine* AutonRegistry::runningRoutine;

void AutonRegistry::initStatics() {
	routines = new VariableArray<AutonRoutine*>;
}

void AutonRegistry::destroy() {
	delete routines;
}

void AutonRegistry::registerRoutine(AutonRoutine* routine) {
	routines->add(routine);
}

int AutonRegistry::getNumberOfRoutines() {
	return routines->getSize();
}

void AutonRegistry::printRoutines() {
	delay(5);
	println("|------------------------------|");
	delay(5);
	println("|        AUTON REGISTRY        |");
	delay(5);
	println("|------------------------------|");
	for (int i = 0; i < getNumberOfRoutines(); i++) {
		delay(5);
		println("Routine %d: %s", i + 1, routines->get(i)->getRoutineName());
		delay(5);
	}
	println("================================");
	delay(5);
}

AutonRoutine* AutonRegistry::getRoutine(AllianceColor color,
		RobotStartLocation location, AutonIdentifier identifier) {
	for (int i = 0; i < routines->getSize(); i++) {
		if (routines->get(i)->doesRoutineMatch(color, location, identifier)) {
			return routines->get(i);
		}
	}
	return NULL;
}

void AutonRegistry::runRoutine(AutonRoutine* routine) {
	if (runningRoutine != NULL) {
		println(WARNING, "AutonRegistry", "runRoutine",
				"Not running routine because another routine is already running.");
		return;
	}
	runningRoutine = routine;
	routine->run();
	runningRoutine = NULL;
}

void AutonRegistry::runRoutine(AllianceColor color, RobotStartLocation location,
		AutonIdentifier identifier) {
	AutonRoutine* routine = getRoutine(color, location, identifier);
	runRoutine(routine);
}

AutonRoutine* AutonRegistry::getRunningRoutine() {
	return runningRoutine;
}

void AutonRegistry::setActiveRoutine(AutonRoutine* routine) {
	activeRoutine = routine;
}

void AutonRegistry::runActiveRoutine() {
	if (activeRoutine == NULL) {
		return;
	}
	runRoutine(activeRoutine);
	clearActiveRoutine();
}

void AutonRegistry::clearActiveRoutine() {
	activeRoutine = NULL;
}

void AutonRegistry::setRobotRoutine(AutonRoutine* routine) {
	robotRoutine = routine;
}

void AutonRegistry::runRobotRoutine() {
	if (robotRoutine != NULL) {
		println(ERROR, "AutonRegistry", "runRobotRoutine",
				"The Robot's auton routine was never set. So nothing can be run.");
	} else {
		runRoutine(robotRoutine);
	}
}

void AutonRegistry::saveRobotRoutineToFile(){

}

AutonRoutine* AutonRegistry::readRoutineFromFile() {
	//TODO implement method
	return NULL;
}

Array<AutonRoutine*>* AutonRegistry::getRoutines() {
	int size = getNumberOfRoutines();
	Array<AutonRoutine*>* tempArray = new Array<AutonRoutine*>(size);

	for (int i = 0; i < size; i++) {
		tempArray->at(i) = routines->at(i);
	}

	return tempArray;
}

Array<AutonRoutine*>* AutonRegistry::getRoutines(AllianceColor color) {
	int maxSize = getNumberOfRoutines();
	int count = 0;
	for (int i = 0; i < maxSize; i++) {
		if (routines->at(i)->getAllianceColor() == color) {
			count++;
		}
	}

	int fillingIndex = 0;
	Array<AutonRoutine*>* tempArray = new Array<AutonRoutine*>(count);
	for (int i = 0; i < maxSize; i++) {
		if (routines->at(i)->getAllianceColor() == color) {
			tempArray->at(fillingIndex) = routines->at(i);
			fillingIndex++;
		}
	}

	return tempArray;
}

Array<AutonRoutine*>* AutonRegistry::getRoutines(RobotStartLocation location) {
	int maxSize = getNumberOfRoutines();
	int count = 0;
	for (int i = 0; i < maxSize; i++) {
		if (routines->at(i)->getStartLocation() == location) {
			count++;
		}

	}

	int fillingIndex = 0;
	Array<AutonRoutine*>* tempArray = new Array<AutonRoutine*>(count);
	for (int i = 0; i < maxSize; i++) {
		if (routines->at(i)->getStartLocation() == location) {
			tempArray->at(fillingIndex) = routines->at(i);
			fillingIndex++;
		}
	}

	return tempArray;
}

Array<AutonRoutine*>* AutonRegistry::getRoutines(AllianceColor color,
		RobotStartLocation location) {
	int maxSize = getNumberOfRoutines();
	int count = 0;
	for (int i = 0; i < maxSize; i++) {
		if ((routines->at(i)->getAllianceColor() == color)
				&& (routines->at(i)->getStartLocation() == location)) {
			count++;
		}
	}

	Array<AutonRoutine*>* tempArray = new Array<AutonRoutine*>(count);
	int fillingIndex = 0;
	for (int i = 0; i < maxSize; i++) {
		if ((routines->at(i)->getAllianceColor() == color)
				&& (routines->at(i)->getStartLocation() == location)) {
			tempArray->at(fillingIndex) = routines->at(i);
			fillingIndex++;
		}
	}

	return tempArray;
}

} /* namespace TRL */
