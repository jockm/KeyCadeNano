EmbedVM
=======

Is a virtual machine for embedded systems. It consists of an emulator for 
an imaginary 16-bit CPU and then a compiler for a 
[Small-C](https://en.wikipedia.org/wiki/Small-C) like language. Please 
consult the [EmbedVM](http://www.clifford.at/embedvm/) page for more information. 


## Commands
The EmbedVM system may be extended by adding up to to 16 User Funtions.  
These are named $uf0 trough $uff.   

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
> $uf3()

Updates the screen

Parameters:
*None*  

Returns:
>Nothing

#### $uf4 — Clear Screen

Usage:
> $uf4()

Clears the screen (fills it with black)

Parameters:
*None*  

Returns:
>Nothing

#### $uf5 — Get System Delay

Usage:
> $uf5()

Gets the System Delay value

Parameters:
*None*  

Returns:
> the System Delay value in 60ths of a second

#### $uf6 — Set System Delay

Usage:
> $uf6(*{delay}*)

Sets the System Delay value

Parameters:
* {delay} — the new delay value in 60ths of a second

Returns:
>Nothing

#### $uf7 — Get Sound Delay

Usage:
> $uf7()

Gets the Sound Delay value

Parameters:
*None*

Returns:
> the Sound Delay value in 60ths of a second

#### $uf8 — Set Sound Delay

Usage:
> $uf8(*{delay}*)

Sets the Sound Delay value

Parameters:
* {delay} — the new delay value in 60ths of a second

Returns:
>Nothing

#### $uf9 — Get Key

Usage:
> $uf9()

Ends the program and returns to the main menu

Parameters:
* {mode} — currently ignored, use `0`
* {var} — the variable that recieves the current key 

Returns:
>Nothing

