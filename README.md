# CPPND: Capstone Snake Game

This is the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

This project launches a main menu with past high scores for the game Snake. The game is played by a player who the computer keyboard arrow keys to navigate the snake toward its food. Once the snake collides with the food, the snake grows and the speed of the snake increases. The game continues until the snake collides with its own body and dies. If a new high score is earned then a prompt will open in the terminal to enter your name to be forever immortalized in the snake hall of fame. 

The main feature added to this project is the menu application. Previously, the snake game would run once and would not have a way to exit without closing the window manually. Two new files were added to solve this, "menu.h/menu.cpp". The menu files reads external text files to use in the game, organizes data, prints a menu and all time high scores, prompts the user for input, and saves the game data to an external text file to use for future games. The menu will also manage the window states so that it is clear when a game is beginning and ending. The "game.cpp" has also been updated so that the "Update()" function uses the menu to update data and files. Lastly, the "run" function in "game.cpp" more explicitly looks for game ending conditions in order to return to "main.cpp" I hope you enjoy the game!


## This project satisfies the project rubric in the following ways:
* Loops, Functions, I/O: 
  * A variety of control structures and functions are used to a varying degree of complexity. The files "menu.cpp/menu.h" contain simple get/set functions as well as complicated recursive quick sort functions used to manage the high scores.
  * "Menu.cpp/menu.h" reads and writes data to a text file which is used to keep track of high scores even after the program has ended.
  * "Menu.cpp/menu.h" prompts and accepts user input and checks for acceptable responses to prevent bugs.

* Object Oriented Programming:
  * The project uses several classes to hold dada and functions to run the game. In addition to the game files, the menu creates menu objects that manage data files as well as sorting high scores.
  * Classes use getter/setter functions to appropriately use private member variables.
  * All class member fucntions document their effects through function names.

* Memory Management:
  * This project uses smart pointers in main.cpp to manage the instance of Menu throughout the program.
  * The Menu object is moved between files using move semantics.
  * This project uses the Rule of 5, although, not all of the functions were used.



## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
