/******************************************************************************
*     File Name           :     input.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 00:04]                            *
*     Last Modified       :     [2016-11-08 13:36]                            *
*     Description         :     Read input.                                   *
******************************************************************************/
#include "input.h"
#include "src/input/keycodes.h"
/*****************************************************************************/
//#ifdef __APPLE__
//#include <ApplicationServices/ApplicationServices.h>
//static int is_pressed(unsigned short key_code) {
//    return CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, key_code);
//}
//#endif
static int is_pressed(unsigned short key_code) {

    return 0;
}
/*---------------------------------------------------------------------------*/
int read_input(player_t *iter) {
    // Exit
    if(is_pressed(KEY__X)) {
        return 0;
    }
    for(; iter != NULL; iter = (player_t*)iter->next) {
        // X-dir
        if(is_pressed(iter->keys.left)) {
            iter->dir.x = LEFT;
        } else if(is_pressed(iter->keys.right)) {
            iter->dir.x = RIGHT;
        } else {
            iter->dir.x = NONE;
        }
        // Y-dir
        if(is_pressed(iter->keys.up)) {
            iter->dir.y = UP;
        } else if(is_pressed(iter->keys.down)) {
            iter->dir.y = DOWN;
        } else {
            iter->dir.y = NONE;
        }
    }
    return 1;
}
