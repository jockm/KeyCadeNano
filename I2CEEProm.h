/*
 * I2CEEProm.h
 *
 *  Created on: Feb 13, 2018
 *      Author: jock
 */

#ifndef I2CEEPROM_H_
#	define I2CEEPROM_H_

#	include "mbed.h"

	class I2CEEProm {
		public:
			I2CEEProm(I2C *i2cPort, uint8_t addr = 0x50)
			{
				this->i2c = i2cPort;
				this->i2cAddr = addr;
			}

			virtual ~I2CEEProm() {
				// Nothing
			}

			int16_t writeByte(uint16_t addr, uint8_t val);


			int16_t readByte(uint16_t addr);
			uint16_t read(uint16_t addr, uint8_t *buf, uint16_t size);
		private:
			I2C     *i2c;
			uint8_t  i2cAddr;
	};

#endif /* I2CEEPROM_H_ */
