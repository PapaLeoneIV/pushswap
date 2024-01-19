#include "../libft.h"

int ft_dll_get_tail_index(dll_list* list)
{
    dll_list* ptr;

    ptr = list;
    while(ptr->next != NULL)
        ptr = ptr->next;
    return ptr->index;
}