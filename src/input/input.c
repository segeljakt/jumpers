/******************************************************************************
*     File Name           :     input.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 00:04]                            *
*     Last Modified       :     [2016-11-02 18:37]                            *
*     Description         :     Read input.                                   *
******************************************************************************/
#include "input.h"
#include "src/input/keycodes.h"
/*****************************************************************************/
#ifdef __APPLE__
#include <ApplicationServices/ApplicationServices.h>
static int is_pressed(unsigned short key_code) {
    CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, key_code);
}
#endif
/*---------------------------------------------------------------------------*/
int read_input(player_t *iter) {
    // Exit
    if(is_pressed(KEY_X)) {
        return 0;
    }
    for(; iter != NULL; iter = iter->next) {
        // X-axis
        if(is_pressed(iter->key.left)) {
            iter->pos.x_axis = LEFT;
        } else if(is_pressed(iter->key.right)) {
            iter->pos.x_axis = RIGHT;
        } else {
            iter->pos.x_axis = NONE;
        }
        // Y-axis
        if(is_pressed(iter->key.up)) {
            iter->pos.y_axis = UP;
        } else if(is_pressed(iter->key.down)) {
            iter->pos.y_axis = DOWN;
        } else {
            iter->pos.y_axis = NONE;
        }
    }
}
