/*
 * Robot.h
 *
 *  Created on: Feb 8, 2015
 *      Author: guywenck
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include "Motor.h"

namespace TRL {
	typedef enum _Direction {
//		Forward,
//		Backward,
//		Left,
//		Right
		Drive_Forward,
		Drive_Backward,
		Turn_Left,
		Turn_Right,
		Strafe_Left,
		Strafe_Right
	}Direction;

	class Robot {
	private:
		Motor driveMotors[10];
		Motor liftMotors[10];

		int numLiftMotors;
		int numDriveMotors;
	public:
		Robot();
		virtual ~Robot();

		void setDriveMotors(Motor driveMotors[]);
		void setLiftMotors(Motor liftMotors[]);

		void drive(int speed, Direction dir);
		void stopDriveMotors();

		void setLiftPower(int power);
	};
}

#endif /* ROBOT_H_ */
