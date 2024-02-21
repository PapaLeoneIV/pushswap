/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_non_lis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:52:34 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_move_non_lis(t_stacks *stacks)
{
	int			num_nlis_pushed;
	t_dll_list	*ptr;

	num_nlis_pushed = 0;
	ptr = stacks->o_non_lis;
	while (ptr != NULL)
	{
		if (*(int *)ptr->val == *(int *)stacks->a->val)
		{
			pb(&stacks->b, &stacks->a, 1);
			ptr = ptr->next;
			num_nlis_pushed++;
		}
		else
			ra(&stacks->a, 1);
		if (num_nlis_pushed == stacks->o_non_lis_len)
			break ;
	}
	ft_dll_return_head(&stacks->o_non_lis);
	ft_dll_update_index(&stacks->a);
}
