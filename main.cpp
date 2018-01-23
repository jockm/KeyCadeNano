#include "mbed.h"

#include "SSD1306.h"
#include "Chip8.h"


//DigitalOut LED(LED1);
I2C        i2c(PA_10, PA_9);
SSD1306    display(&i2c, 0x78);

DigitalIn up(PA_6, PullUp);
DigitalIn down(PB_0, PullUp);
DigitalIn left(PA_3, PullUp);
DigitalIn right(PA_7, PullUp);
DigitalIn center(PA_5, PullUp);
DigitalIn action1(PB_1, PullUp);
DigitalIn action2(PA_8, PullUp);

PwmOut    speaker(PA_1);
AnalogOut    speakerDac(PA_4);


const uint8_t tankGame[] = {
		0x12, 0x34, 0x10, 0x54, 0x7C, 0x6C, 0x7C, 0x7C,
		0x44, 0x7C, 0x7C, 0x6C, 0x7C, 0x54, 0x10, 0x00,
		0xFC, 0x78, 0x6E, 0x78, 0xFC, 0x00, 0x3F, 0x1E,
		0x76, 0x1E, 0x3F, 0x00, 0x72, 0xFF, 0xA2, 0x02,
		0x00, 0xEE, 0x72, 0x01, 0xA2, 0x08, 0x00, 0xEE,
		0x71, 0xFF, 0xA2, 0x15, 0x00, 0xEE, 0x71, 0x01,
		0xA2, 0x0F, 0x00, 0xEE, 0x61, 0x20, 0x62, 0x10,
		0xA2, 0x02, 0xD1, 0x27, 0xF0, 0x0A, 0xD1, 0x27,
		0x40, 0x02, 0x22, 0x1C, 0x40, 0x04, 0x22, 0x28,
		0x40, 0x06, 0x22, 0x2E, 0x40, 0x08, 0x22, 0x22,
		0x12, 0x3A
};

uint8_t mem[4096];
Chip8 chip;

Ticker screenUpdateTicker;
Ticker chipTimersTicker;
Ticker chipRunTicker;

uint8_t lastKey;

uint8_t getKey(void) {
	uint8_t ret = CHIP8_NOKEY;
	uint8_t key = CHIP8_NOKEY;

	if (!up) {
		key = 2;
	} else if (!down) {
		key = 8;
	} else if (!left) {
		key = 4;
	} else if (!right) {
		key = 6;
	}

	if(key != lastKey) {
		ret = key;
	}

	lastKey = key;

	return ret;
}

int main()
{
	memcpy(mem + 0x200, tankGame, sizeof(tankGame));

	i2c.frequency(400000);

	display.setScreenFlipped(true);

	display.fillScreen(0);
	display.update();

	lastKey = CHIP8_NOKEY;

	chip.init(mem, sizeof(mem), &display);

	uint32_t nextFrameTime = 0;
	uint32_t timeToDecrementCounters = 0;

	uint8_t duck = 0;
	uint8_t duck2 = 0;
	uint8_t duck3 = 1;

    while(true) {
		// todo DUCK
//    	if(currTime >= timeToDecrementCounters) {
//    		timeToRunChip = currTime + 16666;
//			chip.intervalCallback();
//    	}

		if(currTime >= nextFrameTime) {
    		for(uint16_t i = 0; i < 25; ++i) {
				uint8_t key = getKey();
				chip.runOne(key);
    		}

			display.update();
			duck = 0; for(uint8_t i = 0; i < 128; ++i) { display.drawPixel(i, 0, 0);} display.drawPixel(127, 0, 1);display.drawPixel(duck2++, 32, 1);
			for(uint8_t i = 0; i < 128; i+=10) { display.drawPixel(i, 3, 1);}
			nextFrameTime = currTime + 50000;
		} else {
			display.drawPixel(duck++ / 3, 0, 1);
		}
    }
}
