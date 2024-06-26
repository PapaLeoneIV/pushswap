/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalizzazione_dati.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/05/04 13:12:30 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../pushswap.h"

int	*ft_manage_string_input(char **av)
{
	int		*arr;
	char	**mtx;
	int		len;

	len = 0;
	if (av[1][0] == '\0')
		error_fn();
	mtx = ft_split(av[1], ' ');
	if (!mtx)
	{
		ft_clear_mtx(mtx, len);
		error_fn();
	}
	while (mtx[len])
		len++;
	arr = ft_cmtx_to_arri_coverter(mtx);
	if (!arr)
	{
		ft_clear_mtx(mtx, len);
		error_fn();
	}
	ft_clear_mtx(mtx, len);
	return (arr);
}

int	*ft_manage_multiple_input(char **av)
{
	int	*arr;
	int	len;
	int	i;

	len = 0;
	i = 1;
	while (av[len] != NULL)
		len++;
	arr = ft_insertion_valid_input(av, len, i);
	if (arr == NULL)
	{
		free(arr);
		error_fn();
	}
	return (arr);
}

int	*ft_normalizzazione_dati(int ac, char **av)
{
	int	*arr;

	if (ac == 2)
		arr = ft_manage_string_input(av);
	else
		arr = ft_manage_multiple_input(av);
	return (arr);
}
