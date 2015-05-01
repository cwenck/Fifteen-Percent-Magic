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
#include "Util.h"

namespace TRL {
	class Port {
	public:
		Port();
		virtual ~Port();

		/*
		 * universal port numbers are as follows
		 * range from -10 to 26
		 * -1 through -10 are IME port
		 * -1 is the first IME in the chain and they decrease by one per encoder
		 * is the Speaker port,
		 * pins 1-12 are the standard Digital I/O,
		 * 13-20 are the Analog I/O,
		 * 21+22 are UART1,
		 * 23+24 are UART2,
		 * and 25+26 are the I2C port.
		 */

		static UniversalPort getUniversalPortNumber(AnalogPort port);
		static UniversalPort getUniversalPortNumber(DigitalPort port);
		static UniversalPort getUniversalPortNumber(IntegratedEncoderPort port);

		static AnalogPort getAnalogPortFromUniversalPort(UniversalPort port);
		static DigitalPort getDigitalPortFromUniversalPort(UniversalPort port);
		static IntegratedEncoderPort getIntegratedEncoderPortFromUniversalPort(UniversalPort port);

		static bool isPortAnalogType(UniversalPort port);
		static bool isPortDigitalType(UniversalPort port);
		static bool isPortIntegratedEncoderType(UniversalPort port);

		static short getAnalogPortNumber(AnalogPort port);
		static short getAnalogPortNumber(UniversalPort port);
		static short getDigitalPortNumber(DigitalPort port);
		static short getDigitalPortNumber(UniversalPort port);
		static short getIntegratedEncoderPortNumber(IntegratedEncoderPort port);
		static short getIntegratedEncoderPortNumber(UniversalPort port);

		static PortType getPortType(UniversalPort port);

		static bool isPortInactive(AnalogPort port);
		static bool isPortInactive(DigitalPort port);
		static bool isPortInactive(UniversalPort port);

		static bool isPortActive(AnalogPort port);
		static bool isPortActive(DigitalPort port);
		static bool isPortActive(UniversalPort port);

		static int getAnalogValue(AnalogPort port);
		static int getAnalogValue(UniversalPort port);

		static bool readUniversalPort(UniversalPort port);
		static void configurePort(PortConfig config, UniversalPort port);
		static void configurePort(PortConfig config, DigitalPort port);
		static void configurePort(PortConfig config, AnalogPort port);

		static string getPortName(UniversalPort port);
		static string getShortPortName(UniversalPort port);
	};
}

#endif /* PORT_H_ */
