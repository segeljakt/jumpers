#include "input.h"
#include <Carbon/Carbon.h>
int isPressed( unsigned short inKeyCode)
{
    unsigned char keyMap[16];
    GetKeys((BigEndianUInt32*) &keyMap);
    return (0 != ((keyMap[ inKeyCode >> 3] >> (inKeyCode & 7)) & 1));
}
