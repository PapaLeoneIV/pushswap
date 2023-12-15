/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:53:01 by rileone           #+#    #+#             */
/*   Updated: 2023/10/20 22:53:01 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct dll_list
{
	void *val;
    int index;
	struct dll_list *prev;
	struct dll_list *next;

} dll_list;

typedef struct item {
	int key;
	int value;
	struct item* next;
} item;

typedef struct hash_map {
	int size;
	int n_item;
	item** array;
} hash_map;

void	error_fn();
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putchr(char c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isnumber(char *str);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_tolower(int i);
int		ft_toupper(int i);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **head, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int 	ft_check_for_dupl(int *arr, int size);
void	ft_insert_in_hash_map(hash_map* map, int key);
hash_map*ft_create_hash_map(int size) ;
int		ft_hash_fn(int key, int size);
void	ft_free_hash_map(hash_map* map);
int		ft_get_frequency(hash_map* map, int key);

void	ft_dll_insert_head(dll_list **head, dll_list *new);
void	ft_dll_insert_tail(dll_list **head, dll_list *new);
dll_list*ft_dll_new(void *val);
void	ft_dll_return_head(dll_list **lst);
void	ft_dll_return_tail(dll_list **lst);
int		ft_dll_size(dll_list *dll);
dll_list*ft_dll_initi(int *arr, int len);
void	ft_dll_clear(dll_list **lst, void (*del)(void *));
dll_list* ft_dll_initi_to(int len, int value);


int* ft_LIS(int* arr, int len);




#endif