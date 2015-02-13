/*
 * Motor.h
 *
 *  Created on: Jan 29, 2015
 *      Author: guywenck
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <API.h>

namespace TRL {

	enum MotorPort{
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
	};

	class Motor {
	private:
		Encoder* encoder;
		bool reversed;
		int speed;
		MotorPort port;

	public:
		Motor();
		Motor(MotorPort port);
		Motor(MotorPort port, bool reversed);
		Motor(MotorPort port, Encoder* encoder, bool reversed);
		virtual ~Motor();

		void setPower(int speed);
		void stop();
		void reverseDirection();

		static void setAllPower(int speed);
		static void stopAll();

		MotorPort getPort();
		Encoder* getEncoder();
	};
}
#endif /* MOTOR_H_ */
