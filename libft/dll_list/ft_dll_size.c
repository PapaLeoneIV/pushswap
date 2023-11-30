#include "../libft.h"

int	ft_dll_size(dll_list *dll)
{
	int		length;
	dll_list	*ptr;

	ptr = dll;
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