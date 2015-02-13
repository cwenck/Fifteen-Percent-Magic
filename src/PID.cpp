/*
 * PID.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: guywenck
 */

#include "TRL/PID.h"

namespace TRL {

PID::PID(Sensor* sensor, void (*setMotorSpeedFunction)(int speed)) {
	this->kp = 0;
	this->ki = 0;
	this->kd = 0;

	this->sensor = sensor;
	this->target = 0;
	this->sensorValue = 0;
	this->prevSensorValue = 0;

	this->targetReached = false;
	this->setMotorSpeedFunction = setMotorSpeedFunction;
}

PID::PID(float kp, float ki, float kd, Sensor* sensor,
		void (*setMotorSpeedFunction)(int)) {
	this->kp = kp;
	this->ki = ki;
	this->kd = kd;

	this->sensor = sensor;
	this->target = 0;
	this->sensorValue = 0;
	this->prevSensorValue = 0;

	this->targetReached = false;
	this->setMotorSpeedFunction = setMotorSpeedFunction;
}

PID::~PID() {
	// TODO Auto-generated destructor stub
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

void PID::setTarget(int target) {
	this->target = target;
}

void PID::goToSetTarget() {
//	pid.target_reached = false;
//	while (!pid.target_reached) {
//		pid.last_error = pid.error;
//		pid.sensor_reading = sensorGet(pid.sensor);
//		pid.error = pid.sensor_target - pid.sensor_reading;
//
//		lcdDisplayFormattedCenteredString(uart1, 1, "Err: %.2f\n\r", pid.error);
//
//		if (abs(pid.error) < pid.integral_range) {
//			pid.integral += pid.error;
//		} else {
//			pid.integral = 0;
//		}
//		pid.derivative = pid.error - pid.last_error;
//
//		if (!pid.ignoreIntegralBounds) {
//			if (abs(pid.integral) > pid.integral_max) {
//				if (pid.integral > 0) {
//					pid.integral = pid.integral_max;
//				} else {
//					pid.integral = -pid.integral_max;
//				}
//			} else if (abs(pid.integral) < pid.integral_min) {
//				if (pid.integral > 0) {
//					pid.integral = pid.integral_min;
//				} else {
//					pid.integral = -pid.integral_min;
//				}
//			}
//		}
//
//		if (abs(pid.error) <= abs(pid.error_tolerance)) {
//			pid.integral = 0;
//			pid.num_checks_passed++;
//			if (pid.num_checks_passed > 3) {
//				pid.target_reached = true;
//			}
//		} else {
//			pid.num_checks_passed = 0;
//			pid.target_reached = false;
//		}
//		printf("Err: %.2f -- ISpd: %d -- I: %.2f\n\r", pid.error, pid.i_speed,
//				pid.integral);
//		pid.p_speed = pid.error * pid.kp;
//		pid.i_speed = pid.integral * pid.ki;
//		pid.d_speed = pid.derivative * pid.kd;
//		pid.motor_speed = pid.p_speed + pid.i_speed + pid.d_speed;
//		pid.setMotorSpeedFunction(pid.motor_speed);
//		delay(20);
//	}
//	pid.setMotorSpeedFunction(0);
}

void PID::goToTarget(int target) {
	setTarget(target);
	goToSetTarget();
}

} /* namespace TRL */
