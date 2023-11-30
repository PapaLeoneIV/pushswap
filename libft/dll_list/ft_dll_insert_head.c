#include "../libft.h"

void ft_dll_insert_head(dll_list **head, dll_list *new) 
{
    if(*head == NULL)
    {
        *head = new;
        new->prev = NULL;
        new->next = NULL;
    }
    else
    {
        new->next = *head;
        new->prev = NULL;
        (*head)->prev = new;
        *head = new;
    }
}
