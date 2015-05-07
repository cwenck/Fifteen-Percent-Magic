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

ControllerInput RobotControls::liftUp;
ControllerInput RobotControls::liftDown;

void RobotControls::initialize() {
	intakeBalls = Ch2;
	shootBall = Btn6U;

	driveStick = ControllerStick::leftMaster;
	strafeStick = ControllerStick::shiftedLeftMaster;

	orientationForward = ShiftedInput_Btn8U;
	orientationBackward = ShiftedInput_Btn8D;

	liftUp = ShiftedInput_Btn6U;
	liftDown = ShiftedInput_Btn6D;

	setupControllers();
}

void RobotControls::setupControllers() {
	Controller::instance->setJoystickDeadzone(MASTER_CONTROLLER, 10);
	Controller::instance->setJoystickDeadzone(SLAVE_CONTROLLER, 20);
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

Motor* MotorList::frontLeftDrive;
Motor* MotorList::backLeftDrive;
Motor* MotorList::frontRightDrive;
Motor* MotorList::backRightDrive;

void MotorList::initialize() {
	testMotor = new Motor(MotorPort_10, OtherMotorLocation, "Test Motor");

	leftLaucherWheelMotorOne = new Motor(MotorPort_2, OtherMotorLocation,
			"L Launch Whl M1");
	leftLaucherWheelMotorTwo = new Motor(MotorPort_3, OtherMotorLocation,
			"L Launch Whl M2");
	rightLaucherWheelMotorOne = new Motor(MotorPort_4, OtherMotorLocation,
			"R Launch Whl M1");
	rightLaucherWheelMotorTwo = new Motor(MotorPort_5, OtherMotorLocation,
			"R Launch Whl M2");

	frontLeftDrive = new Motor(MotorPort_6, FrontLeftMotorLocation, "FL Drive");
	backLeftDrive = new Motor(MotorPort_7, BackLeftMotorLocation, "BL Drive");
	frontRightDrive = new Motor(MotorPort_8, FrontRightMotorLocation,
			"FR Drive");
	backRightDrive = new Motor(MotorPort_9, BackRightMotorLocation, "BR Drive");

	setupRobotMotors();

	println(LOG, "MotorSetup", "initialize", "All motors initialized");
}

void MotorList::setupRobotMotors() {
	/*
	 * Don't call delete on any of these Arrays
	 * to avoid pointers whose objects have been deleted
	 */
	Array<Motor*>* tempDriveMotors = new Array<Motor*>(4, 4, frontLeftDrive,
			backLeftDrive, frontRightDrive, backRightDrive);
	Robot::instance->setDriveMotors(tempDriveMotors);
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
	routineOne = new AutonRoutine(RED, INNER_TILE, RedPolePositionNumberOne, "test 1",
			AutonFunctions::redAuton);
	routineTwo = new AutonRoutine(BLUE, OUTER_TILE, RedPolePositionNumberOne,
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
