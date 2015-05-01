/*
 * IntegratedMotorEncoder.h
 *
 *  Created on: Apr 24, 2015
 *      Author: guywenck
 */

#ifndef INTEGRATEDMOTORENCODER_H_
#define INTEGRATEDMOTORENCODER_H_

#include "../TRL/TRL_BaseIncludes.h"
#include "Sensor.h"
#include "GenericEncoder.h"

namespace TRL {

	class IntegratedMotorEncoder : public GenericEncoder {
	private:
		static int numberInitialized;
		IntegratedEncoderPort port;
	public:
		IntegratedMotorEncoder();
		IntegratedMotorEncoder(IntegratedEncoderPort port);
		virtual ~IntegratedMotorEncoder();

		float getRPM(MotorGearing gearing);

		int getValue();
		EncoderType getEncoderType();
		SensorType getSensorType();
		string getSensorName();

		/*
		 * Reinitializes all the encoders. Wipes any previous values.
		 * @return the number of encoders connected and intitialized
		 */
		static int initAllIntegratedEncoders();
	};

}

#endif /* INTEGRATEDMOTORENCODER_H_ */
