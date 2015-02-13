/*
 * Motor.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: guywenck
 */

#include "TRL/Motor.h"

namespace TRL {

Motor::Motor(){
	this->port = (MotorPort)NULL;
	this->reversed = false;
	this->speed = 0;
	this->encoder = NULL;
}

Motor::Motor(MotorPort port, bool reversed) {
	this->port = port;
	this->reversed = reversed;
	this->speed = 0;
	this->encoder = NULL;
}

Motor::Motor(MotorPort port) {
	this->reversed = false;
	this->port = port;
	this->speed = 0;
	this->encoder = NULL;
}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

void Motor::setPower(int motorSpeed) {
	speed = motorSpeed;
	if (!reversed) {
		motorSet(port, -speed);
	} else {
		motorSet(port, speed);
	}
}

void Motor::stop() {
	motorStop(port);
}

MotorPort Motor::getPort(){
	return port;
}

Encoder* Motor::getEncoder(){
	return encoder;
}

void Motor::reverseDirection(){
	printf("%d : ", reversed);
	reversed = !reversed;
	printf("%d\n\r", reversed);
}

void Motor::setAllPower(int speed){
	for(int i = 1; i < 10; i++){
		motorSet(i, speed);
	}
}

void Motor::stopAll(){
	motorStopAll();
}

}
