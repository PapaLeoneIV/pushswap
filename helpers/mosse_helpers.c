/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:52:34 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_insert_mosse_node(t_dll_list **mosse_a, int val)
{
	t_dll_list	*new;
	int			*tmp1;

	tmp1 = ft_calloc(1, sizeof(int));
	*tmp1 = val;
	new = ft_dll_new(tmp1);
	ft_dll_insert_tail(mosse_a, new);
}

int	ft_handle_mosse_condition_o(t_dll_list **mosse_a, t_dll_list *ptr_a,
		t_dll_list *ptr_b, t_stacks *stack)
{
	int	len;

	len = ft_dll_get_tail_index(ptr_a);
	if ((*(int *)ptr_b->val > *(int *)ptr_a->val
			&& *(int *)ptr_b->val < *(int *)ptr_a->next->val)
		|| (*(int *)ptr_a->val == stack->minmax[1]
			&& *(int *)ptr_a->next->val > *(int *)ptr_b->val)
		|| (*(int *)ptr_a->next->val == stack->minmax[0]
			&& *(int *)ptr_a->val < *(int *)ptr_b->val))
	{
		ft_insert_mosse_node(mosse_a, -1 * (len - ptr_a->next->index + 1));
		return (1);
	}
	return (0);
}

int	ft_handle_mosse_condition_u(t_dll_list **mosse_a, t_dll_list *ptr_a,
		t_dll_list *ptr_b, t_stacks *stack)
{
	if ((*(int *)ptr_b->val > *(int *)ptr_a->val
			&& *(int *)ptr_b->val < *(int *)ptr_a->next->val)
		|| (*(int *)ptr_a->val == stack->minmax[1]
			&& *(int *)ptr_a->next->val > *(int *)ptr_b->val)
		|| (*(int *)ptr_a->next->val == stack->minmax[0]
			&& *(int *)ptr_a->val < *(int *)ptr_b->val))
	{
		ft_insert_mosse_node(mosse_a, ptr_a->next->index);
		return (1);
	}
	return (0);
}

int	ft_check_and_insert_mosse(t_dll_list **mosse_a, t_dll_list *ptr_a,
		t_dll_list *ptr_b, t_stacks *stack)
{
	if (ptr_a->index < stack->pivotindex)
	{
		if (ft_handle_mosse_condition_u(mosse_a, ptr_a, ptr_b, stack))
			return (1);
	}
	else if (ptr_a->index >= stack->pivotindex)
	{
		if (ft_handle_mosse_condition_o(mosse_a, ptr_a, ptr_b, stack))
			return (1);
	}
	return (0);
}

t_dll_list	*ft_handle_empty_stack_b(t_dll_list *ptr_b)
{
	t_dll_list	*mosse_a;
	t_dll_list	*tmp;

	mosse_a = NULL;
	tmp = ptr_b;
	while (tmp != NULL)
	{
		ft_insert_mosse_node(&mosse_a, 0);
		tmp = tmp->next;
	}
	return (mosse_a);
}
