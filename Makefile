NAMEA = libpushswap.a
NAME = push_swap
LIBFT_DIR = libft
DLL_LIST_DIR = dll_list
PRINTF_DIR = printf
HELPERS_DIR = ./helpers
STACK_MOVES_DIR = ./stack_moves
EVERY_INCLUDES=-I. -I$(LIBFT_DIR) -I$(LIBFT_DIR)/$(PRINTF_DIR) -I./$(HELPERS_DIR) -I./$(STACK_MOVES_DIR)

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -g 
ARCHIVE = ar rcs

SRC = 	$(HELPERS_DIR)/ft_normalizzazione_dati.c \
    	$(HELPERS_DIR)/ft_insertion_valid_input.c \
		$(HELPERS_DIR)/ft_cmtx_to_arri_coverter.c \
		$(STACK_MOVES_DIR)/sa.c \
		$(STACK_MOVES_DIR)/sb.c \
		$(STACK_MOVES_DIR)/ss.c \


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

.PHONY: all clean fclean re libft
