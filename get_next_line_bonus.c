/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:43:34 by melperri          #+#    #+#             */
/*   Updated: 2021/01/07 17:20:48 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*cpy_line(char *tmp)
{
	int		i;
	char	*line;

	i = -1;
	if (!tmp)
	{
		if (!(line = malloc(sizeof(char) * 1)))
			return (NULL);
		line[0] = '\0';
		return (line);
	}
	while (tmp[++i])
		if (tmp[i] == '\n')
			break ;
	if (!(line = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] == '\n')
			break ;
		line[i] = tmp[i];
	}
	line[i] = '\0';
	return (line);
}

int		read_file(t_gnl *gnl, int fd)
{
	while ((gnl->ret = read(fd, gnl->buf, BUFFER_SIZE)))
	{
		if (gnl->ret == -1)
			return (-1);
		gnl->buf[gnl->ret] = '\0';
		if (!gnl->tmp)
			gnl->tmp = ft_strdup(gnl->buf);
		else
		{
			gnl->tofree = gnl->tmp;
			gnl->tmp = ft_strjoin(gnl->tmp, gnl->buf);
			free(gnl->tofree);
		}
		if (ft_strchr(gnl->buf, '\n'))
			break ;
	}
	return (0);
}

int		is_line(char *tmp)
{
	int	i;

	i = -1;
	if (!tmp)
		return (-1);
	while (tmp[++i])
		if (tmp[i] == '\n')
			return (1);
	return (0);
}

int		len_to_sub(t_gnl *gnl)
{
	gnl->i = -1;
	while (gnl->tmp[++gnl->i])
		if (gnl->tmp[gnl->i] == '\n')
			break ;
	return (gnl->i);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	gnl[OPEN_MAX];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (gnl[fd].tmp)
	{
		if (read_file(&gnl[fd], fd) == -1)
			return (-1);
		gnl[fd].i = len_to_sub(&gnl[fd]);
		gnl[fd].tofree = gnl[fd].tmp;
		gnl[fd].tmp = ft_substr(gnl[fd].tmp,
				gnl[fd].i + 1, ft_strlen(gnl[fd].tmp) - gnl[fd].i);
		free(gnl[fd].tofree);
	}
	if (!gnl[fd].tmp)
		if (read_file(&gnl[fd], fd) == -1)
			return (-1);
	*line = cpy_line(gnl[fd].tmp);
	if (is_line(gnl[fd].tmp) > 0)
		return (1);
	free(gnl[fd].tmp);
	gnl[fd].tmp = NULL;
	return (0);
}
