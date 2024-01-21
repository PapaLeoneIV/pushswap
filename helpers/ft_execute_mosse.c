#include "pushswap.h"
void ft_execute_mosse(t_stacks* stack)
{
	if(stack->mosse[0] == 0 && stack->mosse[1] == 0)
    {
		pa(&stack->a, &stack->b);
        write(1, "pa\n", 3);
        return ;
    }
	else if(stack->mosse[0] > 0 && stack->mosse[1] > 0)
	{
		while(stack->mosse[0] != 0 || stack->mosse[1] != 0)
		{
            if(stack->mosse[0] > 0 && stack->mosse[1] > 0)
            {
                rr(&stack->a, &stack->b);
                write(1, "rr\n", 3);
				stack->mosse[0]--;
                stack->mosse[1]--;
            }
			else if(stack->mosse[0] > 0)
			{
				ra(&stack->a);
                write(1, "ra\n", 3);
				stack->mosse[0]--;
			}
			else if(stack->mosse[1] > 0)
			{
				rb(&stack->b);
                write(1, "rb\n", 3);
				stack->mosse[1]--;
			}
		}
	}
    else if (stack->mosse[0] < 0 && stack->mosse[1] < 0)
    {
        while (stack->mosse[0] != 0 || stack->mosse[1] != 0)
        {
            if(stack->mosse[0] != 0 && stack->mosse[1] < 0)
            {
                rrr(&stack->a, &stack->b);
                write(1, "rrr\n", 4);
				stack->mosse[0]++;
                stack->mosse[1]++;
            }
            else if(stack->mosse[0] < 0)
			{
				rra(&stack->a);
                write(1, "rra\n", 4);
				stack->mosse[0]++;
			}
			else if(stack->mosse[1] < 0)
			{
				rrb(&stack->b);
                write(1, "rrb\n", 4);
				stack->mosse[1]++;
			}
        }
    }
    else if(stack->mosse[0] >= 0 && stack->mosse[1] < 0)
    {
        while(stack->mosse[0] != 0 || stack->mosse[1] != 0)
        {
            if(stack->mosse[0] > 0)
            {
                ra(&stack->a);
                write(1, "ra\n", 3);
				stack->mosse[0]--;
            }
            if(stack->mosse[1] < 0)
            {
                rrb(&stack->b);
                write(1, "rrb\n", 4);
				stack->mosse[1]++;
            }
        }
    }
    else if(stack->mosse[0] < 0 && stack->mosse[1] >= 0)
    {
        while(stack->mosse[0] != 0 || stack->mosse[1] != 0)
        {
            if(stack->mosse[0] < 0)
            {
                rra(&stack->a);
                write(1, "rra\n", 4);
				stack->mosse[0]++;
            }
            if(stack->mosse[1] > 0)
            {
                rb(&stack->b);
                write(1, "rb\n", 3);
				stack->mosse[1]--;
            }
        }
    }
    else if(stack->mosse[0] >= 0 && stack->mosse[1] == 0)
    {
        while(stack->mosse[0] != 0)
        {
            ra(&stack->a);
            write(1, "ra\n", 3);
            stack->mosse[0]--;
        }
    }
    else if(stack->mosse[0] == 0 && stack->mosse[1] >= 0)
    {
        while(stack->mosse[1] != 0)
        {
            rb(&stack->b);
            write(1, "rb\n", 3);
            stack->mosse[1]--;

        }
    }
    else if(stack->mosse[0] < 0 && stack->mosse[1] == 0)
    {
        while(stack->mosse[0] != 0)
        {
            rra(&stack->a);
            write(1, "rra\n", 4);
            stack->mosse[0]++;
        }
    }
    else if(stack->mosse[0] == 0 && stack->mosse[1] < 0)
    {
        while(stack->mosse[1] != 0)
        {
            rrb(&stack->b);
            write(1, "rrb\n", 4);
            stack->mosse[1]++;
        }
    }
    pa(&stack->a, &stack->b);
    write(1, "pa\n", 3);
/**
 * 5 casistiche:
 * a == 0 && b == 0 (pa); 
 * a > 0 && b > 0 (while a != 0 && b != 0) (rr)
 * a < 0 && b < 0 (while a != 0 && b != 0) (rrr)
 * a >= 0 && b < 0 (while a != 0 -> ra) (while b != 0 -> rrb)
 * a < 0 && b >= 0 (while a != 0 -> rra) (while b != 0 -> rb)
*/

}