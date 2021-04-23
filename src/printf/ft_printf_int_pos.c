/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:46:24 by melperri          #+#    #+#             */
/*   Updated: 2021/01/27 19:02:33 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	ft_preci_int_moins(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	ft_flag_space(flags, 1);
	while (++i < flags->preci - flags->len)
		flags->ret += write(1, "0", 1);
	flags->ret += write(1, s, flags->len);
	i += flags->len;
	while (++i <= flags->width)
		flags->ret += write(1, " ", 1);
}

static void	ft_preci_int_no_moins(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (flags->len < flags->preci)
		while (++i < flags->width - flags->preci)
			flags->ret += write(1, " ", 1);
	else
		while (++i < flags->width - flags->len)
			flags->ret += write(1, " ", 1);
	i = 0;
	ft_flag_space(flags, 1);
	while (++i <= flags->preci - flags->len)
		flags->ret += write(1, "0", 1);
	flags->ret += write(1, s, flags->len);
}

static void	ft_preci_int(t_flags *flags, char *s)
{
	if (flags->moins)
		ft_preci_int_moins(flags, s);
	else
		ft_preci_int_no_moins(flags, s);
}

static void	ft_nopreci_int(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (!flags->moins && !flags->zero)
	{
		while (++i < flags->width - flags->len)
			flags->ret += write(1, " ", 1);
		ft_flag_space(flags, 1);
		flags->ret += write(1, s, flags->len);
	}
	else if (flags->moins && !flags->zero)
	{
		ft_flag_space(flags, 1);
		flags->ret += write(1, s, flags->len);
		i = flags->len;
		while (++i <= flags->width)
			flags->ret += write(1, " ", 1);
	}
	else
	{
		ft_flag_space(flags, 1);
		while (++i < flags->width - flags->len)
			flags->ret += write(1, "0", 1);
		flags->ret += write(1, s, flags->len);
	}
}

void		ft_flags_int(t_flags *flags, char *s)
{
	if (!flags->point)
	{
		ft_nopreci_int(flags, s);
	}
	else
		ft_preci_int(flags, s);
}
