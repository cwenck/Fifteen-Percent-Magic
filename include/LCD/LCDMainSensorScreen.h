/*
 * LCDSensorMainScreen.h
 *
 *  Created on: Apr 7, 2015
 *      Author: cwenck
 */

#ifndef LCDSENSORMAINSCREEN_H_
#define LCDSENSORMAINSCREEN_H_

#include "LCDMenuScreen.h"

namespace TRL {
	class LCDMainSensorScreen : public LCDMenuScreen {
	public:
		LCDMainSensorScreen();
		virtual ~LCDMainSensorScreen();

		void display(LCD* lcd);
	};
}

#endif /* LCDSENSORMAINSCREEN_H_ */
