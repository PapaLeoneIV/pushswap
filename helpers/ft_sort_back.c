/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:31:37 by rileone           #+#    #+#             */
/*   Updated: 2024/02/08 16:31:43 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	*ft_get_mosse_from_best_idx(int best_idx, t_dll_list *a,
	t_dll_list *b)
{
	int	*arr;

	ft_dll_return_head(&a);
	ft_dll_return_head(&b);
	ft_dll_update_index(&a);
	ft_dll_update_index(&b);
	arr = ft_calloc(2, sizeof(int));
	if (arr == NULL)
		return (NULL);
	arr[0] = ft_dll_get_value(a, best_idx);
	arr[1] = ft_dll_get_value(b, best_idx);
	return (arr);
}

void	ft_sortback(t_stacks *stack)
{
	int			best_idx;
	t_dll_list	*mosse_a;
	t_dll_list	*mosse_b;

	while (stack->b != NULL)
	{
		mosse_b = ft_dll_calcola_mosse_b(stack);
		stack->minmax = ft_findminmax(stack->a);
		stack->minmax_len = 2;
		mosse_a = ft_dll_calcola_mosse_a(stack);
		best_idx = ft_dll_calcola_mosse(mosse_a, mosse_b);
		stack->mosse_len = 2;
		stack->mosse = ft_get_mosse_from_best_idx(best_idx, mosse_a, mosse_b);
		ft_execute_mosse(stack);
		ft_dll_update_index(&stack->a);
		ft_dll_update_index(&stack->b);
		ft_dll_clear(&mosse_a, free);
		ft_dll_clear(&mosse_b, free);
		free(stack->minmax);
		free(stack->mosse);
	}
}
