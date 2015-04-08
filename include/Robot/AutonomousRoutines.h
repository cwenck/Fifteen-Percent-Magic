/*
 * AutonomusRoutines.h
 *
 *  Created on: Mar 17, 2015
 *      Author: cwenck
 */

#ifndef AUTONOMUSROUTINES_H_
#define AUTONOMUSROUTINES_H_

//#include "main.h"
#include "Robot_Includes.h"

namespace TRL {
	//Position ONE is the AUTO_LOADER
	//Position TWO is the POLE

	class AutonomousRoutines {
	private:
		void runRedAutonomusPositionOne(short rountineNumber);
		void runBlueAutonomusPositionOne(short rountineNumber);

		void runRedAutonomusPositionTwo(short rountineNumber);
		void runBlueAutonomusPositionTwo(short rountineNumber);

	public:
		//Destructor
		virtual ~AutonomousRoutines();
		AutonomousRoutines();
		static void initStatics();

		static AutonomousRoutines instance;

		void runAutonomusRountine(AllianceColor color, RobotStartLocation startLocation, short rountineNumber);
		void runRedAutonomus(RobotStartLocation startLocation, short routineNumber);
		void runBlueAutonomus(RobotStartLocation startLocation, short routineNumber);

	};
}

#endif /* AUTONOMUSROUTINES_H_ */
