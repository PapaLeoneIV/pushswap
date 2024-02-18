/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:15:33 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:15:39 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free_stacks(t_stacks stack)
{
	free(stack.input_arr);
	ft_dll_return_head(&(stack.a));
	ft_dll_clear(&(stack.a), free);
	ft_dll_return_head(&stack.b);
	ft_dll_clear(&(stack.b), free);
	ft_dll_return_head(&(stack.lis));
	ft_dll_clear(&(stack.lis), free);
	ft_dll_return_head(&(stack.o_non_lis));
	ft_dll_clear(&(stack.o_non_lis), free);
}
