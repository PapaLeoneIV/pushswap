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

static int	ft_execute_instruction(t_stacks *stacks, char *str)
{
	if (!ft_strncmp(str, "pa\n", 3))
		pa(&stacks->a, &stacks->b, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(&stacks->b, &stacks->a, 0);
	else if (!ft_strncmp(str, "sa\n", 3))
		sa(&stacks->a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(&stacks->b, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(stacks->a, stacks->b);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(&stacks->a, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(&stacks->b, 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(&stacks->a, &stacks->b);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(&stacks->a, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(&stacks->b, 0);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(&stacks->a, &stacks->b);
	else
		return (get_next_line(-42), 0);
	return (ft_dll_return_head(&stacks->a), 1);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*str;

	stacks = (t_stacks){0};
	if (ac < 2)
		return (0);
	ft_init_(ac, av, &stacks);
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
		{
			free(str);
			break ;
		}
		if (!ft_execute_instruction(&stacks, str))
			return (free(str), ft_free_stacks(&stacks), 0);
		free(str);
	}
	if (stacks.b == NULL && ft_dll_check_if_ordered(stacks.a))
		return (write(1, "OK\n", 3), ft_free_stacks(&stacks), 0);
	else
		return (write(1, "KO\n", 3), ft_free_stacks(&stacks), 0);
}
