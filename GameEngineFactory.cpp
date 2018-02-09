/*
 * GameEngineFactory.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: jock
 */

#include "GameEngineFactory.h"

#include "GameEngines/Chip8/Chip8.h"
#include "GameEngines/EmbedVM/EmbedVMEngine.h"
#include "GameEngines/UBasic/UBasicGameEngine.h"

GameEngineFactory::GameEngineFactory() {
	// Nothing

}

GameEngineFactory::~GameEngineFactory() {
	// Nothing
}


NanoGameEngine *GameEngineFactory::getEngine(GameType type)
{
	NanoGameEngine *ret = NULL;

	switch(type) {
		case GT_CHIP8:
			ret = (NanoGameEngine *)new Chip8();
			break;

		case GT_EMBEDVM:
			ret = (NanoGameEngine *)new EmbedVMEngine();
			break;

		case GT_UBASIC:
			ret = (NanoGameEngine *)new UBasicGameEngine();
			break;

		default:
			break;
	}

	return ret;
}
