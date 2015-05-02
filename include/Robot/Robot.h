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

		int leftDrivePower;
		int rightDrivePower;

		//TODO use these
		int leftLiftPower;
		int rightLiftPower;

	public:
		//Robot Specific Typedef
		typedef void (Robot::*RobotControllerFunctionPtr)(ControllerType);
		typedef bool (Robot::*RobotControllerHasInputFunctionPtr)(ControllerType);

		//Constructor + Destructor
		Robot();
		static void initStatics();
		virtual ~Robot();

		//Instance
		static Robot* instance;

		//Autonomous Information
		AllianceColor allianceColor;
		RobotStartLocation startLocation;

		//Controllers
		static Controller controller;

		// Controller Input
		void handleInput(InputControlMode controlMode);

//		void driveOrientationInputController(InputControlMode controlMode);
		void driveOrientationController(Controller &controller);

/////////
//DRIVE//
/////////

//		void driveInputController(InputControlMode controlMode);

	private:
		int calcDriveFromAngle(int angle, int maxPow);
		bool softTurnDriveControllerHasInput(ControllerType type);
		bool hardTurnDriveControllerHasInput(ControllerType type);
	public:
		void softTurnDriveController(ControllerType controller);
		void hardTurnDriveController(ControllerType controller);
		void driveControllerHandler(InputControlMode mode);

//		void liftInputController(InputControlMode controlMode);
//		void liftController(Controller &controller);

//		void intakeInputController(InputControlMode controlMode);
//		void intakeController(Controller &controller);

//Set Motor Pointers
		void setDriveMotors(Array<Motor*>* driveMotors);
		void setLiftMotors(Array<Motor*>* liftMotors);
//		void setIntakeMotors(Motor* intake);

//Drive Orientation
		void setDriveOrientation(DriveOrientation orientation);
		void reverseDriveOrientation();

//Drive
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

//Lift
		void powerLeftLift(int speed);
		void powerRightLift(int speed);
		void powerLift(int speed);
		void powerLift(int leftLiftSpeed, int rightLiftSpeed);
		void lift(int power, LiftDirection dir);
		void stopLift();

	};
}

#endif /* ROBOT_H_ */
