/*
 * Robot.h
 *
 *  Created on: Feb 8, 2015
 *      Author: guywenck
 */

#ifndef ROBOT_H_
#define ROBOT_H_

//#include "Robot_Includes.h"

#include "../TRL/TRL_BaseIncludes.h"
#include "../Sensors/Sensor_Includes.h"
#include "../Motor/Motor_Includes.h"
#include "MotorAndSensorSetup.h"

namespace TRL {

	class Robot {
	private:

		DriveOrientation orientation;

		Array<Motor*>* driveMotors;
		Array<Motor*>* liftMotors;
		Array<Motor*>* intakeMotors;

		//Variables to hold the current speed of various groups of motors
		int leftDrivePower;
		int rightDrivePower;

		int leftLiftPower;
		int rightLiftPower;

		int intakePower;

		//Predefined speeds for certain groups of motors when powered
		int intakePowerLevel;

		int liftPowerLevel;

	public:
		//Robot Specific Typedef
		typedef void (Robot::*RobotControllerFunctionPtr)(ControllerType);
		typedef bool (Robot::*RobotControllerHasInputFunctionPtr)(ControllerType);
		typedef void (Robot::*RobotStopMotorsFunctionPtr)(void);

		//Constructor + Destructor
		Robot();
		static void initStatics();
		virtual ~Robot();

		//Instance
		static Robot* instance;

		//Autonomous Information
		AllianceColor allianceColor;
		RobotStartLocation startLocation;

		// Controller Input
		void handleInput(InputControlMode controlMode);

		//////////////////////
		//Set Motor Pointers//
		//////////////////////
		void setDriveMotors(Array<Motor*>* driveMotors);
		void setLiftMotors(Array<Motor*>* liftMotors);
		void setIntakeMotors(Array<Motor*>* intakeMotors);

		//Controller Handler Base Functions
	private:
		void motorControllerHandler(InputControlMode controlMode,
				RobotControllerFunctionPtr masterOperated,
				RobotControllerFunctionPtr slaveOperated,
				RobotStopMotorsFunctionPtr stopMotors,
				RobotControllerHasInputFunctionPtr masterOperatedHasInput,
				RobotControllerHasInputFunctionPtr slaveOperatedHasInput);

		void nonMotorControllerHandler(InputControlMode controlMode,
				RobotControllerFunctionPtr masterOperated,
				RobotControllerFunctionPtr slaveOperated,
				RobotControllerHasInputFunctionPtr masterOperatedHasInput,
				RobotControllerHasInputFunctionPtr slaveOperatedHasInput);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Input Controllers, Controller Handlers, and Functions to Test if an Input Controller has Active Inputs Below Here//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DRIVE ORIENTATION//
	private:
		bool driveOrientationControllerHasInput(ControllerType type);
	public:
		void driveOrientationControllerHandler(InputControlMode controlMode);
		void driveOrientationController(ControllerType type);

//DRIVE//
	private:
		int calcDriveFromAngle(int angle, int maxPow);
		bool softTurnDriveControllerHasInput(ControllerType type);
		bool hardTurnDriveControllerHasInput(ControllerType type);
	public:
		void softTurnDriveController(ControllerType controller);
		void hardTurnDriveController(ControllerType controller);
		void driveControllerHandler(InputControlMode controlMode);

//LIFT//
	private:
		bool liftControllerHasInput(ControllerType type);
	public:
		void liftController(ControllerType controller);
		void liftControllerHandler(InputControlMode controlMode);

//INTAKE//
	private:
		bool intakeControllerHasInput(ControllerType type);
	public:
		void intakeController(ControllerType type);
		void intakeControllerHandler(InputControlMode controlMode);

/////////////////////////////////////////////////////////
//Motor Power Functions For The Above Input Controllers//
/////////////////////////////////////////////////////////

		//DRIVE ORIENTATION//
	public:
		void setDriveOrientation(DriveOrientation orientation);
		void reverseDriveOrientation();

		//DRIVE//
	private:
		void powerDrive(int power);
		void powerDrive(int leftDrivePower, int rightDrivePower);

		void powerLeftDrive(int power, WheelSidePowerMode mode);
		void powerRightDrive(int power, WheelSidePowerMode mode);

	public:
		void printDriveSpeed();

		void manualDrive(int power);
		void manualTurn(int powerLeft, int powerRight);
		void manualTurn(int power);
		void manualStrafe(int power);

		void drive(int power, DriveDirection dir);
		void stopDriveMotors();

//LIFT//
	public:
		void powerLeftLift(int speed);
		void powerRightLift(int speed);
		void powerLift(int speed);
		void powerLift(int leftLiftSpeed, int rightLiftSpeed);
		void lift(int power, LiftDirection dir);
		void stopLift();

//INTAKE//
	public:
		void powerIntakeMotors(int power);
		void stopIntakeMotors();

	};
}

#endif /* ROBOT_H_ */
