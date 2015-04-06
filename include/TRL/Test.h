/*
 * Test.h
 *
 *  Created on: Apr 5, 2015
 *      Author: cwenck
 */

#ifndef TEST_H_
#define TEST_H_

#include "TRL_BaseInitialization.h"
namespace TRL {
	class Test {
	private:
		string name;
	public:
		Test();
		Test(string name);
		virtual ~Test();
	};
}

#endif /* TEST_H_ */
