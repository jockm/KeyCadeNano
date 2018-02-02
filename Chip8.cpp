/*
 * Chip8.cpp
 *
 *  Created on: Jan 11, 2018
 *      Author: jock
 */

#include "mbed.h"
#include "Chip8.h"


const uint8_t chip8Font[] = {
		// Small Font
		/* 0 */ 0xF0, 0x90, 0x90, 0x90, 0xF0,
		/* 1 */ 0x20, 0x60, 0x20, 0x20, 0x70,
		/* 2 */ 0xF0, 0x10, 0xF0, 0x80, 0xF0,
		/* 3 */ 0xF0, 0x10, 0xF0, 0x10, 0xF0,
		/* 4 */ 0x90, 0x90, 0xF0, 0x10, 0x10,
		/* 5 */ 0xF0, 0x80, 0xF0, 0x10, 0xF0,
		/* 6 */ 0xF0, 0x80, 0xF0, 0x90, 0xF0,
		/* 7 */ 0xF0, 0x10, 0x20, 0x40, 0x40,
		/* 8 */ 0xF0, 0x90, 0xF0, 0x90, 0xF0,
		/* 9 */ 0xF0, 0x90, 0xF0, 0x10, 0xF0,
		/* A */ 0xF0, 0x90, 0xF0, 0x90, 0x90,
		/* B */ 0xE0, 0x90, 0xE0, 0x90, 0xE0,
		/* C */ 0xF0, 0x80, 0x80, 0x80, 0xF0,
		/* D */ 0xE0, 0x90, 0x90, 0x90, 0xE0,
		/* E */ 0xF0, 0x80, 0xF0, 0x80, 0xF0,
		/* F */ 0xF0, 0x80, 0xF0, 0x80, 0x80,

		// Large Font.
		/* 0 */ 0x7C, 0xC6, 0xCE, 0xDE, 0xD6, 0xF6, 0xE6, 0xC6, 0x7C, 0x00,
		/* 1 */ 0x10, 0x30, 0xF0, 0x30, 0x30, 0x30, 0x30, 0x30, 0xFC, 0x00,
		/* 2 */ 0x78, 0xCC, 0xCC, 0x0C, 0x18, 0x30, 0x60, 0xCC, 0xFC, 0x00,
		/* 3 */ 0x78, 0xCC, 0x0C, 0x0C, 0x38, 0x0C, 0x0C, 0xCC, 0x78, 0x00,
		/* 4 */ 0x0C, 0x1C, 0x3C, 0x6C, 0xCC, 0xFE, 0x0C, 0x0C, 0x1E, 0x00,
		/* 5 */ 0xFC, 0xC0, 0xC0, 0xC0, 0xF8, 0x0C, 0x0C, 0xCC, 0x78, 0x00,
		/* 6 */ 0x38, 0x60, 0xC0, 0xC0, 0xF8, 0xCC, 0xCC, 0xCC, 0x78, 0x00,
		/* 7 */ 0xFE, 0xC6, 0xC6, 0x06, 0x0C, 0x18, 0x30, 0x30, 0x30, 0x00,
		/* 8 */ 0x78, 0xCC, 0xCC, 0xEC, 0x78, 0xDC, 0xCC, 0xCC, 0x78, 0x00,
		/* 9 */ 0x7C, 0xC6, 0xC6, 0xC6, 0x7C, 0x18, 0x18, 0x30, 0x70, 0x00,
		/* A */ 0x30, 0x78, 0xCC, 0xCC, 0xCC, 0xFC, 0xCC, 0xCC, 0xCC, 0x00,
		/* B */ 0xFC, 0x66, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x66, 0xFC, 0x00,
		/* C */ 0x3C, 0x66, 0xC6, 0xC0, 0xC0, 0xC0, 0xC6, 0x66, 0x3C, 0x00,
		/* D */ 0xF8, 0x6C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x6C, 0xF8, 0x00,
		/* E */ 0xFE, 0x62, 0x60, 0x64, 0x7C, 0x64, 0x60, 0x62, 0xFE, 0x00,
		/* F */ 0xFE, 0x66, 0x62, 0x64, 0x7C, 0x64, 0x60, 0x60, 0xF0, 0x00
};


void Chip8::init(uint8_t *mem, uint16_t memSize, Screen *screen)
{
	srand(us_ticker_read());

	this->screen = screen;
	this->mem = mem;
	this->memSize = memSize;

	memcpy(this->mem, chip8Font, sizeof(chip8Font));

	pc = 0x200;
	sp = 0;

	this->delayCounter = 0;
	this->soundCounter = 0;
	this->hz = 500;

	this->waitingForKey = false;
	this->currentKey = NGE_NOKEY;
	this->keyDest = 0;

	this->screenWidth = CHIP8_MAXWIDTH / 2;
	this->screenHeight = CHIP8_MAXHEIGHT / 2;
	this->enhancedMode = false;

	this->screenDirty = false;


	for(uint8_t i = 0; i < sizeof(v); ++i) {
		v[i] = 0;
	}
}


inline bool Chip8::drawPixel(uint8_t x, uint8_t y, bool on)
{
	// As per: http://www.emulator101.com/chip-8-sprites.html
	// Drawubg us clipped at the screen edge and not wrapped


	if(x > this->screenWidth || y > this->screenHeight) {
		return false;
	}

//	x %= this->screenWidth;
//	y %= this->screenHeight;

	if(!this->enhancedMode) {
		x *= 2;
		y *= 2;
	}

	bool ret = this->screen->xorRawPixel(x, y, on);
	if(!this->enhancedMode) {
		this->screen->xorRawPixel(x + 1, y, on);
		this->screen->xorRawPixel(x, y + 1, on);
		this->screen->xorRawPixel(x + 1, y + 1, on);
	}

	return ret;
}

bool Chip8::runOne(uint8_t keyPressed)
{
	bool ret = true;

	if(this->waitingForKey) {
		if(keyPressed == NGE_NOKEY) {
			return true;
		} else {
			this->v[this->keyDest] = keyPressed;
			this->waitingForKey = false;
		}
	}

	this->currentKey = keyPressed;

	uint16_t inst = (this->mem[this->pc] << 8) |  this->mem[this->pc + 1];

	this->pc += 2;

	uint8_t instType = (inst & 0xF000) >> 12;
	uint8_t opt = inst & 0x000F;
	uint16_t nnn = inst & 0x0FFF;
	uint16_t kk = inst & 0x00FF;
	uint8_t x = (inst & 0x0F00) >> 8;
	uint8_t y = (inst & 0x00F0) >> 4;

	switch(instType) {
		case 0x0:
			ret = this->runOtherOp(kk);
			break;

		case 0x1:
			this->pc = nnn & 0x0FFF;
			break;

		case 0x2:
			ret = this->doCall(nnn);
			break;

		case 0x3:
			ret = this->doSkipEq(x, kk);
			break;

		case 0x4:
			ret = this->doSkipNeq(x, kk);
			break;

		case 0x5:
			ret = this->doSkipEqVar(x, y);
			break;

		case 0x6:
			this->v[x] = kk;
			break;

		case 0x7:
			ret = this->doAddConst(x, kk);
			break;

		case 0x8:
			ret = this->runMathOp(x, y, opt);
			break;

		case 0x9:
			ret = this->doSkipNeqVar(x, y);
			break;

		case 0xA:
			// ANNN     I := NNN
			this->vI = nnn;
			break;

		case 0xB:
			this->pc = (this->vI + this->v[0]) & 0x0FFF;
			break;

		case 0xC:
			this->v[x] = (rand() & 0xFF) & kk;
			break;

		case 0xD:
			ret = this->doDraw(x, y, opt);
			break;

		case 0xE:
			ret = this->runKeyOp(kk, x);
			break;

		case 0xF:
			ret = this->runOtherOtherOp(x, kk);
			break;

	}

	return ret;
}


inline bool Chip8::runOtherOp(uint8_t op)
{
	bool ret = false;

	if((op & 0xF0) == 0xC0) {
		ret = this->doScrollDown(op & 0xF);
		return ret;
	}

	switch(op) {
		case 0xE0:
			ret = this->doCls();
			break;

		case 0xEE:
			ret = this->doRet();
			break;

		case 0xFB:
			ret = this->doScrollRight();
			break;

		case 0xFC:
			ret = this->doScrollLeft();
			break;

		case 0xFD:
			ret = this->doExit();
			break;

		case 0xFE:
			ret = this->doScreenNormal();
			break;

		case 0xFF:
			ret = this->doScreenExtended();
			break;

	}

	return ret;
}


inline bool Chip8::runMathOp(uint8_t x, uint8_t y, uint8_t opt)
{
	bool ret = false;

	switch(opt) {
		case 0x0:
			ret = this->doLoadVar(x, y);
			break;

		case 0x1:
			ret = this->doBitOr(x, y);
			break;

		case 0x2:
			ret = this->doBitAnd(x, y);
			break;

		case 0x3:
			ret = this->doBitXor(x, y);
			break;

		case 0x4:
			ret = this->doAdd(x, y);
			break;

		case 0x5:
			ret = this->doSub(x, y);
			break;

		case 0x6:
			ret = this->doShiftRight(x);
			break;

		case 0x7:
			ret = this->doSubN(x, y);
			break;

		case 0xE:
			ret = this->doShiftLeft(x);
			break;
	}

	return ret;
}


inline bool Chip8::runKeyOp(uint8_t op, uint8_t x)
{
	bool ret = false;

	if(op == 0x9E) {
		ret = this->doSkipKey(x);
	} else if(op == 0xA1) {
		ret = this->doSkipNotKey(x);
	}

	return ret;
}


inline bool Chip8::runOtherOtherOp(uint8_t x, uint8_t op)
{
	bool ret = false;

	switch(op) {
		case 0x07:
			ret = this->doLoadVarDelay(x);
			break;

		case 0x0A:
			ret = this->doWaitKey(x);
			break;

		case 0x15:
			ret = this->doLoadDelay(x);
			break;

		case 0x18:
			ret = this->doLoadSound(x);
			break;

		case 0x1E:
			ret = this->doAddIndex(x);
			break;

		case 0x29:
			ret = this->doSetIndexDigit(x);
			break;

		case 0x30:
			ret = this->doSetIndexBigDigit(x);
			break;

		case 0x33:
			ret = this->doLoadBcd(x);
			break;

		case 0x55:
			ret = this->doStoreVars(x);
			break;

		case 0x65:
			ret = this->doLoadVars(x);
			break;

		case 0x75:
			ret = this->doStoreVarsRpl(x);
			break;

		case 0x85:
			ret = this->doLoadVarsRpl(x);
			break;

	}

	return ret;
}




// 00CN*    Scroll display N lines down
inline bool Chip8::doScrollDown(uint8_t n)
{
	if(n == 0) {
		return true;
	}

	this->screen->scrollDown(n);

	return true;
}


// 00E0     Clear display
inline bool Chip8::doCls()
{
	this->screen->clearScreen();

	return true;
}


inline bool Chip8::doRet()
{
	if(this->sp == 0) {
		return false;
	}

	this->pc = (this->stack[--sp]) & 0x0FFF;

	return true;
}


// 00FB*    Scroll display 4 pixels right
inline bool Chip8::doScrollRight()
{
	uint8_t n = 2;

	if(this->enhancedMode) {
		n *= 2;
	}

	for(uint8_t i = 0; i < n; ++i) {
		this->screen->scrollRight(1);
	}

	return true;
}


// 00FC*    Scroll display 4 pixels left
inline bool Chip8::doScrollLeft()
{
	uint8_t n = 2;

	if(this->enhancedMode) {
		n *= 2;
	}

	for(uint8_t i = 0; i < n; ++i) {
		this->screen->scrollLeft(1);
	}

	return true;
}


// 00FD*    Exit CHIP interpreter
inline bool Chip8::doExit()
{
	return false;
}


// 00FE*    Disable extended screen mode
inline bool Chip8::doScreenNormal()
{
	this->screenWidth = CHIP8_MAXWIDTH / 2;
	this->screenHeight = CHIP8_MAXHEIGHT / 2;
	this->enhancedMode = false;

	this->doCls();

	return true;
}


// *    Enable extended screen mode for full-screen graphics
inline bool Chip8::doScreenExtended()
{
	this->screenWidth = CHIP8_MAXWIDTH;
	this->screenHeight = CHIP8_MAXHEIGHT;
	this->enhancedMode = true;

	this->doCls();

	return true;
}


// 1NNN     Jump to NNN
inline bool Chip8::doJump(uint16_t nnn)
{
	this->pc = nnn & 0x0FFF;

	return true;
}


// 2NNN     Call subroutine at NNN
inline bool Chip8::doCall(uint16_t nnn)
{
	this->stack[this->sp++] = this->pc;

	this->pc = nnn & 0x0FFF;

	return true;
}


// 3XKK     Skip next instruction if VX == KK
inline bool Chip8::doSkipEq(uint8_t x, uint8_t kk)
{
	if(this->v[x] == kk) {
		this->pc += 2;
	}

	return true;
}


// 4XKK     Skip next instruction if VX <> KK
inline bool Chip8::doSkipNeq(uint8_t x, uint8_t kk)
{
	if(this->v[x] != kk) {
		this->pc += 2;
	}

	return true;
}


// 5XY0     Skip next instruction if VX == VY
inline bool Chip8::doSkipEqVar(uint8_t x, uint8_t y)
{
	if(this->v[x] == this->v[y]) {
		this->pc += 2;
	}

	return true;
}


// 6XKK     VX := KK
inline bool Chip8::doLoadConst(uint8_t x, uint8_t kk)
{
	this->v[x] = kk;

	return true;
}


// 7XKK     VX := VX + KK
inline bool Chip8::doAddConst(uint8_t x, uint8_t kk)
{
	this->v[x] += kk;

	return true;
}


// 8XY0     VX := VY, VF may change
inline bool Chip8::doLoadVar(uint8_t x, uint8_t y)
{
	this->v[x] = this->v[y];

	return true;
}


// 8XY1     VX := VX or VY, VF may change
inline bool Chip8::doBitOr(uint8_t x, uint8_t y)
{
	this->v[x] |= this->v[y];

	return true;
}


// 8XY2     VX := VX and VY, VF may change
inline bool Chip8::doBitAnd(uint8_t x, uint8_t y)
{
	this->v[x] &= this->v[y];

	return true;
}


// 8XY3     VX := VX xor VY, VF may change
inline bool Chip8::doBitXor(uint8_t x, uint8_t y)
{
	this->v[x] ^= this->v[y];

	return true;
}


// 8XY4     VX := VX + VY, VF := carry
inline bool Chip8::doAdd(uint8_t x, uint8_t y)
{
	uint16_t result = (uint16_t) this->v[x] + (uint16_t) this->v[y];

	this->v[0xF] = (result > 0xFF) ? 1 : 0;
	this->v[x] = result & 0xFF;

	return true;
}


// 8XY5     VX := VX - VY, VF := not borrow
inline bool Chip8::doSub(uint8_t x, uint8_t y)
{
	this->v[0xF] = (this->v[x] > this->v[y]) ? 1 : 0;
	this->v[x] -= this->v[y];

	return true;
}


// 8XY6     VX := VX shr 1, VF := carry
inline bool Chip8::doShiftRight(uint8_t x)
{
	this->v[0xF] = this->v[x] & 0b00000001;
	this->v[x] >>= 1;

	return true;
}


// 8XY7     VX := VY - VX, VF := not borrow
inline bool Chip8::doSubN(uint8_t x, uint8_t y)
{
	this->v[0xF] = (this->v[y] > this->v[x]) ? 1 : 0;
	this->v[x] = this->v[y] - this->v[x];

	return true;
}


// 8XYE     VX := VX shl 1, VF := carry
inline bool Chip8::doShiftLeft(uint8_t x)
{
	this->v[0xF] = !!(this->v[x] & 0b10000000) > 0;
	this->v[x] <<= 1;

	return true;
}


// 9XY0     Skip next instruction if VX <> VY
inline bool Chip8::doSkipNeqVar(uint8_t x, uint8_t y)
{
	if(this->v[x] != this->v[y]) {
		this->pc += 2;
	}

	return true;
}


//// ANNN     I := NNN
//inline bool Chip8::doLoadIndex(uint16_t nnn)
//{
//	this->vI = nnn;
//
//	return true;
//}


// BNNN     Jump to NNN+V0
inline bool Chip8::doJumpV0(uint16_t nnn)
{
	this->pc = (this->vI + this->v[0]) & 0x0FFF;

	return true;
}


// CXKK     VX := pseudorandom_number and KK
inline bool Chip8::doLoadRandom(uint8_t x, uint8_t kk)
{
    uint8_t randNum = rand() & kk;
    this->v[x] = randNum;
	return true;
}


// DXYN*    Show N-byte sprite from M(I) at coords (VX,VY), VF :=
// collision. If N=0 and extended mode, show 16x16 sprite.
inline bool Chip8::doDraw(uint8_t vx, uint8_t vy, uint8_t height)
{
	bool collision = false;
	uint8_t byteWidth = 1;

	if(height == 0) {
		byteWidth = 2;
		height = 16;
	}

	// Because we know the screen is flipped we are going to do the math
	// once and not on every drawPixel call
	int8_t x = this->v[vx];
	int8_t y = this->v[vy];

	x %= this->screenWidth;
	y %= this->screenHeight;


	x = (this->screenWidth - 1) - x;
	y = (this->screenHeight - 1) - y - (height - 1);


	uint16_t addr = this->vI;
	uint16_t yPos = y + (height - 1);

	for(uint16_t i = 0; i < height; ++i) {
		uint16_t xPos = x;

		for(uint16_t j = 0; j < byteWidth; ++j) {
			uint8_t pixelByte = this->mem[addr++];

			uint8_t color0 = pixelByte & (1 << 7);
			uint8_t color1 = pixelByte & (1 << 6);
			uint8_t color2 = pixelByte & (1 << 5);
			uint8_t color3 = pixelByte & (1 << 4);
			uint8_t color4 = pixelByte & (1 << 3);
			uint8_t color5 = pixelByte & (1 << 2);
			uint8_t color6 = pixelByte & (1 << 1);
			uint8_t color7 = pixelByte & (1 << 0);

			uint8_t collision0 = this->drawPixel(xPos--, yPos, color0);
			uint8_t collision1 = this->drawPixel(xPos--, yPos, color1);
			uint8_t collision2 = this->drawPixel(xPos--, yPos, color2);
			uint8_t collision3 = this->drawPixel(xPos--, yPos, color3);
			uint8_t collision4 = this->drawPixel(xPos--, yPos, color4);
			uint8_t collision5 = this->drawPixel(xPos--, yPos, color5);
			uint8_t collision6 = this->drawPixel(xPos--, yPos, color6);
			uint8_t collision7 = this->drawPixel(xPos--, yPos, color7);

			collision |= collision0 | collision1 | collision2
					| collision3 | collision4 | collision5
					| collision6 | collision7;
		}

		--yPos;
	}

	this->v[0xF] = collision;

	this->screenDirty = true;

	return true;
}


// EX9E     Skip next instruction if key VX pressed
inline bool Chip8::doSkipKey(uint8_t x)
{
	if(this->currentKey == this->v[x]) {
		this->pc += 2;
	}

	return true;
}


// EXA1     Skip next instruction if key VX not pressed
inline bool Chip8::doSkipNotKey(uint8_t x)
{
	if(this->currentKey != this->v[x]) {
		this->pc += 2;
	}

	return true;
}


// FX07     VX := delay_timer
inline bool Chip8::doLoadVarDelay(uint8_t x)
{
	this->v[x] = this->delayCounter;

	return true;
}


// FX0A     wait for keypress, store hex value of key in VX
inline bool Chip8::doWaitKey(uint8_t x)
{

	this->waitingForKey = true;
	this->keyDest = x;

	return true;
}


// FX15     delay_timer := VX
inline bool Chip8::doLoadDelay(uint8_t x)
{
	this->delayCounter = this->v[x];
	return true;
}


// FX18     sound_timer := VX
inline bool Chip8::doLoadSound(uint8_t x)
{
	this->soundCounter = this->v[x];
	return true;
}


// FX1E     I := I + VX
inline bool Chip8::doAddIndex(uint8_t x)
{
	this->vI += this->v[x];

	return true;
}


// FX29     Point I to 5-byte font sprite for hex character VX
inline bool Chip8::doSetIndexDigit(uint8_t x)
{
	this->vI = this->v[x] * 5;

	return true;
}


// *    Point I to 10-byte font sprite for digit VX (0..9)
inline bool Chip8::doSetIndexBigDigit(uint8_t x)
{
	this->vI = 80 + this->v[x] * 0xA;
	return false;
}


// FX33     Store BCD representation of VX in M(I)..M(I+2)
inline bool Chip8::doLoadBcd(uint8_t x)
{
	this->mem[this->vI] = this->v[x] / 100;
	this->mem[this->vI + 1] = this->v[x] % 100 / 10;
	this->mem[this->vI + 2] = this->v[x] % 100 % 10;

	return true;
}


// FX55     Store V0..VX in memory starting at M(I)
inline bool Chip8::doStoreVars(uint8_t x)
{
	for(uint8_t i = 0; i <= x; ++i) {
		this->mem[this->vI + i] = this->v[i];
	}

	return true;
}


// FX65     Read V0..VX from memory starting at M(I)
inline bool Chip8::doLoadVars(uint8_t x)
{
	for(uint8_t i = 0; i <= x; ++i) {
		this->v[i] = mem[this->vI + i];
	}

	return true;
}


// FX75*    Store V0..VX in RPL user flags (X <= 7)
inline bool Chip8::doStoreVarsRpl(uint8_t x)
{
	for(uint8_t i = 0; i <= x; ++i) {
		this->rpl[i] = this->v[i];
	}

	return true;
}


// FX85*    Read V0..VX from RPL user flags (X <= 7)
inline bool Chip8::doLoadVarsRpl(uint8_t x)
{
	for(uint8_t i = 0; i <= x; ++i) {
		this->v[i] = this->rpl[i];
	}

	return true;
}



