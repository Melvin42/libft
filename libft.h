/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 13:01:04 by melperri          #+#    #+#             */
/*   Updated: 2020/10/09 11:31:50 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

void	        *ft_memset(void *s, int c, unsigned int n);
void	        ft_bzero(void *s, unsigned int n);
void	        *ft_memcpy(void *dest, const void *src, unsigned int n);
void	        *ft_memccpy(void *dest, const void *src, int c, unsigned int n);
//ft_memmove
//ft_memchr
//ft_memcmp
int		        ft_strlen(const char *str);
int		        ft_isalpha(int c);
int		        ft_isdigit(int c);
int		        ft_isalnum(int c);
int		        ft_isascii(int c);
int		        ft_isprint(int c);
int		        ft_toupper(int c);
int		        ft_tolower(int c);
char	        *ft_strchr(const char *s, int c);
char	        *ft_strrchr(const char *s, int c);
int		        ft_strncmp(const char *s1, const char *s2, unsigned int n);
unsigned int    ft_strlcpy(char *dst, const char *src, unsigned int size);
unsigned int    ft_strlcat(char *dst, const char *src, unsigned int size);
//strnstr
int             ft_atoi(const char *str);
//calloc
char	        *ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char	        *ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char	        **ft_split(char const *str, char c);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
//t_list			*ft_lstnew(void *content);
//void			ft_lstadd_front(t_list **alst, t_list *new);
//int				ft_lstsize(t_list *lst);
//void			ft_lstadd_back(t_list **alst, t_list *new);
//void			ft_lstdelone(t_list *lst, void (*del)(void *));
//void			ft_lstclear(t_list **lst, void (*del)(void *));
//void			ft_lstiter(t_list *lst, void (*f)(void *));
//void			*ft_lstmap(t_list *lst void *(*f)(void *), void (*del)(void *));


#endif
