/******************************************************************************
*     File Name           :     normal.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-10 12:48]                            *
*     Last Modified       :     [2016-11-15 14:52]                            *
*     Description         :     Normal block (unbreakable).                   *
******************************************************************************/
#include "../block.h"
/*****************************************************************************/
int new_normal_block(int y, int x, int ch, map_t *map) {
    map->block[y][x].ctop = cbtop;
    map->block[y][x].cside = cbside;
    map->block[y][x].cbot = cbbot;
    map->block[y][x].has_collision = 1;
    map->block[y][x].ch = ch;
    return 0;
}
