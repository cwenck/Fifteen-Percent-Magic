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

void AutonRegistry::initStatics(){
	routines = new VariableArray<AutonRoutine*>;
}

void AutonRegistry::destroy(){
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
		println("Routine %d: %s", i+1, routines->get(i)->getRoutineName());
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

void AutonRegistry::runRoutine(AllianceColor color, RobotStartLocation location,
		AutonIdentifier identifier) {
	getRoutine(color, location, identifier)->run();
}

void AutonRegistry::setActiveRoutine(AutonRoutine* routine){
	activeRoutine = routine;
}

void AutonRegistry::runActiveRoutine(){
	if(activeRoutine == NULL){
		return;
	}
	activeRoutine->run();
}

void AutonRegistry::clearActiveRoutine(){
	activeRoutine = NULL;
}

} /* namespace TRL */
