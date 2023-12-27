#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct iarr
{
    
    int* arr;
    int len;
} iarr;



typedef struct s_stacks
{
    dll_list* a;
    dll_list* b;
    dll_list* lis;
    int* input_arr;
    int input_len;
    int* sorted_arr;
    int sorted_arr_len;
    int lis_len;
}   t_stacks;

int*    ft_normalizzazione_dati(int ac ,char **av);
int*    ft_manage_multiple_input(char **av);
int*    ft_manage_string_input(char **av);
int*    ft_cmtx_to_arri_coverter(char **mtx);
int*    ft_insertion_valid_input(char **av, int len, int i);
int*    ft_cmtx_to_arri_coverter(char **mtx);
int     ft_get_input_length(int ac, char** av);
void    ft_init_(int ac, char** av);


void    sa(dll_list *stack_a);
void    sb(dll_list *stack_b);
void    ss(dll_list *stack_a, dll_list *stack_b);
void    pa(dll_list **stack_a, dll_list **stack_b);
void    pb(dll_list **stack_b, dll_list **stack_a);
void    ra(dll_list **stack);
void    rb(dll_list** stack);
void    rr(dll_list** stack_a, dll_list** stack_b);
void    rra(dll_list** stack);
void    rrb(dll_list** stack);
void    rrr(dll_list** stack_a,dll_list** stack_b);














#endif