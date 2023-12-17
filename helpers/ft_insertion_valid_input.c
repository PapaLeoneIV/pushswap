#include"../libft.h"
#include"pushswap.h"

int *ft_insertion_valid_input(char **av, int len, int i)
{
	int *arr;
    int count;

    count = 0;
	arr = (int *)ft_calloc(len , sizeof(int));
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
            printf("errore in ft_insertion_valid_input");
			error_fn();
		}	
	}
	if(ft_check_for_dupl(arr, len - 1) == 1)
	{
		free(arr);
        printf("errore in ft_check_for_dupl");
		error_fn();
	}
	return (arr);
}

