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

static void	minisolver(t_stacks *stacks)
{
	int	len;

	len = ft_dll_size(stacks->a);
	if (len == 2)
		minisolver2(stacks->a, 'a');
	else if (len == 3)
		minisolver3(stacks);
	else if (len == 4)
		minisolver4(stacks);
	else if (len == 5)
		minisolver5(stacks);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	stacks = (t_stacks){0};
	ft_init_(ac, av, &stacks);
	if (stacks.input_arr_len < LIS_INPUT_LIMIT)
		minisolver(&stacks);
	else
	{
		ft_sort_non_lis(&stacks);
		ft_move_non_lis(&stacks);
		ft_sortback(&stacks);
	}
	ft_rotate_until_ordered(&stacks);
	ft_free_stacks(stacks);
	return (0);
}
