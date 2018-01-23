/*
 * gamedata.h
 *
 *  Created on: Jan 12, 2018
 *      Author: jock
 */

#ifndef GAMEDATA_H_
#	define GAMEDATA_H_

#	include "mbed.h"

	typedef struct {
		uint8_t        type;
		uint16_t       instructionHz;
		uint16_t       screenUpdateHz;
		const char    *name;
		const char    *keyMap;
		const char    *instuctions;
		const uint8_t *data;
		uint16_t       size;
	} GameData;



#endif /* GAMEDATA_H_ */
