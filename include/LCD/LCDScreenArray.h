/*
 * LCDScreenArray.h
 *
 *  Created on: May 8, 2015
 *      Author: guywenck
 */

#ifndef LCDSCREENARRAY_H_
#define LCDSCREENARRAY_H_

#include "LCDChildMenuScreenIncludes.h"

namespace TRL {

	class LCDScreenArray : public Array<LCDMenuScreen*> {
	protected:

		LCDMenuScreen* homeScreen;
		bool loopScreens;

		/*
		 * This should fill up the array with instances of subclasses of LCDMenuScreen
		 */

		/*
		 * Repopulates the array with screens. Then, it sets up the relationships between those screens;
		 */
		void setupScreenArray();

	public:
		LCDScreenArray();
		LCDScreenArray(LCDMenuScreen* homeScreen, bool loopScreens);
		virtual ~LCDScreenArray(){}

		void generateArray(LCDMenuScreen* homeScreen, bool loopScreens);
		void setArrayHomeScreen(LCDMenuScreen* homeScreen);
		void setArrayDisplayLCD(LCD* lcd);

		virtual void populateArrayWithScreens() = 0;
	};
}

#endif /* LCDSCREENARRAY_H_ */
