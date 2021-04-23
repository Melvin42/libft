/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:56:59 by melperri          #+#    #+#             */
/*   Updated: 2021/01/27 20:10:55 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	ft_print_int3(t_flags *flags, int d)
{
	int	i;

	i = -1;
	if (flags->plus)
		flags->width--;
	if (flags->moins)
	{
		ft_flag_space(flags, d);
		if (flags->plus)
			flags->ret += write(1, "+", 1);
	}
	while (++i < flags->width)
		flags->ret += write(1, " ", 1);
	if (!flags->moins)
	{
		ft_flag_space(flags, d);
		if (flags->plus)
			flags->ret += write(1, "+", 1);
	}
}

static void	ft_print_int2(t_flags *flags, char *s, int d)
{
	if (d == 0 && flags->width && flags->point && !flags->preci)
		ft_print_int3(flags, d);
	else if (d == 0 && !flags->width && flags->point && !flags->preci)
	{
		if (flags->plus)
			flags->ret += write(1, "+", 1);
		else
			ft_flag_space(flags, d);
	}
	else if (d < 0)
		ft_flags_int_neg(flags, s);
	else if (d >= 0 && flags->plus)
		ft_flags_int_plus(flags, s);
	else
		ft_flags_int(flags, s);
}

void		ft_print_int(va_list ap, t_flags *flags)
{
	int		d;
	char	*s;

	d = va_arg(ap, int);
	s = ft_itoa(d);
	flags->len = (int)ft_strlen(s);
	if (flags->space && flags->width && d >= 0)
		flags->width--;
	if (is_flag_on(flags))
		ft_print_int2(flags, s, d);
	else
	{
		ft_flag_space(flags, d);
		if (flags->plus && d >= 0)
			flags->ret += write(1, "+", 1);
		flags->ret += write(1, s, flags->len);
	}
	free(s);
	s = NULL;
}

void		ft_print_u(va_list ap, t_flags *flags)
{
	unsigned int	u;
	int				i;
	char			*s;

	u = va_arg(ap, unsigned int);
	s = ft_utoa(u);
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
	{
		if (u == 0 && flags->width && flags->point && !flags->preci)
		{
			i = -1;
			while (++i < flags->width)
				flags->ret += write(1, " ", 1);
		}
		else if (u == 0 && !flags->width && flags->point && !flags->preci)
			;
		else
			ft_flags_int(flags, s);
	}
	else
		flags->ret += write(1, s, flags->len);
	free(s);
	s = NULL;
}
