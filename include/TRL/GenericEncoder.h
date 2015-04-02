/*
 * Encoder.h
 *
 *  Created on: Jan 30, 2015
 *      Author: guywenck
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include "TRL_BaseInitialization.h"
#include "Sensor.h"

namespace TRL {

	class GenericEncoder : public TRL::Sensor{

	public:
		GenericEncoder();
		virtual ~GenericEncoder();
		virtual int getValue() = 0;
		virtual EncoderType getType() = 0;

	};
};
#endif /* ENCODER_H_ */
