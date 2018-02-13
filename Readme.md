KeyCade Nano
============

A Keychain size game console that plays SCHIP-8 Games, and more.

Building
--------
You can find instructions on building this project [here](Documentation/Building.md).

Software
--------
The KeyCade Nano supports programs written in:

* [CHIP-8](https://en.wikipedia.org/wiki/CHIP-8) — A Virtual Machine for 
  writing simple games. Originally created for the RCA COSMAC VIP computer. 
  For information the [S]CHIP-8 Instruction set, and hints at its 
  implementation, please check out 
  [Cowgod's Chip-8 Technical Reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)
* [EmbedVM](http://www.clifford.at/embedvm/) — A more generic VM for embedded 
  systems. Clifford Wolf created a emulator for an imaginary 16-bit CPU
  and then a compiler for a [Small-C](https://en.wikipedia.org/wiki/Small-C) 
  like language.
* [uBASIC](https://github.com/jockm/ubasic).  I created a fork of Adam 
  Dunkels' exceptionally simple BASIC interpreter.  It was added as an
  amusement more than anything else, but it can be used to write real code.
  The "About" page on the main menu is written in it (See `Games/About.h` 
  for an example).


Hardware
--------
The KeyCade Nano is (currently) built around the following hardware:

* 0.96" 128x64 Pixel Monochrom OLED Display
* A 5-Way Tactile Switch (aka "the joystick")
* Two tactile buttons: [A] — the top, and [B] - the bottom.
* A [STM32L432KC](http://www.st.com/en/microcontrollers/stm32l432kc.html) 
Low Power ARM Cortex-M4 Mirocontroller:
    * 64K SRAM
    * 256K of Flash
    * 80Mhz 
	

![Open Source Hardware Logo](https://i2.wp.com/www.oshwa.org/wp-content/uploads/2014/03/oshw-logo-100-px.png?resize=95%2C100)

Just as the software for the KeyCade Nano is open source, the hardware is 
also available under a [OSHW compatabile license](https://www.oshwa.org).  Please see the 
[KeyCadeNano Hardware Repository](https://github.com/jockm/KeyCadeNanoHardware)
for more information.

Limitations & Future Plans
--------------------------
Not all [S]CHIP-8 programs are known to work.  Some require the full 16-key 
keyboard, and as such will never be able to work on the hardware as it 
currently is.  Others fail for as yet undetermined reasons, such as the game
_Ant_.  

Currently all game engines are limited to 4K of executable code.  While this
is (more than) enough for many types games, but people will always want more.
While the hardware currently 64K of SRAM, future editions — should they ever
exist — are likely to support much less. So we are sticking with this number 
for now.  You are free to expand this as you see fit.

There is no persistant storage, no way of saving games, high scores, or the 
like.  In the future a portion of cartridge space may be put aside for app
based storage.


Copyrights & License
--------------------
All of the CHIP-8 Games have come from one of the following public archives:

* [Mir3z'w Javascript CHIP-8 Emulator](https://github.com/mir3z/chip8-emu)
* [Dmatlack's CHIP-8 Emulator](https://github.com/dmatlack/chip8)
* [SVision-8: CHIP-8 and SCHIP emulator](http://devernay.free.fr/hacks/chip8/)
* [David Winter's CHIP-8 emulation page](http://pong-story.com/chip8/)
* [Zophar's Domain](https://www.zophar.net/pdroms/chip8)

Except where otherwise noted, all files in the project are covered by
the MIT License as follows:

Copyright (c) 2018 Jock Murphy. jock@jockmurphy.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 