/*
 * Robot.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: cwenck
 */

#include "Robot/Robot.h"

namespace TRL {
///////////////////////////////
//CONTSTRUCTORS + DESTRUCTORS//
///////////////////////////////

Robot* Robot::instance;

void Robot::initStatics() {
	instance = new Robot();
}

Robot::Robot() {
	//Init the defualt orientaiton
	orientation = ForwardOrientation;

	driveMotors = NULL;
	liftMotors = NULL;

	leftLiftPower = 0;
	rightLiftPower = 0;

	leftDrivePower = 0;
	rightDrivePower = 0;

	allianceColor = RED;
	startLocation = OUTER_TILE;
}

Robot::~Robot() {
}

////////////////////
//CONTROLLER INPUT//
////////////////////

void Robot::handleInput(InputControlMode controlMode) {
//	driveInputController(controlMode);
}

//void Robot::driveOrientationInputController(InputControlMode controlMode) {
//	bool masterForwardActive = controller.isInputActive(
//			orientation_forward);
//	bool masterBackwawrdActive = controller.isInputActive(
//			orientation_backward);
//	bool slaveForwardActive = controller.isInputActive(
//			orientation_forward);
//	bool slaveBackwardActive = controller.isInputActive(
//			orientation_backward);
//
//	bool masterActive = masterForwardActive || masterBackwawrdActive;
//	bool slaveActive = slaveForwardActive || slaveBackwardActive;
//
//	switch (controlMode) {
//	case MasterOnly:
//		driveOrientationController(master_controller);
//		return;
//	case SlaveOnly:
//		driveOrientationController(slave_controller);
//		return;
//	case MasterAndSlaveEqualPriority:
//		if (masterActive && !slaveActive) {
//			driveOrientationController(master_controller);
//		} else if (!masterActive && slaveActive) {
//			driveOrientationController(slave_controller);
//		} else if (masterActive && slaveActive) {
//			//Dont send any input if both are trying to control it
//		}
//		return;
//	case MasterHigherPriority:
//		if (masterActive && !slaveActive) {
//			driveOrientationController(master_controller);
//		} else if (!masterActive && slaveActive) {
//			driveOrientationController(slave_controller);
//		} else if (masterActive && slaveActive) {
//			driveOrientationController(master_controller);
//		}
//		return;
//	case SlaveHigherPriority:
//		if (masterActive && !slaveActive) {
//			driveOrientationController(master_controller);
//		} else if (!masterActive && slaveActive) {
//			driveOrientationController(slave_controller);
//		} else if (masterActive && slaveActive) {
//			driveOrientationController(slave_controller);
//		}
//		return;
//	}
//}

void Robot::driveOrientationController(Controller &controller) {
	if (controller.isInputActive(RobotControls::orientationForward)) {
		setDriveOrientation(ForwardOrientation);
	} else if (controller.getValue(RobotControls::orientationBackward) == 1) {
		setDriveOrientation(BackwardOrientation);
	}
}

void Robot::driveControllerHandler(InputControlMode controlMode) {
	RobotControllerFunctionPtr masterOperated = &Robot::softTurnDriveController;
	RobotControllerFunctionPtr slaveOperated = &Robot::hardTurnDriveController;

	RobotControllerHasInputFunctionPtr masterOperatedHasInput =
			&Robot::softTurnDriveControllerHasInput;
	RobotControllerHasInputFunctionPtr slaveOperatedHasInput =
			&Robot::hardTurnDriveControllerHasInput;

	bool masterActive = (this->*masterOperatedHasInput)(MASTER_CONTROLLER);
	bool slaveActive = (this->*slaveOperatedHasInput)(SLAVE_CONTROLLER);

	println(DEBUG, "Robot", "driveControllerHandler",
			"MasterActive: %d, SlaveActive: %d", masterActive, slaveActive);

	switch (controlMode) {
	case MasterOnly:
		(this->*masterOperated)(MASTER_CONTROLLER);
		return;
	case SlaveOnly:
		(this->*slaveOperated)(SLAVE_CONTROLLER);
		return;
	case MasterAndSlaveEqualPriority:
		if (masterActive && !slaveActive) {
			(this->*masterOperated)(MASTER_CONTROLLER);
		} else if (!masterActive && slaveActive) {
			(this->*slaveOperated)(SLAVE_CONTROLLER);
		} else if (masterActive && slaveActive) {
			stopDriveMotors();
		} else if (!masterActive && !slaveActive) {
			stopDriveMotors();
		}
		return;
	case MasterHigherPriority:
		if (masterActive && !slaveActive) {
			(this->*masterOperated)(MASTER_CONTROLLER);
		} else if (!masterActive && slaveActive) {
			(this->*slaveOperated)(SLAVE_CONTROLLER);
		} else if (masterActive && slaveActive) {
			(this->*masterOperated)(MASTER_CONTROLLER);
		} else if (!masterActive && !slaveActive) {
			stopDriveMotors();
		}
		return;
	case SlaveHigherPriority:
		if (masterActive && !slaveActive) {
			(this->*masterOperated)(MASTER_CONTROLLER);
		} else if (!masterActive && slaveActive) {
			(this->*slaveOperated)(SLAVE_CONTROLLER);
		} else if (masterActive && slaveActive) {
			(this->*slaveOperated)(SLAVE_CONTROLLER);
		} else if (!masterActive && !slaveActive) {
			stopDriveMotors();
		}
		return;
	}
}

bool Robot::softTurnDriveControllerHasInput(ControllerType type) {
	ControllerStick* stick =
			RobotControls::driveStick->getCorrespondingStickForControllerType(
					type);

	short y = stick->getY();
	short x = stick->getX();

	if (y == 0 && x == 0) {
		return false;
	} else {
		return true;
	}
}

bool Robot::hardTurnDriveControllerHasInput(ControllerType type) {
	ControllerStick* stick =
			RobotControls::driveStick->getCorrespondingStickForControllerType(
					type);

	short y = stick->getY();
	short x = stick->getX();

	if (y == 0 && x == 0) {
		return false;
	} else {
		return true;
	}
}

void Robot::hardTurnDriveController(ControllerType type) {
	ControllerStick* stick =
			RobotControls::driveStick->getCorrespondingStickForControllerType(
					type);

	short y = stick->getY();
	short x = stick->getX();

	if (abs(y) > abs(x)) {
		manualDrive(y);
	} else if (abs(x) >= abs(y)) {
		manualTurn(x);
	}
}

int Robot::calcDriveFromAngle(int angle, int maxPow) {
	angle = abs(angle);
	int power = maxPow * cos(angle * 2 * PI / 180);
	return power;
}

void Robot::softTurnDriveController(ControllerType type) {
	ControllerStick* stick =
			RobotControls::driveStick->getCorrespondingStickForControllerType(
					type);

	float angle = stick->getStickAngle();
	short y = stick->getY();
	short x = stick->getX();

	short leftPow = 0;
	short rightPow = 0;

	short largePower = 0;
	if (abs(x) > abs(y)) {
		largePower = abs(x);
	} else {
		largePower = abs(y);
	}

	if (x == 0 && y == 0) {
		//Do Nothing
	} else if (x == 0) {
		leftPow = y;
		rightPow = y;
	} else if (x > 0) {

		if (y > 0) {
			leftPow = largePower;
			rightPow = calcDriveFromAngle(angle, largePower);
		} else {
			leftPow = -calcDriveFromAngle(angle, largePower);
			rightPow = -largePower;
		}
	} else if (x < 0) {
		if (y > 0) {
			leftPow = calcDriveFromAngle(angle, largePower);
			rightPow = largePower;
		} else {
			leftPow = -largePower;
			rightPow = -calcDriveFromAngle(angle, largePower);
		}
	}

	leftDrivePower = leftPow;
	rightDrivePower = rightPow;
	manualTurn(leftPow, rightPow);
}

//
///////////////////////////////
//SET MOTOR POINTER FUNCTIONS//
///////////////////////////////

void Robot::setDriveMotors(Array<Motor*>* driveMotors) {
	this->driveMotors = driveMotors;
}

void Robot::setLiftMotors(Array<Motor*>* liftMotors) {
	this->liftMotors = liftMotors;
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

/////////////////////
////DRIVE FUNCTIONS//
/////////////////////

void Robot::powerLeftDrive(int power, WheelSidePowerMode mode) {
	this->leftDrivePower = power;

	for (int i = 0; i < driveMotors->size(); i++) {

		Motor* currentMotor = driveMotors->at(i);

		if (currentMotor->getLocation() == UnspecifiedMotorLocation) {
			println(ERROR, "Robot", "powerLeftDrive",
					"Motor (%s) in port %d doesn't have its location set. Please set it before trying to power it.");
			continue;
		}

		switch (mode) {
		case TogetherWheelPowerMode:
			if (currentMotor->getLocationSide() == LeftMotorLocationSide) {
				currentMotor->setPower(power);
			}
			break;

		case AwayWheelPowerMode:
			power = abs(power);
			switch (currentMotor->getLocation()) {
			case FrontLeftMotorLocation:
				currentMotor->setPower(power);
				break;
			case BackLeftMotorLocation:
				currentMotor->setPower(-power);
				break;
			default:
				//Do nothing
				break;
			}
			break;

		case TowardsWheelPowerMode:
			power = abs(power);
			switch (currentMotor->getLocation()) {
			case FrontLeftMotorLocation:
				currentMotor->setPower(-power);
				break;
			case BackLeftMotorLocation:
				currentMotor->setPower(power);
				break;
			default:
				//Do nothing
				break;
			}
			break;
		}
	}
}

void Robot::powerRightDrive(int power, WheelSidePowerMode mode) {
	this->rightDrivePower = power;

	for (int i = 0; i < driveMotors->size(); i++) {

		Motor* currentMotor = driveMotors->at(i);

		if (currentMotor->getLocation() == UnspecifiedMotorLocation) {
			println(ERROR, "Robot", "powerLeftDrive",
					"Motor (%s) in port %d doesn't have its location set. Please set it before trying to power it.");
			continue;
		}

		switch (mode) {
		case TogetherWheelPowerMode:
			if (currentMotor->getLocationSide() == RightMotorLocationSide) {
				currentMotor->setPower(power);
			}
			break;

		case AwayWheelPowerMode:
			power = abs(power);
			switch (currentMotor->getLocation()) {
			case FrontRightMotorLocation:
				currentMotor->setPower(power);
				break;
			case BackRightMotorLocation:
				currentMotor->setPower(-power);
				break;
			default:
				//Do nothing
				break;
			}
			break;

		case TowardsWheelPowerMode:
			power = abs(power);
			switch (currentMotor->getLocation()) {
			case FrontRightMotorLocation:
				currentMotor->setPower(-power);
				break;
			case BackRightMotorLocation:
				currentMotor->setPower(power);
				break;
			default:
				//Do nothing
				break;
			}
			break;
		}
	}
}

void Robot::powerDrive(int leftDrivePower, int rightDrivePower) {
	powerLeftDrive(leftDrivePower, TogetherWheelPowerMode);
	powerRightDrive(rightDrivePower, TogetherWheelPowerMode);
	this->leftDrivePower = leftDrivePower;
	this->rightDrivePower = rightDrivePower;
}

void Robot::powerDrive(int power) {
	for (int i = 0; i < driveMotors->size(); i++) {
		driveMotors->at(i)->setPower(power);
	}
}

void Robot::manualDrive(int power) {
	if (orientation == BackwardOrientation) {
		power = -power;
	}
	powerDrive(power);
}

void Robot::manualTurn(int powerLeft, int powerRight) {
	if (orientation == BackwardOrientation) {
		int tempLeftPower = powerLeft;
		powerLeft = -powerRight;
		powerRight = -tempLeftPower;
	}

	powerDrive(powerLeft, powerRight);
}

void Robot::manualTurn(int power) {
	//Nothing needs to be done for the reversed orientation
	powerDrive(power, -power);

}

void Robot::manualStrafe(int power) {
	if (orientation == BackwardOrientation) {
		power = -power;
	}

	if (power > 0) {
		powerLeftDrive(power, TowardsWheelPowerMode);
		powerRightDrive(power, AwayWheelPowerMode);
	} else if (power < 0) {
		powerLeftDrive(power, AwayWheelPowerMode);
		powerRightDrive(power, TowardsWheelPowerMode);
	}

}

void Robot::drive(int power, DriveDirection dir) {
	if (orientation == BackwardOrientation) {
		switch (dir) {
		case DriveForward:
			dir = DriveBackward;
			break;
		case DriveBackward:
			dir = DriveForward;
			break;
		case TurnLeft:
			//Nothing needs to be done
			break;
		case TurnRight:
			//Nothing needs to be done
			break;
		case StrafeLeft:
			dir = StrafeRight;
			break;
		case StrafeRight:
			dir = StrafeLeft;
			break;
		}
	}

	if (power == 0) {
		stopDriveMotors();
		return;
	}
	switch (dir) {
	case DriveForward:
		power = abs(power);
		powerDrive(power);
		break;
	case DriveBackward:
		power = abs(power);
		powerDrive(-power);
		break;
	case TurnLeft:
		power = abs(power);
		powerDrive(-power, power);
		break;
	case TurnRight:
		power = abs(power);
		powerDrive(power, -power);
		break;
	case StrafeLeft:
		power = abs(power);
		powerLeftDrive(power, TowardsWheelPowerMode);
		powerRightDrive(power, AwayWheelPowerMode);
		break;
	case StrafeRight:
		power = abs(power);
		powerLeftDrive(power, AwayWheelPowerMode);
		powerRightDrive(power, TowardsWheelPowerMode);
		break;
	}
}

void Robot::stopDriveMotors() {
	powerDrive(0);
}

//////////////////
//LIFT FUNCTIONS//
//////////////////

void Robot::powerLeftLift(int power) {
	this->leftLiftPower = power;
	for (int i = 0; i < liftMotors->size(); i++) {
		Motor* currentMotor = liftMotors->at(i);
		MotorLocationSide side = currentMotor->getLocationSide();
		if (side == NoSide) {
			println(ERROR, "Robot", "powerLeftLift",
					"A motor on the drive does not have it's location properly set for setting the left lift power.");
			continue;
		}
		if (side == LeftMotorLocationSide) {
			currentMotor->setPower(power);
		}
	}
}

void Robot::powerRightLift(int power) {
	this->rightLiftPower = power;
	for (int i = 0; i < liftMotors->size(); i++) {
		Motor* currentMotor = liftMotors->at(i);
		MotorLocationSide side = currentMotor->getLocationSide();
		if (side == NoSide) {
			println(ERROR, "Robot", "powerLeftRight",
					"A motor on the drive does not have it's location properly set for setting the right lift power.");
			continue;
		}
		if (side == LeftMotorLocationSide) {
			currentMotor->setPower(power);
		}
	}
}

void Robot::powerLift(int leftLiftPower, int rightLiftPower) {
	powerLeftLift(leftLiftPower);
	powerRightLift(rightLiftPower);
	this->leftLiftPower = leftLiftPower;
	this->rightLiftPower = rightLiftPower;
}

void Robot::powerLift(int power) {
	for (int i = 0; i < liftMotors->size(); i++) {
		liftMotors->at(i)->setPower(power);
	}
}

void Robot::lift(int power, LiftDirection dir) {
	switch (dir) {
	case ManualLift:
		powerLift(power);
		break;
	case LiftUp:
		power = abs(power);
		powerLift(power);
		break;
	case LiftDown:
		power = abs(power);
		powerLift(-power);
		break;
	}
}

void Robot::stopLift() {
	lift(0, ManualLift);
}
}

/* namespace TRL */
