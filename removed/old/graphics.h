/******************************************************************************
*     File Name           :     graphics.h
*     Created By          :     Klas
*     Creation Date       :     [2016-06-22 09:54]
*     Last Modified       :     [2016-06-22 10:11]
*     Description         :     Graphics engine.
******************************************************************************/
#include <ncurses.h>
/*****************************************************************************/
int main(int argc, char *argv[]); // Temporary main function
int update(WINDOW *win, int prev_y, int prev_x, int y, int y);
