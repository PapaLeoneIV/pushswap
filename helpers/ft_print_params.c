#include "libft.h"
#include "ft_printf.h"
#include "pushswap.h"

void ft_print_params(t_stacks* stack)
{

    ft_printf("\nstack->a");
    ft_dll_printi(stack->a);
    ft_printf("\nstack->b");
    ft_dll_printi(stack->b);
    ft_printf("-------------------");
    ft_printf("\nstack->input_arr");
    ft_print_arri(stack->input_arr, stack->input_arr_len);
   ft_printf("\nstack->lis");
    ft_dll_printi(stack->lis);
    ft_printf("\nstack->o_non_lis");
    ft_dll_printi(stack->o_non_lis);

}