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

			virtual void init(uint8_t *prog, uint16_t memSize, uint16_t startAddr, Screen *screen) = 0;
			virtual bool runOne(uint8_t keyPressed) = 0;

			virtual void intervalCallback(void) {
				if(this->delayCounter > 0) {
					--this->delayCounter;
				}

				if(this->soundCounter > 0) {
					--this->soundCounter;
				}
			};

			volatile uint8_t getDelayCounter() const {
				return delayCounter;
			}

			void setDelayCounter(volatile uint8_t delayCounter) {
				this->delayCounter = delayCounter;
			}

			volatile uint8_t getSoundCounter() const {
				return soundCounter;
			}

			void setSoundCounter(volatile uint8_t soundCounter) {
				this->soundCounter = soundCounter;
			}

		protected:
			Screen *screen;

			volatile uint8_t   delayCounter;
			volatile uint8_t   soundCounter;

	};

#endif /* NANOGAMEENGINE_H_ */
