/*
 * Port.h
 *
 *  Created on: Apr 2, 2015
 *      Author: guywenck
 */

#ifndef PORT_H_
#define PORT_H_

#include "Constants.h"
#include "LibraryFixes.h"
#include "Typedefs.h"
#include "EnumeratedTypedefs.h"
#include "PrintStream.h"

namespace TRL {
	class Port {
	public:
		Port();
		virtual ~Port();

		/*
		 * universal port numbers are as follows
		 * range from 0-26
		 * is the Speaker port,
		 * pins 1-12 are the standard Digital I/O,
		 * 13-20 are the Analog I/O,
		 * 21+22 are UART1,
		 * 23+24 are UART2,
		 * and 25+26 are the I2C port.
		 */

		static UniversalPort getUniversalPortNumber(AnalogPort port);
		static UniversalPort getUniversalPortNumber(DigitalPort port);

		static bool isUniversalPortNumberAnalogType(UniversalPort universalPortNumber);
		static bool isUniversalPortNumberDigitalType(UniversalPort universalPortNumber);

		static short getAnalogPortNumber(AnalogPort port);
		static short getAnalogPortNumber(UniversalPort port);
		static short getDigitalPortNumber(DigitalPort port);
		static short getDigitalPortNumber(UniversalPort port);
	};
}

#endif /* PORT_H_ */
