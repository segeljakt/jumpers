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
    KEY__A = 0x00,
    KEY__B = 0x0B,
    KEY__C = 0x08,
    KEY__D = 0x02,
    KEY__E = 0x0E,
    KEY__F = 0x03,
    KEY__G = 0x05,
    KEY__H = 0x04,
    KEY__I = 0x22,
    KEY__J = 0x26,
    KEY__K = 0x28,
    KEY__L = 0x25,
    KEY__M = 0x2E,
    KEY__N = 0x2D,
    KEY__O = 0x1F,
    KEY__P = 0x23,
    KEY__Q = 0x0C,
    KEY__S = 0x01,
    KEY__T = 0x11,
    KEY__U = 0x20,
    KEY__V = 0x09,
    KEY__W = 0x0D,
    KEY__X = 0x07,
    KEY__Y = 0x10,
    KEY__Z = 0x06,
    KEY__0 = 0x1D,
    KEY__1 = 0x12,
    KEY__2 = 0x13,
    KEY__3 = 0x14,
    KEY__4 = 0x15,
    KEY__5 = 0x17,
    KEY__6 = 0x16,
    KEY__7 = 0x1A,
    KEY__8 = 0x1C,
    KEY__9 = 0x19,
    KEY__LEFT = 0x7B,
    KEY__RIGHT = 0x7C,
    KEY__DOWN = 0x7D,
    KEY__UP = 0x7E,
    KEY__RETURN = 0x24,
    KEY__TAB = 0x30,
    KEY__SPACE = 0x31,
    KEY__DELETE = 0x33,
    KEY__ESCAPE = 0x35,
    KEY__LSHIFT = 0x38,
    KEY__LALT = 0x3A,
    KEY__CAPSLOCK = 0x39,
    KEY__LCONTROL = 0x3B,
    KEY__RSHIFT = 0x3C,
    KEY__RALT = 0x3D,
    KEY__RCONTROL = 0x3E
};
#endif
/*****************************************************************************/
#endif // KEYCODES_H
