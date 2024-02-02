#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "limits.h"

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
    dll_list* o_non_lis;
    int pivotindex;
    int* minmax;
    int minmax_len;
    int* mosse;
    int mosse_len;
    int lis_len;
    int* input_arr;
    int input_arr_len;
    int o_non_lis_len;
}   t_stacks;

int*    ft_normalizzazione_dati(int ac ,char **av);
int*    ft_manage_multiple_input(char **av);
int*    ft_manage_string_input(char **av);
int*    ft_cmtx_to_arri_coverter(char **mtx);
int*    ft_insertion_valid_input(char **av, int len, int i);
int     ft_get_input_length(int ac, char** av);
void    ft_init_(int ac, char** av, t_stacks *stacks);
void    ft_sort_non_lis(t_stacks* stacks);
void    ft_move_non_lis(t_stacks* stacks);
void    ft_print_params(t_stacks* stack);
void    ft_sortback(t_stacks* stack);
dll_list* ft_dll_calcola_mosse_b(t_stacks* stack);
dll_list* ft_dll_calcola_mosse_a(t_stacks* stack);
void ft_insert_mosse_node(dll_list** mosse_a, int val);
int ft_handle_mosse_condition_o(dll_list** mosse_a, dll_list* ptr_a, dll_list* ptr_b, t_stacks* stack);
int ft_handle_mosse_condition_u(dll_list** mosse_a, dll_list* ptr_a, dll_list* ptr_b, t_stacks* stack);
int ft_check_and_insert_mosse(dll_list** mosse_a, dll_list* ptr_a, dll_list* ptr_b, t_stacks* stack);
dll_list* ft_handle_empty_stack_b(dll_list* ptr_b);



int  ft_dll_calcola_mosse(dll_list* a, dll_list* b);
void check_if_ordered(int *arr, int len);
void ft_execute_mosse(t_stacks* stack);
int* ft_findminmax(dll_list* stack_a);












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