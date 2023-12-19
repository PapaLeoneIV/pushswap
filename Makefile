NAMEA = libpushswap.a
NAME = push_swap
LIBFT_DIR = libft
DLL_LIST_DIR = dll_list
PRINTF_DIR = printf
STRING_DIR = strings
HELPERS_DIR = ./helpers
STACK_MOVES_DIR = ./stack_moves
EVERY_INCLUDES=-I. -I$(LIBFT_DIR) -I$(LIBFT_DIR)/$(PRINTF_DIR) -I./$(HELPERS_DIR) -I./$(STACK_MOVES_DIR) -I$(LIBFT_DIR)/$(STRING_DIR) -I$(LIBFT_DIR)/$(MEM_DIR) -I$(LIBFT_DIR)/$(PUT_DIR) 

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -g 
ARCHIVE = ar rcs

SRC = 	$(HELPERS_DIR)/ft_normalizzazione_dati.c \
    	$(HELPERS_DIR)/ft_insertion_valid_input.c \
		$(HELPERS_DIR)/ft_cmtx_to_arri_coverter.c \
		$(HELPERS_DIR)/ft_get_input_length.c \
		$(HELPERS_DIR)/ft_init_.c \
		$(STACK_MOVES_DIR)/sa.c \
		$(STACK_MOVES_DIR)/sb.c \
		$(STACK_MOVES_DIR)/ss.c \
		$(STACK_MOVES_DIR)/pa.c \
		$(STACK_MOVES_DIR)/rb.c \
		$(STACK_MOVES_DIR)/rr.c \
		$(STACK_MOVES_DIR)/rra.c \
		$(STACK_MOVES_DIR)/rrb.c \
		$(STACK_MOVES_DIR)/rrr.c \


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

.SILENT: 
.PHONY: all clean fclean re libft 
