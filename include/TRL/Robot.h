/*
 * Robot.h
 *
 *  Created on: Feb 8, 2015
 *      Author: guywenck
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include "EnumeratedTypedefs.h"
#include "Motor.h"
#include "Controller.h"
#include "PID.h"
#include "AutonomousRoutines.h"

namespace TRL {

	class Robot {
	private:

		PID liftController;
		PID driveController;

		Motor* driveMotors[6];
		Motor* liftMotors[10];
		Motor* clawMotor;
		Motor* clawArmMotor;

		DriveOrientation orientation;

		char numDriveMotors;
		char numLiftMotors;


		//Controller Buttons
		ControllerInput y_drive_stick;
		ControllerInput x_drive_stick;

		short controllerDeadzoneMagnitude;

		ControllerInput lift_up;
		ControllerInput lift_down;

		ControllerInput claw_open;
		ControllerInput claw_close;

		ControllerInput claw_rotate;

		ControllerInput orientation_forward;
		ControllerInput orientation_backward;

		short liftPower;
		short clawOpenPower;
		short clawClosePower;
		short clawArmPower;

		//Motors
		Motor frontRightDrive;
		Motor frontLeftDrive;
		Motor backRightDrive;
		Motor backLeftDrive;

		Motor frontRightLift;
		Motor backRightLift;
		Motor frontLeftLift;
		Motor backLeftLift;

		Motor intakeMotor;
		Motor intakeArmMotor;

		void initializeMotors();
	public:

		//Constructor + Destructor
		Robot();
		virtual ~Robot();

		//Instance
		static Robot instance;

		//Autonomous Information
		AllianceColor allianceColor;
		RobotStartLocation startLocation;

		//Controllers
		static Controller mainController;
		static Controller partnerController;

		// Controller Input
		void handleInput(InputControlMode controlMode);
		void handleDriveOrientation(InputControlMode controlMode);
		void handleDrive(InputControlMode controlMode);
		void handleLift(InputControlMode controlMode);
		void handleClaw(InputControlMode controlMode);

		//Set Motor Pointers
		bool setDriveMotors(Motor* driveMotors[], char numDriveMotors);
		bool setLiftMotors(Motor* liftMotors[], char numLiftMotors);
		void setIntakeMotors(Motor* claw, Motor* clawArm);

		//Drive Orientation
		void setDriveOrientation(DriveOrientation orientation);
		void reverseDriveOrientation();

		//Drive
		void drive(int power, DriveDirection dir);
		void stopDriveMotors();

		//Lift
		void lift(int power, LiftDirection dir);
		void stopLift();

		//Claw
		void claw(int power, ClawDirection dir);
		void stopClaw();

		//Claw Arm
		void clawArm(int power, ClawArmDirection dir);
		void stopClawArm();

	};
}

#endif /* ROBOT_H_ */
