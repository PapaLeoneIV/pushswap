#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

int *ft_normalizzazione_dati(int ac ,char **av);
int *ft_manage_multiple_input(char **av);
int *ft_manage_string_input(char **av);
int *ft_cmtx_to_arri_coverter(char **mtx);
void ft_check_for_dupl(int* arr, int size);


#endif