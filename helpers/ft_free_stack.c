#include "pushswap.h"

void ft_free_stacks(t_stacks stack)
{
	free(stack.input_arr);
	ft_dll_return_head(&(stack.a));
	ft_dll_clear(&(stack.a), free);
	ft_dll_return_head(&stack.b);
	ft_dll_clear(&(stack.b), free);
	ft_dll_return_head(&(stack.lis));
	ft_dll_clear(&(stack.lis), free);
	ft_dll_return_head(&(stack.o_non_lis));
	ft_dll_clear(&(stack.o_non_lis), free);
}