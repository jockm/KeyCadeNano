/*
 * UBasicGameEngine.h
 *
 *  Created on: Feb 7, 2018
 *      Author: jock
 */

#ifndef GAMEENGINES_UBASIC_UBASICGAMEENGINE_H_
#	define GAMEENGINES_UBASIC_UBASICGAMEENGINE_H_

#	include <NanoGameEngine.h>
#	include "ubasic/ubasic.h"


	class UBasicGameEngine: public NanoGameEngine {
		public:
			UBasicGameEngine()
			{
				this->running = false;
				this->currentKey = NGE_NOKEY;
				this->mem = NULL;
				this->memSize = 0;
			}


			virtual ~UBasicGameEngine()
			{
				// Nothing
			}


			void init(uint8_t *prog, uint16_t memSize, uint16_t startAddr, Screen *screen);

			void userFuncBegin();
			void userFuncNum(int16_t v);
			void userFuncString(const char *s);
			void userFuncEnd();

			void printFuncBegin();
			void printFuncNum(int16_t v);
			void printFuncString(const char *s);
			void printFuncSep(const char c);
			void printFuncEnd();

			bool runOne(uint8_t keyPressed)
			{
				this->currentKey = keyPressed;
				ubasic_run(&this->ubInfo);

				bool ret = !ubasic_finished(&this->ubInfo);
				return ret;
			}

			uint8_t getCurrentKey() const {
				return currentKey;
			}

			void setCurrentKey(uint8_t currentKey) {
				this->currentKey = currentKey;
			}

		private:
			bool        running;
			uint8_t     currentKey;
			uint8_t    *mem;
			uint16_t    memSize;
			ubasic_info ubInfo;

			bool        seenCmd;
			bool        seenX;
			bool        seenY;
			bool        seenW;
			bool        seenH;
			bool        collectingBody;

			uint8_t     x;
			uint8_t     y;
			uint8_t     w;
			uint8_t     h;
			char        cmd[11];

			uint8_t     buf[101];
			uint8_t     bufPos;
	};

#endif /* GAMEENGINES_UBASIC_UBASICGAMEENGINE_H_ */
