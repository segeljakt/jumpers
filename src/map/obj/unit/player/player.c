/******************************************************************************
*     File Name           :     player.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-02 09:11]                            *
*     Last Modified       :     [2016-11-05 20:54]                            *
*     Description         :     Player definition.                            *
******************************************************************************/
#include "player.h"
#include <stdlib.h>
/*****************************************************************************/
static int update(map_t *map, obj_t *obj);
static int serialize(obj_t *obj);
static int draw(WINDOW *pad, obj_t *obj);
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
int new_local_player(map_t *map) {
    if(map->num_local_players < MAX_LOCAL_PLAYERS) {
        int p_num = map->num_local_players++;
        player_t *player = malloc(sizeof(player_t));

        player->keys.up     = up[p_num];
        player->keys.down   = down[p_num];
        player->keys.left   = left[p_num];
        player->keys.right  = right[p_num];
        player->keys.sprint = sprint[p_num];
        player->body.x      = map->local_player->body.x;
        player->body.y      = map->local_player->body.y;
        player->body.d_x    = NONE;
        player->body.d_y    = NONE;
        player->body.v_x    = 0;
        player->body.v_y    = 0;
        player->update      = update;
        player->serialize   = serialize;
        player->draw        = draw;
        player->next        = map->local_player;

        map->local_player = player;
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
static int movement(body_t *body, int x, int y) {

    if(body->d_y == UP && body->on_ground)  {
        body->v_y = -MAX_Y_VELOCITY;
        body->on_ground = 0;
    } else if(body->d_x == RIGHT) {
        body->v_x += (body->v_x < 0)? 0.5:X_ACCELERATION;
    } else if(body->d_x == LEFT) {
        body->v_x -= (body->v_x > 0)? 0.5:X_ACCELERATION;
    } else if(body->on_ground && (body->v_x < 0.25 || body->v_x > -0.25)) {
        body->v_x /= 1.5;
    } else if(body->on_ground) {
        body->v_x /= 1.125;
    }

    body->v_y += GRAVITY;

    body->v_x = (body->v_x > MAX_X_VELOCITY)? body->v_x: MAX_X_VELOCITY;
    body->v_x = (body->v_x < MAX_X_VELOCITY)? body->v_x:-MAX_X_VELOCITY;
    body->v_y = (body->v_x > MAX_Y_VELOCITY)? body->v_y: MAX_Y_VELOCITY;
    body->v_y = (body->v_x < MAX_Y_VELOCITY)? body->v_y:-MAX_Y_VELOCITY;

    body->y += body->v_y;
    body->x += body->v_x;

    return 0;
}
static int collision(map_t *map, body_t *body, float x, float y) {
    if(body->y < 0 || body->y >= map->height
    || body->x < 0 || body->x >= map->width) {
        return 0;
    }
    // X-Collision
    if(IN_BOUNDS(y, body->x, map->height, map->width)) {
        if(map->block[(int)y][(int)body->x].collision)
        switch(map->block[(int)y][(int)body->x].collision->side) {
            case COLLISION_DEADLY: {
                return DEAD;
            }
            body->v_x = 0;
            body->x = x;
        }
    }
    // Y-collision
    if(IN_BOUNDS(body->y, x, map->height, map->width)) {
        if(map->block[(int)y][(int)body->x].collision) {
            if(body->v_y > 0) {
                if(!body->on_ground) {
                    body->on_ground = 1;
                    if(body->d_x == NONE) {
                        body->v_x = 0;
                    }
                }
                body->v_y = 0;
                body->y = y;
            } else if(body->v_y < 0) {
            }
        }
    }
    return 0;
}
static int update(map_t *map, mapobj_t* mapobj) {
    player_t *player = (player_t*)mapobj;
    body_t *body = &player->body;

    float x = body->x;
    float y = body->y;

    movement(body, x, y);
    collision(map, body, x, y);

    return 0;
}
static int serialize(mapobj_t *mapobj) {
    return 0;
}
static int draw(WINDOW *pad, mapobj_t *mapobj) {
    return 0;
}
