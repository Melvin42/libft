/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:01:01 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 11:58:00 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_preci_addr(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (flags->moins)
	{
		flags->ret += write(1, "0x", 2);
		flags->ret += write(1, s, flags->len);
		i = flags->len + 2;
		while (++i <= flags->width)
			flags->ret += write(1, " ", 1);
	}
	else
	{
		i += 2;
		while (++i < flags->width - flags->len)
			flags->ret += write(1, " ", 1);
		flags->ret += write(1, "0x", 2);
		flags->ret += write(1, s, flags->len);
	}
}

static void	ft_nopreci_addr(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (!flags->moins)
	{
		i += 2;
		while (++i < flags->width - flags->len)
			flags->ret += write(1, " ", 1);
		flags->ret += write(1, "0x", 2);
		flags->ret += write(1, s, flags->len);
	}
	else
	{
		flags->ret += write(1, "0x", 2);
		flags->ret += write(1, s, flags->len);
		i = flags->len + 2;
		while (++i <= flags->width)
			flags->ret += write(1, " ", 1);
	}
}

void		ft_flags_addr(t_flags *flags, char *s)
{
	if (!flags->point)
		ft_nopreci_addr(flags, s);
	else
		ft_preci_addr(flags, s);
}
