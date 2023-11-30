#include "../libft.h"

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