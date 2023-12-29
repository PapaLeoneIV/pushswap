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
static void ft_print_params(t_stacks* stack)
{
/*     ft_printf("\nstack->input_arr");
    ft_print_arri(stack->input_arr, stack->input_arr_len); */
    ft_printf("\nstack->lis");
    ft_dll_printi(stack->lis);
    ft_printf("\nstack->o_non_lis");
    ft_print_arri(stack->o_non_lis, stack->o_non_lis_len);
    ft_printf("\nstack->a");
    ft_dll_printi(stack->a);
    ft_printf("\nstack->b");
    ft_dll_printi(stack->b);
}
int main(int ac, char **av)
{
	t_stacks stacks;

    stacks = (t_stacks){0};
 	ft_init_(ac, av, &stacks);
    ft_print_params(&stacks);
    ft_printf("-------------------------");
    /*TODO dopo aver otttenuto le dll necessarie ora devo:
    * trovare un pivot all interno di ordered_non_lis (pivot == numero di cicli fino a NULL/2 ---> devo scorrere nuovamente tot volte per prendere il *(int*)val)
    * partendo dal primo elem di ordered_non_lis:
    *                       - controllare l index per vedere se conviene muovere l elem sopra o sotto sullo stack_a
    *                       - spostarlo in stack_b in modo conveniente:
    *                               -if index_elem > stack_a.len /2 allora conviene shifatare verso il basso
    *                               -una volta portato in cima -->pb/pa
    *                               -comparare il pivot con il numero in questione(pivot > num)->sopra al pivot
    *                               -muovere tutti gli elementi non_Lis da stack_a ad stack_b in modo ordinato
    *                               -rimuoverli indietro nello stack_a 
    */

	
	free(stacks.input_arr);
    ft_dll_return_head(&(stacks.a));
    ft_dll_clear(&(stacks.a), free);
    ft_dll_return_head(&stacks.b);
    ft_dll_clear(&(stacks.b), free);
    ft_dll_return_head(&(stacks.lis));
    ft_dll_clear(&(stacks.lis), free);

}