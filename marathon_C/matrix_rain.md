# Ncurses programming.  Matrix rain.
Do you want your programs to have a colorful terminal based interface? Ncurses is a library that
provides window functionallity for text-based terminals. Things that ncurses is capable of:
* Use whole screen as you like.
* Create and manage windows.
* Use 8 different colors.
* Give your program mouse support.
* Use the function keys from the keyboard.

## Description of the task:
Create a program that simulates the screensaver from `The Matrix`. 
The program must show text running from top to bottom of the `Terminal`. It must scrollthrough all the lines with the same speed.
The illusion of `falling` columns with different heights filled with random characters along the width of your Terminal must be created. 
`The first` (lowest) character of each column must be `white` and changing continuously, and the remaining characters of the column must be `green` by default. Background of the Terminal must be `black` by default. 
The program must:
- use all printable `ASCII` characters
- exit by pressing on `q` on the keyboard
- not handle `window resize`
- display usage in case of invalid input

## Instalation:
1. The program works correctly only for Mac
2. Download code [here](Race01)
3. default mode: `make` or `make all`
4. silent debug mode: `make debug`

### Usage:
`./matrix_rain [color] [speed]`

- default color is 4 (green)  
- default speed is 10 

### Screensaver control keys:
| *Key* | *Description* |
|:-:|:-:|
|**`1`**| color black|
|**`2`**| color white |
|**`3`**| color red |
|**`4`**| color green |
|**`5`**| color blue |
|**`6`**| color cyan |
|**`7`**| color magenta |
|**`8`**| color yellow |
|**`+`**| increase the speed of rain |
|**`-`**| reduce the speed of rain |
|**`q`**| exit the program |

### Developers:  
Tetyana Holdanova  
Max Hrynchak  
Vitalii Umanets  

## [Go back](../README.md)
