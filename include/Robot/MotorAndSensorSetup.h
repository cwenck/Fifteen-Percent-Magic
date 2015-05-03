/*
 * MotorAndSensorSetup.h
 *
 *  Created on: Apr 5, 2015
 *      Author: guywenck
 */

#ifndef MOTORANDSENSORSETUP_H_
#define MOTORANDSENSORSETUP_H_

#include "Robot_Includes.h"

namespace TRL {

	namespace Setup {
		void setupRobot();
	};

	class MotorList {
	public:
		static void initialize();
		static void setupRobotMotors();

		//These are just generic names for the template
		//You are encouraged to rename them using eclipse's
		//refactor->rename feature in the right click menu
		static Motor* testMotor;

		static Motor* leftLaucherWheelMotorOne;
		static Motor* leftLaucherWheelMotorTwo;
		static Motor* rightLaucherWheelMotorOne;
		static Motor* rightLaucherWheelMotorTwo;

		static Motor* frontLeftDrive;
		static Motor* backLeftDrive;
		static Motor* frontRightDrive;
		static Motor* backRightDrive;
	};

	class SensorList {
	public:
		static void initialize();

		static PowerExpander* powerExpander;
		static QuadratureEncoder* quad;
	};

	class AutonList {
	public:
		static void initialize();

		static AutonRoutine* routineOne;
		static AutonRoutine* routineTwo;
	};

	class RobotControls {
	public:
		static void initialize();
		static void setupControllers();

		//These controls are game specific
		static ControllerInput intakeBalls;
		static ControllerInput shootBall;

		static ControllerInput liftUp;
		static ControllerInput liftDown;

		//These variables should always exist
		static ControllerStick* driveStick;
		static ControllerStick* strafeStick;

		static ControllerInput orientationForward;
		static ControllerInput orientationBackward;



	};

	class RegistryHelper {
	public:
		static void printEntireRegistry();
	};

}

#endif /* MOTORANDSENSORSETUP_H_ */
