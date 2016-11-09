/******************************************************************************
*     File Name           :     unit.c                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-05 23:32]                            *
*     Last Modified       :     [2016-11-09 22:14]                            *
*     Description         :     Default unit interface.                       *
******************************************************************************/
#include "unit.h"
/*****************************************************************************/
int unit_movement(unit_t *unit, int x, int y) {
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
#include <math.h>
/* http://tinyurl.com/pup2fcs */
int unit_collision(unit_t *player, unit_t *iter) {
    for(; iter != NULL; iter = iter->next) {
        /* Unneccessary check in cases where player calls
         * unit_collision(player, unit)
         */
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
                    iter->ctop(player, iter);
                } else {
                    /* left */
                    iter->cside(player, iter);
                }
            } else {
                if (wy > -hx) {
                    /* right */
                    iter->cside(player, iter);
                } else {
                    /* top */
                    iter->cbot(player, iter);
                }
            }
        }
    }
    return 0;
}
/*****************************************************************************/
int block_collision(unit_t *unit, block_t **blocks) {
    block_t *block = &blocks[(int)unit->pos.y][(int)unit->pos.x];

    if(block->has_collision) {
        float w = (unit->len.x + BLOCKLENGTH)/2;
        float h = (unit->len.y + BLOCKLENGTH)/2;
        float dx = unit->cen.x - ((int)unit->pos.x+BLOCKLENGTH/2);
        float dy = unit->cen.y - ((int)unit->pos.y+BLOCKLENGTH/2);

        float wy = w*dy;
        float hx = h*dx;

        if (wy > hx) {
            if (wy > -hx) {
                /* bottom */
                block->ctop(unit, block);
            } else {
                /* left */
                block->cside(unit, block);
            }
        } else {
            if (wy > -hx) {
                /* right */
                block->cside(unit, block);
            } else {
                /* top */
                block->cbot(unit, block);
            }
        }
    }
    return 0;
}
/*****************************************************************************/
inline int cdamage(unit_t *player, unit_t *self) {
    if(player->status == INVULNERABLE) {
        self->status == DEAD;
    } else {
        player->status == DEAD;
    }
    return 0;
}
/*****************************************************************************/
inline int cnone(unit_t *player, unit_t *self) {
    return 0;
}
