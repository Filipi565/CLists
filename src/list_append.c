#include "clist_includes.h"
#include <memory.h>

int CListAppend(CList list, const void *value)
{
    if (list == NULL)
    {
        return clist_error_null_reference;
    }

    _CList *list_ptr = (_CList *)list;

    if (list_ptr->size + 1 > list_ptr->capacity)
    {
        list_ptr->capacity *= 2;
        list_ptr = realloc(list_ptr, sizeof(_CList) + list_ptr->capacity * list_ptr->member_size);
        if (list_ptr == NULL)
        {
            return clist_error_bad_alloc;
        }
    }

    void *obj = list_ptr->data + (list_ptr->size * list_ptr->member_size);
    memmove(obj, value, list_ptr->member_size);

    list_ptr->size++;

    return clist_no_error;
}