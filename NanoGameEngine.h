// Copyright (c) 2018 Jock Murphy. jock@jockmurphy.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

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
