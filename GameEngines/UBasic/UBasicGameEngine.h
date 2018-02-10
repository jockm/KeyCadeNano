// Copyright (c) 2018 Jock Murphy. jock@jockmurphy.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

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
