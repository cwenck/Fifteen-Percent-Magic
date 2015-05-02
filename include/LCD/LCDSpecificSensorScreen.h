/*
 * LCDSpecificSensorScreen.h
 *
 *  Created on: Apr 7, 2015
 *      Author: cwenck
 */

#ifndef LCDSPECIFICSENSORSCREEN_H_
#define LCDSPECIFICSENSORSCREEN_H_

#include "LCDChildMenuScreenIncludes.h"
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
		void display();

		static Array<LCDSpecificSensorScreen*>* getSpecificSensorScreens(LCDMenuScreen* homeScreen, bool loopScreens);
	};
}

#endif /* LCDSPECIFICSENSORSCREEN_H_ */
