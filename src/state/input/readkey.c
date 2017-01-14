/******************************************************************************
*     File Name           :     readkey.c                                     *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-14 09:24]                            *
*     Last Modified       :     [2017-01-09 21:16]                            *
*     Description         :     Read if a key is currently pressed.           *
******************************************************************************/
#include "./readkey.h"
#ifdef __APPLE__
#include <ApplicationServices/ApplicationServices.h>
int is_pressed(unsigned short key_code) {
    return CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, key_code);
}
#endif
