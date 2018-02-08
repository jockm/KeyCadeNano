/*
 * UBasicGameEngine.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: jock
 */

#include <GameEngines/UBasic/UBasicGameEngine.h>
#include "ubasic/vartype.h"


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
	//TODO Implement Me
}


void UBasicGameEngine::userFuncNum(int16_t v)
{
	//TODO Implement Me
}


void UBasicGameEngine::userFuncString(const char *s)
{
	//TODO Implement Me
}


void UBasicGameEngine::userFuncEnd()
{
	//TODO Implement Me
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
	} else if(!this->seenY) {
		this->y = v;

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