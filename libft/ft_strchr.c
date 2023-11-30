/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:31:04 by rileone           #+#    #+#             */
/*   Updated: 2023/10/20 22:34:33 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	char *str1;
	char chare;
	
	str1 = "sadasdsb";
	chare = 'b';
	printf("risultato : %s\n", ft_strchr(str1, chare));
	printf("risultato : %s", strchr(str1, chare));
	return 0;
	
	
}
*/
