#include "../libft.h"

dll_list	*ft_dll_return_tail(dll_list *lst)
{
	dll_list	*temp;

	temp = lst;
	if (!temp)
		return (NULL);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}