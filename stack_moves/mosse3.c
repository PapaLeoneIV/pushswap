/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:53:01 by rileone           #+#    #+#             */
/*   Updated: 2024/05/04 14:10:45 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ss(t_dll_list *stack_a, t_dll_list *stack_b)
{
	sa(stack_a, 0);
	sa(stack_b, 0);
	write(1, "ss\n", 3);
}

void	rapara(t_stacks *stacks)
{
	ra(&stacks->a, 1);
	pa(&stacks->a, &stacks->b, 1);
	ra(&stacks->a, 1);
}

void	rapa(t_stacks *stacks)
{
	ra(&stacks->a, 1);
	pa(&stacks->a, &stacks->b, 1);
}
