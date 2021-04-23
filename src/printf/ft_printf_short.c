/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:39:11 by melperri          #+#    #+#             */
/*   Updated: 2021/01/27 19:05:59 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void		ft_print_us(va_list ap, t_flags *flags)
{
	unsigned short	u;
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

static void	ft_flag_on_hexmin_us(t_flags *flags, char *s, unsigned short x)
{
	int	i;

	i = -1;
	if (x == 0 && flags->width && flags->point && !flags->preci)
	{
		i = -1;
		while (++i < flags->width)
			flags->ret += write(1, " ", 1);
	}
	else if (x == 0 && !flags->width && flags->point && !flags->preci)
		;
	else
		ft_flags_hexmin(flags, s);
}

static void	ft_flag_on_hexmaj_us(t_flags *flags, char *s, unsigned short x)
{
	int	i;

	i = -1;
	if (x == 0 && flags->width && flags->point && !flags->preci)
	{
		i = -1;
		while (++i < flags->width)
			flags->ret += write(1, " ", 1);
	}
	else if (x == 0 && !flags->width && flags->point && !flags->preci)
		;
	else
		ft_flags_hexmaj(flags, s);
}

void		ft_print_hexmin_us(va_list ap, t_flags *flags)
{
	unsigned short	x;
	char			*s;

	x = va_arg(ap, unsigned int);
	s = ft_utoa_base(x, BASEHEXMIN);
	if (x == 0)
		flags->hash = FALSE;
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
		ft_flag_on_hexmin_us(flags, s, x);
	else
	{
		if (flags->hash)
			flags->ret += write(1, "0x", 2);
		flags->ret += write(1, s, flags->len);
	}
	free(s);
	s = NULL;
}

void		ft_print_hexmaj_us(va_list ap, t_flags *flags)
{
	unsigned short	x;
	char			*s;

	x = va_arg(ap, unsigned int);
	s = ft_utoa_base(x, BASEHEXMIN);
	if (x == 0)
		flags->hash = FALSE;
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
		ft_flag_on_hexmaj_us(flags, s, x);
	else
	{
		if (flags->hash)
			flags->ret += write(1, "0X", 2);
		flags->ret += write(1, s, flags->len);
	}
	free(s);
	s = NULL;
}
