#include "../libft.h"

void    ft_dll_return_tail(dll_list **lst)
{
    while(!lst || !*lst || (*lst)->next)
    {
        *lst = (*lst)->next;
    }
}