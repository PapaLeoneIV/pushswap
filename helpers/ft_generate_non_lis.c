/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_non_lis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/05/04 13:13:08 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../pushswap.h"

static int	ft_generate_non_lis_helper(t_stacks *stacks, int i,
		int *val)
{
	t_dll_list	*newnode;

	val = ft_calloc(1, sizeof(int));
	if (val == NULL)
		return (0);
	*val = stacks->input_arr[i];
	newnode = ft_dll_new(val);
	if (newnode == NULL)
		return (0);
	ft_dll_insert_tail(&stacks->o_non_lis, newnode);
	return (1);
}

int	ft_generate_non_lis(t_stacks *stacks)
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
			{
				if (!ft_generate_non_lis_helper(stacks, i, val))
					return (0);
			}
			ptr = ptr->next;
		}
		i++;
	}
	return (1);
}
