/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_minisolver_heap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:15:20 by rileone           #+#    #+#             */
/*   Updated: 2024/02/19 12:15:27 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_minisolver_heap(t_stacks *stacks)
{
	free(stacks->input_arr);
	ft_dll_return_head(&stacks->a);
	ft_dll_clear(&stacks->a, free);
	ft_dll_return_head(&stacks->b);
	ft_dll_clear(&stacks->b, free);
	ft_dll_return_head(&stacks->lis);
	ft_dll_clear(&stacks->lis, free);
	exit(1);
}
