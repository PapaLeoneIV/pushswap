/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:53:01 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:53:06 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

void ra(dll_list** stack)
{
    int*   tmp;
    int*   head_val;
    
    ft_dll_return_head(stack);
    if(ft_dll_size((*stack)) <= 1)
        return ;
    head_val = (*stack)->val;
    ft_dll_return_tail(stack);
    tmp = (*stack)->val;
    (*stack)->val = (int *)head_val;
    (*stack) = (*stack)->prev;
    while((*stack) != NULL)
    {
        head_val = (*stack)->val;
        (*stack)->val = tmp;
        tmp = head_val;
        if((*stack)->prev == NULL)
            break;
        (*stack) = (*stack)->prev;
    }
    ft_dll_return_head(stack);
}
 
/* int main(void)
{
    int arr[] = {0, 0, 1};
    int arr2[] = {0, 0, 0, 0, 0, 0};
    dll_list* a = ft_dll_initi(arr, 3);
    dll_list* b = ft_dll_initi(arr2, 6);

    ra(&a);
    ft_dll_return_head(&a);
    while(a != NULL)
	{
		printf("%i\n", *(int *)a->val);
		if(a->next == NULL)
				break;
		a = a->next;
	} 
    printf("[----------------------]\n");
    while(b != NULL)
	{
		printf("%i\n", *(int *)b->val);
		if(b->next == NULL)
				break;
		b = b->next;
	}
    ft_dll_return_head(&a);
    ft_dll_clear(&a, free);
    ft_dll_return_head(&b);
    ft_dll_clear(&b, free);
} */
