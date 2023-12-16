#include "../libft.h"

void ft_dll_update_index(dll_list** head)
{   
    int index;

    index = 0;
    ft_dll_return_head(head);
    while((*head) != NULL)
    {
        (*head)->index = index;
        if((*head)->next == NULL)
            break;
        (*head) = (*head)->next;
        index++;
    }
    ft_dll_return_head(head);
}