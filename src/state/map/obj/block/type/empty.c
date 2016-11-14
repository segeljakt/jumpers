/******************************************************************************
*     File Name           :     empty.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-11 18:29]                            *
*     Last Modified       :     [2016-11-14 08:17]                            *
*     Description         :     Empty block.                                  *
******************************************************************************/
#include "../block.h"
#include "src/state/map/obj/unit/player/player.h"
/*****************************************************************************/
int new_empty_block(int y, int x, int ch, map_t *map) {
    map->block[y][x].ctop = cbnone;
    map->block[y][x].cside = cbnone;
    map->block[y][x].cbot = cbnone;
    map->block[y][x].has_collision = 0;
    map->block[y][x].ch = ch;
    return 0;
}
