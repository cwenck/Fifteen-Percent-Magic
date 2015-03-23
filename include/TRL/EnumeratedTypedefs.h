/*
 * EnumeratedTypedefs.h
 *
 *  Created on: Mar 19, 2015
 *      Author: guywenck
 */

#ifndef ENUMERATEDTYPEDEFS_H_
#define ENUMERATEDTYPEDEFS_H_

namespace TRL {

	///////////////////////////////
	//ROBOT ENUMERATED TYPES//
	///////////////////////////////

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

	///////////////////////////////
	//CONTROLLER ENUMERATED TYPES//
	///////////////////////////////

	typedef enum _ControllerInput {
		Btn5U = 1,
		Btn6U = 2,
		Btn7U = 3,
		Btn8U = 4,
		Btn5D = 5,
		Btn6D = 6,
		Btn7D = 7,
		Btn8D = 8,
		Btn7L = 9,
		Btn8L = 10,
		Btn7R = 11,
		Btn8R = 12,
		Ch1 = 13,
		Ch2 = 14,
		Ch3 = 15,
		Ch4 = 16,
		ShiftedInput_Btn5U = 17,
		ShiftedInput_Btn6U = 18,
		ShiftedInput_Btn7U = 19,
		ShiftedInput_Btn8U = 20,
		ShiftedInput_Btn5D = 21,
		ShiftedInput_Btn6D = 22,
		ShiftedInput_Btn7D = 23,
		ShiftedInput_Btn8D = 24,
		ShiftedInput_Btn7L = 25,
		ShiftedInput_Btn8L = 26,
		ShiftedInput_Btn7R = 27,
		ShiftedInput_Btn8R = 28,
		ShiftedInput_Ch1 = 29,
		ShiftedInput_Ch2 = 30,
		ShiftedInput_Ch3 = 31,
		ShiftedInput_Ch4 = 32
	}ControllerInput;

	typedef enum _ControllerShiftButtonInput {
		ShiftBtn_None = 0,
		ShiftBtn_5U = 1,
		ShiftBtn_6U = 2,
		ShiftBtn_7U = 3,
		ShiftBtn_8U = 4,
		ShiftBtn_5D = 5,
		ShiftBtn_6D = 6,
		ShiftBtn_7D = 7,
		ShiftBtn_8D = 8,
		ShiftBtn_7L = 9,
		ShiftBtn_8L = 10,
		ShiftBtn_7R = 11,
		ShiftBtn_8R = 12,
	}ControllerShiftInput;

	typedef enum _ControllerType {
		Master_Controller = 1,
		Slave_Controller = 2
	}ControllerType;

	typedef enum _ControllerInputType {
		BUTTON,
		JOYSTICK
	}ControllerInputType;
}

#endif /* ENUMERATEDTYPEDEFS_H_ */
