/******************************************************************************
*     File Name           :     goomba.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-05 22:40]                            *
*     Last Modified       :     [2016-11-14 21:03]                            *
*     Description         :     Goomba.                                       *
******************************************************************************/
#include "../unit.h"
#include <stdlib.h>
/*****************************************************************************/
static int update(unit_t *self, map_t *map);
static int draw(WINDOW *pad, unit_t *obj);
static int ctop(unit_t *player, unit_t *self, map_t *map);
static int movement(unit_t *self);
/*****************************************************************************/
int parse_goomba(int y, int x, char **raw_map, map_t *map) {
    raw_map[y][x] = ' ';
    new_goomba(y, x, LEFT, map);
    return 0;
}
/*****************************************************************************/
int new_goomba(int y, int x, int d_x, map_t *map) {
    unit_t *unit = malloc(sizeof(unit_t));

    unit->pos.x       = x;
    unit->pos.y       = y;
    unit->dir.x       = d_x;
    unit->dir.y       = NONE;
    unit->vel.x       = 0;
    unit->vel.y       = 0;
    unit->cen.x       = 0;
    unit->cen.y       = 0;
    unit->pre.x       = 0;
    unit->pre.y       = 0;
    unit->len.x       = 1;
    unit->len.y       = 1;
    unit->on_ground   = 0;

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

    self->vel.x = (self->vel.x > MAX_VEL_X)?  MAX_VEL_X : self->vel.x;
    self->vel.x = (self->vel.x < MAX_VEL_X)? -MAX_VEL_X : self->vel.x;
    self->vel.y = (self->vel.y > MAX_VEL_Y)?  MAX_VEL_Y : self->vel.y;
    self->vel.y = (self->vel.y < MAX_VEL_Y)? -MAX_VEL_Y : self->vel.y;

    self->pre.x = self->pos.x;
    self->pre.y = self->pos.y;

    self->pos.x += self->vel.x;
    self->pos.y -= self->vel.y;

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
    mvwaddch(pad, (int)unit->pre.y, (int)unit->pre.x, CHAR_NONE);
    mvwaddch(pad, (int)unit->pos.y, (int)unit->pos.x, CHAR_GOOMBA);
    return 0;
}
