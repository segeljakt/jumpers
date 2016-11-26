/******************************************************************************
*     File Name           :     mario.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-02 09:11]                            *
*     Last Modified       :     [2016-11-23 15:14]                            *
*     Description         :     Player definition.                            *
******************************************************************************/
#include "../player.h"
/*****************************************************************************/
static int update(unit_t *self, map_t *map);
static int movement(unit_t *self);
static int ctop(unit_t *player, unit_t *self, map_t *map);
static int draw(tui_t *tui, unit_t *self);
/*****************************************************************************/
                           /*  PLAYER 1        PLAYER 2  */
static const int  up[]     = {KEY__W,          KEY__UP};
static const int  down[]   = {KEY__S,          KEY__DOWN};
static const int  left[]   = {KEY__A,          KEY__LEFT};
static const int  right[]  = {KEY__D,          KEY__RIGHT};
static const int  sprint[] = {KEY__LSHIFT,     KEY__MINUS};
static const int  color[]  = {COLOR_RED_NONE,  COLOR_BLUE_NONE};
/*****************************************************************************/
int parse_mario(int y, int x, char **raw_map, map_t *map) {
    raw_map[y][x] = CHAR_NONE;
    new_mario(y, x, map);
    return 0;
}
/*****************************************************************************/
int new_mario(int y, int x, map_t *map) {
    int p_num = map->num_players++;
    player_t *player = malloc(sizeof(player_t));

    player->color_attribute = COLOR_PAIR(color[p_num]);

    player->status      = 0;

    player->keys.up     = up[p_num];
    player->keys.down   = down[p_num];
    player->keys.left   = left[p_num];
    player->keys.right  = right[p_num];
    player->keys.sprint = sprint[p_num];

    player->pos.x       = x;
    player->pos.y       = y;
    player->dir.x       = NONE;
    player->dir.y       = NONE;
    player->vel.x       = MAX_VEL_X/2;
    player->vel.y       = 0;
    player->cen.x       = 0;
    player->cen.y       = 0;
    player->pre.x       = x;
    player->pre.y       = y;
    player->len.x       = 1;
    player->len.y       = 1;
    player->on_ground   = 0;

    player->update      = update;
    player->ctop        = ctop;
    player->cside       = cnone;        // Default
    player->cbot        = cnone;        // Default
    player->draw        = draw;

    player->next        = (unit_t*)map->player;

    map->player = player;
    return 0;
}
/*---------------------------------------------------------------------------*/
static int update(unit_t *self, map_t *map) {

    movement(self);
    unit_collision(self, map);
    player_collision(self, map);
    block_collision(self, map);

    return 0;
}
/*---------------------------------------------------------------------------*/
static int movement(unit_t *self) {
    /* Vertical movement */
    if(self->dir.y == UP) {
        if(self->on_ground && !(self->status & HAS_JUMPED)) {
            self->vel.y = MAX_VEL_Y;
            self->on_ground = 0;
            self->status |= HAS_JUMPED;
        }
    } else if(self->vel.y > 0) {
        self->vel.y -= GRAVITY*2;
    } else {
        self->status &= ~HAS_JUMPED;
    }

    /* Horizontal movement */
    if(self->dir.x == RIGHT) {
        self->vel.x = (self->vel.x < 0)? 0:self->vel.x+X_ACCELERATION;
    } else if(self->dir.x == LEFT) {
        self->vel.x = (self->vel.x > 0)? 0:self->vel.x-X_ACCELERATION;
    } else if(self->on_ground && (self->vel.x < 0.25 || self->vel.x > -0.25)) {
//        self->vel.x /= 1.5;
    } else if(self->on_ground) {
//        self->vel.x /= 1.125;
    }

    self->vel.y -= GRAVITY;

    if(self->vel.x > MAX_VEL_X) {
        self->vel.x = MAX_VEL_X;
    } else if(self->vel.x < -MAX_VEL_X){
        self->vel.x = -MAX_VEL_X;
    }
    if(self->vel.y > MAX_VEL_Y) {
        self->vel.y = MAX_VEL_Y;
    } else if(self->vel.y < -MAX_VEL_Y) {
        self->vel.y = -MAX_VEL_Y;
    }

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
//static int serialize(unit_t *unit) {
//    return 0;
//}
/*---------------------------------------------------------------------------*/
#include <math.h>
static int draw(tui_t *tui, unit_t *unit) {
    mvwaddch(tui->win,
            unit->pre.y*TILE_SIZE,
            (unit->pre.x-tui->camera)*TILE_SIZE,
            CHAR_NONE);
    wattron(tui->win, unit->color_attribute);
    mvwaddch(tui->win,
            unit->pos.y*TILE_SIZE,
            (unit->pos.x-tui->camera)*TILE_SIZE,
            CHAR_MARIO);
    wattroff(tui->win, unit->color_attribute);
    return 0;
}
