/*
 * Potentiometer.h
 *
 *  Created on: Apr 2, 2015
 *      Author: guywenck
 */

#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

#define MAX_POTENTIOMETER_READING 4095

#include "../TRL/TRL_BaseIncludes.h"
#include "AnalogSensor.h"

namespace TRL {

	class Potentiometer: public AnalogSensor {
	private:
		//This is set to -1 to disable reading from different positions
		short numSelections;

	public:
		Potentiometer();
		Potentiometer(AnalogPort port);
		virtual ~Potentiometer();

		void disablePotentiometerSelections();
		bool arePotentiometerSelectionsEnabled();
		bool arePotentiometerSelectionsDisabled();

		//returns -1 if selections are disable or something goes wrong
		//returns a selection number (range from 1 to numSlections)
		short getCurrentPotentiometerSelection();

		//selection number ranges from 1 to numSlections
		//1 starts at the part of the potentiometer that returns 0
		//the highest one is at the part of the potentiometer that returns MAX_POTENTIOMETER_READING
		bool isSelectionActive(int selectionNumber);
		bool isSelectionInactive(int selectionNumber);

		SensorType getSensorType();
		string getSensorName();
	};
}

#endif /* POTENTIOMETER_H_ */
