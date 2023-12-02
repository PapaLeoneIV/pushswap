#include"../libft.h"
#include"pushswap.h"

int *ft_cmtx_to_arri_coverter(char **mtx)
{
	int i;
	int len;
	int *arr;
	int tmp;

	i = 0;
	len = 0;
	tmp = 0;
	if(!mtx || !mtx[len])
		return (NULL);
	while(mtx[len])
		len++;
	arr = ft_insertion_valid_input(mtx, len, i);
	return (arr);
}