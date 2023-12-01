#include "libft.h"
#include "ft_printf.h"
#include "pushswap.h"

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
	arr = ft_insertion_valid_input(mtx, len);
	return (arr);
}
	/**
	 * devo capire se fare il free della matrice qui o se farlo nello scope di dove chiamo la funzione 
	*/
int *ft_manage_string_input(char **av)
{
	int *arr;
	char **mtx;
	int i;

	i = 0;
	mtx = ft_split(av[1], ' ');
	arr = ft_cmtx_to_arri_coverter(mtx);
	while(arr && arr[i])
	{
		free(mtx[i]);
		mtx[i] = NULL;
		i++;
	}	
	free(mtx);
	return (arr);
}




int *ft_manage_multiple_input(char **av)
{
	int count;
	int *arr;
	int len;
	int i;

	count = 0;
	len = 0;
	i = 1;
	while(av[len] != NULL)
		len++;
	arr = ft_insertion_valid_input(av, len);
	return (arr);
}
int *ft_normalizzazione_dati(int ac ,char **av)
{
	int *arr;

	if(ac < 2)
		error_fn();
	if(ac == 2) 
		arr = ft_manage_string_input(av);
	else
		arr = ft_manage_multiple_input(av);
	return (arr);
}

