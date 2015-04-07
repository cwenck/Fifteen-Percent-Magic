/*
 * TrueTest.h
 *
 *  Created on: Apr 7, 2015
 *      Author: cwenck
 */

#ifndef TRUETEST_H_
#define TRUETEST_H_

#include "../include/TRL/TRL_Initialization.h"
namespace TRL {
	class TrueTest {
	public:
		TrueTest();
		virtual ~TrueTest();

//		static TrueTest instance;
		static LCDMainAutonScreen* home;
		static LCDMenuScreen* screen;

		static void taskTest(void *);
		static void init();

		static void startTask();
	};
}

#endif /* TRUETEST_H_ */
