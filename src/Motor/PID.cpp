/*
 * PID.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: guywenck
 */

#include "Motor/PID.h"

namespace TRL {

PID::PID() {
	this->kp = 0;
	this->ki = 0;
	this->kd = 0;

	this->pSpeed = 0;
	this->iSpeed = 0;
	this->dSpeed = 0;

	this->integral = 0;
	this->derivative = 0;

	this->integralSpeedThreshold = 127;
	this->shouldIgnoreIntegralBounds = true;
	this->integralMin = 0;
	this->integralMax = 127;

	this->sensor = NULL;
	this->target = 0;
	this->sensorValue = 0;
	this->prevError = 0;

	this->error = 0;
	this->checksPassed = 0;
	this->requiredPassedChecks = 3;
	this->errorTolerance = 10;

	this->targetReached = false;
	this->setMotorSpeedFunction = NULL;
	this->motorSpeed = 0;
}

PID::PID(Sensor* sensor, void (*setMotorSpeedFunction)(int speed)) {
	this->kp = 1;
	this->ki = 0;
	this->kd = 0;

	this->pSpeed = 0;
	this->iSpeed = 0;
	this->dSpeed = 0;

	this->integral = 0;
	this->derivative = 0;

	this->integralSpeedThreshold = 127;
	this->shouldIgnoreIntegralBounds = true;
	this->integralMin = 0;
	this->integralMax = 127;

	this->sensor = sensor;
	this->target = 0;
	this->sensorValue = 0;
	this->prevError = 0;

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

	this->integralSpeedThreshold = 127;
	this->shouldIgnoreIntegralBounds = true;
	this->integralMin = 0;
	this->integralMax = 127;

	this->sensor = sensor;
	this->target = 0;
	this->sensorValue = 0;
	this->prevError = 0;

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

void PID::setIntegralBounds(int maxMagnitude) {
	shouldIgnoreIntegralBounds = false;
	maxMagnitude = abs(maxMagnitude);
	integralMax = maxMagnitude;
	integralMin = -maxMagnitude;
}

void PID::disableIntegralBounds() {
	shouldIgnoreIntegralBounds = true;
}

void PID::setIntegralPositionSpeedThroshold(int threshold) {
	threshold = abs(threshold);
	if (threshold > 127) {
		threshold = 127;
	}
	this->integralSpeedThreshold = threshold;
}

void PID::setErrorTolerance(int errorTolerance) {
	this->errorTolerance = errorTolerance;
}

void PID::setChecksRequiredToBreakPID(int numberOfChecks) {
	this->requiredPassedChecks = numberOfChecks;
}

void PID::setTarget(int target) {
	this->target = target;
}

void PID::goToSetTarget() {
	targetReached = false;
	while (!targetReached) {
		sensorValue = sensor->getValue();
		prevError = error;
		error = target - sensorValue;
		integral += error;
		derivative = (error - prevError);

		if (abs(pSpeed) >= 127) {
			integral = 0;
			pSpeed = 127 * (pSpeed / pSpeed); //keep the magnitude of p at a max of 127
		}

		if (abs(dSpeed) >= 256) {
			dSpeed = 256 * (dSpeed / dSpeed); //keep the magnitude of p at a max of 127
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
		println(DEBUG, "PID", "goToSetTarget",
				"Err: %d :: Sensor: %d :: Speed: %d :: pSpeed: %d :: iSpeed : %d :: dSpeed: %d",
				error, sensorValue, motorSpeed, pSpeed, iSpeed, dSpeed);
		delay(20);

	}
	setMotorSpeedFunction(0);
}

void PID::goToTarget(int target) {
	setTarget(target);
	goToSetTarget();
}

} /* namespace TRL */
