/******************************************************************************
*     File Name           :     red_shroom.c                                  *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-11 18:01]                            *
*     Last Modified       :     [2016-11-11 18:09]                            *
*     Description         :     Red shroom block.                             *
******************************************************************************/
#include "../block.h"
/*****************************************************************************/
static int cbot(unit_t *player, block_t *self, map_t *map);
/*****************************************************************************/
int new_red_shroom_block(int y, int x, map_t *map) {
    map->block[y][x].ctop = cblock;
    map->block[y][x].cside = cblock;
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
            new_red_shroom(y, x, RIGHT, map);
        }
    }
    return 0;
}
