#include "clist_includes.h"
#include <memory.h>

int CListAppend(CList list, const void *value)
{
    if (list == NULL)
    {
        return clist_error_null_reference;
    }

    if (list->size + 1 > list->capacity)
    {
        list->capacity *= 2;
        list = realloc(list, sizeof(_CList) + list->capacity * list->member_size);
        if (list == NULL)
        {
            return clist_error_bad_alloc;
        }
    }

    void *obj = list->data + (list->size * list->member_size);
    memmove(obj, value, list->member_size);

    list->size++;

    return clist_no_error;
}