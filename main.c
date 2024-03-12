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
	if (ft_dll_check_if_ordered(stacks->a) == 1)
		free_minisolver_heap(stacks);
	if (len == 2)
		minisolver2(stacks->a, 'a');
	else if (len == 3)
		minisolver3(stacks);
	else if (len == 4)
		minisolver4(stacks);
	else if (len == 5)
		minisolver5(stacks);
	ft_dll_return_head(&stacks->a);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac < 2)
		return (0);
	stacks = (t_stacks){0};
	ft_init_(ac, av, &stacks);
	if (stacks.input_arr_len < LIS_INPUT_LIMIT)
		minisolver(&stacks);
	else
	{
		if (!ft_generate_non_lis(&stacks))
			return (ft_free_stacks(&stacks), error_fn(), 0);
		ft_move_non_lis(&stacks);
		ft_sortback(&stacks);
	}
	ft_rotate_until_ordered(&stacks);

	ft_free_stacks(&stacks);
	return (0);
}
