/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_valid_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/05/04 13:12:39 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	*ft_insertion_valid_input(char **av, int len, int offset)
{
	int	*arr;
	int	count;
	int	flag;

	flag = offset;
	count = 0;
	arr = (int *)ft_calloc(len, sizeof(int));
	if (!arr)
		return (NULL);
	while (offset < len)
	{
		if (ft_isnumber(av[offset]))
			arr[count++] = ft_atoi(av[offset++], arr);
		else
		{
			free(arr);
			return (NULL);
		}
	}
	if (ft_check_for_dupl(arr, len - flag) == 1)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
