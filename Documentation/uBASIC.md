uBASIC
======

A uBASIC programs is simply a a plaintext file continaing the uBASIC source.  Please consult the [uBASIC](https://github.com/jockm/ubasic) site for documentation (such as it is) on the language.


## Commands
The language has been enhanced in the following ways for the KeyCade Nano:

#### End

Usage:
> end

Ends the program and returns to the main menu

Parameters:
*None*  


#### Input

Usage:
> input *{mode}*, *{var}*

Gets the current key pressed, -1 if no key has been pressed

Parameters:
* {mode} — `0` for the current key pressed, `1` for a random number between 0..99
* {var} — the variable that recieves the current key 

#### Print

Usage:
> print *{x}*, *{y}*, *{sting list}*

Prints {string list} at position {x}, {y}

Parameters:
* {x} — the x-corodinate where to place the text (0..127)
* {y} — the y-corodinate where to place the text (0..63)
* {string list} a comma seperated list of literal strings and variables to 
  be printed to the screen

#### User "cls"

Usage:
> user "cls" [*{color}*]

Clears the screen, optionally in a specific color

Parameters:
* {Color} — The color (0 or 1) to fill the screen.  Default: 0  
  
#### User "update"

Usage:
> user "update"

Updates the screen

Parameters:
*None*  

#### User "draw"

Usage:
> user "draw" *{x}*, *{y}*, *{w}*, *{w}*, *{value list}*

Draws image to the screen at position {x}, {y}; of width {w} and height {h}

Parameters:
* {x} — the x-corodinate where to place the text (0..127)
* {y} — the y-corodinate where to place the text (0..63)
* {w} — the width of the image in pixels
* {h} — the height of the image in pixels
* {value list} a comma seperated list of Base-64 encoded strings and values
  appended together into a single binary array.  The intent is that you may 
  either represent the image as a Base-64 encoded string, or as a list of 
  bytes.  However both data types may be freely intermindled.
  be printed to the screen

#### User "xdraw"

Usage:
> user "draw" *{x}*, *{y}*, *{w}*, *{w}*, *{value list}*

XORs image to the screen at position {x}, {y}; of width {w} and height {h}

Parameters:
* {x} — the x-corodinate where to place the text (0..127)
* {y} — the y-corodinate where to place the text (0..63)
* {w} — the width of the image in pixels
* {h} — the height of the image in pixels
* {value list} a comma seperated list of Base-64 encoded strings and values
  appended together into a single binary array.  The intent is that you may 
  either represent the image as a Base-64 encoded string, or as a list of 
  bytes.  However both data types may be freely intermindled.
  be printed to the screen
  
## Peeks & Pokes
The `peek` and `poke` commands can be used to get and set the following:

* Address 0 — The system delay value in 60ths of a second (0..255)
* Address 1 — The sound delay value in 60ths of a second (0..255)