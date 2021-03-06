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

#ifndef SPLASHSCREEN_H_
#define SPLASHSCREEN_H_


#define SplashScreen_width 128
#define SplashScreen_height 64

static const uint8_t SplashScreen_bits[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x1f,0x0f,0x80,0x00,0x00,0x00,0x00,0x1f,0xf0,0x00,0x00,0x00,0x07,0xc0,0x00,0x00
	,0x1f,0x0f,0x80,0x00,0x00,0x00,0x00,0x1f,0xf0,0x00,0x00,0x00,0x07,0xc0,0x00,0x00
	,0x1f,0x3c,0x01,0xff,0x01,0xe0,0xf0,0x78,0x3c,0x07,0xfc,0x00,0x07,0xc0,0x7f,0xc0
	,0x1f,0x3c,0x01,0xff,0x01,0xe0,0xf0,0x78,0x3c,0x07,0xfc,0x00,0x07,0xc0,0x7f,0xc0
	,0x1f,0x3c,0x01,0xff,0x01,0xe0,0xf0,0x78,0x3c,0x07,0xfc,0x00,0x07,0xc0,0x7f,0xc0
	,0x1f,0xf0,0x07,0xc3,0xc1,0xe0,0xf0,0x78,0x00,0x00,0x0f,0x01,0xff,0xc3,0xe1,0xf0
	,0x1f,0xf0,0x07,0xc3,0xc1,0xe0,0xf0,0x78,0x00,0x00,0x0f,0x01,0xff,0xc3,0xe1,0xf0
	,0x1f,0xf0,0x07,0xff,0xc1,0xe0,0xf0,0x78,0x00,0x07,0xff,0x07,0x87,0xc3,0xff,0xf0
	,0x1f,0xf0,0x07,0xff,0xc1,0xe0,0xf0,0x78,0x00,0x07,0xff,0x07,0x87,0xc3,0xff,0xf0
	,0x1f,0x3c,0x07,0xc0,0x00,0x7f,0xf0,0x78,0x3c,0x1e,0x0f,0x07,0x87,0xc3,0xe0,0x00
	,0x1f,0x3c,0x07,0xc0,0x00,0x7f,0xf0,0x78,0x3c,0x1e,0x0f,0x07,0x87,0xc3,0xe0,0x00
	,0x1f,0x0f,0x81,0xff,0x00,0x03,0xc0,0x1f,0xf0,0x07,0xff,0x01,0xff,0xc0,0x7f,0xc0
	,0x1f,0x0f,0x81,0xff,0x00,0x03,0xc0,0x1f,0xf0,0x07,0xff,0x01,0xff,0xc0,0x7f,0xc0
	,0x1f,0x0f,0x81,0xff,0x00,0x03,0xc0,0x1f,0xf0,0x07,0xff,0x01,0xff,0xc0,0x7f,0xc0
	,0x00,0x00,0x00,0x00,0x01,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x01,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xc1,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xc1,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xf9,0xe0,0x3f,0xe0,0x3f,0xf8,0x03,0xfe,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xf9,0xe0,0x3f,0xe0,0x3f,0xf8,0x03,0xfe,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xf9,0xe0,0x3f,0xe0,0x3f,0xf8,0x03,0xfe,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xff,0xe0,0x00,0x78,0x3c,0x1e,0x0f,0x07,0x80,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xff,0xe0,0x00,0x78,0x3c,0x1e,0x0f,0x07,0x80,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xff,0xe0,0x3f,0xf8,0x3c,0x1e,0x0f,0x07,0x80,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xff,0xe0,0x3f,0xf8,0x3c,0x1e,0x0f,0x07,0x80,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xc7,0xe0,0xf0,0x78,0x3c,0x1e,0x0f,0x07,0x80,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xc7,0xe0,0xf0,0x78,0x3c,0x1e,0x0f,0x07,0x80,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xc1,0xe0,0x3f,0xf8,0x3c,0x1e,0x03,0xfe,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x03,0xc1,0xe0,0x3f,0xf8,0x3c,0x1e,0x03,0xfe,0x00,0x00,0x00,0x00
	,0x00,0x18,0x00,0x03,0xc1,0xe0,0x3f,0xf8,0x3c,0x1e,0x03,0xfe,0x00,0x00,0x00,0x00
	,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xcf,0xc0
	,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xcf,0xc0
	,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xcf,0xf0
	,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xcf,0xf0
	,0x00,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0f,0x00
	,0x00,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0f,0x00
	,0x00,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0xf0
	,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0xf0
	,0x0c,0x66,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xcf,0x00
	,0x07,0xdb,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xcf,0x00
	,0x03,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0xff,0xc0
	,0x07,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0xff,0xc0
	,0x0c,0x3c,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x3f,0xc0
	,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x3f,0xc0
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	};



#endif /* SPLASHSCREEN_H_ */
