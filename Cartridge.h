/*
 * Cartridge.h
 *
 *  Created on: Jan 12, 2018
 *      Author: jock
 */

#ifndef CARTRIDGE_H_
#	define CARTRIDGE_H_

#	include "mbed.h"


	class Cartridge {
		public:
			Cartridge(I2C *i2c);
			virtual ~Cartridge();

			bool load();

		private:
			I2C *i2c;
			uint16_t size;
			uint8_t data[4096];
	};

#endif /* CARTRIDGE_H_ */
