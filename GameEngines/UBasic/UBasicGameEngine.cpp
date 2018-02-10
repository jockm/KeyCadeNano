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

#include <b64.h>

#include <GameEngines/UBasic/UBasicGameEngine.h>
#include "ubasic/vartype.h"
#include "b64.h"


static void userBegin(void *context)
{
	UBasicGameEngine *me = (UBasicGameEngine *)context;
	me->userFuncBegin();
}


static void userNumber(VARIABLE_TYPE num, void *context)
{
	UBasicGameEngine *me = (UBasicGameEngine *)context;
	me->userFuncNum(num);
}


static void userString(const char *str, void *context)
{
	UBasicGameEngine *me = (UBasicGameEngine *)context;
	me->userFuncString(str);
}


static void userSeparator(const char sep, void *context)
{
	// Nothing
}


static void userEnd(void *context)
{
	UBasicGameEngine *me = (UBasicGameEngine *)context;
	me->userFuncEnd();
}


static void printBegin(void *context)
{
	UBasicGameEngine *me = (UBasicGameEngine *)context;
	me->printFuncBegin();
}


static void printNumber(VARIABLE_TYPE num, void *context)
{
	UBasicGameEngine *me = (UBasicGameEngine *)context;
	me->printFuncNum(num);
}


static void printString(const char *str, void *context)
{
	UBasicGameEngine *me = (UBasicGameEngine *)context;
	me->printFuncString(str);
}


static void printSeparator(const char sep, void *context)
{
	UBasicGameEngine *me = (UBasicGameEngine *)context;
	me->printFuncSep(sep);
}


static void printEnd(void *context)
{
	UBasicGameEngine *me = (UBasicGameEngine *)context;
	me->printFuncEnd();
}


VARIABLE_TYPE peekHandler(VARIABLE_TYPE arg, void *context)
{
	UBasicGameEngine *me = (UBasicGameEngine *)context;

	VARIABLE_TYPE ret = -1;

	if(arg == 0) {
		ret = me->getDelayCounter();
	} else if(arg == 1){
		ret = me->getSoundCounter();
	}

    return ret;
}


void pokeHandler(VARIABLE_TYPE arg, VARIABLE_TYPE value, void *context)
{
	UBasicGameEngine *me = (UBasicGameEngine *)context;

	if(arg == 0) {
		me->setDelayCounter(value);
	} else if(arg == 1){
		me->setSoundCounter(value);
	}
}


VARIABLE_TYPE inputHandler(VARIABLE_TYPE arg, void *context)
{
	UBasicGameEngine *me = (UBasicGameEngine *)context;

	VARIABLE_TYPE ret = me->getCurrentKey();
	return ret;
}



void UBasicGameEngine::init(uint8_t *prog, uint16_t memSiz, uint16_t startAddr, Screen *screen)
{
	this->screen = screen;
	this->mem = prog;
	this->memSize = memSiz;

	this->running = true;

	ubasic_init(&this->ubInfo, (const char *)this->mem);

	this->ubInfo.app_context = this;

	this->ubInfo.peek_function = peekHandler;
	this->ubInfo.poke_function = pokeHandler;

	this->ubInfo.input_function = inputHandler;

	this->ubInfo.print_begin_function = printBegin;
	this->ubInfo.print_num_function = printNumber;
	this->ubInfo.print_string_function = printString;
	this->ubInfo.print_separator_function = printSeparator;
	this->ubInfo.print_end_function = printEnd;

	this->ubInfo.user_begin_function = userBegin;
	this->ubInfo.user_num_function = userNumber;
	this->ubInfo.user_string_function = userString;
	this->ubInfo.user_separator_function = userSeparator;
	this->ubInfo.user_end_function = userEnd;
}


void UBasicGameEngine::userFuncBegin()
{
	this->seenCmd = false;
	this->seenX = false;
	this->seenY = false;
	this->seenW = false;
	this->seenH = false;
	this->collectingBody = false;

	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
	this->cmd[0] = '\0';
	this->buf[0] = '\0';
	this->bufPos = 0;
}


void UBasicGameEngine::userFuncNum(int16_t v)
{
	if(!seenX) {
		this->x = v;
		this->seenX = true;

		return;
	}

	if(!seenY) {
		this->y = v;
		this->seenY = true;

		return;
	}

	if(!seenW) {
		this->w = v;
		this->seenW = true;

		return;
	}

	if(!seenH) {
		this->h = v;
		this->seenH = true;

		this->collectingBody = true;

		return;
	}

	if(this->collectingBody) {
		if(this->bufPos < sizeof(this->buf)) {
			this->buf[this->bufPos++] = (uint8_t) v;
		}
	}
}


void UBasicGameEngine::userFuncString(const char *s)
{
	if(this->seenCmd) {
		this->collectingBody = true;

		uint16_t bytesAdded = b64Decode((uint8_t *)s, this->buf + this->bufPos, strlen(s));
		this->bufPos += bytesAdded;
	} else {
		strcpy(this->cmd, s);
		seenCmd = true;
	}
}


void UBasicGameEngine::userFuncEnd()
{
	if(strcmp("cls", (const char *)this->cmd) == 0) {
		this->screen->fillScreen(this->x);
	} else if(strcmp("update", (const char *)this->cmd) == 0) {
		this->screen->update();
	} else if(strcmp("draw", (const char *)this->cmd) == 0) {
		this->screen->drawBitmap(this->x, this->y, this->buf, this->w, this->h);
	} else if(strcmp("xdraw", (const char *)this->cmd) == 0) {
		this->screen->xorBitmap(this->x, this->y, this->buf, this->w, this->h);
	}
}


void UBasicGameEngine::printFuncBegin()
{
	this->seenX = false;
	this->seenY = false;
	this->collectingBody = false;

	this->x = 0;
	this->y = 0;
	this->bufPos = 0;
	this->buf[0] = '\0';
}


void UBasicGameEngine::printFuncNum(int16_t v) {
	char b[11];

	if(this->collectingBody) {
		itoa(v, b, 10);
		strcat((char *) this->buf, b);

		return;
	}

	if(!this->seenX) {
		this->x = v;
		this->seenX = true;
	} else if(!this->seenY) {
		this->y = v;

		this->seenY = true;
		this->collectingBody = true;
	}

}


void UBasicGameEngine::printFuncString(const char *s)
{
	this->collectingBody = true;
	strcat((char *) this->buf, s);
}


void UBasicGameEngine::printFuncSep(const char c)
{
	//TODO Implement Me
}

void UBasicGameEngine::printFuncEnd()
{
	this->screen->drawString(this->x, this->y, (const char *)this->buf);
}
