/*****************************************************************************
*     File Name           :     main.c
*     Created By          :     Klas Segeljakt
*     Creation Date       :     [2016-10-29 23:33]
*     Last Modified       :     [2016-10-30 17:09]
*     Description         :     Game loop.
******************************************************************************/
#include "state.h"
#include "cfg.h"
#include "input.h"
#include "update.h"
#include "online.h"
#include <ncurses.h>
int main(int argc, char *argv[]) {
    state_t *state;
    input_t *input;

    state = init_state(argc, argv);

    if(state->opts.peer) {
        if(setup_online(&state) != 0) {
            return 0;
        }
    } else if(state->opts.host) {
        
    }else {
        state->
    }
    initscr();

    while(read_input(input)) {
        update(state, input);
        sync(state);
        napms(TICKRATE);
    }

    state->active = false;

    endwin();

    return 0;
}

