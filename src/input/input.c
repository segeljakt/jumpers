/******************************************************************************
*     File Name           :     input.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 00:04]                            *
*     Last Modified       :     [2016-11-03 15:51]                            *
*     Description         :     Read input.                                   *
******************************************************************************/
#include "input.h"
#include "src/input/keycodes.h"
/*****************************************************************************/
#ifdef __APPLE__
#include <ApplicationServices/ApplicationServices.h>
static int is_pressed(unsigned short key_code) {
    return CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, key_code);
}
#endif
/*---------------------------------------------------------------------------*/
int read_input(player_t *iter) {
    // Exit
    if(is_pressed(KEY__X)) {
        return 0;
    }
    for(; iter != NULL; iter = iter->next) {
        // X-dir
        if(is_pressed(iter->keys.left)) {
            iter->body.d_x = LEFT;
        } else if(is_pressed(iter->keys.right)) {
            iter->body.d_x = RIGHT;
        } else {
            iter->body.d_x = NONE;
        }
        // Y-dir
        if(is_pressed(iter->keys.up)) {
            iter->body.d_y = UP;
        } else if(is_pressed(iter->keys.down)) {
            iter->body.d_y = DOWN;
        } else {
            iter->body.d_y = NONE;
        }
    }
    return 1;
}
