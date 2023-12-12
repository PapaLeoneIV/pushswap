NAME = libft.a
HNAME = libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c -g
ARCHIVE = ar rc
HASH_DIR = hash_map
DLL_LIST_DIR = dll_list
PRINTF_DIR = printf


SRC = ./ft_isalnum.c \
			./ft_isalpha.c \
			./ft_isascii.c \
			./ft_isdigit.c \
			./ft_isprint.c \
			./ft_strlen.c \
			./ft_memset.c \
			./ft_bzero.c \
			./ft_memcpy.c \
			./ft_memmove.c \
			./ft_strlcpy.c \
			./ft_substr.c \
			./ft_strlcat.c \
			./ft_tolower.c \
			./ft_toupper.c \
			./ft_strchr.c \
			./ft_strrchr.c \
			./ft_strjoin.c \
			./ft_strncmp.c \
			./ft_memchr.c \
			./ft_memcmp.c \
			./ft_strnstr.c \
			./ft_atoi.c \
			./ft_calloc.c \
			./ft_itoa.c \
			./ft_strdup.c \
			./ft_strtrim.c \
			./ft_split.c \
			./ft_strmapi.c \
			./ft_striteri.c \
			./ft_putchar_fd.c \
			./ft_putstr_fd.c \
			./ft_putendl_fd.c \
			./ft_putnbr_fd.c \
			./ft_putchr.c \
			./ft_putstr.c \
			./ft_putnbr.c \
			./ft_isnumber.c \
			./error_fn.c \
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
			$(DLL_LIST_DIR)/ft_dll_init_to_zero.c \

SRC_BONUS =  ./ft_lstnew.c \
			./ft_lstadd_front.c \
			./ft_lstsize.c \
			./ft_lstlast.c \
			./ft_lstadd_back.c \
			./ft_lstdelone.c \
			./ft_lstclear.c \
			./ft_lstiter.c \
			./ft_lstmap.c \


OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: printf $(NAME)


%.o: %.c
	@$(COMPILE) $< -o $@ -I. -Iprintf

printf:
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(OBJ_BONUS) printf
	@mv $(PRINTF_DIR)/libftprintf.a libft.a
	@$(ARCHIVE) $(NAME) $(OBJ)

clean:
	@$(MAKE) -C $(PRINTF_DIR) clean
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re printf