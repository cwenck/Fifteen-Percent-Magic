/*
 * Test.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: cwenck
 */

#include "TRL/Test.h"

namespace TRL {

Test::Test() {
	this->name = "Basic Test";
	println("Basic Test object constructed with the default name.");
}

Test::Test(string name) {
	this->name = name;
	println("Test object constructed with name %s.", this->name);
}

Test::~Test() {
	println("Test object destroyed with name %s.", this->name);
}

} /* namespace TRL */
