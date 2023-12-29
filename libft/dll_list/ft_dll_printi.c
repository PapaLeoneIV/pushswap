#include "../libft.h"
#include "ft_printf.h"

void ft_dll_printi(dll_list* list)
{
    dll_list* ptr;

    ptr = list;
    ft_printf("\n[Lista] : ");
    while(ptr != NULL)
    {
        ft_printf("\n\tidx->[%i]  :  [%i]", ptr->index, *(int*)(ptr->val));
        ptr = ptr->next;
    }
    ft_printf("\n");
}