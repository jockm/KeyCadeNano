/*
 * InternalCartridge.h
 *
 *  Created on: Feb 15, 2018
 *      Author: jock
 */

#ifndef INTERNALCARTRIDGE_H_
#define INTERNALCARTRIDGE_H_

#include <Cartridge.h>

class InternalCartridge: public Cartridge {
public:
	InternalCartridge()
	{
		// Nothing
	}

	virtual ~InternalCartridge()
	{
		// Nothing
	}


	virtual uint16_t getVersion() const
	{
		return 100;
	}

	virtual bool isCartridgePresent()
	{
		return true;
	}

	virtual void loadGameData(uint8_t *memoryPool, uint16_t memSize)
	{
		// Nothing
	}


	virtual uint8_t getGameCount();
	virtual const GameData *getGameAt(uint8_t pos);
	virtual void loadGame(uint8_t gameIdx, uint8_t *mem, uint16_t loadOffset, uint16_t memSize);


};

#endif /* INTERNALCARTRIDGE_H_ */
