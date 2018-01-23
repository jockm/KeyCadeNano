/*
 * NanoGameEngine.h
 *
 *  Created on: Jan 13, 2018
 *      Author: jock
 */

#ifndef NANOGAMEENGINE_H_
#	define NANOGAMEENGINE_H_

#	include "mbed.h"
#	include "screen.h"
#	include  "SSD1306.h"

	class NanoGameEngine {
		public:
			virtual ~NanoGameEngine() {};

			virtual void init(uint8_t *prog, uint16_t memSize, Screen *screen) = 0;
			virtual bool runOne(uint8_t keyPressed) = 0;
			virtual void intervalCallback(void) {};
	};

#endif /* NANOGAMEENGINE_H_ */
