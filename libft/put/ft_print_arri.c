#include "libft.h"
#include "ft_printf.h"

void ft_print_arri(int* arr, int len)
{
    int i;

    i = 0;
    ft_printf("\n[Arr] :");
    while(arr && i < len)
    {
        ft_printf("\tidx->[%i]  :  %i\n", i, arr[i]);
        i++;
    }
}