/*
 * MotorAndSensorSetup.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: guywenck
 */

#include "TRL/MotorAndSensorSetup.h"

namespace TRL {

/////////////////////////
///START OF MOTOR SETUP//
/////////////////////////


Motor MotorList::motor_1;
Motor MotorList::motor_2;
Motor MotorList::motor_3;
Motor MotorList::motor_4;
Motor MotorList::motor_5;
Motor MotorList::motor_6;
Motor MotorList::motor_7;
Motor MotorList::motor_8;
Motor MotorList::motor_9;
Motor MotorList::motor_10;

void MotorList::initialize() {
	motor_1 = Motor(MotorPort_1, UnspecifiedMotorLocation, "Port 1");
	motor_2 = Motor(MotorPort_2, UnspecifiedMotorLocation, "Port 2");
	motor_3 = Motor(MotorPort_3, UnspecifiedMotorLocation, "Port 3");
	motor_4 = Motor(MotorPort_4, UnspecifiedMotorLocation, "Port 4");
	motor_5 = Motor(MotorPort_5, UnspecifiedMotorLocation, "Port 5");
	motor_6 = Motor(MotorPort_6, UnspecifiedMotorLocation, "Port 6");
	motor_7 = Motor(MotorPort_7, UnspecifiedMotorLocation, "Port 7");
	motor_8 = Motor(MotorPort_8, UnspecifiedMotorLocation, "Port 8");
	motor_9 = Motor(MotorPort_9, UnspecifiedMotorLocation, "Port 9");
	motor_10 = Motor(MotorPort_10, UnspecifiedMotorLocation, "Port 10");
	println(LOG, "MotorSetup", "initialize", "All motors initialized");
}

MotorList::MotorList() {
	//Nothing should be done here since this is a static class;
}

MotorList::~MotorList() {
	//Nothing should be done here since this is a static class;
}

///////////////////////
///END OF MOTOR SETUP//
///////////////////////

//////////////////////////
///START OF SENSOR SETUP//
//////////////////////////

Potentiometer SensorList::example;

void SensorList::initialize(){
	example = Potentiometer(Analog_4);
	println(LOG, "SensorSetup", "initialize", "All sensors initialized");
}

////////////////////////
///END OF SENSOR SETUP//
////////////////////////

/////////////////////////////
///START OF REGISTRY HELPER//
/////////////////////////////

void RegistryHelper::printEntireRegistry(){
	MotorRegistry::printMotorRegistry();
	delay(10);
	PortRegistry::printPortRegistry();
}

///////////////////////////
///END OF REGISTRY HELPER//
///////////////////////////


} /* namespace TRL */
