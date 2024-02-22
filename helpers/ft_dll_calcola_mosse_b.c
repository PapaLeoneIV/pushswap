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

static int	ft_ins_from_bot(t_dll_list **mosse,
	int len, int *tmp1, t_dll_list *tmp)
{
	t_dll_list	*new;

	tmp1 = ft_calloc(1, sizeof(int));
	if (tmp1 == NULL)
		return (0);
	*tmp1 = (tmp->index - len) - 1;
	new = ft_dll_new(tmp1);
	if (new == NULL)
		return (0);
	ft_dll_insert_tail(mosse, new);
	return (1);
}

static int	ft_ins_from_top(t_dll_list **mosse, int *tmp1, t_dll_list *tmp)
{
	t_dll_list	*new;

	tmp1 = ft_calloc(1, sizeof(int));
	if (tmp1 == NULL)
		return (0);
	*tmp1 = tmp->index;
	new = ft_dll_new(tmp1);
	if (new == NULL)
		return (0);
	ft_dll_insert_tail(mosse, new);
	return (1);
}

static void	ft_calcola_mosse_b_helper(t_stacks *stacks,
	int *len, t_dll_list **tmp)
{
	*len = ft_dll_get_tail_index(stacks->b);
	ft_dll_return_head(tmp);
	ft_dll_return_head(&stacks->b);
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
	ft_calcola_mosse_b_helper(stack, &len, &tmp);
	while (tmp != NULL)
	{
		if (tmp->index <= pivot_idx)
		{
			if (!ft_ins_from_top(&mosse, tmp1, tmp))
				return (ft_dll_clear(&mosse, free), NULL);
		}
		else
		{
			if (!ft_ins_from_bot(&mosse, len, tmp1, tmp))
				return (ft_dll_clear(&mosse, free), NULL);
		}
		tmp = tmp->next;
	}
	return (mosse);
}

t_dll_list	*ft_dll_calcola_mosse_b(t_stacks *stack)
{
	t_dll_list	*mosse_b;
	int			pivot_idx;

	ft_dll_update_index(&stack->b);
	pivot_idx = ft_find_middle(stack->b);
	mosse_b = ft_create_mosse_list(stack, pivot_idx);
	if (mosse_b == NULL)
		return (NULL);
	return (mosse_b);
}
