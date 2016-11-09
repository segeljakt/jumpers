/******************************************************************************
*     File Name           :     player.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-02 09:11]                            *
*     Last Modified       :     [2016-11-09 00:33]                            *
*     Description         :     Player definition.                            *
******************************************************************************/
#include "player.h"
/*****************************************************************************/
static int
update(unit_t *self, unit_t *player, unit_t *unit, block_t **block);
static int draw(WINDOW *pad, unit_t *self);
static int ctop(unit_t *player, unit_t *self);
static int movement(unit_t *self);
/*****************************************************************************/
                           /*  PLAYER 1    PLAYER 2  */
static const char ch[]     = {CHAR_MARIO, CHAR_MARIO};
static const int  up[]     = {KEY__W,      KEY__UP};
static const int  down[]   = {KEY__S,      KEY__DOWN};
static const int  left[]   = {KEY__A,      KEY__LEFT};
static const int  right[]  = {KEY__D,      KEY__RIGHT};
static const int  sprint[] = {KEY__LSHIFT, KEY__RSHIFT};
static const int  color[]  = {COLOR_RED,  COLOR_BLUE};
/*****************************************************************************/
int new_player(int p_num, int x, int y, player_t **head) {
    player_t *player = malloc(sizeof(player_t));

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

    player->update      = update;
    player->ctop        = ctop;
    player->cside       = cnone;        // Default
    player->cbot        = cnone;        // Default
//    player->serialize   = serialize;
    player->draw        = draw;
    player->next        = (unit_t*)*head;

    *head = player;
}
/*---------------------------------------------------------------------------*/
static int
update(unit_t *self, unit_t *player, unit_t *unit, block_t **blocks) {

    movement(self);
    unit_collision(self, player);
    unit_collision(self, unit);
    block_collision(self, blocks);

    return 0;
}
/*---------------------------------------------------------------------------*/
static int movement(unit_t *self) {
    if(self->dir.y == UP && self->on_ground)  {
        self->vel.y = -MAX_VEL_Y;
        self->on_ground = 0;
    } else if(self->dir.x == RIGHT) {
        self->dir.x += (self->vel.x < 0)? 0.5:X_ACCELERATION;
    } else if(self->dir.x == LEFT) {
        self->vel.x -= (self->vel.x > 0)? 0.5:X_ACCELERATION;
    } else if(self->on_ground && (self->vel.x < 0.25 || self->vel.x > -0.25)) {
        self->vel.x /= 1.5;
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
static int serialize(unit_t *unit) {
    return 0;
}
/*---------------------------------------------------------------------------*/
static int draw(WINDOW *pad, unit_t *unit) {
    return 0;
}
