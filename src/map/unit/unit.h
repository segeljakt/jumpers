/******************************************************************************
*     File Name           :     unit.h                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-01 22:20]                            *
*     Last Modified       :     [2016-11-01 22:25]                            *
*     Description         :     Unit in map.                                  *
******************************************************************************/
#ifndef UNIT_H
#define UNIT_H
/*****************************************************************************/
#include "src/map/map.h"
/*****************************************************************************/
typedef struct map_s map_t;
typedef struct unit_s unit_t;
typedef struct pos_s pos_t;
typedef void (*unit_action_f)(map_t*, unit_t*);
/*****************************************************************************/
struct pos_s {
    double x;
    double y;
    int x_axis;
    int y_axis;
};
/*---------------------------------------------------------------------------*/
struct unit_s {
    char c;
    void *data;
    pos_t pos;
    unit_action_f action;
    unit_t *next;
};
/*****************************************************************************/
#endif // UNIT_H
