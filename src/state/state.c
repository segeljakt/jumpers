/******************************************************************************
*     File Name           :     state.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-29 23:40]                            *
*     Last Modified       :     [2016-11-16 17:09]                            *
*     Description         :     State functions.                              *
******************************************************************************/
#include "state.h"
#include "src/state/args/args.h"
#include <string.h>
/*****************************************************************************/
//static const char *default_fp = "~/.mario/levels/map_1_1.txt";
static const char *default_fp =
    "/Users/Klas/Git/my-projects/mario/levels/special/testmap";
//    "/Users/Klas/Git/my-projects/mario/levels/special/world_1_1";
/*****************************************************************************/
int setup_scr() {
    initscr();
#ifndef DEBUG
    system("/Users/Klas/Git/my-projects/mario/levels/font/font.applescript");
#endif // DEBUG
    start_color();
    use_default_colors();
    init_pair(COLOR_RED_NONE, COLOR_RED, -1);
    init_pair(COLOR_BLUE_NONE, COLOR_BLUE, -1);
    curs_set(0);
    raw();


    return 0;
}
/*---------------------------------------------------------------------------*/
int teardown_scr() {
#ifndef DEBUG
    system("/Users/Klas/Git/my-projects/mario/levels/font/font.applescript");
#endif // DEBUG
    timeout(0);
    // Clear all input
    int c;
    while((c = getch()) != '\n' && c != EOF) {}
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
    state->tui = init_tui(state->map);
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
