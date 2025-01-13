#include "clist_includes.h"

int CListAt(CList list, size_t index, void **out_value)
{
    if (list == NULL)
    {
        return clist_error_null_reference;
    }

    _CList *list_ptr = (_CList *)list;
    (*out_value) = NULL;

    if (index >= list_ptr->size)
    {
        return clist_error_out_of_range;
    }

    (*out_value) = ((char *)list_ptr->data) + (index * list_ptr->member_size);

    return clist_no_error; // Success
}