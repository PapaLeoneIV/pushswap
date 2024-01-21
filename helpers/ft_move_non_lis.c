#include "libft.h"
#include "ft_printf.h"
#include "pushswap.h"

void ft_move_non_lis(t_stacks* stacks)
{
	int i;
	int j;
	int num_nlis_pushed;
	dll_list* ptr;

	num_nlis_pushed = 0;
	i = 0;
	j = 0;
		ptr = stacks->o_non_lis;
		while(ptr != NULL)
		{
			if (*(int*)ptr->val == *(int*)stacks->a->val)
			{		
				pb(&stacks->b, &stacks->a);
				write(1, "pb\n", 3);
				ptr = ptr->next;
				num_nlis_pushed++;
			}
			else
			{
				ra(&stacks->a);
				write(1, "ra\n", 3);
				j++;
			}

		}
		/**in realta qui non dovrei usare rra ma andare a cancellare all 
		 * interno della stringa output gli ultimi n
		*/
	num_nlis_pushed = 0;
 	while(num_nlis_pushed < j)
	{
		rra(&stacks->a);
		write(1, "rra\n", 4);
		num_nlis_pushed++;
	} 

	ft_dll_return_head(&stacks->o_non_lis);
	ft_dll_update_index(&stacks->a);
}