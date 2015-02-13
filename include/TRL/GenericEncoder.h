/*
 * Encoder.h
 *
 *  Created on: Jan 30, 2015
 *      Author: guywenck
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include "Sensor.h"

namespace TRL {

	typedef enum _EncoderType {
		QUAD_ENCODER_TYPE = 0,
		INTEGRATED_ENCODER_TYPE = 1
	}EncoderType;

	typedef enum _IntegratedEncoderPort {
		Integrated_1,
		Integrated_2,
		Integrated_3,
		Integrated_4,
		Integrated_5,
		Integrated_6,
		Integrated_7,
		Integrated_8
	} IntegratedEncoderPort;

	class GenericEncoder : public TRL::Sensor{

	public:
		GenericEncoder();
		virtual ~GenericEncoder();
		virtual int getValue() = 0;
		virtual EncoderType getType() = 0;

	};
};
#endif /* ENCODER_H_ */
