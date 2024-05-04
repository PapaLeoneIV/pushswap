/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_calcola_mosse_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/05/04 13:13:28 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int	ft_process_mosse_nodes(t_dll_list **mosse_a, t_dll_list *ptr_a,
		t_dll_list *ptr_b, t_stacks *stack)
{
	int	tmp;

	while (ptr_a != NULL)
	{
		tmp = ft_check_and_insert_mosse(mosse_a, ptr_a, ptr_b, stack);
		if (tmp == 1)
			break ;
		else if (tmp == -1)
			return (-1);
		ptr_a = ptr_a->next;
		if (ptr_a->next == NULL)
		{
			if (ft_insert_mosse_node(mosse_a, 0))
				break ;
			else
				return (0);
		}
	}
	return (1);
}

static t_dll_list	*ft_generate_mosse_list_a(t_stacks *stack)
{
	t_dll_list	*mosse_a;
	t_dll_list	*ptr_b;
	t_dll_list	*ptr_a;
	int			tmp;

	mosse_a = NULL;
	ptr_b = stack->b;
	ptr_a = stack->a;
	while (ptr_b != NULL)
	{
		tmp = ft_process_mosse_nodes(&mosse_a, ptr_a, ptr_b, stack);
		if (tmp == 1)
			ptr_b = ptr_b->next;
		else if (tmp == -1)
			return (NULL);
	}
	return (mosse_a);
}

t_dll_list	*ft_dll_calcola_mosse_a(t_stacks *stack)
{
	t_dll_list	*mosse_a;
	t_dll_list	*res;
	int			len;

	mosse_a = NULL;
	len = ft_dll_get_tail_index(stack->a);
	stack->pivotindex = len / 2;
	if (len == 0)
	{
		mosse_a = ft_handle_empty_stack_b(stack->b);
		if (mosse_a == NULL)
			return (NULL);
		return (mosse_a);
	}
	res = ft_generate_mosse_list_a(stack);
	if (res == NULL)
		return (NULL);
	return (res);
}
