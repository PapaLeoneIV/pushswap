/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_calcola_mosse_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:52:34 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

static int	ft_find_middle(t_stacks *stack)
{
	int			index;
	t_dll_list	*tmp;

	tmp = stack->b;
	ft_dll_return_tail(&tmp);
	index = tmp->index / 2;
	return (index);
}

static void	ft_ins_from_bot(t_dll_list **mosse,
	int len, int *tmp1, t_dll_list *tmp)
{
	t_dll_list	*new;

	tmp1 = ft_calloc(1, sizeof(int));
	*tmp1 = (tmp->index - len) - 1;
	new = ft_dll_new(tmp1);
	ft_dll_insert_tail(mosse, new);
}

static void	ft_ins_from_top(t_dll_list **mosse, int *tmp1, t_dll_list *tmp)
{
	t_dll_list	*new;

	tmp1 = ft_calloc(1, sizeof(int));
	*tmp1 = tmp->index;
	new = ft_dll_new(tmp1);
	ft_dll_insert_tail(mosse, new);
}

static t_dll_list	*ft_create_mosse_list(t_stacks *stack, int pivot_idx)
{
	t_dll_list	*tmp;
	t_dll_list	*mosse;
	int			len;
	int			*tmp1;

	mosse = NULL;
	tmp1 = NULL;
	ft_dll_return_tail(&stack->b);
	tmp = stack->b;
	len = tmp->index;
	ft_dll_return_head(&tmp);
	ft_dll_return_head(&stack->b);
	while (tmp != NULL)
	{
		if (tmp->index <= pivot_idx)
			ft_ins_from_top(&mosse, tmp1, tmp);
		else
			ft_ins_from_bot(&mosse, len, tmp1, tmp);
		tmp = tmp->next;
	}
	return (mosse);
}

t_dll_list	*ft_dll_calcola_mosse_b(t_stacks *stack)
{
	t_dll_list	*mosse_b;
	int			pivot_idx;

	ft_dll_update_index(&stack->b);
	pivot_idx = ft_find_middle(stack);
	mosse_b = ft_create_mosse_list(stack, pivot_idx);
	return (mosse_b);
}
