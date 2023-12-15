#include "../libft.h"

void ft_dll_insert_tail(dll_list **head, dll_list *new)
{

	dll_list *temp;
	int index_temp;

    index_temp = 0;
	if (*head == NULL)
	{
        *head = new;
		return;
	}
    ft_dll_return_tail(head);
	temp = *head;
	temp->next = new;
	new->prev = temp;
    new->index = (temp->index) + 1;
    ft_dll_return_head(head);
}
