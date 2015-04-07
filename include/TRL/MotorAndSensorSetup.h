/*
 * MotorAndSensorSetup.h
 *
 *  Created on: Apr 5, 2015
 *      Author: guywenck
 */

#ifndef MOTORANDSENSORSETUP_H_
#define MOTORANDSENSORSETUP_H_

#include "MotorRegistry.h"
#include "SensorRegistry.h"

#include "Motor.h"

#include "Sensor.h"
#include "GenericEncoder.h"
#include "QuadratureEncoder.h"
#include "LimitSwitch.h"
#include "Bumper.h"
#include "Potentiometer.h"
#include "LightSensor.h"
#include "LineSensor.h"
#include "Accelerometer.h"
#include "Gyroscope.h"

namespace TRL {

	class MotorList {
	public:
		MotorList();
		virtual ~MotorList();
		static void initialize();

		//These are just generic names for the template
		//You are encouraged to rename them using eclipse's
		//refactor->rename feature in the right click menu
		static Motor* motor_1;
		static Motor* motor_2;
		static Motor* motor_3;
		static Motor* motor_4;
		static Motor* motor_5;
		static Motor* motor_6;
		static Motor* motor_7;
		static Motor* motor_8;
		static Motor* motor_9;
		static Motor* motor_10;
	};

	class SensorList {
	public:
		SensorList();
		virtual ~SensorList();

		static void initialize();

		static Potentiometer* potentiometer;
		static LimitSwitch* limit;
	};

	class RegistryHelper {
	public:
		static void printEntireRegistry();
	};

}

#endif /* MOTORANDSENSORSETUP_H_ */
