/*
 * Robot.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: guywenck
 */

#include "TRL/Robot.h"

namespace TRL {
///////////////////////////////
//CONTSTRUCTORS + DESTRUCTORS//
///////////////////////////////

Robot::Robot() {
	//Init Controller Inputs
	y_drive_stick = Ch3;
	x_drive_stick = Ch4;

	lift_up = Btn6U;
	lift_down = Btn6D;

	claw_rotate_left = Btn8L;
	claw_rotate_right = Btn8R;

	claw_open = Btn8U;
	claw_close = Btn8D;

	orientation_forward = Btn7U;
	orientation_backward = Btn7D;

	//Init the default lift power
	liftPower = 127;
	clawArmPower = 127;
	clawOpenPower = 127;
	clawClosePower = 127;

	//Init the defualt orientaiton
	orientation = ForwardOrientation;

	//Init the number of diive and lift motors
	numDriveMotors = 0;
	numLiftMotors = 0;

	//Init the motor pointers as null
	clawMotor = NULL;
	clawArmMotor = NULL;
}

Robot::~Robot() {
	// TODO Auto-generated destructor stub
}

////////////////////
//CONTROLLER INPUT//
////////////////////

void Robot::handleInput(Controller* controller) {
	handleDriveOrientation(controller);
	handleDrive(controller);
	handleLift(controller);
	handleClaw(controller);
}

void Robot::handleDriveOrientation(Controller* controller) {
	if (controller->getValue(orientation_forward) == 1) {
		setDriveOrientation(ForwardOrientation);
	} else if (controller->getValue(orientation_backward) == 1) {
		setDriveOrientation(BackwardOrientation);
	}
}

void Robot::handleDrive(Controller* controller) {
	short y = controller->getValue(y_drive_stick);
	short x = controller->getValue(x_drive_stick);

	if (abs(y) > abs(x)) {
		drive(y, ManualDrive);
	} else if (abs(x) >= abs(y)) {
		drive(x, ManualTurn);
	}
}

void Robot::handleLift(Controller* controller) {
	if (controller->getValue(lift_up) == 1) {
		lift(liftPower, Up);
	} else if (controller->getValue(lift_down) == 1) {
		lift(liftPower, Down);
	} else {
		stopLift();
	}
}

void Robot::handleClaw(Controller* controller) {
	if (controller->getValue(claw_open) == 1) {
		claw(clawOpenPower, OpenClaw);
	} else if (controller->getValue(claw_close) == 1) {
		claw(clawClosePower, CloseClaw);
	} else {
		stopClaw();
	}

	if (controller->getValue(claw_rotate_left) == 1) {
		clawArm(clawArmPower, RotateArmLeft);
	} else if (controller->getValue(claw_rotate_right) == 1) {
		clawArm(clawArmPower, RotateArmRight);
	} else {
		stopClawArm();
	}
}

///////////////////////////////
//SET MOTOR POINTER FUNCTIONS//
///////////////////////////////

bool Robot::setDriveMotors(Motor* driveMotors[], char numDriveMotors) {
	if (numDriveMotors > 6) {
		printf("[Error] Too many drive motors in array\n\r");
		return false;
	}

	for (int i = 0; i < numDriveMotors; i++) {
		this->driveMotors[i] = driveMotors[i];
	}
	this->numDriveMotors = numDriveMotors;
	return true;
}

bool Robot::setLiftMotors(Motor* liftMotors[], char numLiftMotors) {
	if (numLiftMotors > 10) {
		printf("[Error] Too many lift motors in array\n\r");
		return false;
	}

	for (int i = 0; i < numLiftMotors; i++) {
		this->liftMotors[i] = liftMotors[i];
	}
	this->numLiftMotors = numLiftMotors;
	return true;
}

void Robot::setIntakeMotors(Motor* claw, Motor* clawArm) {
	this->clawMotor = claw;
	this->clawArmMotor = clawArm;
}

///////////////////////////////
//DRIVE ORIENTATION FUNCTIONS//
///////////////////////////////

void Robot::setDriveOrientation(DriveOrientation orientation) {
	this->orientation = orientation;
}

void Robot::reverseDriveOrientation() {
	if (orientation == ForwardOrientation) {
		orientation = BackwardOrientation;
	} else if (orientation == BackwardOrientation) {
		orientation = ForwardOrientation;
	}
}

///////////////////
//DRIVE FUNCTIONS//
///////////////////

void Robot::drive(int power, DriveDirection dir) {
	if (orientation == BackwardOrientation) {
		switch (dir) {
		case ManualDrive:
			power = -power;
			break;
		case ManualTurn:
			power = -power;
			break;
		case ManualStrafe:
			power = -power;
			break;
		case DriveForward:
			dir = DriveBackward;
			break;
		case DriveBackward:
			dir = DriveForward;
			break;
		case TurnLeft:
			dir = TurnRight;
			break;
		case TurnRight:
			dir = TurnLeft;
			break;
		case StrafeLeft:
			dir = StrafeRight;
			break;
		case StrafeRight:
			dir = StrafeLeft;
			break;
		}
	}

	switch (dir) {
	case ManualDrive:
		for (int i = 0; i < numDriveMotors; i++) {
			Motor* motor = driveMotors[i];
			motor->setPower(power);
		}
		break;
	case ManualTurn:
		for (int i = 0; i < numDriveMotors; i++) {
			Motor* motor = driveMotors[i];
			MotorLocationSide side = motor->getLocationSide();
			switch (side) {
			case LeftSide:
				motor->setPower(power);
				break;
			case RightSide:
				motor->setPower(-power);
				break;
			default:
				printf(
						"[Warning] A motor on the drive does not have it's location properly set.\n\r");
				break;
			}
		}
		break;
	case ManualStrafe:
		for (int i = 0; i < numDriveMotors; i++) {
			Motor* motor = driveMotors[i];
			MotorLocation location = motor->getLocation();
			switch (location) {
			case FrontRight:
				motor->setPower(-power);
				break;
			case FrontLeft:
				motor->setPower(power);
				break;
			case BackRight:
				motor->setPower(power);
				break;
			case BackLeft:
				motor->setPower(-power);
			default:
				printf(
						"[Warning] A motor on the drive does not have it's location properly set for strafing.\n\r");
				break;
			}
		}
		break;
	case DriveForward:
		power = abs(power);
		for (int i = 0; i < numDriveMotors; i++) {
			Motor* motor = driveMotors[i];
			motor->setPower(power);
		}
		break;
	case DriveBackward:
		power = -abs(power);
		for (int i = 0; i < numDriveMotors; i++) {
			Motor* motor = driveMotors[i];
			motor->setPower(power);
		}
		break;
	case TurnLeft:
		power = abs(power);
		for (int i = 0; i < numDriveMotors; i++) {
			Motor* motor = driveMotors[i];
			MotorLocationSide side = motor->getLocationSide();
			switch (side) {
			case LeftSide:
				motor->setPower(-power);
				break;
			case RightSide:
				motor->setPower(power);
				break;
			default:
				printf(
						"[Warning] A motor on the drive does not have it's location properly set.\n\r");
			}
		}
		break;
	case TurnRight:
		power = abs(power);
		for (int i = 0; i < numDriveMotors; i++) {
			Motor* motor = driveMotors[i];
			MotorLocationSide side = motor->getLocationSide();
			switch (side) {
			case LeftSide:
				motor->setPower(power);
				break;
			case RightSide:
				motor->setPower(-power);
				break;
			default:
				printf(
						"[Warning] A motor on the drive does not have it's location properly set.\n\r");
				break;
			}
		}
		break;
	case StrafeLeft:
		power = abs(power);
		for (int i = 0; i < numDriveMotors; i++) {
			Motor* motor = driveMotors[i];
			MotorLocation location = motor->getLocation();
			switch (location) {
			case FrontRight:
				motor->setPower(power);
				break;
			case FrontLeft:
				motor->setPower(-power);
				break;
			case BackRight:
				motor->setPower(-power);
				break;
			case BackLeft:
				motor->setPower(power);
			default:
				printf(
						"[Warning] A motor on the drive does not have it's location properly set for strafing.\n\r");
				break;
			}
		}
		break;
	case StrafeRight:
		power = abs(power);
		for (int i = 0; i < numDriveMotors; i++) {
			Motor* motor = driveMotors[i];
			MotorLocation location = motor->getLocation();
			switch (location) {
			case FrontRight:
				motor->setPower(-power);
				break;
			case FrontLeft:
				motor->setPower(power);
				break;
			case BackRight:
				motor->setPower(power);
				break;
			case BackLeft:
				motor->setPower(-power);
			default:
				printf(
						"[Warning] A motor on the drive does not have it's location properly set for strafing.\n\r");
				break;
			}
		}
		break;
	}
}

void Robot::stopDriveMotors(){
	for (int i = 0; i < numDriveMotors; i++){
		driveMotors[i]->stop();
	}
}

//////////////////
//LIFT FUNCTIONS//
//////////////////

void Robot::lift(int power, LiftDirection dir) {
	switch (dir) {
	case ManualLift:
		for (int i = 0; i < numLiftMotors; i++) {
			liftMotors[i]->setPower(power);
		}
		break;
	case Up:
		power = abs(power);
		for (int i = 0; i < numLiftMotors; i++) {
			liftMotors[i]->setPower(power);
		}
		break;
	case Down:
		power = abs(power);
		for (int i = 0; i < numLiftMotors; i++) {
			liftMotors[i]->setPower(-power);
		}
		break;
	}
}

void Robot::stopLift() {
	lift(0, ManualLift);
}

//////////////////
//CLAW FUNCTIONS//
//////////////////

void Robot::claw(int power, ClawDirection dir) {
	switch (dir) {
	case ManualClawControl:
		clawMotor->setPower(power);
		break;
	case OpenClaw:
		power = abs(power);
		clawMotor->setPower(power);
		break;
	case CloseClaw:
		power = abs(power);
		clawMotor->setPower(-power);
		break;
	}
}

void Robot::stopClaw() {
	clawMotor->stop();
}

//////////////////////
//CLAW ARM FUNCTIONS//
//////////////////////

void Robot::clawArm(int power, ClawArmDirection dir) {
	switch (dir) {
	case ManualClawArmControl:
		clawArmMotor->setPower(power);
		break;
	case RotateArmLeft:
		power = abs(power);
		clawArmMotor->setPower(-power);
		break;
	case RotateArmRight:
		power = abs(power);
		clawArmMotor->setPower(power);
		break;
	}
}

void Robot::stopClawArm() {
	clawArmMotor->stop();
}

}
/* namespace TRL */
