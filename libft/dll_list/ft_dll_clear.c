/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:49 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:48:01 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dll_clear(dll_list **lst, void (*del)(void *))
{
	dll_list		*ptr;
	dll_list		*temp;

	if (!*lst ||!lst || !del)
		return ;
	ptr = (*lst);
	while (ptr != NULL)
	{
		temp = ptr;
		ptr = temp->next;
        free(temp->val);
		free(temp);
	}
	*lst = NULL;
}
