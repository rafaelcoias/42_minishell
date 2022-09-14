/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:43:09 by rade-sar          #+#    #+#             */
/*   Updated: 2022/07/13 05:14:51 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* INCLUDES */

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <ctype.h>
# include <sys/types.h>
# include <sys/wait.h>

/* COLORS */

# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

/* STRUCTS */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* LIBFT */

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char		**ft_split(char const *s, char c);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strcpy(char *dest, char *src);

void		ft_free_mtx(char **mtx);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_bzero(void *s, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putlst_fd(char **lst, int fd);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));

void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);

int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_lstsize(t_list *lst);
int			ft_lstsize(t_list *lst);

long long	ft_atol(const char *str);

/* GET_NEXT_LINE */

char		*get_next_line(int fd);
char		*ft_find_nl(char *str);
char		*ft_strcat(char *dest, char *src);
char		*ft_new_save(char *str);
int			ft_count_nl(char *str);

/* FT_PRINT_F */

int			ft_printf(const char *str, ...);
int			ft_check_flag(va_list list, char c);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_put_unsigned_nbr(unsigned int n);
int			ft_putvoid(unsigned long n, char *base, int start);
int			ft_puthexa(unsigned int n, char *base);

#endif
