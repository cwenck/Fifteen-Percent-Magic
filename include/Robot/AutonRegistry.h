/*
 * AutonomusRoutineRegistry.h
 *
 *  Created on: Apr 8, 2015
 *      Author: guywenck
 */

#ifndef AUTONOMUSROUTINEREGISTRY_H_
#define AUTONOMUSROUTINEREGISTRY_H_

#include "Robot_Includes.h"

namespace TRL {

	class AutonRoutine;

	class AutonRegistry {
	private:
		static VariableArray<AutonRoutine*>* routines;
		static AutonRoutine* robotRoutine;
		static AutonRoutine* activeRoutine;
		static AutonRoutine* runningRoutine;
	public:
		AutonRegistry() {}
		virtual ~AutonRegistry() {}
		static void initStatics();
		static void destroy();
		static void registerRoutine(AutonRoutine* routine);
		static int getNumberOfRoutines();
		static void printRoutines();

		static void runRoutine(AutonRoutine* routine);
		static void runRoutine(AllianceColor color, RobotStartLocation location, AutonIdentifier identifier);
		static AutonRoutine* getRunningRoutine();
		static AutonRoutine* getRoutine(AllianceColor color, RobotStartLocation location, AutonIdentifier identifier);

		static void setActiveRoutine(AutonRoutine* routine);
		static void runActiveRoutine();
		static void clearActiveRoutine();

		static void setRobotRoutine(AutonRoutine* routine);
		static void runRobotRoutine();
		static void saveRobotRoutineToFile();
		static AutonRoutine* readRoutineFromFile();

		static Array<AutonRoutine*>* getRoutines();
		static Array<AutonRoutine*>* getRoutines(AllianceColor color);
		static Array<AutonRoutine*>* getRoutines(RobotStartLocation location);
		static Array<AutonRoutine*>* getRoutines(AllianceColor color, RobotStartLocation location);


	};
}

#endif /* AUTONOMUSROUTINEREGISTRY_H_ */
