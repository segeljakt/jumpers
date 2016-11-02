/******************************************************************************
*     File Name           :     player.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-02 09:11]                            *
*     Last Modified       :     [2016-11-02 18:58]                            *
*     Description         :     Player definition.                            *
******************************************************************************/
#include "player.h"
#include <stdlib.h>
/*****************************************************************************/
                           /*  PLAYER 1    PLAYER 2  */
static const char ch[]     = {CHAR_MARIO, CHAR_MARIO};
static const int  up[]     = {KEY_W,      KEY_UP};
static const int  down[]   = {KEY_S,      KEY_DOWN};
static const int  left[]   = {KEY_A,      KEY_LEFT};
static const int  right[]  = {KEY_D,      KEY_RIGHT};
static const int  sprint[] = {KEY_LSHIFT, KEY_RSHIFT};
static const int  color[]  = {COLOR_RED,  COLOR_BLUE};
/*****************************************************************************/
int new_local_player(map_t *map, int x, int y) {
    if(map->num_local_players < MAX_LOCAL_PLAYERS) {
        int p_num = map->num_local_players++;
        player_t *player = malloc(sizeof(player_t));

        player->ch          = ch[p_num];
        player->keys.up     = up[p_num];
        player->keys.down   = down[p_num];
        player->keys.left   = left[p_num];
        player->keys.right  = right[p_num];
        player->keys.sprint = sprint[p_num];
        player->color       = color[p_num];
        player->body.x      = x;
        player->body.y      = y;
        player->body.x_axis = 0;
        player->body.y_axis = 0;
        player->next        = map->local_player;

        map->local_player = player;
    }
}
