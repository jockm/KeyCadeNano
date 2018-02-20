/*
 * I2CEEProm.cpp
 *
 *  Created on: Feb 13, 2018
 *      Author: jock
 */

#include <I2CEEProm.h>



int16_t I2CEEProm::writeByte(uint16_t addr, uint8_t val)
{
	uint8_t buf[3];

	buf[0] = addr >> 8;
	buf[1] = addr & 0xFF;
	buf[2] = val;

	int stat = this->i2c->write(this->i2cAddr, (const char *)buf, 3);
	wait_ms(6);

	int16_t ret = stat ? -1 : 0;

	return ret;
}

int16_t I2CEEProm::readByte(uint16_t addr)
{
	uint8_t buf[2];

	buf[0] = addr >> 8;
	buf[1] = addr & 0xFF;

	this->i2c->write(this->i2cAddr, (const char *)buf, 2);
	wait_ms(6);

	int stat = this->i2c->read(this->i2cAddr, (char *) buf, 1);
	wait_ms(6);

	int16_t ret = stat ? -1 : buf[0];

	return ret;
}


uint16_t I2CEEProm::read(uint16_t addr, uint8_t *buf, uint16_t size)
{
	uint16_t ret = 0;
	uint8_t  aBuf[2];
	int      stat = 0;
	uint8_t *bufAddr = buf;

	aBuf[0] = addr >> 8;
	aBuf[1] = addr & 0xFF;

	this->i2c->write(this->i2cAddr, (const char *)aBuf, 2);

	static const int16_t chunkSize = 16;

	int16_t chunkCount = size / chunkSize;
	int16_t lastChunkSize = size % chunkSize;

	for(uint16_t i = 0; i < chunkCount; ++i) {
		stat = this->i2c->read(this->i2cAddr, (char *) bufAddr, chunkSize);
		if(stat) {
			break;
		}

		ret += chunkSize;
		bufAddr += chunkSize;
	}

	if(!stat && lastChunkSize > 0) {
		stat = this->i2c->read(this->i2cAddr, (char *) bufAddr, lastChunkSize);
		if(!stat) {
			ret += chunkSize;
		}
	}

	return ret;

}

