#include"../libft.h"
#include"pushswap.h"

int *ft_insertion_valid_input(char **av, int len, int offset)
{
	int *arr;
    int count;
	int flag;

	flag = offset;
    count = 0;
	arr = (int *)ft_calloc(len , sizeof(int));
	while(offset < len)
	{
		if(ft_isnumber(av[offset]))
		{
			arr[count] = ft_atoi(av[offset]);
			count++;
			offset++;
		}
		else
		{
			free(arr);
            printf("errore in ft_insertion_valid_input");
			error_fn();
		}	
	}

	if(ft_check_for_dupl(arr, len - flag) == 1)
	{
		free(arr);
        printf("errore in ft_check_for_dupl");
		error_fn();
	}
	return (arr);
}

