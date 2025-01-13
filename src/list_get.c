#include "clist_includes.h"

size_t CListGetCapacity(CList list)
{
    return ((_CList *)list)->capacity;
}

size_t CListGetSize(CList list)
{
    return ((_CList *)list)->size;
}