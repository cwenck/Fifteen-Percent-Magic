/*
 * Robot.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: guywenck
 */

#include "TRL/Robot.h"

namespace TRL {

Robot::Robot() {
}

Robot::~Robot() {
	// TODO Auto-generated destructor stub
}

void Robot::setDriveMotors(Motor driveMotors[]){
	this->driveMotors = driveMotors;
}

void Robot::setLiftMotors(Motor liftMotors[]){
	this->liftMotors = liftMotors;
	numLiftMotors = sizeof(liftMotors) / sizeof(Motor);
}

void Robot::drive(int speed, Direction dir){

}

void Robot::setLiftPower(int power){
	for(int i = 0; i < numLiftMotors; i++){
		liftMotors[i].setPower(power);
	}
}

} /* namespace TRL */
