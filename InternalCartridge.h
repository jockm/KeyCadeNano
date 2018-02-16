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


	virtual uint16_t getVersion() const {
		return 100;
	}

	virtual bool isCartridgePresent() {
		return true;
	}

	virtual uint8_t getGameCount();
	virtual const GameData *getGameAt(uint8_t pos);

};

#endif /* INTERNALCARTRIDGE_H_ */
