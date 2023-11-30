/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_int_pf.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:34:01 by rileone           #+#    #+#             */
/*   Updated: 2023/10/26 12:37:27 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_unsigned_int_pf(int n, int *count)
{
	char			c;
	unsigned int	nl;

	nl = (unsigned int)n;
	if (nl < 0)
	{
		nl *= -1;
		ft_putchar_pf('-', count);
	}
	if (nl >= 10)
	{
		ft_putnbr_pf((nl / 10), count);
	}
	c = (unsigned int)(nl % 10) + '0';
	ft_putchar_pf(c, count);
}
