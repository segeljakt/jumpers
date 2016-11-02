/******************************************************************************
*     File Name           :     cfg.h                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 00:44]                            *
*     Last Modified       :     [2016-10-30 22:47]                            *
*     Description         :     Config file.                                  *
******************************************************************************/
#ifndef CFG_H
#define CFG_H
/*****************************************************************************/
#define TICKRATE 20         // Update loop
#define SCREEN_WIDTH 16     // No. blocks on screen vertically
#define SCREEN_HEIGHT 16    // No. blocks on screen horizontally
#define COLLISION 8         // 8px collision, each character is 16px
                            // Collision  : Characters on screen
                            //  16px      :  16x16  = 256
                            //  8px       :  32x32  = 1024
                            //  4px       :  64x64  = 4096
                            //  2px       : 128x128 = 16384
                            //  1px       : 256x256 = 65536
/*****************************************************************************/
#endif // CFG_H
