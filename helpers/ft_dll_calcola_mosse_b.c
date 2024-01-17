#include "libft.h"
#include "ft_printf.h"
#include "pushswap.h"

static int ft_find_middle(t_stacks* stack)
{	
	int index;
	dll_list* tmp;

	tmp = stack->o_non_lis;
	ft_dll_return_tail(&tmp);
	index = tmp->index / 2;
	return (index);
}

static dll_list* ft_create_mosse_list(t_stacks* stack, int pivot_idx)
{
	dll_list* tmp;
	dll_list* new;
	dll_list* mosse;
	int len;
	int* tmp1;

	
	mosse = NULL;
	ft_dll_return_tail(&stack->o_non_lis);
	tmp =  stack->o_non_lis;
	len = tmp->index;
	ft_dll_return_head(&tmp);
	ft_dll_return_head(&stack->o_non_lis);
	while (tmp != NULL)
	{
		if (tmp->index <= pivot_idx)
		{
			tmp1 = ft_calloc(1, sizeof(int));
			*tmp1 = tmp->index;
			new = ft_dll_new(tmp1);
			ft_dll_insert_tail(&mosse, new);
			//printf("tmp->indx < pivot_index: %d\n", *(int*)new->val);
		}
		else
		{	
			tmp1 = ft_calloc(1, sizeof(int));
			*tmp1 = (tmp->index - len) - 1;
			new = ft_dll_new(tmp1);
			ft_dll_insert_tail(&mosse, new);
		}
		tmp = tmp->next;
	}
	return (mosse);
}

dll_list* ft_dll_calcola_mosse_b(t_stacks* stack)
{
	int pivot_idx;
	dll_list* mosse_b;

	pivot_idx = ft_find_middle(stack);
	mosse_b = ft_create_mosse_list(stack, pivot_idx);
/* 	dll_list* tmp;
	tmp = mosse_b; */
/* 	while(tmp != NULL)
	{
		printf("mosse_b: %d\n", *(int*)tmp->val);
		tmp = tmp->next;
	} */

	return (mosse_b);
	
}