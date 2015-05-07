/*
 * AutonomusRoutineRegistry.cpp
 *
 *  Created on: Apr 8, 2015
 *      Author: guywenck
 */

#include "Robot/AutonRegistry.h"

namespace TRL {

VariableArray<AutonRoutine*>* AutonRegistry::routines;
AutonRoutine* AutonRegistry::activeRoutine;

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
}

void AutonRegistry::clearActiveRoutine() {
	activeRoutine = NULL;
}

Array<AutonRoutine*>* AutonRegistry::getRoutines() {
	int size = getNumberOfRoutines();
	Array<AutonRoutine*>* tempArray = new Array<AutonRoutine*>(size);

	for (int i = 0; i < size; i++) {
		tempArray->at(i) = routines->at(i);
	}

	return tempArray;
}

} /* namespace TRL */
