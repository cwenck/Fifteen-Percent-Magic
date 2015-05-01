/*
 * LCDSpecificMotorScreen.h
 *
 *  Created on: May 1, 2015
 *      Author: guywenck
 */

#ifndef LCDSPECIFICMOTORSCREEN_H_
#define LCDSPECIFICMOTORSCREEN_H_

#include "LCDChildMenuScreenIncludes.h"
#include "../Motor/Motor.h"
#include "../Motor/MotorRegistry.h"

namespace TRL {
	class LCDSpecificMotorScreen : public LCDMenuScreen {
	private:
		Motor* motor;
	public:
		LCDSpecificMotorScreen();
		LCDSpecificMotorScreen(Motor* motor);
		virtual ~LCDSpecificMotorScreen();

		void display();

		void setMotor(Motor* motor);

		static Array<LCDSpecificMotorScreen*>* getSpecificMotorScreens(LCDMenuScreen* homeScreen, bool loopScreens);
	};
}

#endif /* LCDSPECIFICMOTORSCREEN_H_ */
