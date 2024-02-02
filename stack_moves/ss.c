/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
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

void ss(dll_list *stack_a, dll_list *stack_b)
{
    sa(stack_a);
    sa(stack_b);
}
/* 

int main()
{
    dll_list *a_head;
    dll_list *b_head;
    int arr[] = {1, 2 , 3, 4};
    int arr2[] = {99, 98 , 97, 96};
    a_head = ft_dll_initi(arr, 4);
    b_head = ft_dll_initi(arr2, 4);
    ss(a_head, b_head);
    a_head = ft_dll_return_head(a_head);
    b_head = ft_dll_return_head(b_head);
    while(a_head != NULL)
    {
        printf("%i\n", *(int *)a_head->val);
        a_head = a_head->next;
    }
      while(b_head != NULL)
    {
        printf("%i\n", *(int *)b_head->val);
        b_head = b_head->next;
    }


}   */
