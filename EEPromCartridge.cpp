/*
 * EEPromCartridge.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: jock
 */

#include <EEPromCartridge.h>

enum {
	MAX_GAMES = 32
};

bool EEPromCartridge::isCartridgePresent()
{
	bool    ret = false;
	uint8_t buf[16];

	int bytesRead = this->eeprom->read(0, buf, sizeof(buf));

	if(bytesRead != sizeof(buf)) {
		return ret;
	}

	ret =  buf[0] == 'K';
	ret = ret && buf[1] == 'C';
	ret = ret && buf[2] == 'N';

	this->version = (buf[3] << 8) | (buf[4]);
	this->iVersion = (buf[5] << 8) | (buf[6]);
	this->gameCount = buf[7];

	if(this->gameCount > MAX_GAMES) {
		this->gameCount = MAX_GAMES;
	}

	return  ret;
}

const GameData *EEPromCartridge::getGameAt(uint8_t pos)
{
	GameData *ret = (GameData *)(this->mem + (pos * sizeof(GameData)));

	return ret;

}


void EEPromCartridge::loadGameData(uint8_t *memoryPool, uint16_t memSize)
{
	this->mem = memoryPool;

	uint8_t  buf[64];
	uint8_t *stringTop = mem + (sizeof(GameData) * MAX_GAMES);
	uint8_t *name;
	uint8_t *kmap;

	// TODO Implement Me
	for(uint16_t i = 0; i < this->gameCount; ++i) {
		uint16_t eAddr = 0x100 + i * sizeof(buf);
		GameData *gd = (GameData *) (mem + i * sizeof(GameData));

		int bytesRead = this->eeprom->read(eAddr, buf, sizeof(buf));

		name = stringTop;
		memcpy(name, &buf[6], 21);
		stringTop += 21;

		kmap = stringTop;
		memcpy(kmap, &buf[27], 7);
		stringTop += 7;


		gd->type                  = (GameType) buf[0];
		gd->instructionsPerSecond = (buf[1] << 8) | buf[2];
		gd->framesPerSecond       = buf[3];
		gd->flags                 = (buf[4] << 8) | buf[5];
		gd->name                  = (const char *) name;
		gd->keyMap                = (const char *) kmap;
		gd->instuctions           = NULL;
		gd->codeStart             = (buf[38] << 8) | buf[39];
		gd->data                  = (uint8_t *) ((buf[40] << 24) | (buf[41] << 16) | (buf[42] << 8) | buf[43]);
		gd->size                  = (buf[44] << 8) | buf[45];
	}
}


void EEPromCartridge::loadGame(uint8_t gameIdx, uint8_t *mem, uint16_t loadOffset, uint16_t memSize)
{
	const GameData *gd = this->getGameAt(gameIdx);

	// Because we may be about to overwrite where game data is stored,
	// we make a copy of the information we need
	uint16_t eAddr = (uint16_t) ((uint32_t) gd->data & 0xFFFF);
	uint16_t eSize = gd->size;

	memset(mem, 0, memSize);
	this->eeprom->read(eAddr, mem + loadOffset, eSize);
}


