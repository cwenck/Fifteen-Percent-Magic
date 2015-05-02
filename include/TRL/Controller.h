/*
 * Controller.h
 *
 *  Created on: Feb 3, 2015
 *      Author: guywenck
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "MathPlus.h"
#include "EnumeratedTypedefs.h"
#include "Constants.h"
#include "PrintStream.h"
#include "Typedefs.h"

#define NUMBER_NON_SHIFTED_INPUTS 18

namespace TRL {

	class Controller;

	class ControllerStick {
	private:
		Controller* controller;
		ControllerInput xCh;
		ControllerInput yCh;
	public:
		static ControllerStick* leftMaster;
		static ControllerStick* rightMaster;
		static ControllerStick* leftSlave;
		static ControllerStick* rightSlave;

		static ControllerStick* shiftedLeftMaster;
		static ControllerStick* shiftedRightMaster;
		static ControllerStick* shiftedLeftSlave;
		static ControllerStick* shiftedRightSlave;

		static void initStatics();

		ControllerStick();
		ControllerStick(Controller* controller, ControllerInput xChannel, ControllerInput yChannel);
		~ControllerStick();

		float getStickAngle();
		int getX();
		int getY();

		ControllerType getControllerType();
		ControllerStick* getCorrespondingStickForControllerType(ControllerType type);

		static ControllerType getControllerType(ControllerStick* stick);
		static ControllerStick* getCorrespondingStickForControllerType(ControllerType type, ControllerStick* stick);
	};

	class Controller {
	private:
		ControllerShiftButton masterShiftKey;
		ControllerShiftButton slaveShiftKey;
		short masterLeftStickDeadzoneMagnitude;
		short masterRightStickDeadzoneMagnitude;
		short slaveLeftStickDeadzoneMagnitude;
		short slaveRightStickDeadzoneMagnitude;

	public:
		//Instance//
		static Controller* instance;
		static void initInstance();

		//CONSTRUCTORS AND DESTRUCTOR//
		Controller();
		virtual ~Controller();

		//GENERAL CONTROLLER FUNCTIONS//
		bool isInputInactive(ControllerInput in);
		bool isInputActive(ControllerInput in);

		int getRawValue(ControllerInput in);
		int getValue(ControllerInput in);

		//DEADZONE FUNCTIONS//
		void setLeftStickDeadzone(ControllerType type, short deadzone);
		void setRightStickDeadzone(ControllerType type, short deadzone);
		void setJoystickDeadzone(ControllerType type, short deadzone);

		//SHIFT FUNCTIONS//
		void setShiftKey(ControllerType type, ControllerShiftButton input);
		bool isControllerShifted(ControllerType type);//returns true if the controller's shift button is pressed
		bool isShiftedInputType(ControllerInput in);
		bool isNonShiftedInputType(ControllerInput in);
		bool isSlaveControllerInput(ControllerInput in);
		bool isMasterControllerInput(ControllerInput in);

		ControllerInput convertControllerInputToNonShiftedVariant(ControllerInput in);
		ControllerInput convertControllerInputToShiftedVariant(ControllerInput in);
		ControllerInput convertControllerInputToMasterVariant(ControllerInput in);
		ControllerInput convertControllerInputToSlaveVariant(ControllerInput in);
		ControllerInput convertControllerInputToType(ControllerType type, ControllerInput in);

		ControllerInput getControllerInputForShiftBtn(ControllerType type, ControllerShiftButton shiftBtn);

		//CONTROLLER INPUT INFO FUNCTIONS//
		ControllerInputType getControllerInputType(ControllerInput in);
		ControllerStickSide getJoystickSide(ControllerInput in);
		ControllerType getInputControllerType(ControllerInput in);
		int getInputControllerNumber(ControllerInput in);

		//CONTROLLER INFO FUNCTIONS

	};
}
#endif /* CONTROLLER_H_ */
