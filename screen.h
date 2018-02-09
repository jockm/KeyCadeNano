/*
 * screen.h
 *
 *  Created on: Jan 13, 2018
 *      Author: jock
 */

#ifndef SCREEN_H_
#	define SCREEN_H_

#	include "mbed.h"

enum {
	SCREEN_BLACK = 0,
	SCREEN_WHITE = 1,

	SCREEN_MAX_WIDTH = 128,
	SCREEN_MAX_HEIGHT = 128,
};
class Screen {
	public:
		virtual ~Screen() {};

		virtual void update() = 0;
		virtual void updateAsync() = 0;
		virtual void drawBitmap(uint8_t x, uint8_t y, uint8_t *bitmap, uint8_t w, uint8_t h) = 0;
		virtual bool xorBitmap(uint8_t x, uint8_t y, uint8_t *bitmap, uint8_t w, uint8_t h) = 0;
		virtual void drawChar(uint8_t x, uint8_t y, const char ch, uint8_t color = SCREEN_WHITE) = 0;
		virtual void drawRawPixel(uint8_t x, uint8_t y, uint8_t color) = 0;
		virtual void togglePixel(uint8_t x, uint8_t y) = 0;
		virtual bool xorPixel(uint8_t x, uint8_t y, uint8_t color) = 0;
		virtual bool xorRawPixel(uint8_t x, uint8_t y, uint8_t color) = 0;
		virtual uint8_t getPixel(uint8_t x, uint8_t y) = 0;
		virtual void fillScreen(uint8_t color) = 0;
		virtual void clearScreen() = 0;
		virtual void scrollLeft(uint8_t n, uint8_t from = 0, uint8_t to = SCREEN_MAX_WIDTH) = 0;
		virtual void scrollRight(uint8_t n, uint8_t from = 0, uint8_t to = SCREEN_MAX_WIDTH) = 0;
		virtual void scrollUp(uint8_t n, uint8_t from = 0, uint8_t to = SCREEN_MAX_HEIGHT) = 0;
		virtual void scrollDown(uint8_t n, uint8_t from = 0, uint8_t to = SCREEN_MAX_HEIGHT) = 0;
		virtual void drawString(uint8_t x, uint8_t y, const char *str, uint8_t color = SCREEN_WHITE) = 0;
};

#endif /* SCREEN_H_ */
