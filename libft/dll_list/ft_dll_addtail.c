#include "../libft.h"

void ft_dll_addtail(dll_list **head, dll_list *new)
{
    dll_list *tmp;

    tmp = *head;
    new->next = NULL;
    if(*head == NULL)
    {
        *head = new;
        new->prev = NULL;
    }
    while(tmp != NULL)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
}