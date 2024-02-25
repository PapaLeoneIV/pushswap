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

int	*ft_insertion_valid_input(char **mtx, int len, int offset)
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
		if (ft_isnumber(mtx[offset]))
			arr[count++] = ft_atoi(mtx[offset++], arr, mtx, len);
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
