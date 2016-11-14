/******************************************************************************
*     File Name           :     sprite.h                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-28 21:14]                            *
*     Last Modified       :     [2016-11-12 12:07]                            *
*     Description         :     Sprite config.                                *
******************************************************************************/
#ifndef MAP_SPRITE_H
#define MAP_SPRITE_H
/*****************************************************************************/
#define BLOCKLENGTH 16
/*****************************************************************************/
enum EDITOR_ONLY_CHARS {
    EDITOR_CHAR_COIN_BLOCK      = 'U'
};
/*---------------------------------------------------------------------------*/
enum CHARS {
    CHAR_NONE                   = ' ',
    CHAR_SHROOM                 = 'A',
    CHAR_MYSTERY_BLOCK          = 'B',
    CHAR_COIN                   = 'C',
    CHAR_SWITCH                 = 'D',
    CHAR_NORMAL_BLOCK           = 'E',
    CHAR_GOOMBA                 = 'G',
    CHAR_STAR                   = 'I',
    CHAR_PLATFORM               = 'J',
    CHAR_BRICK_BLOCK            = 'L',
    CHAR_COIN_BLOCK             = 'U',
    CHAR_VPIPE_TL               = 'N',
    CHAR_VPIPE_TR               = 'O',
    CHAR_VPIPE_BL               = 'a',
    CHAR_VPIPE_BR               = 'b',
    CHAR_HPIPE_TL               = 'R',
    CHAR_HPIPE_BL               = 'e',
    CHAR_HPIPE_TM               = 'S',
    CHAR_HPIPE_BM               = 'f',
    CHAR_HPIPE_TR               = 'T',
    CHAR_HPIPE_BR               = 'g',
    CHAR_KOOPA_T                = 'P',
    CHAR_KOOPA_B                = 'c',
    CHAR_PIRANHA_T              = 'Q',
    CHAR_PIRANHA_B              = 'd',
    CHAR_FLAG_L                 = 'j',
    CHAR_FLAG_R                 = 'l',
    CHAR_FLAGTOP                = 'K',
    CHAR_FLAGPOLE               = 'k',
    CHAR_FILL                   = 'n',
    CHAR_KEEP1                  = 'o',
    CHAR_KEEP2                  = 'p',
    CHAR_KEEP3                  = 'q',
    CHAR_KEEP4                  = '1',
    CHAR_KEEP5                  = '2',
    CHAR_KEEP6                  = '3',
    CHAR_CLOUD_TL               = 'r',
    CHAR_CLOUD_BL               = '4',
    CHAR_CLOUD_TM               = 's',
    CHAR_CLOUD_BM               = '5',
    CHAR_CLOUD_TR               = 't',
    CHAR_CLOUD_BR               = '6',
    CHAR_PEAK_L                 = 'u',
    CHAR_PEAK_M                 = 'v',
    CHAR_PEAK_T                 = '7',
    CHAR_PEAK_R                 = '8',
    CHAR_SHRUB_L                = 'w',
    CHAR_SHRUB_M                = 'x',
    CHAR_SHRUB_R                = 'y',
    CHAR_MARIO                  = '?',
    CHAR_USED_BLOCK             = ' '  // NOT YET ADDED
};
/*---------------------------------------------------------------------------*/
enum COLLISION_TYPES {
    COLLISION_NONE,
    COLLISION_NORMAL,
    COLLISION_PLAYER,
    COLLISION_DEADLY
};
/*---------------------------------------------------------------------------*/
enum OBJ_TYPES {
    /* Players */
    MARIO,
    /* Enemies */
    GOOMBA,
    KOOPA,
    PIRANHA,
    /* Items */
    ITEM,
    /* Blocks */
    INDESTRUCTIBLE,
    DESTRUCTIBLE
};
/*---------------------------------------------------------------------------*/
enum FG_BG_COLORS {
    COLOR_RED_NONE,
    COLOR_BLUE_NONE
};
/*****************************************************************************/
#endif // GRAPHICS_CFG_H
