/*
 * Cartridge.cpp
 *
 *  Created on: Jan 12, 2018
 *      Author: jock
 */

#include <Cartridge.h>

Cartridge::Cartridge(I2C *i2c) {
	this->i2c = i2c;
	this->size = 0;
}

Cartridge::~Cartridge() {
	// Nothing
}

