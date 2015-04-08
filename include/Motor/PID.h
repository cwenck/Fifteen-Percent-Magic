/*
 * PID.h
 *
 *  Created on: Feb 7, 2015
 *      Author: guywenck
 */

#ifndef PID_H_
#define PID_H_

#include "../TRL/TRL_BaseIncludes.h"
#include "../Sensors/Sensor_Includes.h"
#include "Motor.h"


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
		int error;

		int integral;
		int rangeWhereIntegralComponentIsActive;
		bool shouldIgnoreIntegralBounds;
		int integralMax;	//should be positive
		int integralMin;	//should be positive

		int derivative;

		void (*setMotorSpeedFunction)(int speed); //function pointer with a parameter of int

		bool targetReached;
		short checksPassed;
		short requiredPassedChecks;
		int errorTolerance;

		int pSpeed;
		int iSpeed;
		int dSpeed;
		int motorSpeed;
	public:
		PID();
		PID(Sensor* sensor, void (*setMotorSpeedFunction)(int speed));
		PID(float kp, float ki, float kd, Sensor* sensor, void (*setMotorSpeedFunction)(int speed));
		virtual ~PID();

		void setKp(float positionConstant);
		void setKi(float integralConstant);
		void setKd(float derivativeConstant);

		void setErrorTolerance(int errorTolerance);
		void setChecksRequiredToBreakPID(int numberOfChecks);

		void setTarget(int target);
		void goToSetTarget();
		void goToTarget(int target);
	};
}

#endif /* PID_H_ */
