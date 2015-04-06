/*
 * Motor.h
 *
 *  Created on: Jan 29, 2015
 *      Author: guywenck
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <API.h>
#include "MotorRegistry.h"
#include "GenericEncoder.h"
#include "TRL_BaseInitialization.h"

#define MOTOR_NAME_NULL "**[NULL]**"

namespace TRL {

	class Motor {
	private:
		GenericEncoder* encoder;
		bool reversed;
		int speed;
		short offset;
		MotorPort port;
		MotorLocation location;
		string motorName;

		//functions
		int addOffsetToSpeed(int speed);

	public:
		Motor();
		Motor(MotorPort port, MotorLocation location, string motorName);
		Motor(MotorPort port, MotorLocation location, string motorName, short offset);
		Motor(MotorPort port, MotorLocation location, string motorName, bool reversed);
		Motor(MotorPort port, MotorLocation location, string motorName, bool reversed, short offset);
		Motor(MotorPort port, MotorLocation location, string motorName, GenericEncoder* encoder, bool reversed);
		Motor(MotorPort port, MotorLocation location, string motorName, GenericEncoder* encoder, bool reversed, short offset);
		virtual ~Motor();

		bool removeFromRegistry();

		void setPower(int speed);
		void stop();
		void reverseDirection();

		static void setAllPower(int speed);
		static void stopAll();

		MotorPort getPort();
		MotorLocation getLocation();
		MotorLocationSide getLocationSide();
		GenericEncoder* getEncoder();

		string getName();

	};
}
#endif /* MOTOR_H_ */
