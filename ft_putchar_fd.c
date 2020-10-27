/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:15:02 by melperri          #+#    #+#             */
/*   Updated: 2020/10/08 17:16:43 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char chr;

	if (fd != -1)
	{
		if ((unsigned char)c >= 128)
		{
			chr = (unsigned char)c / 64 + 192;
			write(fd, &chr, 1);
			chr = (unsigned char)c % 64 + 128;
			write(fd, &chr, 1);
		}
		else
		{
			write(fd, &c, 1);
		}
	}
}
/*
int main()
{
	ft_putchar_fd(255, 1);
	return (0);
}
*/
