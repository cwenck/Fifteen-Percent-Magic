/*
 * LCDHomeScreen.h
 *
 *  Created on: Apr 6, 2015
 *      Author: guywenck
 */

#ifndef LCDHOMESCREEN_H_
#define LCDHOMESCREEN_H_

#include "LCDChildMenuScreenIncludes.h"

namespace TRL {

	class LCDMainAutonScreen : public LCDMenuScreen {
	public:
		LCDMainAutonScreen();
		virtual ~LCDMainAutonScreen();

		void display();
	};
}

#endif /* LCDHOMESCREEN_H_ */
