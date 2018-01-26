
#ifndef CHIP8_H_
#	define CHIP8_H_

#	include "mbed.h"
#	include "SSD1306.h"
#	include "NanoGameEngine.h"

#	define CHIP8_MAXWIDTH 128
#	define CHIP8_MAXHEIGHT 64


	class Chip8 : NanoGameEngine{
		public:
			Chip8()
			{
				this->pc = 0;
				this->sp = 0;
				this->mem = NULL;
				this->memSize = 0;
				this->delayCounter = 0;
				this->soundCounter = 0;
				this->hz = 0;
				this->waitingForKey = false;
				this->screenWidth = 32;
				this->screenHeight = 64;
				this->enhancedMode = false;
				this->vI = 0;
				this->currentKey = NGE_NOKEY;
				this->keyDest = 0;
				this->screenDirty = false;
				this->screen = NULL;
			}


			void loadMemory(uint8_t *mem, const uint8_t *prog, uint16_t progSize) {
				memcpy(mem + 0x200, prog, progSize);
			}

			void init(uint8_t *prog, uint16_t memSize, Screen *screen);

			bool runOne(uint8_t keyPressed);

			bool isSoundPlaying()
			{
				return this->soundCounter > 0;
			}

			void setHz(uint16_t hz)
			{
				this->hz = hz;
			}

			void intervalCallback(void) {
				this->decrementCounters();
			}

			bool isScreenDirty() const {
				return screenDirty;
			}

			void setScreenDirty(bool screenDirty) {
				this->screenDirty = screenDirty;
			}

		private:
			bool runOtherOp(uint8_t op1);
			bool runMathOp(uint8_t x, uint8_t y, uint8_t opt);
			bool runKeyOp(uint8_t op, uint8_t x);
			bool runOtherOtherOp(uint8_t x, uint8_t op);

			bool doScrollDown(uint8_t n);
			bool doCls();
			bool doRet();
			bool doScrollRight();
			bool doScrollLeft();
			bool doExit();
			bool doScreenNormal();
			bool doScreenExtended();
			bool doJump(uint16_t nnn);
			bool doCall(uint16_t nnn);
			bool doSkipEq(uint8_t x, uint8_t kk);
			bool doSkipNeq(uint8_t x, uint8_t kk);
			bool doSkipEqVar(uint8_t x, uint8_t y);
			bool doLoadConst(uint8_t x, uint8_t nn);
			bool doAddConst(uint8_t x, uint8_t nn);
			bool doLoadVar(uint8_t x, uint8_t y);
			bool doBitOr(uint8_t x, uint8_t y);
			bool doBitAnd(uint8_t x, uint8_t y);
			bool doBitXor(uint8_t x, uint8_t y);
			bool doAdd(uint8_t x, uint8_t y);
			bool doSub(uint8_t x, uint8_t y);
			bool doShiftRight(uint8_t x);
			bool doSubN(uint8_t x, uint8_t y);
			bool doShiftLeft(uint8_t x);
			bool doSkipNeqVar(uint8_t x, uint8_t y);
			bool doLoadIndex(uint16_t nnn);
			bool doJumpV0(uint16_t nnn);
			bool doLoadRandom(uint8_t x, uint8_t y);
			bool doDraw(uint8_t x, uint8_t y, uint8_t n);
			bool doSkipKey(uint8_t x);
			bool doSkipNotKey(uint8_t x);
			bool doLoadVarDelay(uint8_t x);
			bool doWaitKey(uint8_t x);
			bool doLoadDelay(uint8_t x);
			bool doLoadSound(uint8_t x);
			bool doAddIndex(uint8_t x);
			bool doSetIndexDigit(uint8_t x);
			bool doSetIndexBigDigit(uint8_t x);
			bool doLoadBcd(uint8_t x);
			bool doStoreVars(uint8_t x);
			bool doLoadVars(uint8_t x);
			bool doStoreVarsRpl(uint8_t x);
			bool doLoadVarsRpl(uint8_t x);

			bool drawPixel(uint8_t x, uint8_t y, bool on);



			uint8_t getByte(uint16_t addr) {
				uint8_t ret = addr < this->memSize ? mem[addr] : 0;
				return ret;
			}

			void decrementCounters()
			{
				if(this->delayCounter > 0) {
					--this->delayCounter;
				}

				if(this->soundCounter > 0) {
					--this->soundCounter;
				}
			}


			bool      waitingForKey;
			uint8_t   currentKey;
			uint8_t   keyDest;

			uint16_t  hz;
			uint16_t  memSize;
			uint8_t   *mem;

			uint8_t   sp;
			uint16_t   pc;
			uint16_t   vI;

			volatile uint8_t   delayCounter;
			volatile uint8_t   soundCounter;

			uint16_t  stack[20];
			uint8_t   v[16];
			uint8_t   rpl[16];

			uint8_t   screenWidth;
			uint8_t   screenHeight;
			bool      enhancedMode;

			bool      screenDirty;

			Screen   *screen;
	};

#endif /* CHIP8_H_ */
