/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:52:34 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	ft_get_input_length(int ac, char **av)
{
	char	**mtx;
	int		len;

	len = 0;
	if (ac <= 1)
		exit(1);
	else if (ac == 2)
	{
		mtx = ft_split(av[1], ' ');
		if (!mtx)
		{
			ft_clear_mtx(mtx, len);
			exit(1);
		}
		while (mtx && mtx[len])
			len++;
		ft_clear_mtx(mtx, len);
	}
	else
		len = ac - 1;
	return (len);
}
