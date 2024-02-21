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

static void	sort_back_helper(t_stacks *stack)
{
	ft_dll_return_head(&stack->a);
	ft_dll_return_head(&stack->b);
	ft_dll_update_index(&stack->a);
	ft_dll_update_index(&stack->b);
	ft_dll_clear(&stack->mosse_a, free);
	ft_dll_clear(&stack->mosse_b, free);
	free(stack->minmax);
	stack->minmax = NULL;
	free(stack->mosse);
	stack->mosse = NULL;
}

void	ft_sortback(t_stacks *stack)
{
	int			best_idx;

	while (stack->b != NULL)
	{
		stack->mosse_b = ft_dll_calcola_mosse_b(stack);
		if (stack->mosse_b == NULL)
			return (ft_free_stacks(stack), error_fn());
		stack->minmax = ft_findminmax(stack->a);
		if (stack->minmax == NULL)
			return (ft_free_stacks(stack), error_fn());
		stack->minmax_len = 2;
		stack->mosse_a = ft_dll_calcola_mosse_a(stack);
		if (stack->mosse_a == NULL)
			return (ft_free_stacks(stack), error_fn());
		best_idx = ft_dll_calcola_mosse(stack->mosse_a, stack->mosse_b);
		stack->mosse_len = 2;
		stack->mosse = ft_get_mosse_from_best_idx(best_idx,
				stack->mosse_a, stack->mosse_b);
		if (stack->mosse == NULL)
			return (ft_free_stacks(stack), error_fn());
		ft_execute_mosse(stack);
		sort_back_helper(stack);
	}
}
