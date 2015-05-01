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

	public:
		//Constructor + Destructor
		Robot();
		static void initStatics();
		virtual ~Robot();

		//Instance
		static Robot instance;

		//Autonomous Information
		AllianceColor allianceColor;
		RobotStartLocation startLocation;

		//Controllers
		static Controller controller;

		// Controller Input
		void handleInput(InputControlMode controlMode);

//		void driveOrientationInputController(InputControlMode controlMode);
		void driveOrientationMirrorController(Controller &controller);

		/////////
		//DRIVE//
		/////////

//		void driveInputController(InputControlMode controlMode);
		void powerDrive(int leftDriveSpeed, int rightDriveSpeed);
		void powerDrive();
		int calcDriveFromAngle(int angle, int maxPow);
		void driveController(Controller &controller);
		void softTurnDriveController(Controller *controller);
		void printDriveSpeed();




//		void liftInputController(InputControlMode controlMode);
//		void liftController(Controller &controller);

//		void intakeInputController(InputControlMode controlMode);
//		void intakeController(Controller &controller);

//Set Motor Pointers
		bool setDriveMotors(char numMotors, Motor** driveMotors);
		bool setDriveMotors(Array<Motor*>* driveMotors);
		bool setLiftMotors(Array<Motor*>* liftMotors);
		bool setLiftMotors(char numMotors, Motor** liftMotors);
//		void setIntakeMotors(Motor* intake);

//Drive Orientation
		void setDriveOrientation(DriveOrientation orientation);
		void reverseDriveOrientation();

		//Drive
		void drive(int power, DriveDirection dir);
		void stopDriveMotors();

		//Lift
//		void lift(int power, LiftDirection dir);
//		void stopLift();

	};
}

#endif /* ROBOT_H_ */
