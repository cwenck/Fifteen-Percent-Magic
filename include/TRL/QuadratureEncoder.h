/*
 * QuadratureEncoder.h
 *
 *  Created on: Feb 4, 2015
 *      Author: cwenck
 */

#ifndef QUADRATUREENCODER_H_
#define QUADRATUREENCODER_H_

#include "TRL_BaseInitialization.h"
#include "SensorRegistry.h"
#include "GenericEncoder.h"

namespace TRL {

	class QuadratureEncoder : public GenericEncoder {
	private:
		DigitalPort top;
		DigitalPort bottom;
		bool inverted;
		PROS_Encoder encoder;
	public:
		QuadratureEncoder(DigitalPort top, DigitalPort bottom);
		QuadratureEncoder(DigitalPort top, DigitalPort bottom, bool inverted);
		virtual ~QuadratureEncoder();

		bool destroy();

		int getValue();
		void resetValue();	//resets the value to 0
		EncoderType getEncoderType();
		SensorType getSensorType();
		string getSensorName();

	};
}

#endif /* QUADRATUREENCODER_H_ */
