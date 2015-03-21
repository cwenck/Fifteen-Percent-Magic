/*
 * QuadratureEncoder.h
 *
 *  Created on: Feb 4, 2015
 *      Author: cwenck
 */

#ifndef QUADRATUREENCODER_H_
#define QUADRATUREENCODER_H_

#include "main.h"

namespace TRL {

	class QuadratureEncoder : public TRL::GenericEncoder {
	private:
		DigitalPort top;
		DigitalPort bottom;
		bool inverted;
		PROS_Encoder encoder;
	public:
		QuadratureEncoder(DigitalPort top, DigitalPort bottom);
		QuadratureEncoder(DigitalPort top, DigitalPort bottom, bool inverted);
		virtual ~QuadratureEncoder();
		EncoderType getType();
		int getValue();
		void shutdown();
		void resetValue();	//resets the value to 0

	};
}

#endif /* QUADRATUREENCODER_H_ */
