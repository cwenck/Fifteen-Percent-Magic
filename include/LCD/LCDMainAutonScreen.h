/*
 * LCDHomeScreen.h
 *
 *  Created on: Apr 6, 2015
 *      Author: guywenck
 */

#ifndef LCDHOMESCREEN_H_
#define LCDHOMESCREEN_H_

#include "../TRL/TRL_BaseIncludes.h"
#include "LCD.h"
#include "LCDMenuScreen.h"

namespace TRL {

	class LCDMainAutonScreen : public LCDMenuScreen {
	public:
		LCDMainAutonScreen();
		virtual ~LCDMainAutonScreen();

		void display(LCD* lcd);
	};
}

#endif /* LCDHOMESCREEN_H_ */
