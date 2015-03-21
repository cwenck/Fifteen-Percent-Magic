/*
 * EnumeratedTypedefs.h
 *
 *  Created on: Mar 19, 2015
 *      Author: guywenck
 */

#ifndef ENUMERATEDTYPEDEFS_H_
#define ENUMERATEDTYPEDEFS_H_

namespace TRL {
	typedef enum _RobotStartLocation {
		AUTO_LOADER = 1,
		POLE = 2
	}RobotStartLocation;

	typedef enum _AllianceColor {
		RED,
		BLUE
	}AllianceColor;

	typedef enum _InputControlMode {
		MasterOnly,
		SlaveOnly,
		MasterAndSlaveEqualPriority,
		MasterHigherPriority,
		SlaveHigherPriority
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
}

#endif /* ENUMERATEDTYPEDEFS_H_ */
