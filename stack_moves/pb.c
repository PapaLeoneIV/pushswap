#include "../pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

void pb(dll_list **stack_b, dll_list **stack_a)
{
	int*		val_a;
	dll_list*	newnode;
	dll_list*	tmp;

	if(ft_dll_size(*stack_a) == 0)
		return ;
	val_a = malloc(sizeof(int));
	if(!val_a)
		return ;
	ft_dll_return_head(stack_a);
	if(ft_dll_size(*stack_a) == 1)
	{
		*val_a = *(int* )(*stack_a)->val;
		free((*stack_a)->val);
		free((*stack_a));
		*stack_a = NULL;
		newnode = ft_dll_new(val_a);
		if(!newnode)
			return ;
		ft_dll_insert_head(&(*stack_a), newnode);
		return;
	}
	tmp = (*stack_a)->next;
	*val_a = *(int* )(*stack_a)->val;
	free((*stack_a)->val);
	free((*stack_a));
	tmp->prev = NULL;
	ft_dll_return_head(&tmp);
	(*stack_a) = tmp; 
	newnode = ft_dll_new(val_a);
	if(!newnode)
		return;
	ft_dll_insert_head(&(*stack_b), newnode);
}
/* int main()
{
	dll_list *a_head;
	dll_list *b_head;
	int arr[] = {1, 2,3, 4};
	int arr2[] = {23,5,6};
	a_head = ft_dll_initi(arr, 4);
	b_head = ft_dll_initi(arr2, 3);


	pb(&b_head, &a_head);
    ft_dll_return_head(&a_head);

	while(a_head != NULL)
	{
		printf("%i\n", *(int *)a_head->val);
		if(a_head->next == NULL)
				break;
		a_head = a_head->next;
	} 
	printf("[----------------------]\n");
    	ft_dll_return_head(&b_head);

	 while(b_head != NULL)
	{
		printf("%i\n", *(int *)b_head->val);
		if(b_head->next == NULL)
				break;
		b_head = b_head->next;
	}
	ft_dll_return_head(&a_head);
	ft_dll_return_head(&b_head);
	ft_dll_clear(&a_head, free);
	ft_dll_clear(&b_head, free);
} */