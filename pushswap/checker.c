/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:55:06 by rileone           #+#    #+#             */
/*   Updated: 2024/05/03 20:39:40 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	helper(char *str)
{
	error_fn();
	free(str);
}

static int	ft_execute_instruction(t_stacks *stacks, char *str)
{
	if (!ft_strncmp(str, "pa\n", 3))
		pa(&stacks->a, &stacks->b, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(&stacks->b, &stacks->a, 0);
	else if (!ft_strncmp(str, "sa\n", 3))
		sa(stacks->a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(stacks->b, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(stacks->a, stacks->b);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(&stacks->a, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(&stacks->b, 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(&stacks->a, &stacks->b, 0);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(&stacks->a, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(&stacks->b, 0);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(&stacks->a, &stacks->b, 0);
	else
		return (ft_dll_return_head(&stacks->a), 0);
	return (ft_dll_return_head(&stacks->a), 1);
}

static void	ft_init_checker(int ac, char **av, t_stacks *stacks)
{
	stacks->input_arr_len = ft_get_input_length(ac, av);
	stacks->input_arr = ft_normalizzazione_dati(ac, av);
	stacks->a = ft_dll_initi(stacks->input_arr, stacks->input_arr_len);
	stacks->b = NULL;
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*str;

	stacks = (t_stacks){0};
	if (ac < 2)
		return (0);
	ft_init_checker(ac, av, &stacks);
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (ft_execute_instruction(&stacks, str) == 0)
		{
			helper(str);
			break ;
		}
		free(str);
	}
	free(stacks.input_arr);
	if (stacks.b == NULL && ft_dll_check_if_ordered(stacks.a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_dll_clear(&stacks.b, free), ft_dll_clear(&stacks.a, free), 0);
}
