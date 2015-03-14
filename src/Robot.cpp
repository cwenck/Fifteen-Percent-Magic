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
//	Motor Robot::frontRightDrive = Motor(MotorPort_10, FrontRight);
//	Motor Robot::frontLeftDrive = Motor(MotorPort_9, FrontLeft);
//	Motor Robot::backRightDrive = Motor(MotorPort_2, BackRight, true);
//	Motor Robot::backLeftDrive = Motor(MotorPort_1, BackLeft);
//
//	Motor Robot::frontRightLift = Motor(MotorPort_3, FrontRight);
//	Motor Robot::backRightLift = Motor(MotorPort_5, BackRight);
//	Motor Robot::frontLeftLift = Motor(MotorPort_4, FrontLeft, true);
//	Motor Robot::backLeftLift = Motor(MotorPort_6, BackLeft, true);
//
//	Motor Robot::intakeMotor = Motor(MotorPort_7, Intake);
//	Motor Robot::intakeArmMotor = Motor(MotorPort_8, Other);

//	Controller Robot::mainController = Controller(Normal_Controller);
//	Controller Robot::partnerController = Controller(Partner_Controller);

Robot::Robot() {
	mainController = Controller(Normal_Controller);
	partnerController = Controller(Partner_Controller);

	//Controller Deadzone
	controllerDeadzoneMagnitude = 10;

	//Init Controller Inputs
	y_drive_stick = Ch3;
	x_drive_stick = Ch4;

	lift_up = Btn5D;
	lift_down = Btn5U;

//	claw_rotate_left = ;
//	claw_rotate_right = Btn8R;
	claw_rotate = Ch1;

	claw_open = Btn6U;
	claw_close = Btn6D;

	orientation_forward = Btn7D;
	orientation_backward = Btn7U;

	//Init the default lift power
	liftPower = 127;
	clawArmPower = 127;
	clawOpenPower = 127;
	clawClosePower = 127;

	//Init the defualt orientaiton
	orientation = BackwardOrientation;

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

void Robot::handleInput(InputControlMode controlMode) {
	handleDriveOrientation(controlMode);
	handleDrive(controlMode);
	handleLift(controlMode);
	handleClaw(controlMode);
}

void Robot::handleDriveOrientation(InputControlMode controlMode) {
	switch (controlMode) {
	case NormalControllerOnly:
		if (mainController.getValue(orientation_forward) == 1) {
			setDriveOrientation(ForwardOrientation);
		} else if (mainController.getValue(orientation_backward) == 1) {
			setDriveOrientation(BackwardOrientation);
		}
		break;
	case NormalAndPartnerContoller:
		if (mainController.getValue(orientation_forward) == 1) {
			setDriveOrientation(ForwardOrientation);
		} else if (mainController.getValue(orientation_backward) == 1) {
			setDriveOrientation(BackwardOrientation);
		} else if (partnerController.getValue(orientation_forward) == 1) {
			setDriveOrientation(ForwardOrientation);
		} else if (partnerController.getValue(orientation_backward) == 1) {
			setDriveOrientation(BackwardOrientation);
		}
		break;
	}
}

void Robot::handleDrive(InputControlMode controlMode) {
	short yMain = mainController.getValue(y_drive_stick);
	short xMain = mainController.getValue(x_drive_stick);

	short yPartner = partnerController.getValue(y_drive_stick);
	short xPartner = partnerController.getValue(x_drive_stick);

	switch (controlMode) {
	case NormalControllerOnly:
		if (abs(xMain) < abs(controllerDeadzoneMagnitude)
				&& abs(yMain) < abs(controllerDeadzoneMagnitude)) {
			return;
		}

		if (abs(yMain) > abs(xMain)) {
			drive(yMain, ManualDrive);
		} else if (abs(xMain) >= abs(yMain)) {
			drive(xMain, ManualTurn);
		}
		break;
	case NormalAndPartnerContoller:
		if (!(abs(xMain) < abs(controllerDeadzoneMagnitude)
				&& abs(yMain) < abs(controllerDeadzoneMagnitude))) {
			if (abs(yMain) > abs(xMain)) {
				drive(yMain, ManualDrive);
			} else if (abs(xMain) >= abs(yMain)) {
				drive(xMain, ManualTurn);
			}
		} else if (!(abs(xPartner) < abs(controllerDeadzoneMagnitude)
				&& abs(yPartner) < abs(controllerDeadzoneMagnitude))) {
			if (abs(yPartner) > abs(xPartner)) {
				drive(yPartner, ManualDrive);
			} else if (abs(xPartner) >= abs(yPartner)) {
				drive(xPartner, ManualTurn);
			}
		} else {
			stopDriveMotors();
		}
		break;
	}
}

//returns false if the lift should be set to 0
void Robot::handleLift(InputControlMode controlMode) {
	switch (controlMode) {
	case NormalControllerOnly:
		if (mainController.getValue(lift_up) == 1) {
			lift(liftPower, Up);
		} else if (mainController.getValue(lift_down) == 1) {
			lift(liftPower, Down);
		} else {
			stopLift();
		}
		break;
	case NormalAndPartnerContoller:
		if (mainController.getValue(lift_up) == 1) {
			lift(liftPower, Up);
		} else if (mainController.getValue(lift_down) == 1) {
			lift(liftPower, Down);
		} else if (partnerController.getValue(lift_up) == 1) {
			lift(liftPower, Up);
		} else if (partnerController.getValue(lift_down) == 1) {
			lift(liftPower, Down);
		} else {
			stopLift();
		}
		break;
	}
}

void Robot::handleClaw(InputControlMode controlMode) {
	switch (controlMode) {
	case NormalControllerOnly:
		clawArm(mainController.getValue(claw_rotate), ManualClawArmControl);

		if (mainController.getValue(claw_open) == 1) {
			claw(clawOpenPower, OpenClaw);
		} else if (mainController.getValue(claw_close) == 1) {
			claw(clawClosePower, CloseClaw);
		} else {
			stopClaw();
		}
		break;
	case NormalAndPartnerContoller:
		if (mainController.getValue(claw_rotate) != 0) {
			clawArm(mainController.getValue(claw_rotate), ManualClawArmControl);
		} else if (partnerController.getValue(claw_rotate) != 0) {
			clawArm(partnerController.getValue(claw_rotate),
					ManualClawArmControl);
		} else {
			stopClawArm();
		}

		if (mainController.getValue(claw_open) == 1) {
			claw(clawOpenPower, OpenClaw);
		} else if (mainController.getValue(claw_close) == 1) {
			claw(clawClosePower, CloseClaw);
		} else if (partnerController.getValue(claw_open) == 1) {
			claw(clawOpenPower, OpenClaw);
		} else if (partnerController.getValue(claw_close) == 1) {
			claw(clawClosePower, CloseClaw);
		} else {
			stopClaw();
		}
		break;
	}

//	if (controller->getValue(cl) == 1) {
//		clawArm(clawArmPower, RotateArmLeft);
//	} else if (controller->getValue(claw_rotate_right) == 1) {
//		clawArm(clawArmPower, RotateArmRight);
//	} else {
//		stopClawArm();
//	}
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
//			power = -powe r;
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
//			dir = TurnRight;
			break;
		case TurnRight:
//			dir = TurnLeft;
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

void Robot::stopDriveMotors() {
	for (int i = 0; i < numDriveMotors; i++) {
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
