/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/05/04 13:13:02 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_init_(int ac, char **av, t_stacks *stacks)
{
	stacks->input_arr_len = ft_get_input_length(ac, av);
	stacks->input_arr = ft_normalizzazione_dati(ac, av);
	stacks->a = ft_dll_initi(stacks->input_arr, stacks->input_arr_len);
	if (ft_dll_check_if_ordered(stacks->a) == 1)
	{
		free(stacks->input_arr);
		ft_dll_clear(&stacks->a, free);
		exit(1);
	}
	if (stacks->a == NULL)
	{
		ft_free_stacks(stacks);
		error_fn();
	}
	stacks->b = NULL;
	stacks->lis_len = 1;
	stacks->lis = ft_lis_algo_list(&stacks->lis_len, stacks->a);
	if (stacks->lis == NULL)
	{
		ft_free_stacks(stacks);
		error_fn();
	}
	stacks->o_non_lis_len = (stacks->input_arr_len) - (stacks->lis_len);
}
