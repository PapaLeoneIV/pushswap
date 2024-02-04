/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_hash_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:50:55 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:50:59 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void ft_free_hash_map(hash_map* map) 
{
    int i;
    item* current; 
    item* temp;

    i = 0; 
    while(i < map->size)
    {
        current = map->array[i];
        while (current != NULL) 
        {
            temp = current;
            current = current->next;
            free(temp);
            temp = NULL;
        }
        i++;
    }
    free(map->array);
    free(map);
}
