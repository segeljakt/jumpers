/******************************************************************************
*     File Name           :     player.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-10 17:45]                            *
*     Last Modified       :     [2016-11-10 17:51]                            *
*     Description         :     Player interface.                             *
******************************************************************************/
#include "player.h"
#include <math.h>
/*****************************************************************************/
int player_collision(unit_t *player, map_t *map) {
    unit_t *iter;
    for(iter = (unit_t*)map->player; iter != NULL; iter = iter->next) {
        if(iter->pos.x == player->pos.x
        && iter->pos.y == player->pos.y) {
            continue;
        }
        float w = (player->len.x + iter->len.x)/2;
        float h = (player->len.y + iter->len.y)/2;
        float dx = player->cen.x - iter->cen.x;
        float dy = player->cen.y - iter->cen.y;

        if(abs(dx) <= w && abs(dy) <= h) {
            /* collision! */
            float wy = w*dy;
            float hx = h*dx;

            if (wy > hx) {
                if (wy > -hx) {
                    /* bottom */
                    iter->ctop(player, iter, map);
                } else {
                    /* left */
                    iter->cside(player, iter, map);
                }
            } else {
                if (wy > -hx) {
                    /* right */
                    iter->cside(player, iter, map);
                } else {
                    /* top */
                    iter->cbot(player, iter, map);
                }
            }
        }
    }
    return 0;
}
/*****************************************************************************/
