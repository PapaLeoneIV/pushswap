#include "../libft.h"

dll_list    *ft_dll_initi_to_zero(int len)
{
	dll_list    *head;
	dll_list    *newnode;
	int* val;
	int          i;

	i = 0;
	head = NULL;
	while(i < len)
	{
		val = malloc(sizeof(int));
		if (!val) 
		{
			ft_dll_return_head(&head);
			ft_dll_clear(&head, free);
			return(NULL);
		}
		*val = 0;
		newnode = ft_dll_new(val);
		if(!newnode)
		{
			ft_dll_return_head(&head);
			ft_dll_clear(&head, free);
			return (NULL);
		}
		ft_dll_insert_tail(&head, newnode);
		i++;
	}
	return (head);
}
/* int main() {
	dll_list *start = ft_dll_initi_to_zero(5);
	int i = 0;
	while (start != NULL) {
		printf("%i -> ", *(int *)(start)->val);
		start = start->next;
		i++;
	}
} */