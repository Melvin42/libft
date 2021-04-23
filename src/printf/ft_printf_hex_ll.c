/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../../inc/ft_printf.hex_ll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:06:40 by melperri          #+#    #+#             */
/*   Updated: 2021/01/28 19:06:41 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	ft_flag_on_hexmin_ll(t_flags *flags, char *s, unsigned long long x)
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

static void	ft_flag_on_hexmaj_ll(t_flags *flags, char *s, unsigned long long x)
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

void		ft_print_hexmin_ull(va_list ap, t_flags *flags)
{
	unsigned long long	x;
	char				*s;

	x = va_arg(ap, unsigned long long);
	s = ft_ulltoa_base(x, BASEHEXMIN);
	if (x == 0)
		flags->hash = FALSE;
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
		ft_flag_on_hexmin_ll(flags, s, x);
	else
	{
		if (flags->hash)
			flags->ret += write(1, "0x", 2);
		flags->ret += write(1, s, flags->len);
	}
	free(s);
	s = NULL;
}

void		ft_print_hexmaj_ull(va_list ap, t_flags *flags)
{
	unsigned long long	x;
	char				*s;

	x = va_arg(ap, unsigned long long);
	s = ft_ulltoa_base(x, BASEHEXMIN);
	if (x == 0)
		flags->hash = FALSE;
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
		ft_flag_on_hexmaj_ll(flags, s, x);
	else
	{
		if (flags->hash)
			flags->ret += write(1, "0X", 2);
		flags->ret += write(1, s, flags->len);
	}
	free(s);
	s = NULL;
}
