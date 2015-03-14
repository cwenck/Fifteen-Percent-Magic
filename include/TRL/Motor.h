/*
 * Motor.h
 *
 *  Created on: Jan 29, 2015
 *      Author: guywenck
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <API.h>
#include "GenericEncoder.h"

namespace TRL {

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
		NullMotorLocation = 0,
		Left,
		Right,
		FrontRight,
		FrontLeft,
		CenterRight,
		CenterLeft,
		BackRight,
		BackLeft,
		Intake,
		Other
	}MotorLocation;

	typedef enum _MotorLocationSide {
		NoSide,
		LeftSide,
		RightSide
	}MotorLocationSide;

	class Motor {
	private:
		GenericEncoder* encoder;
		bool reversed;
		int speed;
		MotorPort port;
		MotorLocation location;
	public:
		Motor();
		Motor(MotorPort port, MotorLocation location);
		Motor(MotorPort port, MotorLocation location, bool reversed);
		Motor(MotorPort port, MotorLocation location, GenericEncoder* encoder, bool reversed);
		virtual ~Motor();

		void setPower(int speed);
		void stop();
		void reverseDirection();

		static void setAllPower(int speed);
		static void stopAll();

		MotorPort getPort();
		MotorLocation getLocation();
		MotorLocationSide getLocationSide();
		GenericEncoder* getEncoder();
	};
}
#endif /* MOTOR_H_ */
