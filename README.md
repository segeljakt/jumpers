Terminal-Mario
===============
---------------
"Terminal-Mario" aims to bring the original Super Mario Bros to a terminal environment. Graphics are rendered with [ncurses](https://github.com/gittup/ncurses) and input is received with [carbon](http://tinyurl.com/6q5hqsk). Game maps are read from .txt files.

![Giphy](https://media.giphy.com/media/26vUOybLISep9n9ja/giphy.gif)

Compile
----
Compile the program with

    gcc -lncurses -framework Carbon mario.c block.c blocks.c player.c unit.c players.c units.c input.c

Future
----
Makefile will be added.