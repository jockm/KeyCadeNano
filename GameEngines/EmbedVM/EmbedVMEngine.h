/*
 * EmbedVMEngine.h
 *
 *  Created on: Feb 3, 2018
 *      Author: jock
 */

#ifndef GAMEENGINES_EMBEDVM_EMBEDVMENGINE_H_
#define GAMEENGINES_EMBEDVM_EMBEDVMENGINE_H_

#include <NanoGameEngine.h>
#include "embedvm.h"

class EmbedVMEngine: public NanoGameEngine {
	public:
		EmbedVMEngine();
		virtual ~EmbedVMEngine();

		void init(uint8_t *prog, uint16_t memSize, uint16_t startAddr, Screen *screen);
		bool runOne(uint8_t keyPressed);

		int16_t getEvmMem(uint16_t addr, bool is16bit)
		{
			if(addr >= this->memSize) {
				return 0;
			}

			int16_t ret = this->mem[addr];

			if(is16bit) {
				ret = (ret << 8) | this->mem[addr + 1];
			}

			return ret;
		}

		void setEvmMem(uint16_t addr, int16_t value, bool is16bit)
		{
			if(addr >= this->memSize) {
				return;
			}

			if(is16bit) {
				this->mem[addr] = value >> 8;
				this->mem[addr+1] = value;
			} else {
				this->mem[addr] = value;
			}
		}

		int16_t userFunction(uint8_t funcid, uint8_t argc, int16_t *argv);

		int16_t ufGetDelay(uint8_t argc, int16_t *argv)
		{
			uint16_t ret = this->delayCounter;

			return ret;
		}


		int16_t ufSetDelay(uint8_t argc, int16_t *argv)
		{
			this->delayCounter = argv[0];

			return 0;
		}


		int16_t ufGetSoundDelay(uint8_t argc, int16_t *argv)
		{
			uint16_t ret = this->soundCounter;

			return ret;
		}


		int16_t ufSetSoundDelay(uint8_t argc, int16_t *argv)
		{
			this->soundCounter = argv[0];

			return 0;
		}


		int16_t ufGetKey(uint8_t argc, int16_t *argv)
		{
			return this->currentKey;
		}

		int16_t ufDrawSprite(uint8_t argc, int16_t *argv)
		{
			uint8_t x = argv[0];
			uint8_t y = argv[1];
			uint8_t w = argv[2];
			uint8_t h = argv[3];

			uint8_t *bitmap = (uint8_t *) argv[4];

			this->screen->xorBitmap(x, y, bitmap, w, h);

			return 0;
		}


		int16_t ufUpdateScreen(uint8_t argc, int16_t *argv)
		{
			this->screen->update();
			return 0;
		}


		int16_t ufScroll(uint8_t argc, int16_t *argv)
		{
			uint8_t dir = argv[0];
			uint8_t amount = argv[1];
			uint8_t from = argv[2];
			uint8_t to = argv[3];

			switch(dir) {
				case 0:
					//TODO Scroll Left
					break;

				case 1:
					//TODO Scroll Right
					break;

				case 2:
					//TODO Scroll Up
					break;

				case 3:
					//TODO Scroll Down
					break;

				default:
					break;
			}
			return 0;
		}


		int16_t ufDrawString(uint8_t argc, int16_t *argv)
		{
			uint8_t  x = argv[0];
			uint8_t  y = argv[1];
			uint8_t  c = argv[2];
			uint8_t *s = (uint8_t *)argv[3];

			this->screen->drawString(x, y, (const char *) s, c);

			return 0;
		}

		int16_t ufClearScreen(uint8_t argc, int16_t *argv)
		{
			this->screen->clearScreen();
			return 0;
		}


		int16_t ufExit(uint8_t argc, int16_t *argv)
		{
			this->running = false;
			return 0;
		}


	protected:
		bool              running;
		uint8_t           currentKey;
		uint8_t          *mem;
		uint16_t          memSize;
		struct embedvm_s  vmInfo;
};

#endif /* GAMEENGINES_EMBEDVM_EMBEDVMENGINE_H_ */
