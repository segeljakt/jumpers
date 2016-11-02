/******************************************************************************
*     File Name           :     cfg.h                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-28 21:14]                            *
*     Last Modified       :     [2016-11-02 18:37]                            *
*     Description         :     Map config.                                   *
******************************************************************************/
#ifndef MAP_CFG_H
#define MAP_CFG_H
/*****************************************************************************/
#define MAX_LOCAL_PLAYERS 2
/*****************************************************************************/
enum EDITOR_CHARS {
    EDITOR_CHAR_SHROOM          = 'A',
    EDITOR_CHAR_QUESTION_BLOCK  = 'B',
    EDITOR_CHAR_COIN            = 'C',
    EDITOR_CHAR_SWITCH          = 'D',
    EDITOR_CHAR_NORMAL_BLOCK    = 'E',
    EDITOR_CHAR_GOOMBA          = 'G',
    EDITOR_CHAR_STAR            = 'I',
    EDITOR_CHAR_PLATFORM        = 'J',
    EDITOR_CHAR_BREAKABLE_BLOCK = 'L',
    EDITOR_CHAR_COIN_BLOCK      = 'U',
    EDITOR_CHAR_VPIPE_TL        = 'N',
    EDITOR_CHAR_VPIPE_TR        = 'O',
    EDITOR_CHAR_VPIPE_BL        = 'a',
    EDITOR_CHAR_VPIPE_BR        = 'b',
    EDITOR_CHAR_HPIPE_TL        = 'R',
    EDITOR_CHAR_HPIPE_BL        = 'e',
    EDITOR_CHAR_HPIPE_TM        = 'S',
    EDITOR_CHAR_HPIPE_BM        = 'f',
    EDITOR_CHAR_HPIPE_TR        = 'T',
    EDITOR_CHAR_HPIPE_BR        = 'g',
    EDITOR_CHAR_KOOPA_T         = 'P',
    EDITOR_CHAR_KOOPA_B         = 'c',
    EDITOR_CHAR_PLANT_T         = 'Q',
    EDITOR_CHAR_PLANT_B         = 'd',
    EDITOR_CHAR_FLAG_L          = 'j',
    EDITOR_CHAR_FLAG_R          = 'l',
    EDITOR_CHAR_FLAGTOP         = 'K',
    EDITOR_CHAR_FLAGPOLE        = 'k',
    EDITOR_CHAR_FILL            = 'n',
    EDITOR_CHAR_KEEP1           = 'o',
    EDITOR_CHAR_KEEP2           = 'p',
    EDITOR_CHAR_KEEP3           = 'q',
    EDITOR_CHAR_KEEP4           = '1',
    EDITOR_CHAR_KEEP5           = '2',
    EDITOR_CHAR_KEEP6           = '3',
    EDITOR_CHAR_CLOUD_TL        = 'r',
    EDITOR_CHAR_CLOUD_BL        = '4',
    EDITOR_CHAR_CLOUD_TM        = 's',
    EDITOR_CHAR_CLOUD_BM        = '5',
    EDITOR_CHAR_CLOUD_TR        = 't',
    EDITOR_CHAR_CLOUD_BR        = '6',
    EDITOR_CHAR_PEAK_L          = 'u',
    EDITOR_CHAR_PEAK_M          = 'v',
    EDITOR_CHAR_PEAK_T          = '7',
    EDITOR_CHAR_PEAK_R          = '8',
    EDITOR_CHAR_SHRUB_L         = 'w',
    EDITOR_CHAR_SHRUB_M         = 'x',
    EDITOR_CHAR_SHRUB_R         = 'y',
    EDITOR_CHAR_MARIO           = '?'
}
/*---------------------------------------------------------------------------*/
enum CHARS {
    CHAR_SHROOM          = 'A',
    CHAR_QUESTION_BLOCK  = 'B',
    CHAR_COIN            = 'C',
    CHAR_SWITCH          = 'D',
    CHAR_NORMAL_BLOCK    = 'E',
    CHAR_GOOMBA          = 'G',
    CHAR_STAR            = 'I',
    CHAR_PLATFORM        = 'J',
    CHAR_BREAKABLE_BLOCK = 'L',
    CHAR_COIN_BLOCK      = 'U',
    CHAR_VPIPE_TL        = 'N',
    CHAR_VPIPE_TR        = 'O',
    CHAR_VPIPE_BL        = 'a',
    CHAR_VPIPE_BR        = 'b',
    CHAR_HPIPE_TL        = 'R',
    CHAR_HPIPE_BL        = 'e',
    CHAR_HPIPE_TM        = 'S',
    CHAR_HPIPE_BM        = 'f',
    CHAR_HPIPE_TR        = 'T',
    CHAR_HPIPE_BR        = 'g',
    CHAR_KOOPA_T         = 'P',
    CHAR_KOOPA_B         = 'c',
    CHAR_PLANT_T         = 'Q',
    CHAR_PLANT_B         = 'd',
    CHAR_FLAG_L          = 'j',
    CHAR_FLAG_R          = 'l',
    CHAR_FLAGTOP         = 'K',
    CHAR_FLAGPOLE        = 'k',
    CHAR_FILL            = 'n',
    CHAR_KEEP1           = 'o',
    CHAR_KEEP2           = 'p',
    CHAR_KEEP3           = 'q',
    CHAR_KEEP4           = '1',
    CHAR_KEEP5           = '2',
    CHAR_KEEP6           = '3',
    CHAR_CLOUD_TL        = 'r',
    CHAR_CLOUD_BL        = '4',
    CHAR_CLOUD_TM        = 's',
    CHAR_CLOUD_BM        = '5',
    CHAR_CLOUD_TR        = 't',
    CHAR_CLOUD_BR        = '6',
    CHAR_PEAK_L          = 'u',
    CHAR_PEAK_M          = 'v',
    CHAR_PEAK_T          = '7',
    CHAR_PEAK_R          = '8',
    CHAR_SHRUB_L         = 'w',
    CHAR_SHRUB_M         = 'x',
    CHAR_SHRUB_R         = 'y',
    CHAR_MARIO           = '?'
}
/*---------------------------------------------------------------------------*/
enum COLOR_CODES {
    COLOR_BLACK = 0,
    COLOR_RED = 1,
    COLOR_GREEN = 2,
    COLOR_YELLOW = 3,
    COLOR_BLUE = 4,
    COLOR_MAGENTA = 5,
    COLOR_CYAN = 6,
    COLOR_WHITE = 7
}
/*****************************************************************************/
#endif // GRAPHICS_CFG_H
