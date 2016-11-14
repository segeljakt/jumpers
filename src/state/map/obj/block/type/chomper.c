/******************************************************************************
*     File Name           :     chomper.c                                     *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-10 13:08]                            *
*     Last Modified       :     [2016-11-10 23:26]                            *
*     Description         :     Chomper block (lethal).                       *
******************************************************************************/
#include "../block.h"
/*****************************************************************************/
static int ckill(unit_t *player, block_t *self, map_t *map);
/*****************************************************************************/
int new_chomper_block(int y, int x, map_t *map) {
    map->block[y][x].ctop = ckill;
    map->block[y][x].cside = ckill;
    map->block[y][x].cbot = ckill;
    map->block[y][x].has_collision = 1;
    map->block[y][x].ch = CHAR_BRICK_BLOCK;
    return 0;
}
/*****************************************************************************/
static int ckill(unit_t *player, block_t *self, map_t *map) {
    player->status |= DEAD;
    return 0;
}
