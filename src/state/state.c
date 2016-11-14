/******************************************************************************
*     File Name           :     state.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-29 23:40]                            *
*     Last Modified       :     [2016-11-14 21:06]                            *
*     Description         :     State functions.                              *
******************************************************************************/
#include "state.h"
#include "src/state/args/args.h"
#include <string.h>
/*****************************************************************************/
//static const char *default_fp = "~/.mario/levels/map_1_1.txt";
static const char *default_fp =
    "/Users/Klas/Git/my-projects/jump-squad/levels/special/world_1_1";
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
    /* Initialize map */
    state->fp = (args->fp == NULL)? strdup(default_fp):args->fp;
    if((state->map = init_map(state->fp)) == NULL) {
        free_state(state);
        free_args(args);
        return NULL;
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
        iter->update(iter, map);
    }
    for(iter = map->unit; iter != NULL; iter = iter->next) {
        iter->update(iter, map);
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
