/*
 * LCDSelectionScreen.h
 *
 *  Created on: May 7, 2015
 *      Author: guywenck
 */

#ifndef LCDSELECTIONSCREEN_H_
#define LCDSELECTIONSCREEN_H_

#include "LCDChildMenuScreenIncludes.h"

namespace TRL {
	template <typename T> class LCDSelectionScreen : public LCDMenuScreen {
	protected:
		T selectionReturnValue;
		string selectionDisplayName;
	public:
		LCDSelectionScreen() {
			this->selectionReturnValue = *((T*) NULL);
			this->selectionDisplayName = "";
		}

		LCDSelectionScreen(T selectionReturnValue, string selectionDisplayName) {
			this->selectionReturnValue = selectionReturnValue;
			this->selectionDisplayName = selectionDisplayName;
		}

		LCDSelectionScreen(T selectionReturnValue) {
			this->selectionReturnValue = selectionReturnValue;
			this->selectionDisplayName = "";
		}

		void setSelectionDisplayName(string displayName){
			selectionDisplayName = displayName;
		}

		virtual ~LCDSelectionScreen() {}

		void display(){
			lcd->displayCenteredString(1, selectionDisplayName);
			lcd->displayDownNavigation(2, "Select");
		}

		virtual LCDMenuScreen* onShortCenterButtonPress() = 0;

	};
}

#endif /* LCDSELECTIONSCREEN_H_ */
