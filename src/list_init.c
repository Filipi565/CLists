#include "clist_includes.h"

int CListInit(CList *outlist, size_t member_size)
{
    _CList *list;
    list = malloc(sizeof(_CList));

    if (list == NULL)
    {
        (*outlist) = NULL;
        return clist_error_bad_alloc;
    }

    list->data = malloc(member_size);
    list->member_size = member_size;
    list->capacity = 1;
    list->size = 0;

    if (list->data == NULL)
    {
        free(list);
        (*outlist) = NULL;
        return clist_error_bad_alloc;
    }

    (*outlist) = list;

    return clist_no_error; // Success
}