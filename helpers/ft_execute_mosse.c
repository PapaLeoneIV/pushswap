#include "pushswap.h"
void ft_execute_mosse(t_stacks* stack)
{
	if(stack->mosse[0] == 0 && stack->mosse[1] == 0)
    {
		pa(&stack->a, &stack->b);
        return ;
    }
	else if(stack->mosse[0] > 0 && stack->mosse[1] > 0)
	{
		while(stack->mosse[0] != 0 || stack->mosse[1] != 0)
		{
            if(stack->mosse[0] > 0 && stack->mosse[1] > 0)
            {
                rr(&stack->a, &stack->b);
				stack->mosse[0]--;
                stack->mosse[1]--;
            }
			else if(stack->mosse[0] > 0)
			{
				ra(&stack->a);
				stack->mosse[0]--;
			}
			else if(stack->mosse[1] > 0)
			{
				rb(&stack->b);
				stack->mosse[1]--;
			}
		}
	}
    else if (stack->mosse[0] < 0 && stack->mosse[1] < 0)
    {
        while (stack->mosse[0] != 0 || stack->mosse[1] != 0)
        {
            if(stack->mosse[0] < 0 && stack->mosse[1] < 0)
            {
                rrr(&stack->a, &stack->b);
				stack->mosse[0]++;
                stack->mosse[1]++;
            }
            else if(stack->mosse[0] < 0)
			{
				rra(&stack->a);
				stack->mosse[0]++;
			}
			else if(stack->mosse[1] < 0)
			{
				rrb(&stack->b);
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
				stack->mosse[0]--;
            }
            if(stack->mosse[1] < 0)
            {
                rrb(&stack->b);
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
				stack->mosse[0]++;
            }
            if(stack->mosse[1] > 0)
            {
                rb(&stack->b);
				stack->mosse[1]--;
            }
        }
    }
    else if(stack->mosse[0] >= 0 && stack->mosse[1] == 0)
    {
        while(stack->mosse[0] != 0)
        {
            ra(&stack->a);
            stack->mosse[0]--;
        }
    }
    else if(stack->mosse[0] == 0 && stack->mosse[1] >= 0)
    {
        while(stack->mosse[1] != 0)
        {
            rb(&stack->b);
            stack->mosse[1]--;
        }
    }
    else if(stack->mosse[0] < 0 && stack->mosse[1] == 0)
    {
        while(stack->mosse[0] != 0)
        {
            rra(&stack->a);
            stack->mosse[0]++;
        }
    }
    else if(stack->mosse[0] == 0 && stack->mosse[1] < 0)
    {
        while(stack->mosse[1] != 0)
        {
            rrb(&stack->b);
            stack->mosse[1]++;
        }
    }

    pa(&stack->a, &stack->b);
/**
 * 5 casistiche:
 * a == 0 && b == 0 (pa); 
 * a > 0 && b > 0 (while a != 0 && b != 0) (rr)
 * a < 0 && b < 0 (while a != 0 && b != 0) (rrr)
 * a >= 0 && b < 0 (while a != 0 -> ra) (while b != 0 -> rrb)
 * a < 0 && b >= 0 (while a != 0 -> rra) (while b != 0 -> rb)
*/

}