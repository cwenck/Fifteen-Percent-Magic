/*
 * AutonRoutine.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: guywenck
 */

#include "Robot/AutonRoutine.h"

namespace TRL {

AutonRoutine::AutonRoutine(AllianceColor color, RobotStartLocation location,
		AutonIdentifier identifier, string routineName,
		VoidFunctionPtr autonFunction) {
	AutonRegistry::registerRoutine(this);
	this->color = color;
	this->location = location;
	this->identifier = identifier;
	this->name = routineName;
	this->autonFunction = autonFunction;
	this->running = false;
}

void AutonRoutine::run() {
	println(DEBUG, "AutonRoutine", "run", "Starting execution of %s.", this->getRoutineName());
	this->running = true;
	autonFunction();
	this->running = false;
	println(DEBUG, "AutonRoutine", "run", "Stopping execution of %s.", this->getRoutineName());
}

bool AutonRoutine::isRunning(){
	return running;
}

AllianceColor AutonRoutine::getAllianceColor() {
	return color;
}

RobotStartLocation AutonRoutine::getStartLocation() {
	return location;
}

string AutonRoutine::getRoutineName() {
	return name;
}

AutonIdentifier AutonRoutine::getIdentifier() {
	return identifier;
}

bool AutonRoutine::doesRoutineMatch(AutonRoutine* routine) {
	bool colorMatches = (routine->getAllianceColor() == this->color);
	bool locationMatches = (routine->getStartLocation() == this->location);
	bool identifierMatches = (routine->getIdentifier() == this->identifier);
	return (colorMatches && locationMatches && identifierMatches);
}

bool AutonRoutine::doesRoutineMatch(AllianceColor color,
		RobotStartLocation location, AutonIdentifier identifier) {
	bool colorMatches = (color == this->color);
	bool locationMatches = (location == this->location);
	bool identifierMatches = (identifier == this->identifier);
	return (colorMatches && locationMatches && identifierMatches);
}

}
/* namespace TRL */
