#include "../libft.h"

int	ft_dll_size(dll_list *head)
{
	int		length;
	dll_list	*ptr;

	ptr = head;
	length = 0;
	if (!ptr)
		return (0);
	while (ptr->next != NULL)
	{
		length++;
		ptr = ptr->next;
	}
	if (ptr->next == NULL)
		length++;
	return (length);
}