/*
 * Motor.h
 *
 *  Created on: Jan 29, 2015
 *      Author: guywenck
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "../TRL/TRL_BaseIncludes.h"
#include "../Sensors/Sensor_Includes.h"
#include "MotorRegistry.h"

#define MOTOR_NAME_NULL "**[NULL]**"

namespace TRL {

	class MotorRegistry;

	class Motor {
	private:
		GenericEncoder* encoder;
		bool reversed;
		int rawPower;
		int power;
		float powerPercent;
		short offset;
		MotorPort port;
		MotorLocation location;
		string motorName;

	public:
		Motor();
		Motor(MotorPort port, MotorLocation location, string motorName);
		Motor(MotorPort port, MotorLocation location, string motorName, short offset);
		Motor(MotorPort port, MotorLocation location, string motorName, bool reversed);
		Motor(MotorPort port, MotorLocation location, string motorName, bool reversed, short offset);
		Motor(MotorPort port, MotorLocation location, string motorName, GenericEncoder* encoder, bool reversed);
		Motor(MotorPort port, MotorLocation location, string motorName, GenericEncoder* encoder, bool reversed, short offset);
		virtual ~Motor();

		bool destroy();

		void setPower(int speed);
		void setAdjustedPower(int speed);
		void setAdjustedPowerPercentage(float percent);
		void stop();
		void reverseDirection();

		//This should only ever be used for testing circumstances
		static void setAllRawPower(int speed);
		static void stopAll();

		MotorPort getPort();
		MotorLocation getLocation();
		MotorLocationSide getLocationSide();
		GenericEncoder* getEncoder();

		int getPower(){return power;}
		int getRawPower(){return rawPower;}
		bool isReversed(){return reversed;}
		short getPowerOffset(){return offset;}

		string getName();

	};
}
#endif /* MOTOR_H_ */
