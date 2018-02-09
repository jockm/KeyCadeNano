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
	this->sendCommand(this->displayHeight == 32 ? 0x02 : 0x12);

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
	this->transferInProgress = false;
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

	memcpy(transferBuffer + 1, this->displayBuffer, sizeof(this->displayBuffer));
	this->i2c->write(this->i2cAddr, (const char *) this->transferBuffer, sizeof(this->displayBuffer) + 1);
}


void SSD1306::updateAsync()
{
	// Abord if a transfer is already happening
	if(this->transferInProgress) {
		return;
	}

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

	event_callback_t callbackEvent;
	callbackEvent.attach(this, &SSD1306::transferCallback);

	this->transferInProgress = true;
	memcpy(transferBuffer + 1, this->displayBuffer, sizeof(this->displayBuffer));
	this->i2c->transfer(this->i2cAddr, (const char *) transferBuffer, sizeof(this->displayBuffer) + 1, (char *)transferResponseBuffer, sizeof(transferResponseBuffer), callbackEvent);
}


void SSD1306::drawBitmap(uint8_t x, uint8_t y, uint8_t *bitmap, uint8_t w, uint8_t h)
{
	uint16_t bytePos = 0;
	int8_t bitPos = 7;

	uint8_t currByte = bitmap[bytePos++];

	for(int yPos = y; yPos < y + h; ++yPos) {
		for(int xPos = x; xPos < x + w; ++xPos) {
			uint8_t c = currByte & (1 << bitPos--);
			this->drawPixel(xPos, yPos, c);

			if(bitPos < 0) {
				currByte = bitmap[bytePos++];
				bitPos = 7;
			}
		}
	}
}


bool SSD1306::xorBitmap(uint8_t x, uint8_t y, uint8_t *bitmap, uint8_t w, uint8_t h)
{
	bool ret = false;

	uint16_t bytePos = 0;
	int8_t bitPos = 7;

	uint8_t currByte = bitmap[bytePos++];

	for(int yPos = y; yPos < y + h; ++yPos) {
		for(int xPos = x; xPos < x + w; ++xPos) {
			uint8_t c = currByte & (1 << bitPos--);
			bool col = this->xorPixel(xPos, yPos, c);

			ret |= col;

			if(bitPos < 0) {
				currByte = bitmap[bytePos++];
				bitPos = 7;
			}
		}
	}

	return ret;
}


void SSD1306::drawChar(uint8_t x, uint8_t y, const char ch, uint8_t color)
{
	const uint8_t *fontChar = font + ((uint16_t) ch * 5);

	for(uint8_t xOffset = 0; xOffset < 5; ++xOffset) {
		for(uint8_t yOffset = 0; yOffset < 7; ++yOffset) {
			uint8_t pixel = (fontChar[xOffset] >> yOffset) & 1;

			this->drawPixel(x + xOffset, y + yOffset, color ? pixel : !pixel);
		}
	}
}

void SSD1306::scrollLeft(uint8_t n, uint8_t fromY, uint8_t toY)
{
	uint8_t targetX = 0;
	uint8_t sourceX = targetX + n;
	uint8_t colCount = this->displayWidth - n;

	for(uint8_t i = 0; i < colCount; ++i) {
		for(uint8_t y = fromY; y < toY; ++y) {
			uint8_t c = this->getPixel(sourceX, y);
			this->drawPixel(targetX, y, c);
		}

		++sourceX;
		++targetX;
	}


	for(uint8_t x = this->displayWidth - n; x < this->displayWidth; ++x) {
		for(uint8_t y = fromY; y < toY; ++y) {
			this->drawPixel(x, y, 0);
		}
	}
}


void SSD1306::scrollRight(uint8_t n, uint8_t fromY, uint8_t toY)
{
	uint8_t targetX = this->displayWidth - 1;
	uint8_t sourceX = targetX - n;
	uint8_t colCount = this->displayWidth - n;

	for(uint8_t i = 0; i < colCount; ++i) {
		for(uint8_t y = fromY; y < toY; ++y) {
			uint8_t c = this->getPixel(sourceX, y);
			this->drawPixel(targetX, y, c);
		}

		--sourceX;
		--targetX;
	}


	for(uint8_t x = 0; x < n; ++x) {
		for(uint8_t y = fromY; y < toY; ++y) {
			this->drawPixel(x, y, 0);
		}
	}
}


void SSD1306::scrollUp(uint8_t n, uint8_t fromX, uint8_t toX)
{
	uint8_t targetY = 0;
	uint8_t sourceY = targetY + n;
	uint8_t rowCount = this->displayHeight - n;

	for(uint8_t i = 0; i < rowCount; ++i) {
		for(uint8_t x = 0; x < this->displayWidth; ++x) {
			uint8_t c = this->getPixel(x, sourceY);
			this->drawPixel(x, targetY, c);
		}

		++sourceY;
		++targetY;
	}

	for(uint8_t y = this->displayHeight - n; y < this->displayHeight; ++y) {
		for(uint8_t x = fromX; x < toX; ++x) {
			this->drawPixel(x, y, 0);
		}
	}
}


void SSD1306::scrollDown(uint8_t n, uint8_t fromX, uint8_t toX)
{
	uint8_t targetY = this->displayHeight - 1;
	uint8_t sourceY = targetY - n;
	uint8_t rowCount = this->displayHeight - n;

	for(uint8_t i = 0; i < rowCount; ++i) {
		for(uint8_t x = 0; x < this->displayWidth; ++x) {
			uint8_t c = this->getPixel(x, sourceY);
			this->drawPixel(x, targetY, c);
		}

		--sourceY;
		--targetY;
	}

	for(uint8_t y = 0; y < n; ++y) {
		for(uint8_t x = fromX; x < toX; ++x) {
			this->drawPixel(x, y, 0);
		}
	}
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
