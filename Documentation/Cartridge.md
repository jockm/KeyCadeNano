Building Cartridges
===================

*TODO* Write some text here


Cartridge Memory Layout
-----------------------

Note: all addresses are in [Hexadecimal](https://en.wikipedia.org/wiki/Hexadecimal]), offsets are in decimal, and all values are stored [Big Endian](https://en.wikipedia.org/wiki/Endianness).

### Cartridge Header

The cartridge header is at the beginning of the cartridge and has a maximum size of 256 bytes.

| Address | Length | Name           | Description            
| ------: | ------: | :------------ | :-------------------
| 0       |       2 | Cartridge ID  | `0x4B`, `0x43`, `0x4E`  ("KCN")
| 3       |       2 | Cartridge Layout Version | 16-bit big endian value indicating the type (or version) of the cartridge layout.  The last two digits should be considered the decimal portion of the number, and the rest the integer.  So `100` would be version 1.00 
| 5       |       2 | Cartridge Distribution Version. | *Optional.* Used by the cartridge producer to indicate the version (or other information) of the cartridge.  For internal use only, it is not used by the KeyCade Nano
| 6       |       1 |  Game Count  | Number of games stored on this cartridge.  

### Game Data 

Game Data storage starts at addrss `0x100` and consists of 64 byte records containing the  the `GameData` structure used by the KeyCade Nano.  For details on the structure see  [Commonalities](Common.md).

The maximum number of entries is limited to 60, but an actual cartridge will likely have far fewer entries

| Offset | Length | Name           | Description            
| ------: | ------: | :------------ | :-------------------
| 0       |       1 | Type          | Single byte indicating what GameEngine is used.  The possible values are: `0` for CHIP-8, `1` for EmbedVM, and `2` for uBASIC
| 1       |       2 | instructionsPerSecond | The number of instructions per second the game is allowed to run.  `0` for unrestricted
| 3       |       1 | framesPerSecond       | The number of times the screens should be updated per second. `0` for manual updating of the screen
| 4       |       2 | flags                 | Flags passed to the game engine.  Currently non
| 6       |      21 | name                  | The name to display for the game. `NULL` terminated string 
| 27      |       7 | keyMap                | Key mappings for the game.  The order is Up, Down, Left, Right, Center, A, & B
| 34      |       4 | instuctions           | *Not Implemented*
| 38      |       2 | codeStart             | The offset into the program to begin execution
| 40      |       4 | data                  | The address on the EEProm where the program is located
| 44      |       2 | size                  | Size in bytes of the program.  Cannot be more than 4096 bytes


### Game Storage 

Game Storage begins at address `0x1000` and contains the programs referenced in the Game Data secion.  The order is up to the program that writes the data

