/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../../inc/ft_printf.hexmin2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:54:01 by melperri          #+#    #+#             */
/*   Updated: 2021/01/27 19:54:03 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	ft_preci_hexmin_moins(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (flags->hash)
		flags->ret += write(1, "0x", 2);
	while (++i < flags->preci - flags->len)
		flags->ret += write(1, "0", 1);
	flags->ret += write(1, s, flags->len);
	i += flags->len;
	while (++i <= flags->width)
		flags->ret += write(1, " ", 1);
}

static void	ft_preci_hexmin_no_moins(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (flags->len < flags->preci)
		while (++i < flags->width - flags->preci)
			flags->ret += write(1, " ", 1);
	else
		while (++i < flags->width - flags->len)
			flags->ret += write(1, " ", 1);
	if (flags->hash)
		flags->ret += write(1, "0x", 2);
	i = 0;
	while (++i <= flags->preci - flags->len)
		flags->ret += write(1, "0", 1);
	flags->ret += write(1, s, flags->len);
}

static void	ft_preci_hexmin(t_flags *flags, char *s)
{
	if (flags->moins)
		ft_preci_hexmin_moins(flags, s);
	else
		ft_preci_hexmin_no_moins(flags, s);
}

static void	ft_nopreci_hexmin(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (!flags->moins && !flags->zero)
	{
		while (++i < flags->width - flags->len)
			flags->ret += write(1, " ", 1);
		if (flags->hash)
			flags->ret += write(1, "0x", 2);
		flags->ret += write(1, s, flags->len);
	}
	else if (flags->moins && !flags->zero)
	{
		if (flags->hash)
			flags->ret += write(1, "0x", 2);
		flags->ret += write(1, s, flags->len);
		i = flags->len;
		while (++i <= flags->width)
			flags->ret += write(1, " ", 1);
	}
	else
		ft_nopreci_hexmin2(flags, s, i);
}

void		ft_flags_hexmin(t_flags *flags, char *s)
{
	if (flags->hash)
	{
		if (flags->width && flags->width > 1)
			flags->width -= 2;
		else if (flags->width && flags->width == 1)
			flags->width = FALSE;
	}
	if (!flags->point)
		ft_nopreci_hexmin(flags, s);
	else
		ft_preci_hexmin(flags, s);
}
