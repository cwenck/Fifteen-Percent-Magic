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

	/*
	 * All child classes should implement a constructor that calls generateArray(LCDMenuScreen* homeScreen, bool loopScreens)
	 * with the correct parameters.
	 */

	class LCDScreenArray : public Array<LCDMenuScreen*> {
	protected:

		LCD* lcd;
		LCDMenuScreen* homeScreen;
		bool loopScreens;

		/*
		 * This should fill up the array with instances of subclasses of LCDMenuScreen
		 */
		virtual void initArrayScreens() = 0;

		/*
		 * Repopulates the array with screens. Then, it sets up the relationships between those screens;
		 */
		void setupScreenArray();

	public:
		LCDScreenArray();
		virtual ~LCDScreenArray(){}

		virtual void generateArray(LCDMenuScreen* homeScreen, bool loopScreens);
		void generateArray();
		void setArrayHomeScreen(LCDMenuScreen* homeScreen);
		void setArrayEnterScreen(LCDMenuScreen* enterScreen);
		void setArrayDisplayLCD(LCD* lcd);
		void setArrayDisplayLCD();

		virtual LCDMenuScreen* getArrayStartScreen() = 0;

	};
}

#endif /* LCDSCREENARRAY_H_ */
