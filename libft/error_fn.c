#include "ft_printf.h"
#include "libft.h"

void error_fn()
{
	write(2, "Error\n", 6);
	exit(0);
}