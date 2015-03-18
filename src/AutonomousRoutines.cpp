/*
 * AutonomusRoutines.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: cwenck
 */

#include "TRL/AutonomousRoutines.h"

namespace TRL {

AutonomousRoutines AutonomousRoutines::instance;

AutonomousRoutines::AutonomousRoutines() {
}

AutonomousRoutines::~AutonomousRoutines() {
}

void AutonomousRoutines::runAutonomusRountine(AllianceColor color,
		RobotStartLocation startLocation, short rountineNumber) {
	switch (color) {
	case RED:
		runRedAutonomus(startLocation, rountineNumber);
		return;
	case BLUE:
		runBlueAutonomus(startLocation, rountineNumber);
		return;
	}
}

void AutonomousRoutines::runRedAutonomus(RobotStartLocation startLocation,
		short routineNumber) {
	switch (startLocation) {
	case AUTO_LOADER:
		runRedAutonomusPositionOne(routineNumber);
		return;
	case POLE:
		runRedAutonomusPositionTwo(routineNumber);
		return;
	}
}

void AutonomousRoutines::runBlueAutonomus(RobotStartLocation startLocation,
		short routineNumber) {
	switch (startLocation) {
		case AUTO_LOADER:
			runBlueAutonomusPositionOne(routineNumber);
			return;
		case POLE:
			runBlueAutonomusPositionTwo(routineNumber);
			return;
		}
}

void AutonomousRoutines::runRedAutonomusPositionOne(short rountineNumber) {

}

void AutonomousRoutines::runBlueAutonomusPositionOne(short rountineNumber) {

}

void AutonomousRoutines::runRedAutonomusPositionTwo(short rountineNumber) {

}
void AutonomousRoutines::runBlueAutonomusPositionTwo(short rountineNumber) {

}

} /* namespace TRL */
