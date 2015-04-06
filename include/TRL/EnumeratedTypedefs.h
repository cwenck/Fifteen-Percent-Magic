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
		LiftUp,
		LiftDown
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
		Accel_X = 17,
		Accel_Y = 18,
		ShiftedInput_Btn5U = 19,
		ShiftedInput_Btn6U = 20,
		ShiftedInput_Btn7U = 21,
		ShiftedInput_Btn8U = 22,
		ShiftedInput_Btn5D = 23,
		ShiftedInput_Btn6D = 24,
		ShiftedInput_Btn7D = 25,
		ShiftedInput_Btn8D = 26,
		ShiftedInput_Btn7L = 27,
		ShiftedInput_Btn8L = 28,
		ShiftedInput_Btn7R = 29,
		ShiftedInput_Btn8R = 30,
		ShiftedInput_Ch1 = 31,
		ShiftedInput_Ch2 = 32,
		ShiftedInput_Ch3 = 33,
		ShiftedInput_Ch4 = 34,
		ShiftedInput_Accel_X = 35,
		ShiftedInput_Accel_Y = 36,
		Partner_Btn5U = 37,
		Partner_Btn6U = 38,
		Partner_Btn7U = 39,
		Partner_Btn8U = 40,
		Partner_Btn5D = 41,
		Partner_Btn6D = 42,
		Partner_Btn7D = 43,
		Partner_Btn8D = 44,
		Partner_Btn7L = 45,
		Partner_Btn8L = 46,
		Partner_Btn7R = 47,
		Partner_Btn8R = 48,
		Partner_Ch1 = 49,
		Partner_Ch2 = 50,
		Partner_Ch3 = 51,
		Partner_Ch4 = 52,
		Partner_Accel_X = 53,
		Partner_Accel_Y = 54,
		Partner_ShiftedInput_Btn5U = 55,
		Partner_ShiftedInput_Btn6U = 56,
		Partner_ShiftedInput_Btn7U = 57,
		Partner_ShiftedInput_Btn8U = 58,
		Partner_ShiftedInput_Btn5D = 59,
		Partner_ShiftedInput_Btn6D = 60,
		Partner_ShiftedInput_Btn7D = 61,
		Partner_ShiftedInput_Btn8D = 62,
		Partner_ShiftedInput_Btn7L = 63,
		Partner_ShiftedInput_Btn8L = 64,
		Partner_ShiftedInput_Btn7R = 65,
		Partner_ShiftedInput_Btn8R = 66,
		Partner_ShiftedInput_Ch1 = 67,
		Partner_ShiftedInput_Ch2 = 68,
		Partner_ShiftedInput_Ch3 = 69,
		Partner_ShiftedInput_Ch4 = 70,
		Partner_ShiftedInput_Accel_X = 71,
		Partner_ShiftedInput_Accel_Y = 72
	}ControllerInput;

	typedef enum _ControllerShiftButton {
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
	}ControllerShiftButton;

	typedef enum _ControllerType {
		MASTER_CONTROLLER = 1,
		SLAVE_CONTROLLER = 2,
	}ControllerType;

	typedef enum _ControllerInputType {
		BUTTON,
		JOYSTICK,
		ACCEL
	}ControllerInputType;

	typedef enum _ControllerStickSide {
		NULL_JOYSTICK,
		LEFT_JOYSTICK,
		RIGHT_JOYSTICK,
		ACCEL_JOYSTICK
	}ControllerStickSide;

	////////////////////////////////
	//CORTEX FILE ENUMERATED TYPES//
	////////////////////////////////

	typedef enum _FileMode {
		UnsetFileMode,
		ReadFileMode,
		WriteFileMode
	}FileMode;

	////////////////////////////////
	//SENSOR/PORT ENUMERATED TYPES//
	////////////////////////////////

	typedef enum _AnalogPort {
		NoAnalogInput = 0,
		Analog_1 = 1,
		Analog_2 = 2,
		Analog_3 = 3,
		Analog_4 = 4,
		Analog_5 = 5,
		Analog_6 = 6,
		Analog_7 = 7,
		Analog_8 = 8
	}AnalogPort;

	typedef enum _DigitalPort {
		NoDigitalInput = 0,
		Digital_1 = 1,
		Digital_2 = 2,
		Digital_3 = 3,
		Digital_4 = 4,
		Digital_5 = 5,
		Digital_6 = 6,
		Digital_7 = 7,
		Digital_8 = 8,
		Digital_9 = 9,
		Digital_10 = 10,
		Digital_11 = 11,
		Digital_12 = 12
	}DigitalPort;

	typedef enum _IntegratedEncoderPort {
		IntegratedEncoder_1 = 1,
		IntegratedEncoder_2 = 2,
		IntegratedEncoder_3 = 3,
		IntegratedEncoder_4 = 4,
		IntegratedEncoder_5 = 5,
		IntegratedEncoder_6 = 6,
		IntegratedEncoder_7 = 7,
		IntegratedEncoder_8 = 8,
		IntegratedEncoder_9 = 9,
		IntegratedEncoder_10 = 10
	}IntegratedEncoderPort;

	typedef enum _EncoderType {
		QuadratureEncoderType = 1,
		IntegratedEncoderType = 2
	}EncoderType;

	typedef enum _Axis{
		UnsetAxis,
		xAxis,
		yAxis,
		zAxis
	}Axis;

	typedef enum _LCDPort {
		NoLCD = 0,
		UART_1 = 1,
		UART_2 = 2
	}LCDPort;

	typedef enum _SonarUnit {
		CM,
		INCH
	}SonarUnit;

	typedef enum _UnefinedBehavior {
		ReturnHighValue,
		ReturnLowValue
	}UnefinedBehavior;

	typedef enum _PortType {
		AnalogPortType,
		DigitalPortType,
		OtherPortType
	}PortType;

	//Analog ports can be configured as ditgitial inputs
	typedef enum _PortConfig {
		DigitalInputPort,
		AnalogInputPort,
		OutputPort
	}PortConfig;

	typedef enum _SensorType {
		NullSensorType = 0,
		QuadratureEncoderSensorType,
		PotentiometerSensorType,
		LightSensorType,
		SonarSensorType,
		LineSensorType,
		BumperSensorType,
		LimitSwitchSensorType,
		GyroscopeSensorType,
		AccelerometerSensorType

	}SensorType;

	//////////////////////////
	//MOTOR ENUMERATED TYPES//
	//////////////////////////

	typedef enum _MotorPort {
		MotorPort_NULL = 0,
		MotorPort_1 = 1,
		MotorPort_2 = 2,
		MotorPort_3 = 3,
		MotorPort_4 = 4,
		MotorPort_5 = 5,
		MotorPort_6 = 6,
		MotorPort_7 = 7,
		MotorPort_8 = 8,
		MotorPort_9 = 9,
		MotorPort_10 = 10
	}MotorPort;

	typedef enum _MotorLocation {
		UnspecifiedMotorLocation = 0,
		LeftMotorLocation,
		RightMotorLocation,
		FrontRightMotorLocation,
		FrontLeftMotorLocation,
		CenterRightMotorLocation,
		CenterLeftMotorLocation,
		BackRightMotorLocation,
		BackLeftMotorLocation,
		IntakeMotorLocation,
		OtherMotorLocation
	}MotorLocation;

	typedef enum _MotorLocationSide {
		NoSide,
		LeftSide,
		RightSide
	}MotorLocationSide;

}

#endif /* ENUMERATEDTYPEDEFS_H_ */
