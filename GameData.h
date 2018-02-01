/*
 * gamedata.h
 *
 *  Created on: Jan 12, 2018
 *      Author: jock
 */

#ifndef GAMEDATA_H_
#	define GAMEDATA_H_

#	include "mbed.h"

	enum GameType {
		GT_CHIP8 = 0,
		GT_EOL = 0xFF
	};

	enum GameFlags {
		GF_NONE = 0,
		GF_NOYWRAP = 0b0000000000000000,
	};

	typedef struct {
		uint8_t       type;
		uint16_t       instructionsPerSecond;
		uint16_t       framesPerSecond;
		uint16_t       flags;
		const char    *name;
		const char    *keyMap;
		const char    *instuctions;
		const uint8_t *data;
		uint16_t       size;
	} GameData;



#endif /* GAMEDATA_H_ */
