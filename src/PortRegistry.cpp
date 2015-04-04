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
					"Port was never registered.");
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

string PortRegistry::getStringForSensorType(SensorType type){
	switch(type){
	case SonarSensorType:
		return "Sonar";
	case QuadratureEncoderSensorType:
		return "Quadrature Encoder";
	case PotentiometerSensorType:
		return "Potentiometer";
	case LightSensorType:
		return "Light Sensor";
	case DigitalSwitchSensorType:
		return "Switch";
	default:
		println(ERROR, "PortRegistry", "getStringForSensorType", "This should never get called");
		return "";
	}
}

void PortRegistry::printRegistryEntry(UniversalPort port) {
	if (port <= 20) {
		if (port == 0) {
			print("Speaker: ");
		} else if (port >= 1 && port <= 12){
			print("Digital_%d: ", Port::getDigitalPortFromUniversalPort(port));
		} else if (port >= 13 && port <= 20){
			print("Analog_%d: ", Port::getAnalogPortFromUniversalPort(port));
		}
		if(sensors[port] == NullSensorType){
			println("Not Registed");
		} else {
			println(getStringForSensorType(sensors[port]));
		}
	}
}

void PortRegistry::printRegistry() {
	for(int i = 0; i <= 21; i++){
		printRegistryEntry(i);
	}
}

} /* namespace TRL */
