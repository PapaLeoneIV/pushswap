#include "../libft.h"

dll_list	*ft_dll_return_head(dll_list *lst)
{
	dll_list	*temp;

	temp = lst;
	if (!temp)
		return (NULL);
	while (temp->prev != NULL)
	{
		temp = temp->prev;
	}
	return (temp);
}