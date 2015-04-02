/*
 * CortexFile.h
 *
 *  Created on: Apr 1, 2015
 *      Author: guywenck
 */

#ifndef CORTEXFILE_H_
#define CORTEXFILE_H_

#include "Constants.h"
#include "LibraryFixes.h"
#include "Typedefs.h"
#include "EnumeratedTypedefs.h"
#include "PrintStream.h"

//File write cooldown time in milliseconds
#define FILE_WRITE_COOLDOWN_TIME 10000

namespace TRL {
	class CortexFile {
	private:
		string fileName;
		FileMode fileMode;
		int cooldownTimer;
		int resetTime;
		PROS_File fileHandle;

		void resetCooldownTimer();
		void updateCooldownTimer();
	public:
		CortexFile();
		CortexFile(string fileName);
		virtual ~CortexFile();
		void writeStringToFile(string textToWrite);
		string readFileContents();
		int getFileWriteCooldownMillis();
	};
}

#endif /* CORTEXFILE_H_ */
