#include "pushswap.h"

void minisolver2(t_dll_list *stacks, char x)
{
	if (*(int*)stacks->val > *(int*)stacks->next->val)
	{
		if(x == 'a')
		{
			sa(stacks, 1);
		}
		if(x == 'b')
		{
			sb(stacks, 1);
		}
	}
}


void minisolver3(t_stacks *stacks)
{
	int a;
	int b;
	int c;

	a = *(int*)stacks->a->val;
	b = *(int*)stacks->a->next->val;
	c = *(int*)stacks->a->next->next->val;
	if(a > b && a > c && b < c)
		ra(&stacks->a, 1);
	else if(a < b && a > c && b > c)
		rra(&stacks->a, 1);
	else if(a > b && a > c && b > c)
	{
		ra(&stacks->a, 1);
		sa(stacks->a, 1);
	}
	else if(a < b && a < c && b > c)
	{
		sa(stacks->a, 1);
		ra(&stacks->a, 1);
	}
	else if(a > b && a < c && b < c)
		sa(stacks->a, 1);
	ft_dll_update_index(&stacks->a);
}
void minisolver4(t_stacks *stacks)
{
	int *minmax;

	minmax =  ft_findminmax(stacks->a);
	pb(&stacks->b, &stacks->a, 1);
	minisolver3(stacks);
	while(stacks->b != NULL)
	{
		minmax =  ft_findminmax(stacks->a);
		if (*(int*)stacks->b->val > *(int*)stacks->a->val && *(int*)stacks->b->val < *(int*)stacks->a->next->val)
		{
			rapa(stacks);
			break;
		}
		else if (minmax[1] == *(int*)stacks->a->val && *(int*)stacks->b->val > minmax[1])
			rapara(stacks);
		else if (minmax[0] == *(int*)stacks->a->val && *(int*)stacks->b->val < minmax[0])
			pa(&stacks->a, &stacks->b, 1);
		else 
			ra(&stacks->a, 1);
	}
}

void minisolver5(t_stacks *stacks)
{
	int *minmax;
	int index;

	while(ft_dll_size(stacks->a) > 3)
	{
		ft_dll_update_index(&stacks->a);
		minmax = ft_findminmax(stacks->a);
		index = ft_dll_get_node_index(stacks->a, minmax[0]);
		if(index < ft_dll_size(stacks->a) / 2)
		{
			while(index-- != 0)
				ra(&stacks->a, 1);
		}
		else
		{
			while(index++ != ft_dll_size(stacks->a))
				rra(&stacks->a, 1);
		}
		pb(&stacks->b, &stacks->a, 1);
	}
	minisolver3(stacks);
	pa(&stacks->a, &stacks->b, 1);
	pa(&stacks->a, &stacks->b, 1);
}



