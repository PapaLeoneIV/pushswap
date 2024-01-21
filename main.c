/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:55:06 by rileone           #+#    #+#             */
/*   Updated: 2023/11/22 13:55:07 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include "ft_printf.h"
#include "../libft.h"
int ft_find_min(dll_list* a)
{
    int min;
    int idx;
    dll_list* ptr;


    min = INT_MAX;
    ptr = a;
    while(ptr != NULL)
    {
        if(*(int*)ptr->val < min)
        {
            min = *(int*)ptr->val;
            idx = ptr->index;
        }
        ptr = ptr->next;
    }
    return idx;
}

void ft_rotate_until_ordered(t_stacks* stack)
{
    int min_idx;
    int pivot;
    int len;
    
    min_idx = ft_find_min(stack->a);
    len = ft_dll_size(stack->a);
    pivot = len / 2;
    if(min_idx <= pivot)
    {
        while(min_idx != 0)
        {
            ra(&stack->a);
            write(1, "ra\n", 3);
            min_idx--;
        }   
    }
    else
    {
        while(min_idx != len)
        {
            rra(&stack->a);
            write(1, "rra\n", 4);
            min_idx++;
        }
    }
} 

int main(int ac, char **av)
{
	t_stacks stacks;

    stacks = (t_stacks){0};
 	ft_init_(ac, av, &stacks);
    ft_sort_non_lis(&stacks);
    ft_move_non_lis(&stacks);
    ft_sortback(&stacks);
     ft_rotate_until_ordered(&stacks); 
//ft_print_params(&stacks);
	
	free(stacks.input_arr);
    ft_dll_return_head(&(stacks.a));
    ft_dll_clear(&(stacks.a), free);
    ft_dll_return_head(&stacks.b);
    ft_dll_clear(&(stacks.b), free);
    ft_dll_return_head(&(stacks.lis));
    ft_dll_clear(&(stacks.lis), free);
} 