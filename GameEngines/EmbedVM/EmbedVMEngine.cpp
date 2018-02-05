/*
 * EmbedVMEngine.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: jock
 */

#include <screen.h>
#include <NanoGameEngine.h>
#include <GameEngines/EmbedVM/EmbedVMEngine.h>

static int16_t readMem(uint16_t addr, bool is16bit, void *ctx)
{
	EmbedVMEngine *me = (EmbedVMEngine *) ctx;
	int16_t ret = me->getEvmMem(addr, is16bit);

	return ret;
}


static void writeMem(uint16_t addr, int16_t value, bool is16bit, void *ctx)
{
	EmbedVMEngine *me = (EmbedVMEngine *) ctx;
	me->setEvmMem(addr, value, is16bit);
}


static int16_t userFunc(uint8_t funcid, uint8_t argc, int16_t *argv, void *ctx)
{
	EmbedVMEngine *me = (EmbedVMEngine *) ctx;

	int16_t ret = me->userFunction(funcid, argc, argv);

	return ret;
}


EmbedVMEngine::EmbedVMEngine() {
	this->running = true;
	this->mem = NULL;
	this->memSize = 0;
	this->currentKey = NGE_NOKEY;
}

EmbedVMEngine::~EmbedVMEngine() {
	// Nothing
}


void EmbedVMEngine::init(uint8_t *prog, uint16_t memSiz, uint16_t startAddr, Screen *screen)
{
	this->screen = screen;
	this->mem = prog;
	this->memSize = memSiz;

	this->running = true;

	this->vmInfo.ip = 0xffff;

	this->vmInfo.sp = this->memSize;
	this->vmInfo.sfp = this->memSize;

	this->vmInfo.user_ctx = this;

	this->vmInfo.mem_read = &readMem;
	this->vmInfo.mem_write = &writeMem;
	this->vmInfo.call_user = &userFunc;

	embedvm_interrupt(&this->vmInfo, startAddr);
}


int16_t EmbedVMEngine::userFunction(uint8_t funcid, uint8_t argc, int16_t *argv)
{
	uint16_t ret = 0;

	switch (funcid) {
		case 0:
			ret = this->ufExit(argc, argv);
			break;

		case 1:
			ret = this->ufDrawSprite(argc, argv);
			break;

		case 2:
			ret = this->ufScroll(argc, argv);
			break;

		case 3:
			ret = this->ufUpdateScreen(argc, argv);
			break;

		case 4:
			ret = this->ufClearScreen(argc, argv);
			break;

		case 5:
			ret = this->ufGetDelay(argc, argv);
			break;

		case 6:
			ret = this->ufSetDelay(argc, argv);
			break;

		case 7:
			ret = this->ufGetSoundDelay(argc, argv);
			break;

		case 8:
			ret = this->ufSetSoundDelay(argc, argv);
			break;

		case 9:
			ret = this->ufGetKey(argc, argv);
			break;

		default:
			break;
	}
	return ret;
}


bool EmbedVMEngine::runOne(uint8_t keyPressed)
{
	bool ret = false;

	this->currentKey = keyPressed;

	if(this->vmInfo.ip == 0xFFFF) {
		ret = false;
	} else {
		embedvm_exec(&this->vmInfo);
		ret |= this->running;
	}


	return ret;
}

