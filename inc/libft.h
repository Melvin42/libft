/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:07:12 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 16:12:21 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <stdio.h>
# include <limits.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isgraph(int c);
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);
int				ft_str_is_alpha(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_printable(char *str);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_uppercase(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strupcase(char *str);
char			*ft_strcpy(char *dest, const char *src);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy_rev(void *dest, const void *src, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *str, char c);
char			*ft_itoa(int n);
char			*ft_ltoa(long n);
char			*ft_lltoa(long long n);
char			*ft_utoa(unsigned int n);
char			*ft_ultoa(unsigned long n);
char			*ft_ulltoa(unsigned long long n);
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
int				findchar(char c, char *base);
int				stopatoi(char c, char *base);
int				checkbase(char *base);
char			*ft_itoa_base(int nb, char *base);
char			*ft_utoa_base(unsigned int nb, char *base);
char			*ft_ultoa_base(unsigned long int nb, char *base);
char			*ft_ulltoa_base(unsigned long long nb, char *base);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
int				ft_atoi_base(char *str, char *base);
int				get_next_line(int fd, char **line);

#endif
