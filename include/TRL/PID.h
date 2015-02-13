/*
 * PID.h
 *
 *  Created on: Feb 7, 2015
 *      Author: guywenck
 */

#ifndef PID_H_
#define PID_H_

#include "Sensor.h"

namespace TRL {

	class PID {
	private:
		float kp;
		float ki;
		float kd;

		Sensor* sensor;
		int target;
		int sensorValue;
		int prevSensorValue;

		void (*setMotorSpeedFunction)(int speed); //function pointer with a parameter of int

		bool targetReached;
	public:
		PID(Sensor* sensor, void (*setMotorSpeedFunction)(int speed));
		PID(float kp, float ki, float kd, Sensor* sensor, void (*setMotorSpeedFunction)(int speed));
		virtual ~PID();

		void setKp(float positionConstant);
		void setKi(float integralConstant);
		void setKd(float derivativeConstant);

		void setTarget(int target);
		void goToSetTarget();
		void goToTarget(int target);
	};
}

#endif /* PID_H_ */
