#include "clist_includes.h"

CLISTAPI void CListDeinit(CList list_pointer)
{
    _CList *list = (_CList *)list_pointer;
    free(list->data);
    free(list);
}