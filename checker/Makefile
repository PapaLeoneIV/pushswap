NAMEA = libpushswap.a
NAME = checker
LIBFT_DIR = libft
t_dll_list_DIR = t_dll_list
PRINTF_DIR = printf
STRING_DIR = strings
HELPERS_DIR = ./helpers
STACK_MOVES_DIR = ./stack_moves
GNL_DIR = gnl
EVERY_INCLUDES=-I. -I$(LIBFT_DIR) -I$(LIBFT_DIR)/$(PRINTF_DIR) -I$(LIBFT_DIR)/$(GNL_DIR) -I./$(HELPERS_DIR) -I./$(STACK_MOVES_DIR) -I$(LIBFT_DIR)/$(STRING_DIR) -I$(LIBFT_DIR)/$(MEM_DIR) -I$(LIBFT_DIR)/$(PUT_DIR) 

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -g 
ARCHIVE = ar rcs

SRC =		$(addprefix $(HELPERS_DIR)/,    ft_free_stack.c ft_normalizzazione_dati.c ft_insertion_valid_input.c ft_cmtx_to_arri_coverter.c ft_get_input_length.c ft_init_.c) \
			$(addprefix $(STACK_MOVES_DIR)/,mosse.c  mosse2.c mosse3.c ) \


OBJ = $(SRC:.c=.o)

all: $(NAMEA)

%.o: %.c
	@$(COMPILE) -c $< -o $@ $(EVERY_INCLUDES)

libft:
	@$(MAKE) -C $(LIBFT_DIR)


$(NAMEA): libft $(OBJ)
	@mv libft/libft.a ./$(NAMEA)
	@$(ARCHIVE) $(NAMEA) $(OBJ)
	@$(COMPILE) $(EVERY_INCLUDES) main.c -L. -lpushswap -o $(NAME)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ) $(NAMEA)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) $(NAMEA)

re: fclean all

#.SILENT: 
.PHONY: all clean fclean re libft 