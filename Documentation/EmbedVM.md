EmbedVM
=======

Is a virtual machine for embedded systems. It consists of an emulator for 
an imaginary 16-bit CPU and then a compiler for a 
[Small-C](https://en.wikipedia.org/wiki/Small-C) like language. Please 
consult the [EmbedVM](http://www.clifford.at/embedvm/) page for more information. 


## Commands
The EmbedVM system may be extended by adding up to to 9 User Funtions.  
These are named $uf0 trough $uf8. The following have been implmented in
the KeyCade Nano  

#### $uf0 — Exit

Usage:
> $uf0()

Ends the program and returns to the main menu

Parameters:
* {mode} — currently ignored, use `0`
* {var} — the variable that recieves the current key 


#### $uf1 — XDraw Image

Usage:
> $uf1(*{x}*, *{x}*, *{w}*, *{h}*, *{bitmapPtr}*)

XORs image to the screen at position {x}, {y}; of width {w} and height {h}

Parameters:
* {x} — the x-corodinate where to place the text (0..127)
* {y} — the y-corodinate where to place the text (0..63)
* {w} — the width of the image in pixels
* {h} — the height of the image in pixels
* {bitmapPtr} a pointer to the bitmap data

Returns:
>0 if there was no collision, and non-0 if there was.  A collision occurs
when any "white" pixel in the image is drawn over a "white" pixel in the screen

#### $uf2 — Scroll Display

Usage:
> $uf2(*{dir}*, *{amount}*, *{from}*, *{to}*)

Scrolls the display

Parameters:
* {dir} — the direction to scroll the display:
    * 0 — scroll left
    * 1 — scroll right
    * 2 — scroll up
    * 3 — scroll down
* {amount} — the number of pixels to scroll 
* {from} — the first row/column of the horizontal/vertical zone you wish to
  scroll 
* {to} — the last row/column (exclusive) of the horizontal/vertical zone you wish to
  scroll 

Returns:
>Nothing

#### $uf3 — Update Screen

Usage:
> $uf3([*{cmd}*])

Updates the screen

Parameters:
* {cmd} — optional.  If `0` then update screen.  If `1` then clear the 
  screen (fill it with black).  Default `0`

Returns:
>Nothing

#### $uf4 — Get Value

Usage:
> $uf4(*{type}*)

Gets the a system value

Parameters:
* {type} — one of the following:
    * `0` the system delay value in 60ths of a second
    * `1` the sound delay value in 60ths of a second
    * `3` a random number between 0 and 999
    

Returns:
> The requested value 

#### $uf5 — Set Value

Usage:
> $uf5(*{type}*, *{value}*)

Sets a system value

Parameters:
* {type} — one of the following:
    * `0` the system delay value in 60ths of a second
    * `1` the sound delay value in 60ths of a second
* {type} — one of the   	 following:

Returns:
>Nothing

#### $uf6 — Get Key

Usage:
> $uf6()

Ends the program and returns to the main menu

Parameters:
* {mode} — currently ignored, use `0`
* {var} — the variable that recieves the current key 

Returns:
>Nothing

