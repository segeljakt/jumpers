/******************************************************************************
*     File Name           :     type.h                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-04 20:58]                            *
*     Last Modified       :     [2016-11-05 14:13]                            *
*     Description         :     All typedefs.                                 *
******************************************************************************/
#ifndef TYPE_H
#define TYPE_H
/*****************************************************************************/
#include <ncurses.h>
/*****************************************************************************/
typedef struct args_s args_t;
typedef struct state_s state_t;
typedef struct change_s change_t;
typedef struct online_s online_t;
typedef struct peer_s peer_t;
typedef struct map_s map_t;
typedef struct player_s player_t;
typedef struct keys_s keys_t;
typedef struct unit_s unit_t;
typedef struct block_s block_t;
typedef struct collision_s collision_t;
typedef void obj_t;
typedef struct body_s body_t;
typedef struct gfx_s gfx_t;
typedef int (*update_f)(map_t*, obj_t*);
typedef int (*serialize_f)(obj_t*);
typedef int (*draw_f)(WINDOW*, obj_t*);
typedef int (*collide_f)(obj_t *, int, obj_t*);
/*****************************************************************************/
#endif // TYPE_H
