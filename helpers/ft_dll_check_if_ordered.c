
#include "pushswap.h"

int ft_dll_check_if_ordered(t_dll_list *stack)
{
    t_dll_list *ptr;

    ptr = stack;
    while(ptr != NULL)
    {
        if(ptr->next == NULL)
            break ;
        if(*(int*)ptr->val > *(int*)ptr->next->val)
            return 0;
        ptr = ptr->next;
    }
    return 1;
}