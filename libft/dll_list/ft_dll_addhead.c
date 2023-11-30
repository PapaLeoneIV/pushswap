#include "../libft.h"

void	ft_dll_addhead(dll_list **head, dll_list *new)
{
	if (head == NULL)
    {
        new->next = *head;
        new->prev = NULL;
    }
	else
		(*head)->prev = new;
    *head = new;
}