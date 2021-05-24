/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:50:58 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 20:19:57 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

static char	*cpy_line(int i, char *tmp)
{
	char	*line;

	if (!tmp)
	{
		line = malloc(sizeof(char) * 1);
		if (!line)
			return (NULL);
		line[0] = '\0';
		return (line);
	}
	while (tmp[++i])
		if (tmp[i] == '\n')
			break ;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
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

static int	read_file(t_gnl *gnl, int fd)
{
	while (1)
	{
		gnl->ret = read(fd, gnl->buf, BUFFER_SIZE);
		if (gnl->ret == 0)
			break ;
		else if (gnl->ret == -1)
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

static int	is_line(char *tmp)
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

static int	len_to_sub(t_gnl *gnl)
{
	gnl->i = -1;
	while (gnl->tmp[++gnl->i])
		if (gnl->tmp[gnl->i] == '\n')
			break ;
	return (gnl->i);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl	gnl;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (gnl.tmp)
	{
		if (read_file(&gnl, fd) == -1)
			return (-1);
		gnl.i = len_to_sub(&gnl);
		gnl.tofree = gnl.tmp;
		gnl.tmp = ft_substr(gnl.tmp, gnl.i + 1, ft_strlen(gnl.tmp) - gnl.i);
		free(gnl.tofree);
	}
	if (!gnl.tmp)
		if (read_file(&gnl, fd) == -1)
			return (-1);
	*line = cpy_line(-1, gnl.tmp);
	if (is_line(gnl.tmp) > 0)
		return (1);
	free(gnl.tmp);
	gnl.tmp = NULL;
	return (0);
}
