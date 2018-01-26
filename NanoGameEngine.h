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

#	define NGE_NOKEY 0xFF
#	define NGE_EXIT  0xFE

	class NanoGameEngine {
		public:
			virtual ~NanoGameEngine() {};

			virtual void loadMemory(uint8_t *mem, const uint8_t *prog, uint16_t progSize) {
				memcpy(mem, prog, progSize);
			}

			virtual void init(uint8_t *prog, uint16_t memSize, Screen *screen) = 0;
			virtual bool runOne(uint8_t keyPressed) = 0;
			virtual void intervalCallback(void) {};

			static NanoGameEngine *getGameEngine(uint8_t type)
			{
				// TODO should we move this?
				return NULL;
			}
	};

#endif /* NANOGAMEENGINE_H_ */
