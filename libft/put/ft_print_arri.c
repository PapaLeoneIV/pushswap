/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:50:55 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:51:00 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_arri(int *arr, int len)
{
	int	i;

	i = 0;
	ft_printf("\n[Arr] :");
	while (arr && i < len)
	{
		ft_printf("\tidx->[%i]  :  %i\n", i, arr[i]);
		i++;
	}
}
