#include "clist_includes.h"

int CListInit(CList *outlist, size_t member_size)
{
    if (outlist == NULL)
    {
        return clist_error_null_reference;
    }

    _CList *list;
    list = malloc(sizeof(_CList) + member_size);

    if (list == NULL)
    {
        (*outlist) = NULL;
        return clist_error_bad_alloc;
    }

    list->member_size = member_size;
    list->capacity = 1;
    list->size = 0;

    (*outlist) = list;

    return clist_no_error; // Success
}