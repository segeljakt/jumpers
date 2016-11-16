/******************************************************************************
*     File Name           :     mario.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-02 09:11]                            *
*     Last Modified       :     [2016-11-16 21:44]                            *
*     Description         :     Player definition.                            *
******************************************************************************/
#include "../player.h"
/*****************************************************************************/
static int update(unit_t *self, map_t *map);
static int movement(unit_t *self);
static int ctop(unit_t *player, unit_t *self, map_t *map);
static int draw(WINDOW *pad, unit_t *self);
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

    player->color_attribute = COLOR_PAIR(color[p_num]) | A_STANDOUT;

    player->keys.up     = up[p_num];
    player->keys.down   = down[p_num];
    player->keys.left   = left[p_num];
    player->keys.right  = right[p_num];
    player->keys.sprint = sprint[p_num];

    player->pos.x       = x;
    player->pos.y       = y;
    player->dir.x       = NONE;
    player->dir.y       = NONE;
    player->vel.x       = 0;
    player->vel.y       = 0;
    player->cen.x       = 0;
    player->cen.y       = 0;
    player->pre.x       = 0;
    player->pre.y       = 0;
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
    if(self->dir.y == UP && self->on_ground) {
        self->vel.y = MAX_VEL_Y;
        self->on_ground = 0;
    }
    if(self->dir.x == RIGHT) {
        self->vel.x += (self->vel.x < 0)? 0.5:X_ACCELERATION;
    } else if(self->dir.x == LEFT) {
        self->vel.x -= (self->vel.x > 0)? 0.5:X_ACCELERATION;
    } else if(self->on_ground && (self->vel.x < 0.25 || self->vel.x > -0.25)) {
        self->vel.x /= 1.5;
    } else if(self->on_ground) {
        self->vel.x /= 1.125;
    }

    self->vel.y -= GRAVITY;

    self->vel.x = (self->vel.x >  MAX_VEL_X)?  MAX_VEL_X : self->vel.x;
    self->vel.x = (self->vel.x < -MAX_VEL_X)? -MAX_VEL_X : self->vel.x;
    self->vel.y = (self->vel.x >  MAX_VEL_Y)?  MAX_VEL_Y : self->vel.y;
    self->vel.y = (self->vel.x < -MAX_VEL_Y)? -MAX_VEL_Y : self->vel.y;

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
static int draw(WINDOW *pad, unit_t *unit) {
    mvwaddch(pad,
            (int)(unit->pre.y*BLOCK_SPACING),
            (int)(unit->pre.x*BLOCK_SPACING), CHAR_NONE);
//    wattron(pad, unit->color_attribute);
    mvwaddch(pad,
            (int)(unit->pos.y*BLOCK_SPACING),
            (int)(unit->pos.x*BLOCK_SPACING), CHAR_MARIO);
//    wattroff(pad, unit->color_attribute);
    return 0;
}
