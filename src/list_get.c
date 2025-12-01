#include "clist_includes.h"

size_t CListGetCapacity(CList list)
{
    return list->capacity;
}

size_t CListGetSize(CList list)
{
    return list->size;
}