/*
 * PID.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: guywenck
 */

#include "Motor/PID.h"

namespace TRL {

PID::PID(){
	this->kp = 0;
	this->ki = 0;
	this->kd = 0;

	this->pSpeed = 0;
	this->iSpeed = 0;
	this->dSpeed = 0;

	this->integral = 0;
	this->derivative = 0;

	this->shouldIgnoreIntegralBounds = true;
	this->integralMin = 0;
	this->integralMax = 127;
	this->rangeWhereIntegralComponentIsActive = -1;

	this->sensor = NULL;
	this->target = 0;
	this->sensorValue = 0;
	this->prevSensorValue = 0;

	this->error = 0;
	this->checksPassed = 0;
	this->requiredPassedChecks = 3;
	this->errorTolerance = 10;

	this->targetReached = false;
	this->setMotorSpeedFunction = NULL;
	this->motorSpeed = 0;
}

PID::PID(Sensor* sensor, void (*setMotorSpeedFunction)(int speed)) {
	this->kp = 0;
	this->ki = 0;
	this->kd = 0;

	this->pSpeed = 0;
	this->iSpeed = 0;
	this->dSpeed = 0;

	this->integral = 0;
	this->derivative = 0;

	this->shouldIgnoreIntegralBounds = true;
	this->integralMin = 0;
	this->integralMax = 127;
	this->rangeWhereIntegralComponentIsActive = -1;

	this->sensor = sensor;
	this->target = 0;
	this->sensorValue = 0;
	this->prevSensorValue = 0;

	this->error = 0;
	this->checksPassed = 0;
	this->requiredPassedChecks = 3;
	this->errorTolerance = 10;

	this->targetReached = false;
	this->setMotorSpeedFunction = setMotorSpeedFunction;
	this->motorSpeed = 0;
}

PID::PID(float kp, float ki, float kd, Sensor* sensor,
		void (*setMotorSpeedFunction)(int)) {
	this->kp = kp;
	this->ki = ki;
	this->kd = kd;

	this->pSpeed = 0;
	this->iSpeed = 0;
	this->dSpeed = 0;

	this->integral = 0;
	this->derivative = 0;

	this->shouldIgnoreIntegralBounds = true;
	this->integralMin = 0;
	this->integralMax = 127;
	this->rangeWhereIntegralComponentIsActive = -1;

	this->sensor = sensor;
	this->target = 0;
	this->sensorValue = 0;
	this->prevSensorValue = 0;

	this->error = 0;
	this->checksPassed = 0;
	this->requiredPassedChecks = 3;
	this->errorTolerance = 10;

	this->targetReached = false;
	this->setMotorSpeedFunction = setMotorSpeedFunction;
	this->motorSpeed = 0;
}

PID::~PID() {
}

void PID::setKp(float postionConstant) {
	this->kp = postionConstant;
}

void PID::setKi(float integralConstant) {
	this->ki = integralConstant;
}

void PID::setKd(float derivativeConstant) {
	this->kd = derivativeConstant;
}

void PID::setErrorTolerance(int errorTolerance){
	this->errorTolerance = errorTolerance;
}

void PID::setChecksRequiredToBreakPID(int numberOfChecks){
	this->requiredPassedChecks = numberOfChecks;
}

void PID::setTarget(int target) {
	this->target = target;
}

void PID::goToSetTarget() {
	targetReached = false;
	while (!targetReached) {
		prevSensorValue = error;
		sensorValue = sensor->getValue();
		error = target - sensorValue;

		if (abs(error) < abs(rangeWhereIntegralComponentIsActive)) {
			integral += error;
		}

		if (!shouldIgnoreIntegralBounds) {
			if (abs(integral) > abs(integralMax)) {
				if (integral > 0) {
					integral = integralMax;
				} else if (integral < 0) {
					integral = -integralMax;
				}
			}
			if (abs(integral) < abs(integralMin)) {
				if (integral > 0) {
					integral = integralMin;
				} else if (integral < 0) {
					integral = -integralMin;
				}
			}
		}

		if (abs(error) <= abs(errorTolerance)) {
			integral = 0;
			checksPassed++;
			if (checksPassed > 3) {
				targetReached = true;
			}
		} else {
			checksPassed = 0;
			targetReached = false;
		}
		pSpeed = error * kp;
		iSpeed = integral * ki;
		dSpeed = derivative * kd;
		motorSpeed = pSpeed + iSpeed + dSpeed;
		setMotorSpeedFunction(motorSpeed);
		delay(20);

	}
	setMotorSpeedFunction(0);
}

void PID::goToTarget(int target) {
	setTarget(target);
	goToSetTarget();
}

} /* namespace TRL */
