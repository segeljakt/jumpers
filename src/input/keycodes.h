/******************************************************************************
*     File Name           :     keycodes.h                                    *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-01 00:10]                            *
*     Last Modified       :     [2016-11-02 18:37]                            *
*     Description         :     Keycodes for Mac and Linux.                   *
******************************************************************************/
#ifndef KEYCODES_H
#define KEYCODES_H
/*****************************************************************************/
#ifdef __APPLE__
enum KEYCODES {
    KEY_A = 0x00,
    KEY_B = 0x0B,
    KEY_C = 0x08,
    KEY_D = 0x02,
    KEY_E = 0x0E,
    KEY_F = 0x03,
    KEY_G = 0x05,
    KEY_H = 0x04,
    KEY_I = 0x22,
    KEY_J = 0x26,
    KEY_K = 0x28,
    KEY_L = 0x25,
    KEY_M = 0x2E,
    KEY_N = 0x2D,
    KEY_O = 0x1F,
    KEY_P = 0x23,
    KEY_Q = 0x0C,
    KEY_S = 0x01,
    KEY_T = 0x11,
    KEY_U = 0x20,
    KEY_V = 0x09,
    KEY_W = 0x0D,
    KEY_X = 0x07,
    KEY_Y = 0x10,
    KEY_Z = 0x06,
    KEY_0 = 0x1D,
    KEY_1 = 0x12,
    KEY_2 = 0x13,
    KEY_3 = 0x14,
    KEY_4 = 0x15,
    KEY_5 = 0x17,
    KEY_6 = 0x16,
    KEY_7 = 0x1A,
    KEY_8 = 0x1C,
    KEY_9 = 0x19,
    KEY_LEFT = 0x7B,
    KEY_RIGHT = 0x7C,
    KEY_DOWN = 0x7D,
    KEY_UP = 0x7E,
    KEY_RETURN = 0x24,
    KEY_TAB = 0x30,
    KEY_SPACE = 0x31,
    KEY_DELETE = 0x33,
    KEY_ESCAPE = 0x35,
    KEY_LSHIFT = 0x38,
    KEY_LALT = 0x3A,
    KEY_CAPSLOCK = 0x39,
    KEY_LCONTROL = 0x3B,
    KEY_RSHIFT = 0x3C,
    KEY_RALT = 0x3D,
    KEY_RCONTROL = 0x3E
};
#endif
/*****************************************************************************/
#endif // KEYCODES_H
