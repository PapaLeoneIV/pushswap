#include "../libft.h"

dll_list    *ft_dll_initi(int *arr, int len)
{
	dll_list*	head;
	dll_list*	newnode;
	int*		val;
	int          i;

	i = 0;
	head = NULL;
	while(i < len)
	{
		val = malloc(sizeof(int));
		*val = arr[i];
		if (!val) 
		{
			ft_dll_return_head(&head);
			ft_dll_clear(&head, free);
			return(NULL);
		}
		newnode = ft_dll_new(val);
		if(!newnode)
		{
			ft_dll_return_head(&head);
			ft_dll_clear(&head, free);
			return(NULL);
		}
		ft_dll_insert_tail(&head, newnode);
		i++;
	}
	return (head);
}

/* 
int main()
{
	dll_list *start;
	int arr[5] = {1, 2 , 3, 4, -99};
	start = ft_dll_initi(arr, 5);
	int i = 0;
 	while(start->next != NULL)
	{
		printf("%i\n", *(int *)start->val);
		start = start->next;
		i++;
	}
	ft_dll_return_head(&start);
	ft_dll_clear(&start, free);



}  */