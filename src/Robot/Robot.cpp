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

Robot Robot::instance;

Controller Robot::controller;

void Robot::initStatics() {
	instance = Robot();
}

Robot::Robot() {
	//Init the defualt orientaiton
	orientation = ForwardOrientation;

	driveMotors = NULL;
	liftMotors = NULL;
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

void Robot::driveOrientationMirrorController(Controller &controller) {
	if (controller.isInputActive(RobotControls::orientationForward)) {
		setDriveOrientation(ForwardOrientation);
	} else if (controller.getValue(RobotControls::orientationBackward) == 1) {
		setDriveOrientation(BackwardOrientation);
	}
}

//void Robot::driveInputController(InputControlMode controlMode) {
//	bool yMasterActiveDrive = master_controller.isInputActive(y_drive_stick);
//	bool xMasterActiveDrive = master_controller.isInputActive(x_drive_stick);
//
//	bool yMasterActiveStrafe = master_controller.isInputActive(y_strafe_stick);
//	bool xMasterActiveStrafe = master_controller.isInputActive(x_strafe_stick);
//
//	bool ySlaveActiveDrive = slave_controller.isInputActive(y_drive_stick);
//	bool xSlaveActiveDrive = slave_controller.isInputActive(x_drive_stick);
//
//	bool ySlaveActiveStrafe = slave_controller.isInputActive(y_strafe_stick);
//	bool xSlaveActiveStrafe = slave_controller.isInputActive(x_strafe_stick);
//
//	bool masterDriveActive = xMasterActiveDrive || yMasterActiveDrive;
//	bool masterStrafeActive = xMasterActiveStrafe || yMasterActiveStrafe;
//	bool masterActive = masterDriveActive || masterStrafeActive;
//
//	bool slaveDriveActive = xSlaveActiveDrive || ySlaveActiveDrive;
//	bool slaveStrafeActive = xSlaveActiveStrafe || ySlaveActiveStrafe;
//	bool slaveActive = slaveDriveActive || slaveStrafeActive;
//
//	switch (controlMode) {
//	case MasterOnly:
//		driveController(master_controller);
//		return;
//	case SlaveOnly:
//		driveController(slave_controller);
//		return;
//	case MasterAndSlaveEqualPriority:
//		if (masterActive && !slaveActive) {
//			driveController(master_controller);
//		} else if (!masterActive && slaveActive) {
//			driveController(slave_controller);
//		} else if (masterActive && slaveActive) {
//			//Dont send any input if both are trying to control it
//		} else if (!masterActive && !slaveActive) {
//			stopDriveMotors();
//		}
//		return;
//	case MasterHigherPriority:
//		if (masterActive && !slaveActive) {
//			driveController(master_controller);
//		} else if (!masterActive && slaveActive) {
//			driveController(slave_controller);
//		} else if (masterActive && slaveActive) {
//			driveController(master_controller);
//		} else if (!masterActive && !slaveActive) {
//			stopDriveMotors();
//		}
//		return;
//	case SlaveHigherPriority:
//		if (masterActive && !slaveActive) {
//			driveController(master_controller);
//		} else if (!masterActive && slaveActive) {
//			driveController(slave_controller);
//		} else if (masterActive && slaveActive) {
//			driveController(slave_controller);
//		} else if (!masterActive && !slaveActive) {
//			stopDriveMotors();
//		}
//		return;
//	}
//}

void Robot::driveController(Controller *controller) {
	short y = RobotControls::driveStick->getY();
	short x = RobotControls::driveStick->getX();

	if (abs(y) > abs(x)) {
		drive(y, ManualDrive);
	} else if (abs(x) >= abs(y)) {
		drive(x, ManualTurn);
	}
}

int Robot::calcDriveFromAngle(int angle, int maxPow) {
	angle = abs(angle);
	int power = maxPow * cos(angle * 2 * PI / 180);
	return power;
}

void Robot::softTurnDriveController(Controller *controller) {
	float angle = RobotControls::driveStick->getStickAngle();
	int x = RobotControls::driveStick->getX();
	int y = RobotControls::driveStick->getY();
	int leftPow = 0;
	int rightPow = 0;

	int largePower = 0;
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
	powerDrive(leftPow, rightPow);
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

}

void Robot::powerRightDrive(int power, WheelSidePowerMode mode) {

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

void Robot::drive(int power, DriveDirection dir) {
	if (orientation == BackwardOrientation) {
		switch (dir) {
			case ManualDrive:
				power = -power;
				break;
			case ManualTurn:
				//Nothing needs to be done
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

	switch (dir) {
		case ManualDrive:
			for (int i = 0; i < driveMotors->size(); i++) {
				Motor* motor = driveMotors->at(i);
				motor->setPower(power);
			}
			break;
		case ManualTurn:
			for (int i = 0; i < driveMotors->size(); i++) {
				Motor* motor = driveMotors->at(i);
				MotorLocationSide side = motor->getLocationSide();
				switch (side) {
					case LeftSide:
						motor->setPower(power);
						break;
					case RightSide:
						motor->setPower(-power);
						break;
					default:
						println(ERROR, "Robot", "drive",
								"A motor on the drive does not have it's location properly set for strafing.");
						break;
				}
			}
			break;
		case ManualStrafe:
			for (int i = 0; i < driveMotors->size(); i++) {
				Motor* motor = driveMotors->at(i);
				MotorLocation location = motor->getLocation();
				switch (location) {
					case FrontRightMotorLocation:
						motor->setPower(-power);
						break;
					case FrontLeftMotorLocation:
						motor->setPower(power);
						break;
					case BackRightMotorLocation:
						motor->setPower(power);
						break;
					case BackLeftMotorLocation:
						motor->setPower(-power);
					default:
						println(ERROR, "Robot", "drive",
								"A motor on the drive does not have it's location properly set for strafing.");
						break;
				}
			}
			break;
		case DriveForward:
			power = abs(power);
			for (int i = 0; i < driveMotors->size(); i++) {
				Motor* motor = driveMotors->at(i);
				motor->setPower(power);
			}
			break;
		case DriveBackward:
			power = -abs(power);
			for (int i = 0; i < driveMotors->size(); i++) {
				Motor* motor = driveMotors->at(i);
				motor->setPower(power);
			}
			break;
		case TurnLeft:
			power = abs(power);
			for (int i = 0; i < driveMotors->size(); i++) {
				Motor* motor = driveMotors->at(i);
				MotorLocationSide side = motor->getLocationSide();
				switch (side) {
					case LeftSide:
						motor->setPower(-power);
						break;
					case RightSide:
						motor->setPower(power);
						break;
					default:
						println(ERROR, "Robot", "drive",
								"A motor on the drive does not have it's location properly set for strafing.");
				}
			}
			break;
		case TurnRight:
			power = abs(power);
			for (int i = 0; i < driveMotors->size(); i++) {
				Motor* motor = driveMotors->at(i);
				MotorLocationSide side = motor->getLocationSide();
				switch (side) {
					case LeftSide:
						motor->setPower(power);
						break;
					case RightSide:
						motor->setPower(-power);
						break;
					default:
						println(ERROR, "Robot", "drive",
								"A motor on the drive does not have it's location properly set for strafing.");
						break;
				}
			}
			break;
		case StrafeLeft:
			power = abs(power);
			for (int i = 0; i < driveMotors->size(); i++) {
				Motor* motor = driveMotors->at(i);
				MotorLocation location = motor->getLocation();
				switch (location) {
					case FrontRightMotorLocation:
						motor->setPower(power);
						break;
					case FrontLeftMotorLocation:
						motor->setPower(-power);
						break;
					case BackRightMotorLocation:
						motor->setPower(-power);
						break;
					case BackLeftMotorLocation:
						motor->setPower(power);
					default:
						println(ERROR, "Robot", "drive",
								"A motor on the drive does not have it's location properly set for strafing.");
						break;
				}
			}
			break;
		case StrafeRight:
			power = abs(power);
			for (int i = 0; i < driveMotors->size(); i++) {
				Motor* motor = driveMotors->at(i);
				MotorLocation location = motor->getLocation();
				switch (location) {
					case FrontRightMotorLocation:
						motor->setPower(-power);
						break;
					case FrontLeftMotorLocation:
						motor->setPower(power);
						break;
					case BackRightMotorLocation:
						motor->setPower(power);
						break;
					case BackLeftMotorLocation:
						motor->setPower(-power);
					default:
						println(ERROR, "Robot", "drive",
								"A motor on the drive does not have it's location properly set for strafing.");
						break;
				}
			}
			break;
	}
}

void Robot::stopDriveMotors() {
	for (int i = 0; i < driveMotors->size(); i++) {
		driveMotors->at(i)->stop();
	}
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
		if (side == LeftSide) {
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
		if (side == LeftSide) {
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
