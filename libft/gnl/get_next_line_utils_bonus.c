/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:03:43 by rileone           #+#    #+#             */
/*   Updated: 2023/11/17 19:03:51 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	ft_gnl_strlen(char *str)
{
	int		i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

void	*ft_gnl_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(size * nmemb);
	if (str == 0)
		return (0);
	i = 0;
	while (i < nmemb * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

char	*ft_gnl_strjoin(char *s1, char *s2, int bytes)
{
	char	*out;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	len = ft_gnl_strlen(s1) + ft_gnl_strlen(s2);
	out = (char *)ft_gnl_calloc(sizeof(char), len + 1);
	if (!(out))
		return (NULL);
	while (s1 && s1[i])
		out[j++] = s1[i++];
	i = 0;
	while (i < bytes)
		out[j++] = s2[i++];
	out[len] = 0;
	return (out);
}

char	*ft_gnl_substr(char *s, unsigned int start, int len)
{
	char	*p;
	int		i;
	int		slen;

	if (!s)
		return (NULL);
	slen = ft_gnl_strlen(s);
	if (len < slen)
		p = (char *) ft_gnl_calloc(sizeof(char), (len + 1));
	else
		p = (char *) ft_gnl_calloc(sizeof(char), ((slen - start) + 1));
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
	p[i] = '\0';
	return (p);
}

int	ft_gnl_strchri(char *s, int c)
{
	int	i;

	i = 0;
	while (i <= ft_gnl_strlen(s))
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}
