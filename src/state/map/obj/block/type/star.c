/******************************************************************************
*     File Name           :     star.c                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-12 12:19]                            *
*     Last Modified       :     [2016-11-15 16:22]                            *
*     Description         :     Star block.                                   *
******************************************************************************/
#include "../block.h"
/*****************************************************************************/
static int cbot(unit_t *player, block_t *self, map_t *map);
/*****************************************************************************/
int new_star_block(int y, int x, map_t *map) {
    map->block[y][x].ctop = cbtop;
    map->block[y][x].cside = cbside;
    map->block[y][x].cbot = cbot;
    map->block[y][x].has_collision = 1;
    map->block[y][x].ch = CHAR_BRICK_BLOCK;
    return 0;
}
/*****************************************************************************/
static int cbot(unit_t *player, block_t *self, map_t *map) {
    self->ch = CHAR_USED_BLOCK;
    self->status = MODIFIED;
    int y = (int)player->pos.y-1;
    int x = (int)player->pos.x;
    if(y >= 0) {
        if(map->block[y][x].status == EMPTY) {
            new_star(y, x, RIGHT, map);
        }
    }
    return 0;
}
