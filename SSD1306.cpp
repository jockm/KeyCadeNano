#include "mbed.h"
#include <Font.h>
#include "SSD1306.h"


#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A




void SSD1306::initDisplay()
{
	uint8_t vccState = SSD1306_SWITCHCAPVCC;

	this->sendCommand(SSD1306_DISPLAYOFF);
	this->sendCommand(SSD1306_SETDISPLAYCLOCKDIV);
	this->sendCommand(0x80);                                  // the suggested ratio 0x80

	this->sendCommand(SSD1306_SETMULTIPLEX);
	this->sendCommand(this->displayHeight-1);

	this->sendCommand(SSD1306_SETDISPLAYOFFSET);
	this->sendCommand(0x0);                                   // no offset

	this->sendCommand(SSD1306_SETSTARTLINE | 0x0);            // line #0

	this->sendCommand(SSD1306_CHARGEPUMP);
	this->sendCommand((vccState == SSD1306_EXTERNALVCC) ? 0x10 : 0x14);

	this->sendCommand(SSD1306_MEMORYMODE);
	this->sendCommand(0x00);                                  // 0x0 act like ks0108

	this->sendCommand(SSD1306_SEGREMAP | 0x1);

	this->sendCommand(SSD1306_COMSCANDEC);

	this->sendCommand(SSD1306_SETCOMPINS);
	this->sendCommand(this->displayHeight == 32 ? 0x02 : 0x12);        // TODO - calculate based on _rawHieght ?

	this->sendCommand(SSD1306_SETCONTRAST);
	this->sendCommand(this->displayHeight == 32 ? 0x8F : ((vccState == SSD1306_EXTERNALVCC) ? 0x9F : 0xCF) );

	this->sendCommand(SSD1306_SETPRECHARGE);
	this->sendCommand((vccState == SSD1306_EXTERNALVCC) ? 0x22 : 0xF1);

	this->sendCommand(SSD1306_SETVCOMDETECT);
	this->sendCommand(0x40);

	this->sendCommand(SSD1306_DISPLAYALLON_RESUME);

	this->sendCommand(SSD1306_NORMALDISPLAY);

	this->sendCommand(SSD1306_DISPLAYON);


	this->sendCommand(SSD1306_DISPLAYOFF);                    // 0xAE
	this->sendCommand(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
	this->sendCommand(0x80);                                  // the suggested ratio 0x80

	this->sendCommand(SSD1306_SETMULTIPLEX);                  // 0xA8
	this->sendCommand(this->displayHeight - 1);

	this->sendCommand(SSD1306_SETDISPLAYOFFSET);              // 0xD3
	this->sendCommand(0x0);                                   // no offset
	this->sendCommand(SSD1306_SETSTARTLINE | 0x0);            // line #0
	this->sendCommand(SSD1306_CHARGEPUMP);                    // 0x8D
	this->sendCommand((vccState == SSD1306_EXTERNALVCC) ? 0x10 : 0x14);

	this->sendCommand(SSD1306_MEMORYMODE);                    // 0x20
	this->sendCommand(0x00);                                  // 0x0 act like ks0108
	this->sendCommand(SSD1306_SEGREMAP | 0x1);
	this->sendCommand(SSD1306_COMSCANDEC);

	if(this->displayHeight == 32) {
		// 128x32
		this->sendCommand(SSD1306_SETCOMPINS);                    // 0xDA
		this->sendCommand(0x02);
		this->sendCommand(SSD1306_SETCONTRAST);                   // 0x81
		this->sendCommand(0x8F);
	} else if(this->displayHeight == 64) {
		// 128x64
		this->sendCommand(SSD1306_SETCOMPINS);                    // 0xDA
		this->sendCommand(0x12);
		this->sendCommand(SSD1306_SETCONTRAST);                   // 0x81
		this->sendCommand((vccState == SSD1306_EXTERNALVCC) ? 0x9F : 0xCF);
	} else {
		// 96x16
		this->sendCommand(SSD1306_SETCOMPINS);                    // 0xDA
		this->sendCommand(0x2);   //ada x12
		this->sendCommand(SSD1306_SETCONTRAST);                   // 0x81
		this->sendCommand((vccState == SSD1306_EXTERNALVCC) ? 0x10 : 0xAF);
	}

	this->sendCommand(SSD1306_SETPRECHARGE);                  // 0xd9
	this->sendCommand((vccState == SSD1306_EXTERNALVCC) ? 0x22 : 0xF1);
	this->sendCommand(SSD1306_SETVCOMDETECT);                 // 0xDB
	this->sendCommand(0x40);
	this->sendCommand(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
	this->sendCommand(SSD1306_NORMALDISPLAY);                 // 0xA6

	this->sendCommand(SSD1306_DEACTIVATE_SCROLL);

	this->sendCommand(SSD1306_DISPLAYON);//--turn on oled panel


}

void SSD1306::transferCallback(int foo)
{

}


void SSD1306::update()
{
	this->sendCommand(SSD1306_COLUMNADDR);
	this->sendCommand(0);   // Column start address (0 = reset)
	this->sendCommand(this->displayWidth - 1); // Column end address (127 = reset)

	this->sendCommand(SSD1306_PAGEADDR);
	this->sendCommand(0); // Page start address (0 = reset)

	uint8_t pageAddr = 0;
	if(this->displayHeight == 16) {
		pageAddr = 1;
	} else if(this->displayHeight == 16) {
		pageAddr = 3;
	} else {
		pageAddr = 7;
	}
	this->sendCommand(pageAddr); // Page end address

	transferBuffer[0] = 0x40;

#if defined(SSD1306_TRANSFRER_ASYNC)
	event_callback_t callbackEvent;
	callbackEvent.attach(this, &SSD1306::transferCallback);

	memcpy(transferBuffer + 1, this->displayBuffer, sizeof(this->displayBuffer));
	this->i2c->transfer(this->i2cAddr, (const char *) transferBuffer, sizeof(this->displayBuffer) + 1, (char *)transferResponseBuffer, sizeof(transferResponseBuffer), callbackEvent);
#elif defined(SSD1306_TRANSFRER_SYNC_WHOLE)
	memcpy(transferBuffer + 1, this->displayBuffer, sizeof(this->displayBuffer));
	this->i2c->write(this->i2cAddr, (const char *) this->transferBuffer, sizeof(this->displayBuffer) + 1);
#else
	// send display buffer in 16 byte chunks
	for(uint16_t i= 0; i < bufferSize; i += 16 )
	{
		memcpy(this->transferBuffer + 1, this->displayBuffer + i, 17);
		this->i2c->write(this->i2cAddr, (const char *) this->transferBuffer, 17);
	}
#endif

}


void SSD1306::drawBitmap(uint8_t x, uint8_t y, uint8_t *bitmap, uint8_t w, uint8_t h)
{
	uint16_t byteIdx = 0;
	uint16_t bitIdx = 7;
	uint8_t  currByte;

	for(uint8_t bitmapY = y; bitmapY < y + h; ++bitmapY) {
		currByte = bitmap[byteIdx];

		for(uint8_t bitmapX = x; bitmapX < x + w; ++bitmapX) {
			uint8_t pixel = (currByte >> bitIdx) & 1;

			this->drawPixel(bitmapX, bitmapY, pixel);

			if(bitIdx == 0) {
				currByte = bitmap[++byteIdx];
				bitIdx = 7;
			} else {
				--bitIdx;
			}
		}
	}
}


void SSD1306::xorBitmap(uint8_t x, uint8_t y, uint8_t *bitmap, uint8_t w, uint8_t h)
{
	uint16_t byteIdx = 0;
	uint16_t bitIdx = 7;

	for(uint8_t bitmapY = y; bitmapY < y + h; ++bitmapY) {
		for(uint8_t bitmapX = x; bitmapX < x + w; ++bitmapX) {
			uint8_t pixel = (bitmap[byteIdx] >> bitIdx) & 1;

			if(bitmapY < this->displayHeight) {
				if(bitmapX < this->displayWidth) {
					this->xorPixel(bitmapX, bitmapY, pixel);
				}
			}

			if(bitIdx == 0) {
				++byteIdx;
				bitIdx = 7;
			} else {
				--bitIdx;
			}
		}
	}
}


void SSD1306::drawChar(uint8_t x, uint8_t y, const char ch)
{
	const uint8_t *fontChar = font + ((uint16_t) ch * 5);

	for(uint8_t xOffset = 0; xOffset < 5; ++xOffset) {
		for(uint8_t yOffset = 0; yOffset < 7; ++yOffset) {
			uint8_t pixel = (fontChar[xOffset] >> yOffset) & 1;

			this->drawPixel(x + xOffset, y + yOffset, pixel);
		}
	}
}

void SSD1306::scrollLeft(uint8_t n)
{
	// todo implement me
}


void SSD1306::scrollRight(uint8_t n)
{
	// todo implement me
}


void SSD1306::scrollUp(uint8_t n)
{
	// todo implement me
}


void SSD1306::scrollDown(uint8_t n)

{
	// todo implement me
}



void SSD1306::sendData(uint8_t d)
{
	this->transferBuffer[0] = 0x40; // Data Mode
	this->transferBuffer[1] = d;
	this->i2c->write(this->i2cAddr, (const char *)this->transferBuffer, 2);
}


void SSD1306::sendCommand(uint8_t c)
{
	this->transferBuffer[0] = 0; // Command Mode
	this->transferBuffer[1] = c;
	this->i2c->write(this->i2cAddr, (const char *)this->transferBuffer, 2);
}
