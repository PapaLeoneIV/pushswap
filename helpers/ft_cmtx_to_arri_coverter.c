/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmtx_to_arri_coverter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/05/04 13:12:48 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	*ft_cmtx_to_arri_coverter(char **mtx)
{
	int	i;
	int	len;
	int	*arr;

	i = 0;
	len = 0;
	if (!mtx || !mtx[len])
		return (NULL);
	while (mtx[len])
		len++;
	arr = ft_insertion_valid_input(mtx, len, i);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
