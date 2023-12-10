 #include "../pushswap.h"
#include "ft_printf.h"
#include "../libft.h"
#include "limits.h"

void pa(dll_list **stack_a, dll_list **stack_b)
{
	int*		val_b;
	dll_list*	newnode;
	dll_list*	tmp;

	/* dovrei gestire i casi in cui non ci sono elementi nello stack da pushare */
	if(ft_dll_size(*stack_b) == 0)
		return ;
	val_b = malloc(sizeof(int));
	if(!val_b)
		return ;
	ft_dll_return_tail(stack_b);
	tmp = (*stack_b)->prev;
	*val_b = *(int* )(*stack_b)->val;
	free((*stack_b)->val);
	free((*stack_b));
	tmp->next = NULL;
	ft_dll_return_head(&tmp);
	(*stack_b) = tmp; 
	newnode = ft_dll_new(val_b);
	if(!newnode)
		return ;
	ft_dll_insert_tail(&(*stack_a), newnode);	
}
/* 
int main()
{
	dll_list *a_head;
	dll_list *b_head;
	int arr[] = {INT_MIN, INT_MIN , INT_MAX, INT_MAX};
	int arr2[] = {-99, -98 , INT_MAX, INT_MAX};
	a_head = ft_dll_initi(arr, 4);
	b_head = ft_dll_initi(arr2, 4);


	pa(&a_head, &b_head);
	while(a_head != NULL)
	{
		printf("%i\n", *(int *)a_head->val);
		if(a_head->next == NULL)
				break;
		a_head = a_head->next;
	} 
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