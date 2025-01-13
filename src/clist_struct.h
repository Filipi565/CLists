#ifndef CLIST_STRUCT_H
#define CLIST_STRUCT_H

#include <stddef.h>

typedef struct _CList
{
    size_t member_size;
    size_t capacity;
    size_t size;
    void *data;
} _CList;

#endif