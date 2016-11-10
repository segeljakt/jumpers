/******************************************************************************
*     File Name           :     normal.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-10 12:48]                            *
*     Last Modified       :     [2016-11-10 13:33]                            *
*     Description         :     Normal block (unbreakable).                   *
******************************************************************************/
#include "../block.h"
/*****************************************************************************/
static int ctop(unit_t *player, block_t *self, map_t *map);
static int cside(unit_t *player, block_t *self, map_t *map);
static int cbot(unit_t *player, block_t *self, map_t *map);
/*****************************************************************************/
int new_normal_block(int y, int x, int ch, map_t *map) {
    block_t block;
    block.ctop = cblock;
    block.cside = cblock;
    block.cbot = cbot;
    block.ch = ch;
    return 0;
}
/*****************************************************************************/
static int cbot(unit_t *player, block_t *self, map_t *map) {
    player->pos.x = player->pre.x;
    player->pos.y = player->pre.y;
    player->vel.y = 0;
    return 0;
}
