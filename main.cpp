#include "mbed.h"

#include "SSD1306.h"
#include "Chip8.h"
#include "GameData.h"
#include "Games/tank.h"


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



const GameData games[] = {
//		 Type        IPS   FPS	Name                      U  D  L  R  C  1  2   Instructions Data         Size
//       ___________ ____  ___  ______________________ ______________________   ____________ ____________ _______________________
		{GT_CHIP8,    500,  25, "Tank",                "\x2\x8\x6\x4\xc\x1\x2", NULL,        game_tank,    sizeof(game_tank)},
		{GT_EOL,        0,   0, NULL,                  NULL,                    NULL,        NULL,        0}
};

uint8_t   mem[4096];
Chip8     chip;
const GameData *currGame;

Ticker intervalTicker;

uint8_t lastKey;

uint8_t getKey(void) {
	uint8_t ret = CHIP8_NOKEY;
	char    key = CHIP8_NOKEY;

	if (!up) {
		key = currGame->keyMap[0];
	} else if (!down) {
		key = currGame->keyMap[1];
	} else if (!left) {
		key = currGame->keyMap[2];
	} else if (!right) {
		key = currGame->keyMap[3];
	} else if (!center) {
		key = currGame->keyMap[4];
	} else if (!action1) {
		key = currGame->keyMap[5];
	} else if (!action2) {
		key = currGame->keyMap[6];
	}

	if(key != lastKey) {
		ret = key;
	}

	lastKey = key;

	return ret;
}


//void callback()
//{
//	chip.intervalCallback();
//}

int main()
{
	currGame = &games[0];
	memcpy(mem + 0x200, currGame->data, currGame->size);

	i2c.frequency(400000);

	display.setScreenFlipped(true);

	display.fillScreen(0);
	display.update();

	lastKey = CHIP8_NOKEY;

	chip.init(mem, sizeof(mem), &display);

	uint32_t nextFrameTime = 0;

	intervalTicker.attach_us(Callback<void()>(&chip, &Chip8::intervalCallback), 16666);

	const int microsconstPerFrame = 1000000 / currGame->framesPerSecond;
	const int instructionsPerFrame = currGame->instructionsPerSecond / currGame->framesPerSecond;

    while(true) {
    	uint32_t currTime = us_ticker_read();

		if(currTime >= nextFrameTime) {
    		for(uint16_t i = 0; i < instructionsPerFrame; ++i) {
				uint8_t key = getKey();
				chip.runOne(key);
    		}

			display.update();
			nextFrameTime = currTime + microsconstPerFrame;
		}
    }
}
