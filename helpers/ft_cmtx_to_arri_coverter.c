/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmtx_to_arri_coverter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:52:34 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../libft.h"
#include"pushswap.h"

int *ft_cmtx_to_arri_coverter(char **mtx)
{
	int i;
	int len;
	int *arr;

	i = 0;
	len = 0;
	if(!mtx || !mtx[len])
		return (NULL);
	while(mtx[len])
		len++;
	arr = ft_insertion_valid_input(mtx, len, i);
	return (arr);
}
