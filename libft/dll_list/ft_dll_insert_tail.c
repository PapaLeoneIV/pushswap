#include "../libft.h"

void ft_dll_insert_tail(dll_list **head, dll_list *new)
{

    dll_list *temp;
    
    temp = *head;

    if (*head == NULL) {
        new->prev = NULL;
        *head = new;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
    new->next = NULL;
    new->prev = temp;
}

