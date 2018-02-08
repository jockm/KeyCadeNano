#ifndef SSD1306_H
#	define SSD1306_H

#	include "mbed.h"
#	include "screen.h"

#	define SSD1306_MAX_WIDTH 128
#	define SSD1306_MAX_HEIGHT 64

#	define SSD1306_BLACK 0
#	define SSD1306_WHITE 1

//#define SSD1306_TRANSFRER_ASYNC
#define SSD1306_TRANSFRER_SYNC_WHOLE
//#define SSD1306_TRANSFRER_SYNC_CHUNK


	class  SSD1306 : public Screen {
		public:
			SSD1306(I2C *i2cPort, uint8_t addr = 0x78, uint8_t width = SSD1306_MAX_WIDTH, uint8_t height = SSD1306_MAX_HEIGHT)
			{
				this->i2c = i2cPort;
				this->i2cAddr = addr;
				this->displayWidth = width;
				this->displayHeight = height;
				this->bufferSize = (this->displayWidth / 8) * this->displayHeight;

				this->screenFlipped = false;

				this->transferInProgress = false;

				this->initDisplay();
			};

			void update();
			void updateAsync();

			void drawBitmap(uint8_t x, uint8_t y, uint8_t *bitmap, uint8_t w, uint8_t h);
			void xorBitmap(uint8_t x, uint8_t y, uint8_t *bitmap, uint8_t w, uint8_t h);
			void drawChar(uint8_t x, uint8_t y, const char ch, uint8_t color = 1);

			void scrollLeft(uint8_t n, uint8_t from = 0, uint8_t to = SSD1306_MAX_WIDTH);
			void scrollRight(uint8_t n, uint8_t from = 0, uint8_t to = SSD1306_MAX_WIDTH);
			void scrollUp(uint8_t n, uint8_t from = 0, uint8_t to = SSD1306_MAX_HEIGHT);
			void scrollDown(uint8_t n, uint8_t from = 0, uint8_t to = SSD1306_MAX_HEIGHT);


			inline void drawRawPixel(uint8_t x, uint8_t y, uint8_t color)
			{
				uint8_t pixelByte = this->displayBuffer[x+ (y / 8) * this->displayWidth];

				if(color) {
					pixelByte |= 1 << (y & 7);
				} else {
					pixelByte &= ~(1 << (y & 7));
				}

				this->displayBuffer[x+ (y / 8) * this->displayWidth] = pixelByte;
			}


			inline void drawPixel(uint8_t x, uint8_t y, uint8_t color)
			{
				if(y >= this->displayHeight || x >= this->displayWidth) {
					return;
				}

				x = this->screenFlipped ? this->displayWidth - 1 - x : x;
				y = this->screenFlipped ? this->displayHeight - 1 - y : y;

				this->drawRawPixel(x, y, color);
			}


			inline void togglePixel(uint8_t x, uint8_t y)
			{
				uint8_t pixel = this->getPixel(x, y);
				this->drawPixel(x, y, !pixel);
			}


			inline bool xorRawPixel(uint8_t x, uint8_t y, uint8_t color)
			{
				uint8_t pixel = this->getRawPixel(x, y);
				color = !!color;

				bool ret = pixel && color;

				this->drawRawPixel(x, y, pixel ^ color);

				return ret;
			}

			inline bool xorPixel(uint8_t x, uint8_t y, uint8_t color)
			{
				uint8_t pixel = this->getPixel(x, y);
				color = color ? 1 : 0;

				bool ret = pixel && color;

				this->drawPixel(x, y, pixel ^ color);

				return ret;
			}


			inline uint8_t getRawPixel(uint8_t x, uint8_t y)
			{
				uint8_t pixelByte = this->displayBuffer[x+ (y / 8) * this->displayWidth];

				uint8_t ret = pixelByte & (1 << (y & 7));

				return !!ret;
			}

			inline uint8_t getPixel(uint8_t x, uint8_t y)
			{
				if(y >= this->displayHeight || x >= this->displayWidth) {
					return 0;
				}

				x = this->screenFlipped ? this->displayWidth - 1 - x : x;
				y = this->screenFlipped ? this->displayHeight - 1 - y : y;

				uint8_t ret = this->getRawPixel(x, y);

				return ret;
			}


			inline void fillScreen(uint8_t color)
			{
				uint8_t fillByte = (color != SSD1306_BLACK) ? 0xFF : 0x00;
				memset(this->displayBuffer, fillByte, this->bufferSize);
			};


			inline void clearScreen() {
				this->fillScreen(SSD1306_BLACK);
			};


			void drawString(uint8_t x, uint8_t y, const char *str, uint8_t c = 1)
			{
				uint16_t xPos = x;
				for(uint16_t i = 0; i < strlen(str); ++i) {
					if(str[i] == '\n') {
						xPos = x;
						y += 8;

						continue;
					}

					this->drawChar(xPos, y, str[i], 1);

					xPos += 6;
				}
			}

			bool isScreenFlipped() const {
				return screenFlipped;
			}

			void setScreenFlipped(bool screenFlipped) {
				this->screenFlipped = screenFlipped;
			}

			uint8_t getDisplayHeight() const {
				return displayHeight;
			}

			uint8_t getDisplayWidth() const {
				return displayWidth;
			}

		private:
			void initDisplay();
			void sendCommand(uint8_t c);
			void sendData(uint8_t c);

			void transferCallback(int foo);


			I2C      *i2c;
			uint8_t   i2cAddr;
			uint8_t   displayWidth;
			uint8_t   displayHeight;
			uint16_t  bufferSize;
			bool      screenFlipped;

			uint8_t   displayBuffer[(SSD1306_MAX_WIDTH / 8) * SSD1306_MAX_HEIGHT];
			uint8_t   transferBuffer[sizeof(displayBuffer) + 1];
			uint8_t   transferResponseBuffer[10];

			volitile bool transferInProgress;

	};
#endif
