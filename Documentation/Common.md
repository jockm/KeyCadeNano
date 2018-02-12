Commonalities
=============

#### Display
The display if the KeyCade Nano is a Black and White (1-bit per pixel) 
OLED with a resolution of 128x64 pixels.

Because the display uses the *comparatively* slow I^2^C bus — as opposed 
to the much faster SPI interface — your maximum frame rate is somewhat 
limited.  Technically the display can operate at 30FPS, but practically 
you should consider a frame rate between 20 and 25 FPS.

#### Memory
All programs, regardless of Game Engine, are limited to a program size of 
no more than 4096 byte (4K). Some Game Engines (for example uBasic) may 
store variables, and stack, external to the program, but you should not 
count on it.

#### Execution Throttling

The `instructionsPerSecond` field in the `GameData` structure indicates how
many "instructions" are to be executed per second.  A instruction is defined
as how many times the `runOne(...)` method in the Game Engine is called.  

Most games will not want to use hrottling, and should set the 
`instructionsPerSecond` field to `0` to allow as many instructions as possible
to be executed.

#### Display Updating

Progams have to options.  They can either have the system update the display
on a regular basis, or they can indicate when they want the screen to be
updated.  Techincally it would be possible to do both, but this would not be
the best idea.

To indicate that the program is in charge of screen updates se the
`framesPerSecond` field in the `GameData` structure to `0`.

Any other value will indicate the number of times per second that the screen
should be updated.  As mentioned above, the maximum framerate should probably
be between 20 to 25 FPS. 

#### Keyboard
The Keyboard Consists of a 5 way tactile switch (aka "joystick") and two control buttons layed out like this:
```			
   [U]    [A]
[L][C][R]
   [D]    [B]
```

No more than one keypress can be registered at a time, and the keys have the following precidence (from most to least):

1. `[U]` (Up)
2. `[D]` (Down)
3. `[L]` (Left)
4. `[R]` (Right)
5. `[C]` (Center)
6. `[A]` (A)
7. `[B]` (B)

This means that if the user is pressing `[U]` and `[L]` then the key `[U]` will be returned.  Likewise if `[A]` and `[B]` are pressed at the same time then `[A]` will be returned.

The KeyCade Nano doesn't have a fixed mapping for they keyboard, instead a mapping is estabilished in the program's associated GameData structure.  Each key will return a single 0..255 value for each of the seven keys.

Care should be used mapping the `[C]` key as it *can* be easy to press when pressing the joystick in one of the ordinal directions.


#### Keymapping
TODO: Write this

#### GameData Data Structure

Every game must be represented by a `GameData` structure, either in the
 `games.h` array, or in the Cartridge Header (see
```C++
typedef struct {
	GameType       type;
	uint16_t       instructionsPerSecond;
	uint8_t        framesPerSecond;
	uint16_t       flags;
	const char    *name;
	const char    *keyMap;
	const char    *instuctions;
	uint16_t       codeStart;
	const uint8_t *data;
	uint16_t       size;
} GameData;
```

| Field                 | Definition                                                          |
| --------------------- | ------------------------------------------------------------------- |
| type                  | What `GameEngine` should be used
| instructionsPerSecond | How many instructions per second should be executed (see: Execution Throttling)
| framesPerSecond       | How many times per second should the display be uptated (see: Display Updating)
| flags                 | Flags to pass into the game engine. Currently none defined
| name                  | The name of the program (no more than 20 characters)
| keyMap                | The map of button presses to what is passed to the game engine (see Key Mapping)
| instuctions           | Optional. Not implemented. A page of text to be displayed before the game starts.  No more than 168 characters
| codeStart             | The byte offet into the program where execution begins.  For CHIP-8 this is normally `0x200`; for EmbedVM this will vary based on the location of the `main` function; and for uBASIC it will be `0x0` 
| data                  | Pointer to memory (or location in the cartridge) of the program.
| size                  | The size (in bytes) of the program.  Currently this can be no more than 4K (4096 bytes)

 

