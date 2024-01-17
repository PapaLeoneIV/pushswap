#include "../libft.h"

void ft_del_lastnode(dll_list* list)
{
	dll_list* tmp;
	
	tmp = list;
	if(!list)
		return ;
	while (tmp != NULL)
	{
		if(tmp->next->next == NULL)
		{
			free(tmp->next);
			tmp->next = NULL;
			return ;
		}
		tmp = tmp->next;
	}
}