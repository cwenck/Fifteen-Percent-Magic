/*
 * AutonomusRoutineRegistry.h
 *
 *  Created on: Apr 8, 2015
 *      Author: guywenck
 */

#ifndef AUTONOMUSROUTINEREGISTRY_H_
#define AUTONOMUSROUTINEREGISTRY_H_

//#include "../TRL/TRL_BaseIncludes.h"
//#include "AutonRoutine.h"
#include "Robot_Includes.h"

namespace TRL {

	class AutonRoutine;

	class AutonRegistry {
	private:
		static VariableArray<AutonRoutine*>* routines;
		static AutonRoutine* activeRoutine;
	public:
		AutonRegistry(){}
		virtual ~AutonRegistry(){}
		static void initStatics();
		static void destroy();
		static void registerRoutine(AutonRoutine* routine);
		static int getNumberOfRoutines();
		static void printRoutines();

		static void runRoutine(AllianceColor color, RobotStartLocation location, AutonIdentifier identifier);
		static AutonRoutine* getRoutine(AllianceColor color, RobotStartLocation location, AutonIdentifier identifier);

		static void setActiveRoutine(AutonRoutine* routine);
		static void runActiveRoutine();
		static void clearActiveRoutine();

	};
}

#endif /* AUTONOMUSROUTINEREGISTRY_H_ */
