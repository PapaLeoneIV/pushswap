NAMEA = libpushswap.a
NAME = push_swap
NAME_BONUS = checker
LIBFT_DIR = libft
t_dll_list_DIR = t_dll_list
PRINTF_DIR = ./libft/printf
STRING_DIR = strings
HELPERS_DIR = ./helpers
STACK_MOVES_DIR = ./stack_moves
GNL_DIR = ./libft/gnl
EVERY_INCLUDES=-I. -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -I./$(HELPERS_DIR) -I./$(STACK_MOVES_DIR) -I$(LIBFT_DIR)/$(STRING_DIR) -I$(LIBFT_DIR)/$(MEM_DIR) -I$(LIBFT_DIR)/$(PUT_DIR) 

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -g 
ARCHIVE = ar rcs

SRC =		$(addprefix $(HELPERS_DIR)/, ft_free_minisolver_heap.c ft_rotate_until_ordered.c minisolvers.c ft_free_stack.c ft_normalizzazione_dati.c ft_insertion_valid_input.c ft_cmtx_to_arri_coverter.c ft_get_input_length.c ft_init_.c ft_generate_non_lis.c ft_move_non_lis.c ft_sort_back.c ft_dll_calcola_mosse.c ft_dll_calcola_mosse_b.c ft_dll_calcola_mosse_a.c ft_execute_mosse.c mosse_helpers.c) \
			$(addprefix $(STACK_MOVES_DIR)/,mosse.c  mosse2.c mosse3.c ) \

SRC_BONUS = $(addprefix $(HELPERS_DIR)/, ft_free_minisolver_heap.c ft_rotate_until_ordered.c minisolvers.c ft_free_stack.c ft_normalizzazione_dati.c ft_insertion_valid_input.c ft_cmtx_to_arri_coverter.c ft_get_input_length.c ft_init_.c ft_generate_non_lis.c ft_move_non_lis.c ft_sort_back.c ft_dll_calcola_mosse.c ft_dll_calcola_mosse_b.c ft_dll_calcola_mosse_a.c ft_execute_mosse.c mosse_helpers.c) \
			$(addprefix $(STACK_MOVES_DIR)/,mosse.c  mosse2.c mosse3.c ) \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAMEA)

%.o: %.c
	$(COMPILE) -c $< -o $@ $(EVERY_INCLUDES)


$(NAMEA): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(COMPILE) $(EVERY_INCLUDES) main.c $(OBJ) -L./$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(GNL_DIR) -lgnl -o $(NAME)

bonus: $(OBJ_BONUS)
	$(MAKE) -C $(LIBFT_DIR)
	$(COMPILE) $(EVERY_INCLUDES) $(OBJ_BONUS) checker.c -L./$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(GNL_DIR) -lgnl  -o $(NAME_BONUS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ) $(OBJ_BONUS) $(NAMEA)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS) $(NAMEA)

re: fclean all bonus 

#.SILENT: 
.PHONY: all clean fclean re libft 