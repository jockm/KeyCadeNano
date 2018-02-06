/*
 * GameEngineFactory.h
 *
 *  Created on: Feb 3, 2018
 *      Author: jock
 */

#ifndef GAMEENGINEFACTORY_H_
#	define GAMEENGINEFACTORY_H_

#	include "mbed.h"
#	include "NanoGameEngine.h"
#	include "GameData.h"

	class GameEngineFactory {
		public:
			GameEngineFactory();
			virtual ~GameEngineFactory();

			static NanoGameEngine *getEngine(GameType type);
	};

#	endif /* GAMEENGINEFACTORY_H_ */
