#include "clist_includes.h"

int CListAt(CList list, size_t index, void **out_value)
{
    if (list == NULL)
    {
        return clist_error_null_reference;
    }

    (*out_value) = NULL;

    if (index >= list->size)
    {
        return clist_error_out_of_range;
    }

    (*out_value) = list->data + (index * list->member_size);

    return clist_no_error; // Success
}