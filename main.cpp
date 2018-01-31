#include "mbed.h"

#include "SSD1306.h"
#include "GameData.h"
#include "games.h"
#include "NanoGameEngine.h"
#include "Chip8.h"


#define _MAX(a,b) ((a)<(b))?(b):(a)
#define _MIN(a,b) !((b)<(a))?(a):(b);

enum {
	RAWKEY_NONE    = NGE_NOKEY,
	RAWKEY_EXIT    = NGE_EXIT,

	RAWKEY_UP      = 0,
	RAWKEY_DOWN    = 1,
	RAWKEY_LEFT    = 2,
	RAWKEY_RIGHT   = 3,
	RAWKEY_CENTER  = 4,
	RAWKEY_ACTION1 = 5,
	RAWKEY_ACTION2 = 6,
};



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

//PwmOut    speaker(PA_1);
//AnalogOut    speakerDac(PA_4);
//PwmOut    speaker(PA_1);
//AnalogOut    speakerDac(PA_4);


uint8_t   gameCount;

uint8_t   mem[4096];
NanoGameEngine *gameEngine;
const GameData *currGame;

Ticker intervalTicker;

uint8_t lastKey;
uint8_t lastMenuKey;


uint8_t getGameCount(void)
{
	if(games[0].type == GT_EOL) {
		return 0;
	}

	uint8_t ret = 0;

	while(games[ret].type != GT_EOL) {
		++ret;
	}

	return ret;
}

uint8_t getRawCurrentKey(void)
{
	char ret = NGE_NOKEY;

	if(!center && !action1 && !action2) {
		ret = NGE_EXIT;
	} else if (!up) {
		ret = RAWKEY_UP;
	} else if (!down) {
		ret = RAWKEY_DOWN;
	} else if (!left) {
		ret = RAWKEY_LEFT;
	} else if (!right) {
		ret = RAWKEY_RIGHT;
	} else if (!center) {
		ret = RAWKEY_CENTER;
	} else if (!action1) {
		ret = RAWKEY_ACTION1;
	} else if (!action2) {
		ret = RAWKEY_ACTION2;
	}

	return ret;
}

uint8_t getCurrentGameKey(void)
{
	uint8_t ret = NGE_NOKEY;
	uint8_t key = getRawCurrentKey();

	if(key == RAWKEY_EXIT) {
		return NGE_EXIT;
	}

	if(key != NGE_NOKEY) {
		ret = currGame->keyMap[key];
	}

	return ret;
}


uint8_t getGameKey(void)
{
	uint8_t ret = NGE_NOKEY;
	char    key = getCurrentGameKey();

	if(key != lastKey) {
		ret = key;
	}

	lastKey = key;

	return ret;
}


uint8_t getMenuKey(void)
{
	uint8_t ret = NGE_NOKEY;
	while((ret = getRawCurrentKey()) == lastMenuKey) {
		wait_ms(50);
	}

	lastMenuKey = ret;

	return ret;
}

uint8_t pickGame(void)
{
	static const int linesPerPage = 6;

	bool done = false;

	lastMenuKey = NGE_NOKEY;
	uint8_t menuKey;

	int8_t currIdx = 0;
	int8_t pageTop = 0;
	int8_t pageEnd = _MIN(pageTop + linesPerPage, gameCount);

	bool updateMenu = true;

	while(!done) {
		if(updateMenu) {
			updateMenu = false;

			uint8_t yPos = 8;

			display.fillScreen(0);
			display.drawString(25, 0, "Select A Game");

			for(uint8_t i = pageTop; i < pageEnd; ++i) {
				if(i == currIdx) {
					display.drawChar(0, yPos, '>');
				}
				display.drawString(6, yPos, games[i].name);
				yPos += 8;
			}
			display.update();
		}


		menuKey = getMenuKey();

		if(menuKey == RAWKEY_UP && currIdx > 0) {
			updateMenu = true;

			if(--currIdx < pageTop) {
				pageTop = currIdx;
			}
		} else if(menuKey == RAWKEY_DOWN && currIdx < gameCount - 1) {
			updateMenu = true;

			if(++currIdx >= pageEnd) {
				++pageTop;
			}
		} else if(menuKey == RAWKEY_ACTION1 || menuKey == RAWKEY_ACTION2 || menuKey == RAWKEY_CENTER) {
			done = true;
		}

		pageEnd = _MIN(pageTop + linesPerPage, gameCount);
	}

	return currIdx;
}



void runGame(uint8_t gameIdx)
{
	bool done = false;

	display.fillScreen(0);
	display.update();

	lastKey = NGE_NOKEY;

	currGame = &games[gameIdx];

	//TODO use factory method to create game engine
	gameEngine = (NanoGameEngine *)new Chip8();
	gameEngine->loadMemory(mem, currGame->data, currGame->size);
	gameEngine->init(mem, sizeof(mem), &display);

	uint32_t nextFrameTime = 0;
	uint32_t nextDecrementTime = 0;

//	intervalTicker.attach_us(Callback<void()>(gameEngine, &NanoGameEngine::intervalCallback), 16666);

	const int microsconstPerFrame = 1000000 / currGame->framesPerSecond;
	const int instructionsPerFrame = currGame->instructionsPerSecond / currGame->framesPerSecond;

	while(!done) {
		uint32_t currTime = us_ticker_read();

		if(currTime >= nextFrameTime) {
			for(uint16_t i = 0; i < instructionsPerFrame; ++i) {
				if(us_ticker_read() >= nextDecrementTime) {
					gameEngine->intervalCallback();
					nextDecrementTime = us_ticker_read() + 16666;
				}
				uint8_t key = getCurrentGameKey();

				if(key == NGE_EXIT) {
					// TODO Should there be a confirmation screen?
					done = true;

					wait(0.5);
					break;
				}

				gameEngine->runOne(key);
			}

			//TODO make this async?
			display.update();
			nextFrameTime = currTime + microsconstPerFrame;
		}
	}

	delete gameEngine;
}


int main()
{
	i2c.frequency(400000);

	display.setScreenFlipped(true);

	display.fillScreen(0);
	display.update();

	gameCount = getGameCount();

	while(true) {
		uint8_t currGameIdx = pickGame();
		runGame(currGameIdx);
	}
}
