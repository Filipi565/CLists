#include "clist_includes.h"

void CListDeinit(CList list_pointer)
{
    if (list_pointer != NULL)
    {
        _CList *list = (_CList *)list_pointer;
        if (list->data != NULL)
        {
            free(list->data);
        }
        free(list);
    }
}