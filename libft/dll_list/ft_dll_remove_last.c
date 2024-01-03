#include "../libft.h"

void ft_dll_remove_last(dll_list** stack_b)
{
	dll_list* ptr;
	dll_list* prev;
	if(!(*stack_b) || !stack_b)
		return;
	ptr = *(stack_b);
	while(ptr != NULL)
	{
		prev = ptr->prev;
		if(ptr->next == NULL)
		{
			prev->next = NULL;
			free(ptr->val);
			free(ptr->next);
			break;
		}
		ptr = ptr->next;
	}
}
