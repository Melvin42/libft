/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:42:26 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 16:11:17 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 32

# include "libft.h"
# include <fcntl.h>

typedef struct s_gnl
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;
	char	*tmp;
	int		i;
	char	*tofree;
}	t_gnl;

char			*cpy_line(char *tmp);
int				is_line(char *tmp);
int				read_file(t_gnl *gnl, int fd);
int				get_next_line(int fd, char **line);

#endif
