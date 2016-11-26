/******************************************************************************
*     File Name           :     unit.c                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-05 23:32]                            *
*     Last Modified       :     [2016-11-23 12:26]                            *
*     Description         :     Default unit interface.                       *
******************************************************************************/
#include "unit.h"
#include <math.h>
/*****************************************************************************/
int kill_unit(unit_t **unit) {
    unit_t *tmp = (*unit)->next;
    free(*unit);
    unit = &tmp;
    return 0;
}
/*---------------------------------------------------------------------------*/
int unit_movement(unit_t *unit, int y, int x) {
    if(unit->dir.y == UP && unit->on_ground)  {
        unit->vel.y = -MAX_VEL_Y;
        unit->on_ground = 0;
    } else if(unit->dir.x == RIGHT) {
        unit->vel.x += (unit->vel.x < 0)? 0.5:X_ACCELERATION;
    } else if(unit->dir.x == LEFT) {
        unit->vel.x -= (unit->vel.x > 0)? 0.5:X_ACCELERATION;
    } else if(unit->on_ground && (unit->vel.x < 0.25 || unit->vel.x > -0.25)) {
        unit->vel.x /= 1.5;
    } else if(unit->on_ground) {
        unit->vel.x /= 1.125;
    }

    unit->vel.y -= GRAVITY;

    unit->vel.x = (unit->vel.x > MAX_VEL_X)? unit->vel.x: MAX_VEL_X;
    unit->vel.x = (unit->vel.x < MAX_VEL_X)? unit->vel.x:-MAX_VEL_X;
    unit->vel.y = (unit->vel.x > MAX_VEL_Y)? unit->vel.y: MAX_VEL_Y;
    unit->vel.y = (unit->vel.x < MAX_VEL_Y)? unit->vel.y:-MAX_VEL_Y;

    unit->pos.x += unit->vel.x;
    unit->pos.y += unit->vel.y;
    unit->cen.x = unit->pos.x - unit->len.x;
    unit->cen.y = unit->pos.y - unit->len.y;

    return 0;
}
/***************************************************************************/
/* http://tinyurl.com/pup2fcs */
int unit_collision(unit_t *player, map_t *map) {
    unit_t *iter;
    for(iter = map->unit; iter != NULL; iter = iter->next) {
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
                    iter->cbot(player, iter, map);
//                    iter->ctop(player, iter, map);
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
                    iter->ctop(player, iter, map);
//                    iter->cbot(player, iter, map);
                }
            }
        }
    }
    return 0;
}
/*****************************************************************************/
int cdamage(unit_t *player, unit_t *self, map_t *map) {
    if(player->status == INVINCIBLE) {
        self->status = DEAD;
    } else {
        player->status = DEAD;
    }
    return 0;
}
/*****************************************************************************/
int cnone(unit_t *player, unit_t *self, map_t *map) {
    return 0;
}
