/*
 * Util.h
 *
 *  Created on: Apr 2, 2015
 *      Author: guywenck
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <API.h>
#include <string.h>
#include "Typedefs.h"
#include "EnumeratedTypedefs.h"

namespace TRL {
	float getPrimaryBatteryPower();
	float getBackupBatteryPower();

	string getStringForAllianceColor(AllianceColor color);

	string allocateStringForNumberOfChars(int numChars);
	string strsub(string* storeStr, string str, int startChar);
	string strsub(string* storeStr, string str, int startChar, int endChar);
}

#endif /* UTIL_H_ */
