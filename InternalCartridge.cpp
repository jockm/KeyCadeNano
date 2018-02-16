/*
 * InternalCartridge.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: jock
 */

#include <InternalCartridge.h>
#include "games.h"


uint8_t InternalCartridge::getGameCount() {
	if(games[0].type == GT_EOL) {
		return 0;
	}

	uint8_t ret = 0;

	while(games[ret].type != GT_EOL) {
		++ret;
	}

	return ret;
}


const GameData *InternalCartridge::getGameAt(uint8_t pos)
{
	const GameData * ret = &games[pos];

	return ret;
}
