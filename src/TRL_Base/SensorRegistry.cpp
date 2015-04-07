/*
 * PortRegistry.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#include "TRL/SensorRegistry.h"

namespace TRL {

Sensor* SensorRegistry::sensors[21];

SensorRegistry::SensorRegistry() {

}

SensorRegistry::~SensorRegistry() {

}

bool SensorRegistry::registerSensor(Sensor* sensor) {
	UniversalPort portOne = sensor->getMainPort();
	UniversalPort portTwo = sensor->getSecondaryPort();

	bool twoPortSensor = sensor->isTwoPortSensor();
	bool portOneOpen = false;
	bool portTwoOpen = false;

	if (portOne <= 20) {
		if (sensors[portOne] == NULL) {
			portOneOpen = true;
		}
		if (!twoPortSensor && portOneOpen) {
			sensors[portOne] = sensor;
			return true;
		} else if (twoPortSensor) {
			if (sensors[portTwo] == NULL) {
				portTwoOpen = true;
			}

			if (portOneOpen && portTwoOpen) {
				sensors[portOne] = sensor;
				sensors[portTwo] = sensor;
				return true;
			}
		}

	}

	println(ERROR, "PortRegistry", "registerPort", "Failed to register port.");
	println(ERROR, "PortRegistry", "registerPort", "Port already taken.");
	return false;
}

//bool SensorRegistry::registerSensor(AnalogPort port, Sensor* sensor) {
//	return registerSensor(Port::getUniversalPortNumber(port), sensor);
//}
//
//bool SensorRegistry::registerSensor(DigitalPort port, Sensor* sensor) {
//	return registerSensor(Port::getUniversalPortNumber(port), sensor);
//}

bool SensorRegistry::deleteRegistryEntry(UniversalPort port) {
	if (port <= 20) {
		if (sensors[port] == NULL) {
			println(WARNING, "PortRegistry", "deleteRegistryEntry",
					"Port %d was never registered.", port);
			return false;
		}
		sensors[port] = NULL;
		return true;
	}
	return false;
}

bool SensorRegistry::deleteRegistryEntry(AnalogPort port) {
	return deleteRegistryEntry(Port::getUniversalPortNumber(port));
}

bool SensorRegistry::deleteRegistryEntry(DigitalPort port) {
	return deleteRegistryEntry(Port::getUniversalPortNumber(port));
}

void SensorRegistry::resetRegistry() {
	for (int i = 0; i < 21; i++) {
		sensors[i] = NULL;
	}
}

void SensorRegistry::printRegistryEntry(UniversalPort port) {
	if (port <= 20) {
//		if (port == 0) {
//			print("Speaker: ");
//		} else if (port >= 1 && port <= 12) {
//			printf("Digital_%d: ", Port::getDigitalPortFromUniversalPort(port));
//		} else if (port >= 13 && port <= 20) {
//			printf("Analog_%d: ", Port::getAnalogPortFromUniversalPort(port));
//		}
		print(Port::getPortName(port));
		print(": ");
		if (sensors[port] == NULL) {
			println("Not Registered");
		} else {
			println(sensors[port]->getSensorName());
		}
	}
}

void SensorRegistry::printSensorRegistry() {
	delay(5);
	println("|------------------------------|");
	delay(5);
	println("|        PORT REGISTRY         |");
	delay(5);
	println("|------------------------------|");
	for (int i = 0; i <= 21; i++) {
		delay(5);
		printRegistryEntry(i);
		delay(5);
	}
	println("================================");
	delay(5);
}

bool SensorRegistry::isSensorRegistered(UniversalPort port) {
	return !(sensors[port] == NULL);
}

bool SensorRegistry::isSensorRegistered(AnalogPort port) {
	return isSensorRegistered(Port::getUniversalPortNumber(port));
}

bool SensorRegistry::isSensorRegistered(DigitalPort port) {
	return isSensorRegistered(Port::getUniversalPortNumber(port));
}

short SensorRegistry::getNumberOfRegisteredSensors() {
	int count = 0;
	for (int i = 0; i < 21; i++) {
		if (sensors[i] != NULL) {
			count++;
		}
	}
	return count;
}

Sensor** SensorRegistry::getRegisteredSensorsArray() {
	Sensor** registeredSensors = new Sensor*[getNumberOfRegisteredSensors()];
	int currentFillingIndex = 0;
	for (int i = 0; i < 21; i++) {
		if (sensors[i] != NULL) {
			registeredSensors[currentFillingIndex] = sensors[i];
			currentFillingIndex++;
		}
	}
	return registeredSensors;
}

} /* namespace TRL */
