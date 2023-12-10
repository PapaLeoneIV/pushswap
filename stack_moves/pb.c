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
	ft_dll_return_tail(stack_a);
	tmp = (*stack_a)->prev;
	*val_a = *(int* )(*stack_a)->val;
	free((*stack_a)->val);
	free((*stack_a));
	tmp->next = NULL;
	ft_dll_return_head(&tmp);
	(*stack_a) = tmp; 
	newnode = ft_dll_new(val_a);
	if(!newnode)
		return;
	ft_dll_insert_tail(&(*stack_b), newnode);	
}
/* int main()
{
	dll_list *a_head;
	dll_list *b_head;
	int arr[] = {1, 2,3, 4};
	int arr2[] = {};
	a_head = ft_dll_initi(arr, 4);
	b_head = ft_dll_initi(arr2, 0);


	pb(&b_head, &a_head);
	while(a_head != NULL)
	{
		printf("%i\n", *(int *)a_head->val);
		if(a_head->next == NULL)
				break;
		a_head = a_head->next;
	} 
	printf("[----------------------]\n");
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