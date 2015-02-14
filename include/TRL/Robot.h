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

		//Controller Buttons
		ControllerInput y_drive_stick;
		ControllerInput x_drive_stick;

		ControllerInput lift_up;
		ControllerInput lift_down;

		ControllerInput claw_open;
		ControllerInput claw_close;

		ControllerInput claw_rotate_left;
		ControllerInput claw_rotate_right;

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
		void handleInput(Controller *controller);
		void handleDriveOrientation(Controller* controller);
		void handleDrive(Controller* controller);
		void handleLift(Controller* controller);
		void handleClaw(Controller* controller);


		//Set Motor Pointers
		bool setDriveMotors(Motor* driveMotors[], char numDriveMotors);
		bool setLiftMotors(Motor* liftMotors[], char numLiftMotors);
		void setIntakeMotors(Motor* claw, Motor* clawArm);

		//Drive Orientation
		void setDriveOrientation(DriveOrientation orientation);
		void reverseDriveOrientation();

		//Drive
		void drive(int powerC, DriveDirection dir);
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
