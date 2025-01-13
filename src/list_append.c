#include "clist_includes.h"
#include <memory.h>

CLISTAPI int CListAppend(CList list, void *value)
{
    _CList *list_ptr = (_CList *)list;

    if (list_ptr->size + 1 > list_ptr->capacity)
    {
        list_ptr->capacity *= 2;
        list_ptr->data = realloc(list_ptr->data, list_ptr->capacity * list_ptr->member_size);
        if (list_ptr->data == NULL)
        {
            CListDeinit(list);
            return clist_error_bad_alloc;
        }
    }

    void *obj = ((char *)list_ptr->data) + (list_ptr->size * list_ptr->member_size);
    memmove(obj, value, list_ptr->member_size);

    list_ptr->size++;

    return clist_no_error;
}