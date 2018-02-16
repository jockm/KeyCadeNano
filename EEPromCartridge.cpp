/*
 * EEPromCartridge.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: jock
 */

#include <EEPromCartridge.h>

bool EEPromCartridge::isCartridgePresent()
{
	bool    ret = false;
	uint8_t buf[16];

	int status = this->eeprom->read(0, buf, sizeof(buf));

	if(status) {
		return ret;
	}

	ret |= buf[0] == 'K';
	ret |= buf[1] == 'C';
	ret |= buf[2] == 'N';

	this->version = (buf[3] << 8) | (buf[4]);

	return  ret;
}

uint8_t EEPromCartridge::getGameCount()
{
	//TODO Implement me
	return 0;
}
const GameData *EEPromCartridge::getGameAt(uint8_t pos)
{
	//TODO Implement me
	return NULL;

}
