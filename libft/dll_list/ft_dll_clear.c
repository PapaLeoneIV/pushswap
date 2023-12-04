#include "../libft.h"

void	ft_dll_clear(dll_list **lst, void (*del)(void *))
{
	dll_list		*ptr;
	dll_list		*temp;

	if (!*lst ||!lst || !del)
		return ;
	ptr = (*lst);
	while (ptr != NULL)
	{
		temp = ptr;
		ptr = temp->next;
		free(temp);
	}
	*lst = NULL;
}