/*
 * LCDMenuHandler.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: guywenck
 */

#include "LCD/LCDMenuHandler.h"

namespace TRL {

void LCDMenuHandler::initScreens() {

	//Initialize Screens
	mainAutonScreen = new LCDMainAutonScreen();
	mainBatteryScreen = new LCDMainBatteryScreen();
	mainSensorScreen = new LCDMainSensorScreen();
	mainMotorScreen = new LCDMainMotorScreen();

	//Set the start screen
	currentScreen = mainAutonScreen;

	specificSensorScreens = LCDSpecificSensorScreen::getSpecificSensorScreens(
			mainAutonScreen, false);
	specificBatteryScreens =
			LCDSpecificBatteryScreen::getSpecificBatteryScreens(mainAutonScreen,
					true);
	specificMotorScreens = LCDSpecificMotorScreen::getSpecificMotorScreens(
			mainAutonScreen, true);

	specificAutonScreens = LCDSpecificAutonScreen::getSpecificAutonScreens(
			mainAutonScreen, true);
}

LCDMenuHandler::~LCDMenuHandler() {
//Delete any screens you initialized
	delete mainAutonScreen;
	delete mainBatteryScreen;
	delete mainSensorScreen;
	delete mainMotorScreen;

//delete the arrays of screens
	delete specificSensorScreens;
	delete specificBatteryScreens;
	delete specificMotorScreens;
	delete specificAutonScreens;
}

void LCDMenuHandler::initScreenRelationships(LCD* lcd) {
	this->lcd = lcd;

//Init menu LCD
	mainAutonScreen->setDisplayLCD(lcd);
	mainBatteryScreen->setDisplayLCD(lcd);
	mainSensorScreen->setDisplayLCD(lcd);
	mainMotorScreen->setDisplayLCD(lcd);

	LCDMenuScreen::setScreenArrayLCD(
			(Array<LCDMenuScreen*>*) specificSensorScreens, lcd);

	LCDMenuScreen::setScreenArrayLCD(
			(Array<LCDMenuScreen*>*) specificBatteryScreens, lcd);

	LCDMenuScreen::setScreenArrayLCD(
			(Array<LCDMenuScreen*>*) specificMotorScreens, lcd);

	LCDMenuScreen::setScreenArrayLCD(
			(Array<LCDMenuScreen*>*) specificAutonScreens, lcd);

//Set the relationships between menus
	if (specificAutonScreens->size() == 0) {
		mainAutonScreen->setReferencedScreens(mainAutonScreen,
				mainBatteryScreen, mainAutonScreen, mainSensorScreen);
	} else {
		mainAutonScreen->setReferencedScreens(mainAutonScreen,
				mainBatteryScreen, specificAutonScreens->at(0), mainSensorScreen);
	}

	mainBatteryScreen->setReferencedScreens(mainAutonScreen, mainMotorScreen,
			specificBatteryScreens->at(0), mainAutonScreen);

	if (SensorRegistry::getNumberOfRegisteredSensorsWithoutDuplicates() == 0) {
		mainSensorScreen->setReferencedScreens(mainAutonScreen, mainAutonScreen,
				mainSensorScreen, mainMotorScreen);
	} else {
		mainSensorScreen->setReferencedScreens(mainAutonScreen, mainAutonScreen,
				specificSensorScreens->at(0), mainMotorScreen);
	}

	if (MotorRegistry::getNumberOfRegisteredMotors() == 0) {
		mainMotorScreen->setReferencedScreens(mainAutonScreen, mainSensorScreen,
				mainMotorScreen, mainBatteryScreen);
	} else {
		mainMotorScreen->setReferencedScreens(mainAutonScreen, mainSensorScreen,
				specificMotorScreens->at(0), mainBatteryScreen);
	}
}

//the parameter is a requirement of a function being run in its own task
void LCDMenuHandler::run(void* lcdMenuHandlerInstance) {
	LCDMenuHandler* handler = (LCDMenuHandler*) lcdMenuHandlerInstance;
	handler->lcd->enableBacklight();
	while (handler->running) {
		handler->updateLCDButtonPresses();
		if (handler->currentScreen == NULL) {
			println(ERROR, "LCDMenuHandler", "run",
					"The pointer currentScreen has a null value. Aborting the task.");
			handler->stop();
			break;
		} else {
			handler->currentScreen->display();
		}

		if (handler->wasShortLeftJustReleased) {
			handler->currentScreen = handler->currentScreen
					->onShortLeftButtonPress();
			handler->updateLCDButtonPresses();
		} else if (handler->wasShortCenterJustReleased) {
			handler->currentScreen = handler->currentScreen
					->onShortCenterButtonPress();
			handler->updateLCDButtonPresses();
		} else if (handler->wasShortRightJustReleased) {
			handler->currentScreen = handler->currentScreen
					->onShortRightButtonPress();
			handler->updateLCDButtonPresses();
		} else if (handler->wasLeftJustNowLongPressed) {
			handler->currentScreen = handler->currentScreen
					->onLongLeftButtonPress();
			handler->updateLCDButtonPresses();
		} else if (handler->wasCenterJustNowLongPressed) {
			handler->currentScreen = handler->currentScreen
					->onLongCenterButtonPress();
			handler->updateLCDButtonPresses();
		} else if (handler->wasRightJustNowLongPressed) {
			handler->currentScreen = handler->currentScreen
					->onLongRightButtonPress();
			handler->updateLCDButtonPresses();
		}
		delay(20);
	}
}

void LCDMenuHandler::start(LCD* lcd) {
	initScreenRelationships(lcd);
	if (running) {
		return;
	}
	running = true;
	taskHandle = taskCreate(run, TASK_DEFAULT_STACK_SIZE, this,
			TASK_PRIORITY_DEFAULT + 1);
}

void LCDMenuHandler::stop() {
	if (!running) {
		return;
	}
	running = false;
	taskDelete(taskHandle);
}

void LCDMenuHandler::updateLCDButtonPresses() {
	wasLeftPressed = isLeftPressed;
	wasCenterPressed = isCenterPressed;
	wasRightPressed = isRightPressed;

	wasLeftLongPressed = isLeftLongPressed;
	wasCenterLongPressed = isCenterLongPressed;
	wasRightLongPressed = isRightLongPressed;

	isLeftPressed = lcd->isOnlyLeftButtonPressed();
	isCenterPressed = lcd->isOnlyCenterButtonPressed();
	isRightPressed = lcd->isOnlyRightButtonPressed();

	wasShortLeftJustReleased = false;
	wasShortCenterJustReleased = false;
	wasShortRightJustReleased = false;

	wasLongLeftJustReleased = false;
	wasLongCenterJustReleased = false;
	wasLongRightJustReleased = false;

	wasLeftJustNowLongPressed = false;
	wasCenterJustNowLongPressed = false;
	wasRightJustNowLongPressed = false;

//Start a timer if a button has just been pressed
	if (!wasLeftPressed && isLeftPressed) {
		leftPressedAt = millis();
	} else if (wasLeftPressed && !isLeftPressed) {
		leftPressedAt = 0;
		if (isLeftLongPressed) {
			wasLongLeftJustReleased = true;
		} else {
			wasShortLeftJustReleased = true;
		}
	}

	if (!wasCenterPressed && isCenterPressed) {
		centerPressedAt = millis();
	} else if (wasCenterPressed && !isCenterPressed) {
		centerPressedAt = 0;
		if (isCenterLongPressed) {
			wasLongCenterJustReleased = true;
		} else {
			wasShortCenterJustReleased = true;
		}
	}

	if (!wasRightPressed && isRightPressed) {
		rightPressedAt = millis();
	} else if (wasRightPressed && !isRightPressed) {
		rightPressedAt = 0;
		if (isRightLongPressed) {
			wasLongRightJustReleased = true;
		} else {
			wasShortRightJustReleased = true;
		}
	}

//Dettermine if a long press has been initiated
	if (leftPressedAt != 0) {
		if ((millis() - leftPressedAt) >= LCD_LONG_PRESS_TIME_MILLIS) {
			isLeftLongPressed = true;
		}
	} else {
		isLeftLongPressed = false;
	}

	if (centerPressedAt != 0) {
		if ((millis() - centerPressedAt) >= LCD_LONG_PRESS_TIME_MILLIS) {
			isCenterLongPressed = true;
		}
	} else {
		isCenterLongPressed = false;
	}

	if (rightPressedAt != 0) {
		if ((millis() - rightPressedAt) >= LCD_LONG_PRESS_TIME_MILLIS) {
			isRightLongPressed = true;
		}
	} else {
		isRightLongPressed = false;
	}

//Long Presses Handling
	if (!wasLeftLongPressed && isLeftLongPressed) {
		wasLeftJustNowLongPressed = true;
	}

	if (!wasCenterLongPressed && isCenterLongPressed) {
		wasCenterJustNowLongPressed = true;
	}

	if (!wasRightLongPressed && isRightLongPressed) {
		wasRightJustNowLongPressed = true;
	}
}

LCDMenuHandler::LCDMenuHandler() {
	taskHandle = NULL;
	running = NULL;
	lcd = NULL;

	wasLeftPressed = false;
	isLeftPressed = false;
	wasLeftLongPressed = false;
	isLeftLongPressed = false;
	wasLeftJustNowLongPressed = false;
	wasShortLeftJustReleased = false;
	wasLongLeftJustReleased = false;
	leftPressedAt = 0;

	wasCenterPressed = false;
	isCenterPressed = false;
	wasCenterLongPressed = false;
	isCenterLongPressed = false;
	wasCenterJustNowLongPressed = false;
	wasShortCenterJustReleased = false;
	wasLongCenterJustReleased = false;
	centerPressedAt = 0;

	wasRightPressed = false;
	isRightPressed = false;
	wasRightLongPressed = false;
	isRightLongPressed = false;
	wasRightJustNowLongPressed = false;
	wasShortRightJustReleased = false;
	wasLongRightJustReleased = false;
	rightPressedAt = 0;

	initScreens();
}

} /* namespace TRL */
