/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:55:06 by rileone           #+#    #+#             */
/*   Updated: 2023/11/22 13:55:07 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

int main(int ac, char **av)
{
	t_stacks stacks;

    stacks = (t_stacks){0};
 	ft_init_(ac, av, &stacks);
    ft_move_non_lis(&stacks);
    ft_sortback(&stacks);
    ft_print_params(&stacks);
	
	free(stacks.input_arr);
    ft_dll_return_head(&(stacks.a));
    ft_dll_clear(&(stacks.a), free);
    ft_dll_return_head(&stacks.b);
    ft_dll_clear(&(stacks.b), free);
    ft_dll_return_head(&(stacks.lis));
    ft_dll_clear(&(stacks.lis), free);

}