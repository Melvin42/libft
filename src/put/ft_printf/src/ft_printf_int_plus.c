/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_plus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:02:05 by melperri          #+#    #+#             */
/*   Updated: 2021/01/27 19:02:06 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_preci_int_plus_moins(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	flags->ret += write(1, "+", 1);
	while (++i < flags->preci - flags->len)
		flags->ret += write(1, "0", 1);
	flags->ret += write(1, s, flags->len);
	i += flags->len;
	while (++i < flags->width)
		flags->ret += write(1, " ", 1);
}

static void	ft_preci_int_plus_no_moins(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (flags->len < flags->preci)
		while (++i < flags->width - flags->preci - 1)
			flags->ret += write(1, " ", 1);
	else
		while (++i < flags->width - flags->len - 1)
			flags->ret += write(1, " ", 1);
	flags->ret += write(1, "+", 1);
	i = 0;
	while (++i <= flags->preci - flags->len)
		flags->ret += write(1, "0", 1);
	flags->ret += write(1, s, flags->len);
}

static void	ft_preci_int_plus(t_flags *flags, char *s)
{
	if (flags->moins)
		ft_preci_int_plus_moins(flags, s);
	else
		ft_preci_int_plus_no_moins(flags, s);
}

static void	ft_nopreci_int_plus(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (!flags->moins && !flags->zero)
	{
		while (++i < flags->width - flags->len - 1)
			flags->ret += write(1, " ", 1);
		flags->ret += write(1, "+", 1);
		flags->ret += write(1, s, flags->len);
	}
	else if (flags->moins && !flags->zero)
	{
		flags->ret += write(1, "+", 1);
		flags->ret += write(1, s, flags->len);
		i = flags->len;
		while (++i < flags->width)
			flags->ret += write(1, " ", 1);
	}
	else
	{
		flags->ret += write(1, "+", 1);
		while (++i < flags->width - flags->len - 1)
			flags->ret += write(1, "0", 1);
		flags->ret += write(1, s, flags->len);
	}
}

void		ft_flags_int_plus(t_flags *flags, char *s)
{
	if (!flags->point)
		ft_nopreci_int_plus(flags, s);
	else
		ft_preci_int_plus(flags, s);
}
