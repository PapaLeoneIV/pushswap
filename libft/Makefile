NAME = libft.a
HNAME = libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c -g
ARCHIVE = ar rc
DLL_LIST_DIR = dll_list
ERROR_DIR = errors
HASH_DIR = hash_map
IS_DIR = is
MEM_DIR = mem
PRINTF_DIR = printf
PUT_DIR = put
SLL_DIR = sll_list
STRING_DIR = strings
TO_DIR = to
ALGO_DIR = algorithms



SRC =		$(ERROR_DIR)/error_fn.c \
			$(addprefix ${TO_DIR}/, ft_atoi.c ft_itoa.c)  \
			$(IS_DIR)/ft_isnumber.c \
			$(IS_DIR)/ft_isalnum.c \
			$(IS_DIR)/ft_isalpha.c \
			$(IS_DIR)/ft_isascii.c \
			$(IS_DIR)/ft_isdigit.c \
			$(IS_DIR)/ft_isprint.c \
			$(STRING_DIR)/ft_split.c \
			$(STRING_DIR)/ft_strchr.c \
			$(STRING_DIR)/ft_strdup.c \
			$(STRING_DIR)/ft_striteri.c \
			$(STRING_DIR)/ft_strjoin.c \
			$(STRING_DIR)/ft_strlcat.c \
			$(STRING_DIR)/ft_strlcpy.c \
			$(STRING_DIR)/ft_strlen.c \
			$(STRING_DIR)/ft_strmapi.c \
			$(STRING_DIR)/ft_strncmp.c \
			$(STRING_DIR)/ft_strnstr.c \
			$(STRING_DIR)/ft_strrchr.c \
			$(STRING_DIR)/ft_strtrim.c \
			$(STRING_DIR)/ft_substr.c \
			$(STRING_DIR)/ft_tolower.c \
			$(STRING_DIR)/ft_toupper.c \
			$(PUT_DIR)/ft_putchar_fd.c\
			$(PUT_DIR)/ft_putchr.c \
			$(PUT_DIR)/ft_putstr.c \
			$(PUT_DIR)/ft_putendl_fd.c \
			$(PUT_DIR)/ft_putnbr.c \
			$(PUT_DIR)/ft_putnbr_fd.c \
			$(PUT_DIR)/ft_putstr_fd.c \
			$(PUT_DIR)/ft_print_arri.c \
			$(MEM_DIR)/ft_calloc.c \
			$(MEM_DIR)/ft_memchr.c \
			$(MEM_DIR)/ft_memcmp.c \
			$(MEM_DIR)/ft_memcpy.c \
			$(MEM_DIR)/ft_memmove.c \
			$(MEM_DIR)/ft_memset.c \
			$(MEM_DIR)/ft_bzero.c \
			$(HASH_DIR)/ft_create_hash_map.c \
			$(HASH_DIR)/ft_free_hash_map.c \
			$(HASH_DIR)/ft_get_frequency.c \
			$(HASH_DIR)/ft_hash_fn.c \
			$(HASH_DIR)/ft_insert_in_hash_map.c \
			$(HASH_DIR)/ft_check_for_dupl.c \
			$(DLL_LIST_DIR)/ft_dll_insert_head.c \
			$(DLL_LIST_DIR)/ft_dll_insert_tail.c \
			$(DLL_LIST_DIR)/ft_dll_new.c \
			$(DLL_LIST_DIR)/ft_dll_return_head.c \
			$(DLL_LIST_DIR)/ft_dll_return_tail.c \
			$(DLL_LIST_DIR)/ft_dll_size.c \
			$(DLL_LIST_DIR)/ft_dll_clear.c \
			$(DLL_LIST_DIR)/ft_dll_initi.c \
			$(DLL_LIST_DIR)/ft_dll_initi_to.c \
			$(DLL_LIST_DIR)/ft_dll_update_index.c \
			$(DLL_LIST_DIR)/ft_dll_get_node.c \
			$(DLL_LIST_DIR)/ft_dll_get_value.c \
			$(DLL_LIST_DIR)/ft_dll_printi.c \
			$(DLL_LIST_DIR)/ft_del_lastnode.c \
			$(DLL_LIST_DIR)/ft_dll_get_tail_index.c \
			$(SLL_DIR)/ft_lstnew.c \
			$(SLL_DIR)/ft_lstadd_front.c \
			$(SLL_DIR)/ft_lstsize.c \
			$(SLL_DIR)/ft_lstlast.c \
			$(SLL_DIR)/ft_lstadd_back.c \
			$(SLL_DIR)/ft_lstdelone.c \
			$(SLL_DIR)/ft_lstclear.c \
			$(SLL_DIR)/ft_lstiter.c \
			$(SLL_DIR)/ft_lstmap.c \
			$(ALGO_DIR)/ft_lis_algo_list.c \
			$(ALGO_DIR)/ft_quick_sort.c \
			$(ALGO_DIR)/ft_lis_algo_arr.c \


OBJ = ${SRC:.c=.o}

all: printf $(NAME)


%.o: %.c
	@$(COMPILE) $< -o $@ -I. -Iprintf

printf:
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ)  printf
	@mv $(PRINTF_DIR)/libftprintf.a libft.a
	@$(ARCHIVE) $(NAME) $(OBJ)
	
clean:
	@$(MAKE) -C $(PRINTF_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re printf