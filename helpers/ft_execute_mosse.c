/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_mosse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:52:34 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
void move_positives(t_stacks *stacks)
{
    int i;

    i = 0;
    while(i < stacks->mosse[0] && i < stacks->mosse[1])
    {
        rr(&stacks->a, &stacks->b);
        write(1, "rr\n", 3);
        i++;
    }
    while(i < stacks->mosse[0] || i < stacks->mosse[1])
    {
        if(i < stacks->mosse[0])
        {
            ra(&stacks->a);
            write(1, "ra\n", 3);
        }
        else if(i < stacks->mosse[1])
        {
            rb(&stacks->b);
            write(1, "rb\n", 3);
        }
        i++;
    }
}

void move_pos_neg(t_stacks *stacks)
{
    int i;

    i = 0;
    while(i < stacks->mosse[0])
    {
        ra(&stacks->a);
        write(1, "ra\n", 3);
        i++;
    }
    while(stacks->mosse[1] < 0)
    {
        rrb(&stacks->b);
        write(1, "rrb\n", 4);
        stacks->mosse[1]++;
    }
}
void move_neg_pos(t_stacks *stacks)
{
    int i;

    i = 0;
    while(stacks->mosse[0] < 0)
    {
        rra(&stacks->a);
        write(1, "rra\n", 4);
        stacks->mosse[0]++;
    }
    while(i < stacks->mosse[1])
    {
        rb(&stacks->b);
        write(1, "rb\n", 3);
        i++;
    }
}

void move_negatives(t_stacks *stacks)
{
    while(stacks->mosse[0] < 0 && stacks->mosse[1] < 0)
    {
        rrr(&stacks->a, &stacks->b);
        write(1, "rrr\n", 4);
        stacks->mosse[0]++;
        stacks->mosse[1]++;
    }
    while(stacks->mosse[0] < 0 || stacks->mosse[1] < 0)
    {
        if(stacks->mosse[0] < 0)
        {
            rra(&stacks->a);
            write(1, "rra\n", 4);
            stacks->mosse[0]++;
        }
        else if(stacks->mosse[1] < 0)
        {
            rrb(&stacks->b);
            write(1, "rrb\n", 4);
            stacks->mosse[1]++;
        }
    }
}

void ft_execute_mosse(t_stacks* stack)
{
	if(stack->mosse[0] >= 0 && stack->mosse[1] >= 0)
        move_positives(stack);
    else if (stack->mosse[0] >= 0 && stack->mosse[1] <= 0)
        move_pos_neg(stack);
    else if(stack->mosse[0] <= 0 && stack->mosse[1] >= 0)
        move_neg_pos(stack);
    else if(stack->mosse[0] <= 0 && stack->mosse[1] <= 0)
        move_negatives(stack);
    pa(&stack->a, &stack->b);
    write(1, "pa\n", 3);
  
}
