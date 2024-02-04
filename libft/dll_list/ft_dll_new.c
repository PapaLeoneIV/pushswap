/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:50 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:48:01 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
//#include "ft_printf.h"

dll_list	*ft_dll_new(void *val)
{
	dll_list	*new;

	new = ft_calloc(1, sizeof(dll_list));
	if (!new)
		return (NULL);
	new->val = (int *)val;
	new->next = NULL;
    new->index = 0;
    new->prev = NULL;
	return (new);
}

/* 

int main()
{
	dll_list *head;
	dll_list *first;

	head = NULL;
	first = ft_dll_new((char *)"stringa!");
	ft_printf("%s\n", first->val);

} */
