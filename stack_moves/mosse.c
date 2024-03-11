/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:53:01 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:53:06 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../pushswap.h"
#include "ft_printf.h"
#include "limits.h"

void	pa(t_dll_list **stack_a, t_dll_list **stack_b, int flag)
{
	t_dll_list	*tmp;

	if (ft_dll_size(*stack_b) == 0)
		return ;
	tmp = (*stack_b)->next;
	if (ft_dll_size(*stack_a) == 0)
	{
		(*stack_b)->next->prev = NULL;
		(*stack_b)->next = NULL;
	}
	else
	{
		ft_dll_return_head(stack_b);
		ft_dll_return_head(stack_a);
		if (ft_dll_size(*stack_b) != 1)
			(*stack_b)->next->prev = NULL;
		(*stack_b)->next = (*stack_a);
		(*stack_a)->prev = (*stack_b);
	}
	(*stack_a) = (*stack_b);
	(*stack_b) = tmp;
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	pb(t_dll_list **stack_b, t_dll_list **stack_a, int flag)
{
	t_dll_list	*tmp;

	if (ft_dll_size(*stack_a) == 0)
		return ;
	tmp = (*stack_a)->next;
	if (ft_dll_size(*stack_b) == 0)
	{
		(*stack_a)->next->prev = NULL;
		(*stack_a)->next = NULL;
	}
	else
	{
		ft_dll_return_head(stack_a);
		ft_dll_return_head(stack_b);
		if (ft_dll_size(*stack_a) != 1)
			(*stack_a)->next->prev = NULL;
		(*stack_a)->next = (*stack_b);
		(*stack_b)->prev = (*stack_a);
	}
	(*stack_b) = (*stack_a);
	(*stack_a) = tmp;
	if (flag == 1)
		write(1, "pb\n", 3);
}

void	ra(t_dll_list **stack, int flag)
{
	t_dll_list	*tail;
	t_dll_list	*head;

	if (ft_dll_size((*stack)) <= 1)
		return ;
	head = (*stack);
	ft_dll_return_tail(stack);
	tail = (*stack);
	tail->next = head;
	(head->next)->prev = NULL;
	(*stack) = head->next;
	head->next = NULL;
	head->prev = tail;
	ft_dll_return_head(stack);
	ft_dll_update_index(stack);
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_dll_list **stack, int flag)
{
	t_dll_list	*tail;
	t_dll_list	*head;

	if (ft_dll_size((*stack)) <= 1)
		return ;
	head = (*stack);
	ft_dll_return_tail(stack);
	tail = (*stack);
	tail->next = head;
	(head->next)->prev = NULL;
	(*stack) = head->next;
	head->next = NULL;
	head->prev = tail;
	ft_dll_return_head(stack);
	ft_dll_update_index(stack);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_dll_list **stack_a, t_dll_list **stack_b, int flag)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (flag == 1)
		write(1, "rr\n", 3);
}
