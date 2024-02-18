#include "../libft.h"

int ft_dll_get_node_index(t_dll_list *list, int value)
{
    int i;
    t_dll_list *ptr;

    i = 0;
    ptr = list;
    if (!list)
        return (-1);
    ft_dll_return_head(&ptr);
    while (ptr != NULL)
    {
        if (*(int *)ptr->val == value)
            return (i);
        ptr = ptr->next;
        i++;
    }
    return (-1);
}