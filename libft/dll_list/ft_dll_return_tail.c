/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_return_tail.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:50 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:48:01 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void    ft_dll_return_tail(dll_list **lst)
{
    while(!lst || !*lst || (*lst)->next)
    {
        *lst = (*lst)->next;
    }
}
