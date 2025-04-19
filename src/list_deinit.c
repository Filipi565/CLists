#include "clist_includes.h"

void CListDeinit(CList list_pointer)
{
    if (list_pointer != NULL)
    {
        free(list_pointer);
    }
}