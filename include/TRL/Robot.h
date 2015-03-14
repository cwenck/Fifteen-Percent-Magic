/*
 * Robot.h
 *
 *  Created on: Feb 8, 2015
 *      Author: guywenck
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include "Motor.h"
#include "Controller.h"

namespace TRL {

	typedef enum _InputControlMode {
		NormalControllerOnly,
		NormalAndPartnerContoller
	}InputControlMode;

	typedef enum _DriveDirection {
		ManualDrive,
		ManualTurn,
		ManualStrafe,
		DriveForward,
		DriveBackward,
		TurnLeft,
		TurnRight,
		StrafeLeft,
		StrafeRight
	}DriveDirection;

	typedef enum _DriveOrientation {
		ForwardOrientation,
		BackwardOrientation
	}DriveOrientation;

	typedef enum _LiftDirection {
		ManualLift,
		Up,
		Down
	}LiftDirection;

	typedef enum _ClawArmDirection {
		ManualClawArmControl,
		RotateArmLeft,
		RotateArmRight
	}ClawArmDirection;

	typedef enum _ClawDirection {
		ManualClawControl,
		OpenClaw,
		CloseClaw
	}ClawDirection;

	class Robot {
	private:
		Motor* driveMotors[6];
		Motor* liftMotors[10];
		Motor* clawMotor;
		Motor* clawArmMotor;

		DriveOrientation orientation;

		char numDriveMotors;
		char numLiftMotors;

		//Controllers
		Controller mainController;
		Controller partnerController;

		//Controller Buttons
		ControllerInput y_drive_stick;
		ControllerInput x_drive_stick;

		short controllerDeadzoneMagnitude;

		ControllerInput lift_up;
		ControllerInput lift_down;

		ControllerInput claw_open;
		ControllerInput claw_close;

//		ControllerInput claw_rotate_left;
//		ControllerInput claw_rotate_right;
		ControllerInput claw_rotate;

		ControllerInput orientation_forward;
		ControllerInput orientation_backward;

		short liftPower;
		short clawOpenPower;
		short clawClosePower;
		short clawArmPower;

	public:
		//Constructor + Destructor
		Robot();
		virtual ~Robot();

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

		//Motors
//		static Motor frontRightDrive;
//		static Motor frontLeftDrive;
//		static Motor backRightDrive;
//		static Motor backLeftDrive;
//
//		static Motor frontRightLift;
//		static Motor backRightLift;
//		static Motor frontLeftLift;
//		static Motor backLeftLift;
//
//		static Motor intakeMotor;
//		static Motor intakeArmMotor;

	};
}

#endif /* ROBOT_H_ */
