/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:55:06 by rileone           #+#    #+#             */
/*   Updated: 2023/11/22 13:55:07 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"



void	ft_rotate_until_ordered2(t_stacks *stack)
{
	int	min_idx;
	int	pivot;
	int	len;

	ft_dll_update_index(&stack->a);
	min_idx = ft_find_min(stack->a);
	len = ft_dll_size(stack->a);
	pivot = len / 2;
	if (min_idx <= pivot)
	{
		while (min_idx-- != 0)
			ra(&stack->a, 1);
	}
	else
	{
		while (min_idx++ != len)
			rra(&stack->a, 1);
	}
}

static void minisolver(t_stacks *stacks)
{
	int len;
	
	len = ft_dll_size(stacks->a);
	if(len == 2)
		minisolver2(stacks->a, 'a');
	else if(len == 3)
		minisolver3(stacks);
	else if(len == 4)
		minisolver4(stacks); 
	else if(len == 5)
		minisolver5(stacks);
	ft_dll_update_index(&stacks->a);
} 


int	main(int ac, char **av)
{
	t_stacks	stacks;

	stacks = (t_stacks){0};
	ft_init_(ac, av, &stacks);
	 if(stacks.input_arr_len < 6)
		minisolver(&stacks);
	 else
	{
		ft_sort_non_lis(&stacks);
		ft_move_non_lis(&stacks);
		ft_sortback(&stacks);
	}
 	ft_rotate_until_ordered2(&stacks); 
	ft_free_stacks(stacks);
	return (0);
}
