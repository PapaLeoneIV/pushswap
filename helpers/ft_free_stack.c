/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:15:33 by rileone           #+#    #+#             */
/*   Updated: 2024/05/04 13:12:03 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_free_stacks(t_stacks *stack)
{
	if (stack->input_arr != NULL)
		free(stack->input_arr);
	if (stack->minmax != NULL)
		free(stack->minmax);
	free(stack->mosse);
	ft_dll_clear(&(stack->a), free);
	ft_dll_clear(&(stack->b), free);
	ft_dll_clear(&(stack->lis), free);
	ft_dll_clear(&(stack->o_non_lis), free);
	ft_dll_clear(&(stack->mosse_a), free);
	ft_dll_clear(&(stack->mosse_b), free);
}
