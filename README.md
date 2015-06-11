# Monkey


Was created using LIBtcod

http://roguecentral.org/doryen/libtcod/ is the main place for all things required and for coding help.
Used a nice tutorial http://codeumbra.eu/complete-roguelike-tutorial-using-c-and-libtcod-part-1-setting-up was used to help with creating certain things.
Although I deviated from some of the code I found it a helpfultutorial and got a lot of help from the roguecentral forums.

 Pre-requisites

Installing the compiler

First you need a C++ compiler. On Linux, it's easy :
> sudo apt-get install g++ gdb libsdl1.2debian-all

Installing libtcod

All you have to do is download the library corresponding to your platform from this URL :

http://roguecentral.org/doryen/libtcod/download

and extract it on your hard drive.

Create an empty directory somewhere on your hardrive. Inside, create 3 empty directories :
> mkdir include src lib

Then you'll have to copy those files from the libtcod directory to your project directory :

    include/*.h
    include/*.hpp
    terminal.png

For Linux only :

    libtcod.so
    libtcodxx.so
    libtcod_debug.so
    libtcodxx_debug.so

