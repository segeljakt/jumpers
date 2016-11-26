/******************************************************************************
*     File Name           :     green_shroom.c                                *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-13 13:44]                            *
*     Last Modified       :     [2016-11-21 14:15]                            *
*     Description         :     Green shroom unit.                            *
******************************************************************************/
#include "../unit.h"
#include <stdlib.h>
/*****************************************************************************/
static int update(unit_t *self, map_t *map);
static int draw(tui_t *tui, unit_t *obj);
static int ctop(unit_t *player, unit_t *self, map_t *map);
static int movement(unit_t *self);
/*****************************************************************************/
int new_green_shroom(int y, int x, int d_x, map_t *map) {
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
    return 0;
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
static int draw(tui_t *tui, unit_t *unit) {
    mvwaddch(tui->win, unit->pre.y, unit->pre.y, CHAR_NONE);
    mvwaddch(tui->win, unit->pos.y, unit->pos.x, CHAR_GOOMBA);
    return 0;
}
