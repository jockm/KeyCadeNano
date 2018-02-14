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
			if(argc == 0 || argv[1] == 0) {
				ret = this->ufUpdateScreen(argc, argv);
			} else {
				ret = this->ufClearScreen(argc, argv);
			}
			break;

		case 4:
			ret = this->ufGetValue(argc, argv);
			break;

		case 5:
			ret = this->ufSetValue(argc, argv);
			break;

		case 6:
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

