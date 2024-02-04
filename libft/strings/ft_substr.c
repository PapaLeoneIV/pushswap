/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:34:02 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:51:53 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strnull(void)
{
	char	*p;

	p = (char *) malloc(sizeof(char));
	*p = 0;
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strnull());
	if (len < slen)
		p = (char *) malloc(sizeof(char) * (len + 1));
	else
		p = (char *) malloc(sizeof(char) * ((slen - start) + 1));
	if (!p)
		return (0);
	i = 0;
	while (s[start] && len)
	{
		p[i] = s[start];
		start++;
		i++;
		len--;
	}
	p[i] = 0;
	return (p);
}
/*
int main()
{
	char *str = "";
    char *str1;
    size_t size = 343434;
    str1 = ft_substr(str, 43, size);
    if(!str1)
    printf("questa e' la sottostringa : %s\n", str1);
}
*/
/*
Parameters ????????????
s: The string from which to create the substring.
start: The start index of the substring in the
string ’s’.
len: The maximum length of the substring


Description"""""""""
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
*/
