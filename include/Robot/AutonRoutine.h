/*
 * AutonRoutine.h
 *
 *  Created on: Apr 9, 2015
 *      Author: guywenck
 */

#ifndef AUTONROUTINE_H_
#define AUTONROUTINE_H_

//#include "AutonRegistry.h"
#include "Robot_Includes.h"

namespace TRL {

	class AutonRegistry;

	class AutonRoutine {
	private:
		AllianceColor color;
		RobotStartLocation location;
		AutonIdentifier identifier;
		string name;
		VoidFunctionPtr autonFunction;

	public:
		AutonRoutine(AllianceColor color, RobotStartLocation location, AutonIdentifier identifier, string routineName, VoidFunctionPtr autonFunction);
		virtual ~AutonRoutine() {}

		void run();

		AllianceColor getAllianceColor();
		RobotStartLocation getStartLocation();
		string getRoutineName();
		AutonIdentifier getIdentifier();

		bool doesRoutineMatch(AutonRoutine* routine);
		bool doesRoutineMatch(AllianceColor color, RobotStartLocation location, AutonIdentifier identifier);
	};
}
#endif /* AUTONROUTINE_H_ */
