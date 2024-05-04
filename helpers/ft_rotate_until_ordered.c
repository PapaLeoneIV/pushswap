/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_until_ordered.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:43:15 by rileone           #+#    #+#             */
/*   Updated: 2024/05/04 13:11:44 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_rotate_until_ordered(t_stacks *stack)
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
