/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:53:01 by rileone           #+#    #+#             */
/*   Updated: 2024/05/04 13:14:19 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rra(t_dll_list **stack, int flag)
{
	t_dll_list	*tail;
	t_dll_list	*head;

	if (ft_dll_size((*stack)) <= 1)
		return ;
	head = (*stack);
	ft_dll_return_tail(stack);
	tail = (*stack);
	(tail->prev)->next = NULL;
	(*stack) = tail;
	tail->next = head;
	tail->prev = NULL;
	head->prev = tail;
	ft_dll_return_head(stack);
	ft_dll_update_index(stack);
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_dll_list **stack, int flag)
{
	t_dll_list	*tail;
	t_dll_list	*head;

	if (ft_dll_size((*stack)) <= 1)
		return ;
	head = (*stack);
	ft_dll_return_tail(stack);
	tail = (*stack);
	(tail->prev)->next = NULL;
	(*stack) = tail;
	tail->next = head;
	tail->prev = NULL;
	head->prev = tail;
	ft_dll_return_head(stack);
	ft_dll_update_index(stack);
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_dll_list **stack_a, t_dll_list **stack_b, int flag)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (flag == 1)
		write(1, "rrr\n", 4);
}

void	sa(t_dll_list *stack_a, int flag)
{
	t_dll_list	*second_node;
	t_dll_list	*head;
	t_dll_list	*tmp;

	if (ft_dll_size(stack_a) <= 1)
		return ;
	if (ft_dll_size(stack_a) <= 1)
		return ;
	head = stack_a;
	second_node = head->next;
	if (ft_dll_size(stack_a) == 2)
		head->next = NULL;
	else
	{
		tmp = head->next->next;
		head->next = tmp;
		tmp->prev = head;
	}
	head->prev = second_node;
	second_node->prev = NULL;
	second_node->next = head;
	stack_a = second_node;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_dll_list *stack_b, int flag)
{
	t_dll_list	*second_node;
	t_dll_list	*head;
	t_dll_list	*tmp;

	ft_dll_return_head(&stack_b);
	if (ft_dll_size(stack_b) <= 1)
		return ;
	head = stack_b;
	second_node = head->next;
	if (ft_dll_size(stack_b) == 2)
		head->next = NULL;
	else
	{
		tmp = head->next->next;
		head->next = tmp;
		tmp->prev = head;
	}
	head->prev = second_node;
	second_node->prev = NULL;
	second_node->next = head;
	stack_b = second_node;
	if (flag == 1)
		write(1, "sb\n", 3);
}
