/*
 * MotorAndSensorSetup.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: guywenck
 */

#include "Robot/MotorAndSensorSetup.h"

namespace TRL {

void Setup::setupRobot() {
	MotorList::initialize();
	SensorList::initialize();
	AutonList::initialize();
	RobotControls::initialize();
}

/////////////////////
//START OF CONTROLS//
/////////////////////

ControllerInput RobotControls::intakeBalls;
ControllerInput RobotControls::shootBall;

ControllerStick* RobotControls::driveStick;
ControllerStick* RobotControls::strafeStick;

ControllerInput RobotControls::orientationForward;
ControllerInput RobotControls::orientationBackward;

void RobotControls::initialize() {
	intakeBalls = Ch2;
	shootBall = Btn6U;

	driveStick = ControllerStick::leftMaster;
	strafeStick = ControllerStick::shiftedLeftMaster;

	orientationForward = ShiftedInput_Btn8U;
	orientationBackward = ShiftedInput_Btn8D;
}

void RobotControls::setupControllers() {
	Controller::instance->setJoystickDeadzone(MASTER_CONTROLLER, 10);
	Controller::instance->setJoystickDeadzone(SLAVE_CONTROLLER, 10);
}

///////////////////
//END OF CONTROLS//
///////////////////

/////////////////////////
///START OF MOTOR SETUP//
/////////////////////////

Motor* MotorList::testMotor;
Motor* MotorList::leftLaucherWheelMotorOne;
Motor* MotorList::leftLaucherWheelMotorTwo;
Motor* MotorList::rightLaucherWheelMotorOne;
Motor* MotorList::rightLaucherWheelMotorTwo;

void MotorList::initialize() {
	testMotor = new Motor(MotorPort_9, UnspecifiedMotorLocation, "Test Motor");
	leftLaucherWheelMotorOne = new Motor(MotorPort_2, OtherMotorLocation, "Left Wheel");
	leftLaucherWheelMotorTwo = new Motor(MotorPort_3, OtherMotorLocation, "Left Wheel");
	rightLaucherWheelMotorOne = new Motor(MotorPort_4, OtherMotorLocation, "Right Wheel");
	rightLaucherWheelMotorTwo = new Motor(MotorPort_5, OtherMotorLocation, "Right Wheel");
	println(LOG, "MotorSetup", "initialize", "All motors initialized");
}

///////////////////////
///END OF MOTOR SETUP//
///////////////////////

//////////////////////////
///START OF SENSOR SETUP//
//////////////////////////

QuadratureEncoder* SensorList::quad;
PowerExpander* SensorList::powerExpander;

void SensorList::initialize() {
	//The Power Expander Should Always be here
	//Set it to NoAnalogInput if your not using it
	powerExpander = new PowerExpander(NoAnalogInput);

	quad = new QuadratureEncoder(Digital_1, Digital_2);
	println(LOG, "SensorSetup", "initialize", "All sensors initialized");
}

////////////////////////
///END OF SENSOR SETUP//
////////////////////////

/////////////////////////
///START OF AUTON SETUP//
/////////////////////////

AutonRoutine* AutonList::routineOne;
AutonRoutine* AutonList::routineTwo;

void AutonList::initialize() {
	routineOne = new AutonRoutine(RED, POLE, RedPolePositionNumberOne, "test 1",
			AutonFunctions::redAuton);
	routineTwo = new AutonRoutine(BLUE, POLE, RedPolePositionNumberOne,
			"test 2", AutonFunctions::blueAuton);
}

///////////////////////
///END OF AUTON SETUP//
///////////////////////

/////////////////////////////
///START OF REGISTRY HELPER//
/////////////////////////////

void RegistryHelper::printEntireRegistry() {
	MotorRegistry::printMotorRegistry();
	delay(10);
	SensorRegistry::printSensorRegistry();
}

///////////////////////////
///END OF REGISTRY HELPER//
///////////////////////////

} /* namespace TRL */
