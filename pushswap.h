/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:59:35 by rileone           #+#    #+#             */
/*   Updated: 2024/02/10 17:59:40 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf.h"
# include "libft.h"
# include "limits.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

# define LIS_INPUT_LIMIT 6

typedef struct s_stacks
{
	t_dll_list	*a;
	t_dll_list	*b;
	t_dll_list	*lis;
	t_dll_list	*o_non_lis;
	t_dll_list	*mosse_a;
	t_dll_list	*mosse_b;
	int			pivotindex;
	int			*minmax;
	int			minmax_len;
	int			*mosse;
	int			mosse_len;
	int			lis_len;
	int			*input_arr;
	int			input_arr_len;
	int			o_non_lis_len;
}				t_stacks;

/**
 * @brief Frees the memory allocated for the minisolver heap.
 * 
 * @param stacks The pointer to the stacks structure.
 * 
 * @return void
 */
void		free_minisolver_heap(t_stacks *stacks);

/**
 * Rotates the stack until it is ordered in ascending order.
 *
 * @param stack A pointer to the stack structure.
 */
void		ft_rotate_until_ordered(t_stacks *stack);

/**
 *  check if the doubly linked list is ordered
 * @param stacks The pointer to the stacks structure.
 * @return int 1 if the list is ordered, 0 otherwise.
 */
int			ft_dll_check_if_ordered(t_dll_list *stack);

/**
 * @brief Performs the "rapa" operation on the given stacks.
 *
 * This function executes the "rapa" operation on the stacks,
 * which is a custom operation specific to the program.
 * The exact behavior of the "rapa" operation is not specified here.
 *
 * @param stacks A pointer to the `t_stacks` structure representing the stacks.
 *
 * @return void
 */
void		rapa(t_stacks *stacks);

/**
 *  it s a set of moves, ra -> pa -> ra
 *
 * @param stacks The pointer to the stacks structure.
 */
void		rapara(t_stacks *stacks);

/**
 * @brief Performs a mini solver for the given stacks.
 *
 * This function is responsible for solving a subset
 * of the problem for the given stacks.
 *
 * @param stacks The pointer to the stacks structure.
 *
 * @return void
 */
void		minisolver2(t_dll_list *stacks, char x);
/**
 * @brief Performs a mini solver for the given stacks.
 *
 * This function is responsible for solving a 
 * subset of the problem for the given stacks.
 *
 * @param stacks The pointer to the stacks structure.
 *
 * @return void
 */
void		minisolver3(t_stacks *stacks);

/**
 * @brief Solves a specific case of the problem using a mini solver.
 *
 * This function is responsible for solving a specific case
 * of the problem using a mini solver.
 * It takes a pointer to a `t_stacks` structure as a parameter.
 *
 * @param stacks A pointer to a `t_stacks` structure representing the stacks.
 *
 * @return void
 */
void		minisolver4(t_stacks *stacks);

/**
 * Solves a specific case of the pushswap algorithm using a mini solver.
 *
 * @param stacks The pointer to the stacks structure.
 */

void		minisolver5(t_stacks *stacks);
/**
 * @brief Free the memory allocated for the stacks structure.
 * @param stack The stacks structure to be freed.
 */

void		ft_free_stacks(t_stacks *stack);
/**
 * @brief Normalize the input data by converting it to an array of integers.
 * @param ac The number of arguments.
 * @param av The array of arguments.
 * @return int* The normalized array of integers.
 */
int			*ft_normalizzazione_dati(int ac, char **av);

/**
 * @brief Manage multiple input arguments and 
 * convert them to an array of integers.
 * @param av The array of arguments.
 * @return int* The array of integers.
 */
int			*ft_manage_multiple_input(char **av);

/**
 * @brief Manage string input and convert it to an array of integers.
 * @param av The array of arguments.
 * @return int* The array of integers.
 */
int			*ft_manage_string_input(char **av);

/**
 * @brief Convert a matrix of strings to an array of integers.
 * @param mtx The matrix of strings.
 * @return int* The array of integers.
 */
int			*ft_cmtx_to_arri_coverter(char **mtx);

/**
 * @brief Insert valid input arguments into an array of integers.
 * @param av The array of arguments.
 * @param len The length of the array.
 * @param i The index of the current argument.
 * @return int* The array of integers.
 */
int			*ft_insertion_valid_input(char **av, int len, int i);

/**
 * @brief Get the length of the input arguments.
 * @param ac The number of arguments.
 * @param av The array of arguments.
 * @return int The length of the input.
 */
int			ft_get_input_length(int ac, char **av);

/**
 * @brief Initialize the stacks and input data.
 * @param ac The number of arguments.
 * @param av The array of arguments.
 * @param stacks The stacks structure.
 */
void		ft_init_(int ac, char **av, t_stacks *stacks);

/**
 * @brief Sort the non-LIS (Longest Increasing Subsequence) part of the stack.
 * @param stacks The stacks structure.
 */
int			ft_generate_non_lis(t_stacks *stacks);

/**
 * @brief Move the non-LIS (Longest Increasing Subsequence) part of the stack.
 * @param stacks The stacks structure.
 */
void		ft_move_non_lis(t_stacks *stacks);

/**
 * @brief Sort the stack back to its original order.
 * @param stack The stacks structure.
 */
void		ft_sortback(t_stacks *stack);

/**
 * @brief Calculate the moves for stack B.
 * @param stack The stacks structure.
 * @return t_dll_list* The list of moves for stack B.
 */
t_dll_list	*ft_dll_calcola_mosse_b(t_stacks *stack);

/**
 * @brief Calculate the moves for stack A.
 * @param stack The stacks structure.
 * @return t_dll_list* The list of moves for stack A.
 */
t_dll_list	*ft_dll_calcola_mosse_a(t_stacks *stack);

/**
 * @brief Insert a move node into the list of moves for stack A.
 * @param mosse_a The list of moves for stack A.
 * @param val The value of the move.
 */
int			ft_insert_mosse_node(t_dll_list **mosse_a, int val);

/**
 * @brief Handle the move condition "o" for the list of moves.
 * @param mosse_a The list of moves for stack A.
 * @param ptr_a The current node of stack A.
 * @param ptr_b The current node of stack B.
 * @param stack The stacks structure.
 * @return int The number of moves to execute.
 */
int			ft_handle_mosse_condition_o(t_dll_list **mosse_a,
				t_dll_list *ptr_a,
				t_dll_list *ptr_b,
				t_stacks *stack);

/**
 * @brief Handle the move condition "u" for the list of moves.
 * @param mosse_a The list of moves for stack A.
 * @param ptr_a The current node of stack A.
 * @param ptr_b The current node of stack B.
 * @param stack The stacks structure.
 * @return int The number of moves to execute.
 */
int			ft_handle_mosse_condition_u(t_dll_list **mosse_a,
				t_dll_list *ptr_a,
				t_dll_list *ptr_b,
				t_stacks *stack);

/**
 * @brief Check and insert the moves into the list of moves.
 * @param mosse_a The list of moves for stack A.
 * @param ptr_a The current node of stack A.
 * @param ptr_b The current node of stack B.
 * @param stack The stacks structure.
 * @return int The number of moves to execute.
 */
int			ft_check_and_insert_mosse(t_dll_list **mosse_a,
				t_dll_list *ptr_a,
				t_dll_list *ptr_b,
				t_stacks *stack);

/**
 * @brief Handle the case when stack B is empty.
 * @param ptr_b The current node of stack B.
 * @return t_dll_list* The updated node of stack B.
 */
t_dll_list	*ft_handle_empty_stack_b(t_dll_list *ptr_b);

/**
 * @brief Calculate the best move between the moves in Mova and Movb.
 * @param a The list of moves for stack A.
 * @param b The list of moves for stack B.
 * @return int The number of moves to execute.
 */
int			ft_dll_calcola_mosse(t_dll_list *a, t_dll_list *b);

/**
 * @brief Check if the array is ordered.
 * @param arr The array to check.
 * @param len The length of the array.
 * @return int 1 if the array is ordered, 0 otherwise.
 */

int			check_if_ordered(int *arr, int len);

/**
 * @brief Execute the moves.
 * @param stack The stacks structure.
 */
void		ft_execute_mosse(t_stacks *stack);

/**
 * @brief Swap the top two elements of stack A.
 * @param stack_a The stack A.
 */
void		sa(t_dll_list *stack_a, int flag);

/**
 * @brief Swap the top two elements of stack B.
 * @param stack_b The stack B.
 */
void		sb(t_dll_list *stack_b, int flag);

/**
 * @brief Swap the top two elements of both stack A and stack B.
 * @param stack_a The stack A.
 * @param stack_b The stack B.
 */
void		ss(t_dll_list *stack_a, t_dll_list *stack_b);

/**
 * @brief Push the top element of stack B to stack A.
 * @param stack_a The stack A.
 * @param stack_b The stack B.
 */
void		pa(t_dll_list **stack_a, t_dll_list **stack_b, int flag);

/**
 * @brief Push the top element of stack A to stack B.
 * @param stack_b The stack B.
 * @param stack_a The stack A.
 */
void		pb(t_dll_list **stack_b, t_dll_list **stack_a, int flag);

/**
 * @brief Rotate the stack A.
 * @param stack The stack A.
 */
void		ra(t_dll_list **stack, int flag);

/**
 * @brief Rotate the stack B.
 * @param stack The stack B.
 */
void		rb(t_dll_list **stack, int flag);

/**
 * @brief Rotate both stack A and stack B.
 * @param stack_a The stack A.
 * @param stack_b The stack B.
 */
void		rr(t_dll_list **stack_a, t_dll_list **stack_b);

/**
 * @brief Reverse rotate the stack A.
 * @param stack The stack A.
 */
void		rra(t_dll_list **stack, int flag);

/**
 * @brief Reverse rotate the stack B.
 * @param stack The stack B.
 */
void		rrb(t_dll_list **stack, int flag);

/**
 * @brief Reverse rotate both stack A and stack B.
 * @param stack_a The stack A.
 * @param stack_b The stack B.
 */
void		rrr(t_dll_list **stack_a, t_dll_list **stack_b);

#endif
