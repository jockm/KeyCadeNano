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
		this->iVersion = 0;
		this->gameCount = 0;
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

	virtual uint8_t getGameCount()
	{
		return this->gameCount;
	}

	virtual const GameData *getGameAt(uint8_t pos);
	virtual void loadGameData(uint8_t *memoryPool, uint16_t memSize);
	virtual void loadGame(uint8_t gameIdx, uint8_t *mem, uint16_t loadOffset, uint16_t memSize);


private:
	I2CEEProm *eeprom;
	uint8_t   *mem;
	uint16_t   size;
	uint16_t   version;
	uint16_t   iVersion;
	uint8_t    gameCount;

};

#endif /* EEPROMCARTRIDGE_H_ */
