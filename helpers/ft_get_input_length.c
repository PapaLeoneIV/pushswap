#include "libft.h"
#include "ft_printf.h"
#include "pushswap.h"

int ft_get_input_length(int ac, char** av)
{
	char **mtx;
	int len;
    int i;

    i = 0;
	len = 0;
	if(ac <= 1)
		error_fn();
	else if(ac == 2)
	{
		mtx = ft_split(av[1], ' ');
		while(mtx && mtx[len])
			len++;
        while(i < len)
	    {
		    free(mtx[i]);
		    mtx[i] = NULL;
		    i++;
	    }
        free(mtx);
        mtx = NULL;
	}
	else
	{
		len = ac - 1;
	}
	return (len);
}