/******************************************************************************
*     File Name           :     serialize.h                                   *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-09 11:54]                            *
*     Last Modified       :     [AUTO_UPDATE_BEFORE_SAVE]                     *
*     Description         :     Serializer.                                   *
******************************************************************************/
#ifndef SERIALIZE_H
#define SERIALIZE_H
/*****************************************************************************/
typedef struct change_s change_t;
/*****************************************************************************/
struct change_s {
    void *data;
    size_t len;
    change_t *next;
};
/*****************************************************************************/
#endif // SERIALIZE_H
