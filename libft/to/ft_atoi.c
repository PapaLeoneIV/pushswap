/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:19:40 by rileone           #+#    #+#             */
/*   Updated: 2023/10/20 22:34:33 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(char *nptr)
{
	int		isnegative;
	long	res;

	res = 0;
	isnegative = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			isnegative = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	if(res > 2147483647 || res < -2147483648)
	{
		/*TODO devo fare la error function*/
		write(1, "Error\n", 6);
		exit(1);
	}
	return (res * isnegative);
}
