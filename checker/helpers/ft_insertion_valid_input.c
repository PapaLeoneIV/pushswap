/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_valid_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:52:34 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "pushswap.h"

int	*ft_insertion_valid_input(char **av, int len, int offset)
{
	int	*arr;
	int	count;
	int	flag;

	flag = offset;
	count = 0;
	arr = (int *)ft_calloc(len, sizeof(int));
	while (offset < len)
	{
		if (ft_isnumber(av[offset]))
			arr[count++] = ft_atoi(av[offset++]);
		else
		{
			free(arr);
			error_fn();
		}
	}
	if (ft_check_for_dupl(arr, len - flag) == 1)
	{
		free(arr);
		error_fn();
	}
	return (arr);
}
