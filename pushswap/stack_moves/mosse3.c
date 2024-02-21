/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:53:01 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:53:06 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../pushswap.h"
#include "ft_printf.h"

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
