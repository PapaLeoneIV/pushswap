#include "pushswap.h"
#include "ft_printf.h"
#include "../libft.h"



void    ft_init_(int ac, char** av, t_stacks *stacks)
{
    //normalizzo gli input che mi vengono dati
    stacks->input_arr_len = ft_get_input_length(ac, av);
	stacks->input_arr = ft_normalizzazione_dati(ac ,av);
    //inizializzo i due stack a , b
    stacks->a = ft_dll_initi(stacks->input_arr, stacks->input_arr_len);
	stacks->b = ft_dll_initi_to(stacks->input_arr_len , 0);
    //mi prendo il mio LIS
    stacks->lis_len = 1;
    stacks->lis = ft_lis_algo_list(&stacks->lis_len, stacks->a);
    //mi prendo tutti i non lis
    stacks->non_lis_len = (stacks->input_arr_len) - (stacks->lis_len);
    ft_return_non_lis_with_idx(stacks);

}