#include "pushswap.h"
#include "ft_printf.h"
#include "../libft.h"


void    ft_init_(int ac, char** av, t_stacks *stacks)
{
    stacks->input_arr_len = ft_get_input_length(ac, av);
	stacks->input_arr = ft_normalizzazione_dati(ac ,av);
    stacks->a = ft_dll_initi(stacks->input_arr, stacks->input_arr_len);
	stacks->b = ft_dll_initi_to(stacks->input_arr_len , 0);
    stacks->lis_len = 1;
    stacks->lis = ft_lis_algo_list(&stacks->lis_len, stacks->a);
    stacks->sorted_arr_len = (stacks->input_arr_len) - (stacks->lis_len);
    ft_sort_non_lis(stacks);
} 