/*
 * LCDSpecificSensorScreen.h
 *
 *  Created on: Apr 7, 2015
 *      Author: cwenck
 */

#ifndef LCDSPECIFICSENSORSCREEN_H_
#define LCDSPECIFICSENSORSCREEN_H_

#include "../TRL/TRL_BaseIncludes.h"
#include "LCD.h"
#include "LCDMenuScreen.h"
#include "../Sensors/Sensor_Includes.h"

namespace TRL {
	class LCDSpecificSensorScreen : public LCDMenuScreen {
	private:
		Sensor* sensor;
	public:
		LCDSpecificSensorScreen();
		LCDSpecificSensorScreen(Sensor* sensor);
		virtual ~LCDSpecificSensorScreen();

		void setSensor(Sensor* sensor);
		void display(LCD* lcd);

		static LCDSpecificSensorScreen** getSpecificSensorScreens(LCDMenuScreen* homeScreen, bool loopScreens);
	};
}

#endif /* LCDSPECIFICSENSORSCREEN_H_ */
