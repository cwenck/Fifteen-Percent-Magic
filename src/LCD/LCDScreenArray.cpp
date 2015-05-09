/*
 * LCDScreenArray.cpp
 *
 *  Created on: May 8, 2015
 *      Author: guywenck
 */

#include "LCD/LCDScreenArray.h"

namespace TRL {

LCDScreenArray::LCDScreenArray() {
	this->homeScreen = NULL;
	this->loopScreens = false;
}

void LCDScreenArray::setupScreenArray() {
	populateArrayWithScreens();
	for (int i = 0; i < this->size(); i++) {
		if (loopScreens) {
			if (i == 0) {
				if (this->size() == 1) {
					this->at(0)->setReferencedScreens(homeScreen, this->at(0),
							this->at(0), this->at(0));
				} else {
					this->at(0)->setReferencedScreens(homeScreen,
							this->at(this->size() - 1), this->at(0),
							this->at(1));
				}
			} else if (i == (this->size() - 1)) {
				this->at(i)->setReferencedScreens(homeScreen, this->at(i - 1),
						this->at(i), this->at(0));
			} else {
				this->at(i)->setReferencedScreens(homeScreen, this->at(i - 1),
						this->at(i), this->at(i + 1));
			}
		} else {
			if (i == 0) {
				if (this->size() == 1) {
					this->at(0)->setReferencedScreens(homeScreen, this->at(0),
							this->at(0), this->at(0));
				} else {
					this->at(0)->setReferencedScreens(homeScreen, this->at(0),
							this->at(0), this->at(1));
				}
			} else if (i == (this->size() - 1)) {
				this->at(i)->setReferencedScreens(homeScreen, this->at(i - 1),
						this->at(i), this->at(i));
			} else {
				this->at(i)->setReferencedScreens(homeScreen, this->at(i - 1),
						this->at(i), this->at(i + 1));
			}
		}
	}
}

void LCDScreenArray::generateArray(LCDMenuScreen* homeScreen,
		bool loopScreens) {
	this->homeScreen = homeScreen;
	this->loopScreens = loopScreens;
	setupScreenArray();
}

void LCDScreenArray::setArrayHomeScreen(LCDMenuScreen* homeScreen){
	for(int i = 0; i < this->size(); i++){
		this->at(i)->setHomeScreen(homeScreen);
	}
}

void LCDScreenArray::setArrayDisplayLCD(LCD* lcd) {
	for(int i = 0; i < size(); i++) {
		this->at(i)->setDisplayLCD(lcd);
	}
}
}

