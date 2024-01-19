 #include "../pushswap.h"
#include "ft_printf.h"
#include "../libft.h"
#include "limits.h"

void pa(dll_list **stack_a, dll_list **stack_b)
{
	int*		val_b;
	dll_list*	newnode;
	dll_list*	tmp;

	if(ft_dll_size(*stack_b) == 0)
		return ;
	val_b = malloc(sizeof(int));
	if(!val_b)
		return ;

	ft_dll_return_head(stack_b);
	if(ft_dll_size(*stack_b) == 1)
	{
		*val_b = *(int* )(*stack_b)->val;
		free((*stack_b)->val);
		free((*stack_b));
		*stack_b = NULL;
		newnode = ft_dll_new(val_b);
		if(!newnode)
			return ;
		ft_dll_insert_head(&(*stack_a), newnode);
		return;
	}
	tmp = (*stack_b)->next;
	*val_b = *(int* )(*stack_b)->val;
	free((*stack_b)->val);
	free((*stack_b));
	tmp->prev = NULL;
	ft_dll_return_head(&tmp);
	(*stack_b) = tmp;
	newnode = ft_dll_new(val_b);
	if(!newnode)
		return ;
	ft_dll_insert_head(&(*stack_a), newnode);	
}

/*  int main()
{
	dll_list *a_head;
	dll_list *b_head;
	int arr[] = {2, 3, 5, 6};
	int arr2[] = {1};
	a_head = ft_dll_initi(arr, 4);
	b_head = ft_dll_initi(arr2, 1);


	pa(&a_head, &b_head);
    ft_dll_return_head(&a_head);
	ft_dll_return_head(&b_head);
	while(a_head != NULL)
	{
		printf("%i\n", *(int *)a_head->val);
		if(a_head->next == NULL)
				break;
		a_head = a_head->next;
	} 
    printf("[--------------]\n");
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
} 	  */