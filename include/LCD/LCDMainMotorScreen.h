/*
 * LCDMainMotorScreen.h
 *
 *  Created on: May 1, 2015
 *      Author: guywenck
 */

#ifndef LCDMAINMOTORSCREEN_H_
#define LCDMAINMOTORSCREEN_H_

#include "LCDChildMenuScreenIncludes.h"

namespace TRL {

	class LCDMainMotorScreen : public LCDMenuScreen {
	public:
		LCDMainMotorScreen();
		virtual ~LCDMainMotorScreen();

		void display();
	};
}

#endif /* LCDMAINMOTORSCREEN_H_ */
