/*
 * TrueTest.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: cwenck
 */

#include "TrueTest.h"

namespace TRL {
LCDMainAutonScreen* TrueTest::home;
LCDMenuScreen* TrueTest::screen;

//TrueTest TrueTest::instance;

TrueTest::TrueTest() {
//	home = LCDHomeScreen();
//	println("1-Screen: %d Home:%d", screen, &home);
//	screen = &home;
//	println("2-Screen: %d Home:%d", screen, &home);
}

void TrueTest::init() {
	home = new LCDMainAutonScreen();
	//	home = (LCDHomeScreen *) malloc(sizeof(LCDHomeScreen));
//	home = &(LCDHomeScreen());
//	home =  LCDHomeScreen();
	println("1-Screen: %d Home:%d", screen, &home);
	screen = home;
	println("2-Screen: %d Home:%d", screen, &home);
}

TrueTest::~TrueTest() {
	// TODO Auto-generated destructor stub
}

void TrueTest::startTask() {
	taskCreate(TrueTest::taskTest, TASK_DEFAULT_STACK_SIZE, NULL,
			TASK_PRIORITY_DEFAULT);
}
void TrueTest::taskTest(void *nothing) {
	println("3-Screen: %d Home:%d", screen, home);
//	instance = TrueTest();
	init();
	println("4-Screen: %d Home:%d", screen, home);
	screen = home;
	println("5-Screen: %d Home:%d", screen, home);
	//	LCDHomeScreen home = LCDHomeScreen();
//	LCDMenuScreen* screen = &instance.home;
	while (1) {
//		println("running");
		screen->display(&LCD::instance);
		delay(1000);
	}
}
} /* namespace TRL */
