/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_lastnode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:49 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:48:01 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void ft_del_lastnode(dll_list* list)
{
	dll_list* tmp;
	
	tmp = list;
	if(!list)
		return ;
	while (tmp != NULL)
	{
		if(tmp->next->next == NULL)
		{
			free(tmp->next);
			tmp->next = NULL;
			return ;
		}
		tmp = tmp->next;
	}
}
