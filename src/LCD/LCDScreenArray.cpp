/*
 * LCDScreenArray.cpp
 *
 *  Created on: May 8, 2015
 *      Author: guywenck
 */

#include "LCD/LCDScreenArray.h"

namespace TRL {

LCDScreenArray::LCDScreenArray() {
	this->lcd = NULL;
	this->homeScreen = NULL;
	this->loopScreens = false;
}

void LCDScreenArray::setupScreenArray() {
	initArrayScreens();
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
	setArrayDisplayLCD();
}

void LCDScreenArray::generateArray(LCDMenuScreen* homeScreen,
		bool loopScreens) {
	this->homeScreen = homeScreen;
	this->loopScreens = loopScreens;
	setupScreenArray();
}

/*
 * Only works if homeScreen and loopScreens have already been set.
 */
void LCDScreenArray::generateArray(){
	if(homeScreen == NULL){
		println(ERROR, "LCDScreenArray", "generateArray", "The homeScreen for the array was not set.");
	}
	generateArray(homeScreen, loopScreens);
}

void LCDScreenArray::setArrayHomeScreen(LCDMenuScreen* homeScreen){
	for(int i = 0; i < this->size(); i++){
		this->at(i)->setHomeScreen(homeScreen);
	}
}

void LCDScreenArray::setArrayEnterScreen(LCDMenuScreen* enterScreen){
	for(int i = 0; i < this->size(); i++){
		this->at(i)->setEnterScreen(enterScreen);
	}
}

void LCDScreenArray::setArrayDisplayLCD(LCD* lcd) {
	this->lcd = lcd;
	for(int i = 0; i < size(); i++) {
		this->at(i)->setDisplayLCD(lcd);
	}
}

void LCDScreenArray::setArrayDisplayLCD() {
	for(int i = 0; i < size(); i++) {
		this->at(i)->setDisplayLCD(lcd);
	}
}
}

