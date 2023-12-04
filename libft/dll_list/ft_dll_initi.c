#include "../libft.h"

dll_list    *ft_dll_initi(int *arr, int len)
{
	dll_list    *head;
	dll_list    *newnode;
	dll_list    *tmp;
	int          i;

	i = 0;
	head = NULL;
	while(i < len)
	{
		newnode = ft_dll_new(&arr[i]);
		if(!newnode)
		{
			while(head != NULL)
			{
				tmp = head->next;
				free(head);
				head = tmp;
				return (NULL);
			}
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
 	while(i < 5)
	{
		printf("%i\n", *(int *)start->val);
		start = start->next;
		i++;
	} 



} */