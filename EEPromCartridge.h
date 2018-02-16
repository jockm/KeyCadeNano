/*
 * EEPromCartridge.h
 *
 *  Created on: Feb 15, 2018
 *      Author: jock
 */

#ifndef EEPROMCARTRIDGE_H_
#define EEPROMCARTRIDGE_H_

#include <Cartridge.h>

class EEPromCartridge: public Cartridge {
public:
	EEPromCartridge(I2CEEProm *ee)
	{
		this->eeprom = ee;
		this->mem = NULL;
		this->size = 0;
		this->version = 0;
	}


	virtual ~EEPromCartridge()
	{
		// Nothing
	}

	void setMem(uint8_t *m, uint16_t siz)
	{
		this->mem = m;
		this->size = siz;
	}

	virtual uint16_t getVersion() const {
		return version;
	}


	virtual bool isCartridgePresent();

	virtual uint8_t getGameCount();
	virtual const GameData *getGameAt(uint8_t pos);



private:
	I2CEEProm *eeprom;
	uint8_t   *mem;
	uint16_t   size;
	uint16_t   version;

};

#endif /* EEPROMCARTRIDGE_H_ */
