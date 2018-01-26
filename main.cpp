#include "mbed.h"

#include "SSD1306.h"
#include "GameData.h"
#include "games.h"
#include "NanoGameEngine.h"
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


uint8_t   gameCount;

uint8_t   mem[4096];
NanoGameEngine *gameEngine;
const GameData *currGame;

Ticker intervalTicker;

uint8_t lastKey;


uint8_t getGameCount(void)
{
	if(games[0].type == GT_EOL) {
		return 0;
	}

	uint8_t ret = 0;

	while(games[ret].type != GT_EOL) {
		++ret;
	}

	return ret - 1;
}


uint8_t pickGame(void)
{
	display.drawString(25, 0, "Select A Game");

	for(uint8_t i = 0; i < gameCount; ++i) {
		display.drawString(6, i * 8 + 8, games[i].name);
	}
	display.update();

	while(1) {}
	//TODO
	return 0;
}


uint8_t getCurrentKey(void)
{
	char ret = NGE_NOKEY;

	if (!up) {
		ret = currGame->keyMap[0];
	} else if (!down) {
		ret = currGame->keyMap[1];
	} else if (!left) {
		ret = currGame->keyMap[2];
	} else if (!right) {
		ret = currGame->keyMap[3];
	} else if (!center) {
		ret = currGame->keyMap[4];
	} else if (!action1) {
		ret = currGame->keyMap[5];
	} else if (!action2) {
		ret = currGame->keyMap[6];
	}

	return ret;
}


uint8_t getKey(void)
{
	uint8_t ret = NGE_NOKEY;
	char    key = getCurrentKey();

	if(key != lastKey) {
		ret = key;
	}

	lastKey = key;

	return ret;
}



int main()
{
	i2c.frequency(400000);

	display.setScreenFlipped(true);

	display.fillScreen(0);
	display.update();

	//BEGIN MASTER LOOP
	gameCount = getGameCount();
	uint8_t currGameIdx = pickGame();


	// BEGIN NEW GAME
	lastKey = NGE_NOKEY;

	currGame = &games[currGameIdx];
	gameEngine = (NanoGameEngine *)new Chip8();
	gameEngine->loadMemory(mem, currGame->data, currGame->size);
	gameEngine->init(mem, sizeof(mem), &display);

	uint32_t nextFrameTime = 0;

	intervalTicker.attach_us(Callback<void()>(gameEngine, &NanoGameEngine::intervalCallback), 16666);

	const int microsconstPerFrame = 1000000 / currGame->framesPerSecond;
	const int instructionsPerFrame = currGame->instructionsPerSecond / currGame->framesPerSecond;

    while(true) {
    	uint32_t currTime = us_ticker_read();

		if(currTime >= nextFrameTime) {
    		for(uint16_t i = 0; i < instructionsPerFrame; ++i) {
				uint8_t key = getKey();

				//TODO Test if exit key pressed

				gameEngine->runOne(key);
    		}

			display.update();
			nextFrameTime = currTime + microsconstPerFrame;
		}
    }
    // END NEW GAME
    // END MASTER LOOP
}
