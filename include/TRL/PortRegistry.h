/*
 * PortRegistry.h
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#ifndef PORTREGISTRY_H_
#define PORTREGISTRY_H_

#include "LibraryFixes.h"
#include "Typedefs.h"
#include "EnumeratedTypedefs.h"
#include "PrintStream.h"
#include "Port.h"

namespace TRL {
	class PortRegistry {
	private:
		static SensorType sensors[21];
	public:
		PortRegistry();
		virtual ~PortRegistry();

		static void resetRegistry();
		static void printRegistryEntry(UniversalPort port);
		static void printRegistry();

		static bool deleteRegistryEntry(UniversalPort port);
		static bool deleteRegistryEntry(AnalogPort port);
		static bool deleteRegistryEntry(DigitalPort port);

		static bool registerPort(UniversalPort port, SensorType type);
		static bool registerPort(AnalogPort port, SensorType type);
		static bool registerPort(DigitalPort port, SensorType type);

		static string getStringForSensorType(SensorType type);

		static bool isPortRegistered(UniversalPort port);
		static bool isPortRegistered(AnalogPort port);
		static bool isPortRegistered(DigitalPort port);

	};
}

#endif /* PORTREGISTRY_H_ */
