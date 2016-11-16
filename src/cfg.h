/******************************************************************************
*     File Name           :     cfg.h                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 00:44]                            *
*     Last Modified       :     [2016-11-16 17:37]                            *
*     Description         :     Config file.                                  *
******************************************************************************/
#ifndef CFG_H
#define CFG_H
/*****************************************************************************/
#define TICKRATE 20         // Update loop
#define SCREEN_WIDTH 16     // No. blocks on screen vertically
#define SCREEN_HEIGHT 16    // No. blocks on screen horizontally
#define COLLISION_PX 8      // 8px collision, each character is 16px
                            // Collision  : Characters on screen
                            //  16px      :  16x16  = 256
                            //  8px       :  32x32  = 1024
                            //  4px       :  64x64  = 4096
                            //  2px       : 128x128 = 16384
                            //  1px       : 256x256 = 65536

#define BLOCK_SPACING 2

#define MAX_VEL_Y 0.725
#define MAX_VEL_X 0.2
#define MAX_LOCAL_PLAYERS 2

#define X_OFFSET 10

#define WINDOW_WIDTH 16
#define WINDOW_HEIGHT 16

#define GRAVITY 0.055
#define X_ACCELERATION 0.2

#define IN_BOUNDS(Y, X, HEIGHT, WIDTH) \
    (Y) >= 0 && (Y) < (HEIGHT) && (X) >= 0 && (X) < (WIDTH)
/*****************************************************************************/
#endif // CFG_H
