#include "../libft.h"
//#include "ft_printf.h"

dll_list	*ft_dll_new(void *val)
{
	dll_list	*new;

	new = malloc(sizeof(dll_list));
	if (!new)
		return (NULL);
	new->val = val;
	new->next = NULL;
    new->prev = NULL;
	return (new);
}

/* 

int main()
{
	dll_list *head;
	dll_list *first;

	head = NULL;
	first = ft_dll_new((char *)"stringa!");
	ft_printf("%s\n", first->val);

} */