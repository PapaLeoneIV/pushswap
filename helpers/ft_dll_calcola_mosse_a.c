/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_calcola_mosse_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:52:34 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "pushswap.h"

static void	ft_process_mosse_nodes(t_dll_list **mosse_a, t_dll_list *ptr_a,
		t_dll_list *ptr_b, t_stacks *stack)
{
	while (ptr_a != NULL)
	{
		if (ft_check_and_insert_mosse(mosse_a, ptr_a, ptr_b, stack))
			break ;
		ptr_a = ptr_a->next;
		if (ptr_a->next == NULL)
		{
			ft_insert_mosse_node(mosse_a, 0);
			break ;
		}
	}
}

static t_dll_list	*ft_generate_mosse_list_a(t_stacks *stack)
{
	t_dll_list	*mosse_a;
	t_dll_list	*ptr_b;
	t_dll_list	*ptr_a;

	mosse_a = NULL;
	ptr_b = stack->b;
	ptr_a = stack->a;
	while (ptr_b != NULL)
	{
		ft_process_mosse_nodes(&mosse_a, ptr_a, ptr_b, stack);
		ptr_b = ptr_b->next;
	}
	return (mosse_a);
}

t_dll_list	*ft_dll_calcola_mosse_a(t_stacks *stack)
{
	t_dll_list	*mosse_a;
	int			len;

	mosse_a = NULL;
	len = ft_dll_get_tail_index(stack->a);
	stack->pivotindex = len / 2;
	if (len == 0)
	{
		mosse_a = ft_handle_empty_stack_b(stack->b);
		return (mosse_a);
	}
	return (ft_generate_mosse_list_a(stack));
}
