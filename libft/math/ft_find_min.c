#include "libft.h"

int	ft_find_min(t_dll_list *a)
{
	int			min;
	int			idx;
	t_dll_list	*ptr;

	min = INT_MAX;
	ptr = a;
	while (ptr != NULL)
	{
		if (*(int *)ptr->val < min)
		{
			min = *(int *)ptr->val;
			idx = ptr->index;
		}
		ptr = ptr->next;
	}
	return (idx);
}