#include "pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

 static stacks* ft_normalizza_dati(int ac, char** av)
{   
    iarr* input;
    stacks* stacks;

    input = malloc(sizeof(iarr));
    stacks = malloc(sizeof(stacks));
    input->len = ft_get_input_length(ac, av);
	input->arr = ft_normalizzazione_dati(ac ,av);
    stacks->a = ft_dll_initi(input->arr, input->len);
	stacks->b = ft_dll_initi_to(input->len, 0);
    return (stacks);
}


static void ft_algo_helper(stacks** stacks)
{
    iarr* lis;

    lis = malloc(sizeof(iarr));
    lis->len = 1;
    (*stacks)->lis = ft_lis_algo_list(&lis->len, (*stacks)->a);
     //TODO spostare tutti i non_lis numeri in b;devo spostarli in maniera ordinata, prendo  l index a meta dei non_lis, e sposto da a in b mettendoli sopra o sotto il pivot number 
}
void    ft_init_(int ac, char** av)
{
    stacks* stacks;

    stacks = ft_normalizza_dati(ac, av);
    stacks->lis = NULL;
    ft_algo_helper(&stacks);
    while(stacks->lis != NULL)
    {
        printf("%i\n", *(int*)stacks->lis->val);
        stacks->lis = stacks->lis->next;
    }
} 