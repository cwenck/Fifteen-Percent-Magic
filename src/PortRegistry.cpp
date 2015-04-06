/*
 * PortRegistry.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: cwenck
 */

#include "TRL/PortRegistry.h"

namespace TRL {

SensorType PortRegistry::sensors[21];

PortRegistry::PortRegistry() {

}

PortRegistry::~PortRegistry() {

}

bool PortRegistry::registerPort(UniversalPort port, SensorType type) {
	if (port <= 20) {
		if (sensors[port] == NullSensorType) {
			sensors[port] = type;
			return true;
		}
	}
	println(ERROR, "PortRegistry", "registerPort", "Failed to register port.");
	println(ERROR, "PortRegistry", "registerPort", "Port already taken.");
	return false;
}

bool PortRegistry::registerPort(AnalogPort port, SensorType type) {
	return registerPort(Port::getUniversalPortNumber(port), type);
}

bool PortRegistry::registerPort(DigitalPort port, SensorType type) {
	return registerPort(Port::getUniversalPortNumber(port), type);
}

bool PortRegistry::deleteRegistryEntry(UniversalPort port) {
	if (port <= 20) {
		if (sensors[port] == NullSensorType) {
			println(WARNING, "PortRegistry", "deleteRegistryEntry",
					"Port %d was never registered.", port);
			return false;
		}
		sensors[port] = NullSensorType;
		return true;
	}
	return false;
}

bool PortRegistry::deleteRegistryEntry(AnalogPort port) {
	return deleteRegistryEntry(Port::getUniversalPortNumber(port));
}

bool PortRegistry::deleteRegistryEntry(DigitalPort port) {
	return deleteRegistryEntry(Port::getUniversalPortNumber(port));
}

void PortRegistry::resetRegistry() {
	for (int i = 0; i < 21; i++) {
		sensors[i] = NullSensorType;
	}
}

string PortRegistry::getStringForSensorType(SensorType type) {
	switch (type) {
	case SonarSensorType:
		return "Sonar";
	case QuadratureEncoderSensorType:
		return "Quadrature Encoder";
	case PotentiometerSensorType:
		return "Potentiometer";
	case LightSensorType:
		return "Light Sensor";
	case LineSensorType:
		return "Line Sensor";
	case DigitalSwitchSensorType:
		return "Switch";
	default:
		println(ERROR, "PortRegistry", "getStringForSensorType",
				"This should never get called.");
		return "";
	}
}

void PortRegistry::printRegistryEntry(UniversalPort port) {
	if (port <= 20) {
		if (port == 0) {
			print("Speaker: ");
		} else if (port >= 1 && port <= 12) {
			printf("Digital_%d: ", Port::getDigitalPortFromUniversalPort(port));
		} else if (port >= 13 && port <= 20) {
			printf("Analog_%d: ", Port::getAnalogPortFromUniversalPort(port));
		}
		if (sensors[port] == NullSensorType) {
			println("Not Registered");
		} else {
			println(getStringForSensorType(sensors[port]));
		}
	}
}

void PortRegistry::printPortRegistry() {
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

bool PortRegistry::isPortRegistered(UniversalPort port) {
	return !(sensors[port] == NullSensorType);
}

bool PortRegistry::isPortRegistered(AnalogPort port) {
	return isPortRegistered(Port::getUniversalPortNumber(port));
}

bool PortRegistry::isPortRegistered(DigitalPort port) {
	return isPortRegistered(Port::getUniversalPortNumber(port));
}

} /* namespace TRL */
