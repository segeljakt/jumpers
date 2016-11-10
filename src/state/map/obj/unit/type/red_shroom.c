/******************************************************************************
*     File Name           :     red_shroom.c                                  *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-10 21:29]                            *
*     Last Modified       :     [AUTO_UPDATE_BEFORE_SAVE]                     *
*     Description         :     Red shroom.                                   *
******************************************************************************/
#include "../unit.h"
#include <stdlib.h>
/*****************************************************************************/
static int update(unit_t *self, map_t *map);
static int draw(WINDOW *pad, unit_t *obj);
static int ctop(unit_t *player, unit_t *self, map_t *map);
static int movement(unit_t *self);
/*****************************************************************************/
int new_red_shroom(int x, int y, int d_x, map_t *map) {
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
    unit->draw        = draw;

    unit->next        = map->unit;

    map->unit = unit;
}
/*---------------------------------------------------------------------------*/
static int update(unit_t *self, map_t *map) {

    movement(self);
    block_collision(self, map);

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
static int ctop(unit_t *player, unit_t *self, map_t *map) {
    self->vel.y = 0;
    player->vel.y = MAX_VEL_Y;
    return 0;
}
/*---------------------------------------------------------------------------*/
static int draw(WINDOW *pad, unit_t *unit) {
    mvwaddch(pad, (int)unit->pre.y, (int)unit->pre.y, CHAR_NONE);
    mvwaddch(pad, (int)unit->pos.y, (int)unit->pos.x, CHAR_GOOMBA);
    return 0;
}
