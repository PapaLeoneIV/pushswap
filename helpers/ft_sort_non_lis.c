/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_non_lis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:52:34 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include "pushswap.h"

static void	ft_sort_non_lis_helper(t_stacks *stacks, t_dll_list *ptr, int i,
		int *val)
{
	t_dll_list	*newnode;

	val = ft_calloc(1, sizeof(int));
	*val = stacks->input_arr[i];
	newnode = ft_dll_new(val);
	if (!newnode)
	{
		ft_dll_return_head(&ptr);
		ft_dll_clear(&ptr, free);
	}
	ft_dll_insert_tail(&stacks->o_non_lis, newnode);
}

void	ft_sort_non_lis(t_stacks *stacks)
{
	t_dll_list	*ptr;
	int			*val;
	int			i;

	i = 0;
	val = NULL;
	while (i < stacks->input_arr_len)
	{
		ptr = stacks->lis;
		while (ptr != NULL)
		{
			if (stacks->input_arr[i] == *(int *)(ptr->val))
				break ;
			if (ptr->next == NULL)
				ft_sort_non_lis_helper(stacks, ptr, i, val);
			ptr = ptr->next;
		}
		i++;
	}
}
