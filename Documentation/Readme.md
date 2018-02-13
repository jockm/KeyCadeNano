Writing programs for the KeyCade Nano
=====================================

*TL;DR I just want [A quick tutorial on writing your own programs](WritingYourProgram.md)*

While it would be possible to write new programs and games to the KeyCade Nano by forking the repository and modifying the code, this would not be the preferred approach .

Instead the KeyCade Nano supports a handful of interpreters and virtual machines to allow you to write in different languages:

* [EmbedVM](EmbedVM.md) — The game engine you probably want to use
* [CHIP-8](CHIP-8.md) — If you are into the 
  [CHIP-8](https://en.wikipedia.org/wiki/CHIP-8) scene
* [uBASIC](uBASIC.md) — If you really really must, use the tiniest basic around...but you probably don't.

Once you have picked the endine you want to use, you need to understand the [concepts common](Common..md) to all engines; and what [Useful tools](UsefulTools.md) to help you,

Once you have written your program you will need to put it on a [Cartridge](Cartridge.md).

[A quick tutorial on writing your own programs](WritingYourProgram.md)

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
