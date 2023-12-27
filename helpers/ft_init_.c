#include "pushswap.h"
#include "ft_printf.h"
#include "../libft.h"


void    ft_init_(int ac, char** av, t_stacks *stacks)
{
    stacks->input_len = ft_get_input_length(ac, av);
	stacks->input_arr = ft_normalizzazione_dati(ac ,av);
    stacks->a = ft_dll_initi(stacks->input_arr, stacks->input_len);
	stacks->b = ft_dll_initi_to(stacks->input_len , 0);
    stacks->lis_len = 1;
    stacks->lis = ft_lis_algo_list(&stacks->lis_len, stacks->a);
    
} 