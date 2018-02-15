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

#ifndef CARTRIDGE_H_
#	define CARTRIDGE_H_

#	include "mbed.h"
#	include "GameData.h"
#	include "I2CEEProm.h"


	class Cartridge {
		public:
			Cartridge(I2CEEProm *ee)
			{
				this->eeprom = ee;
				this->mem = NULL;
				this->size = 0;
			}


			virtual ~Cartridge()
			{
				// Nothing
			}

			void setMem(uint8_t *m, uint16_t siz)
			{
				this->mem = m;
				this->size = siz;
			}

			uint16_t getVersion() const {
				return version;
			}


			bool isCartridgePresent();

		private:
			I2CEEProm *eeprom;
			uint8_t   *mem;
			uint16_t   size;
			uint16_t   version;
	};

#endif /* CARTRIDGE_H_ */
