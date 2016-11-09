/******************************************************************************
*     File Name           :     goomba.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-05 22:40]                            *
*     Last Modified       :     [2016-11-09 00:16]                            *
*     Description         :     Goomba unit.                                  *
******************************************************************************/
#include "goomba.h"
#include <stdlib.h>
/*****************************************************************************/
static int
update(unit_t *self, unit_t *player, unit_t *unit, block_t **block);
static int draw(WINDOW *pad, unit_t *obj);
static int ctop(unit_t *player, unit_t *self);
static int movement(unit_t *self);
/*****************************************************************************/
int new_goomba(int x, int y, int d_x, unit_t **head) {
    unit_t *unit = malloc(sizeof(unit_t));

    unit->pos.x       = x;
    unit->pos.y       = y;
    unit->dir.x       = d_x;
    unit->dir.y       = NONE;
    unit->vel.x       = 0;
    unit->vel.y       = 0;

    unit->update      = update;
    unit->ctop        = ctop;
    unit->cside       = cdamage;        // Default
    unit->cbot        = cdamage;        // Default
//    unit->serialize   = serialize_unit; // Default
    unit->draw        = draw;

    unit->next        = *head;

    *head = unit;
}
/*---------------------------------------------------------------------------*/
static int
update(unit_t *self, unit_t *player, unit_t *unit, block_t **block) {

    movement(self);
    block_collision(unit, block);

    return 0;
}
/*---------------------------------------------------------------------------*/
static int movement(unit_t *self) {
    if(self->dir.x == RIGHT) {
        self->dir.x += (self->vel.x < 0)? 0.5:X_ACCELERATION;
    } else if(self->dir.x == LEFT) {
        self->vel.x -= (self->vel.x > 0)? 0.5:X_ACCELERATION;
    } else if(self->on_ground) {
        self->vel.x /= 1.125;
    }

    self->vel.y -= GRAVITY;

    self->vel.x = (self->vel.x > MAX_VEL_X)? self->vel.x: MAX_VEL_X;
    self->vel.x = (self->vel.x < MAX_VEL_X)? self->vel.x:-MAX_VEL_X;
    self->vel.y = (self->vel.x > MAX_VEL_Y)? self->vel.y: MAX_VEL_Y;
    self->vel.y = (self->vel.x < MAX_VEL_Y)? self->vel.y:-MAX_VEL_Y;

    self->pre.x = self->pos.x;
    self->pre.y = self->pos.y;

    self->pos.x += self->vel.x;
    self->pos.y += self->vel.y;

    return 0;
}
/*---------------------------------------------------------------------------*/
static int ctop(unit_t *player, unit_t *self) {
    self->vel.y = 0;
    player->vel.y = MAX_VEL_Y;
    return 0;
}
/*---------------------------------------------------------------------------*/
static int draw(WINDOW *pad, unit_t *unit) {
    return 0;
}
/*****************************************************************************/
