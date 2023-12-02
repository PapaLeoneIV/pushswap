#include"../libft.h"
#include"pushswap.h"

int *ft_insertion_valid_input(char **av, int len, int i)
{
	int *arr;
    int count;

    count = 0;
	arr = (int *)ft_calloc(len + 1 , sizeof(int));
	while(i < len)
	{
		if(ft_isnumber(av[i]))
		{
			arr[count] = ft_atoi(av[i]);
			count++;
			i++;
		}
		else
		{
			free(arr);
			error_fn();
		}	
	}
	if(ft_check_for_dupl(arr, len) == 1)
	{
		free(arr);
		error_fn();
	}
	return (arr);
}

