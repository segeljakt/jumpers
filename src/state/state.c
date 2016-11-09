/******************************************************************************
*     File Name           :     state.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-29 23:40]                            *
*     Last Modified       :     [2016-11-03 21:15]                            *
*     Description         :     State functions.                              *
******************************************************************************/
#include "state.h"
#include "src/state/args/args.h"
#include <string.h>
/*****************************************************************************/
static const char *default_fp = "~/.mario/levels/map_1_1.txt";
/*****************************************************************************/
static int setup_scr() {
    initscr();
    return 0;
}
/*---------------------------------------------------------------------------*/
static int teardown_scr() {
    endwin();
    return 0;
}
/*---------------------------------------------------------------------------*/
state_t *init_state(int argc, char *argv[]) {
    args_t *args = parse_args(argc, argv);
    state_t *state = malloc(sizeof(state_t));
    int i;
    /* Initialize map */
    state->fp = (args->fp == 0)? strdup(default_fp):args->fp;
    if((state->map = init_map(state->fp)) == NULL) {
        free_state(state);
        free_args(args);
        return NULL;
    }
    /* Create players */
    float x = state->map->player->pos.x;
    float y = state->map->player->pos.y;
    for(i = 0; i < args->num_players; i++) {
        new_player(i, x, y, &state->map->player);
    }
    /* Set difficulty */
    state->difficulty = args->difficulty;
    /* Draw map */
    setup_scr();
    state->gfx = init_gfx(state->map);
    free_args(args);
    return state;
}
/*---------------------------------------------------------------------------*/
void update(state_t *state) {
    unit_t *iter;
    map_t *map = state->map;
    for(iter = (unit_t*)map->player; iter != NULL; iter = iter->next) {
        iter->update(iter, (unit_t*)map->player, map->unit, map->block);
    }
    for(iter = map->unit; iter != NULL; iter = iter->next) {
        iter->update(iter, (unit_t*)map->player, map->unit, map->block);
    }
}
/*---------------------------------------------------------------------------*/
void serialize(state_t *state) {

}
/*---------------------------------------------------------------------------*/
void free_state(state_t *state) {
    teardown_scr();
    if(state->map) {
        free_map(state->map);
    }
    if(state) {
        free(state);
    }
}
