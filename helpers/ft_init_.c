/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_.c                                         :+:      :+:    :+:   */
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

void	ft_init_(int ac, char **av, t_stacks *stacks)
{
	stacks->input_arr_len = ft_get_input_length(ac, av);
	stacks->input_arr = ft_normalizzazione_dati(ac, av);
	stacks->a = ft_dll_initi(stacks->input_arr, stacks->input_arr_len);
	stacks->b = NULL;
	stacks->lis_len = 1;
	stacks->lis = ft_lis_algo_list(&stacks->lis_len, stacks->a);
	stacks->o_non_lis_len = (stacks->input_arr_len) - (stacks->lis_len);
}
