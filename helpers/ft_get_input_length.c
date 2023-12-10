#include "libft.h"
#include "ft_printf.h"
#include "pushswap.h"

int	ft_get_input_length(int ac, char** av)
{
	char **mtx;
	int len;

	len = 0;
	if(ac <= 1)
		error_fn();
	else if(ac == 2)
	{
		mtx = ft_split(av[1], ' ');
		while(mtx[len])
			len++;
	}
	else
	{
		len = ac - 1;
	}
	return (len);
}