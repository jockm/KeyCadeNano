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
