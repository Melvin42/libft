/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../inc/ft_printf.hex_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:31:55 by melperri          #+#    #+#             */
/*   Updated: 2021/01/27 19:31:57 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_flags_on_hexmaj_ul(t_flags *flags, char *s, unsigned long x)
{
	int	i;

	i = -1;
	if (x == 0 && flags->width && flags->point && !flags->preci)
		while (++i < flags->width)
			flags->ret += write(1, " ", 1);
	else if (x == 0 && !flags->width && flags->point && !flags->preci)
		;
	else
		ft_flags_hexmin(flags, s);
}

static void	ft_flags_on_hexmin_ul(t_flags *flags, char *s, unsigned long x)
{
	int	i;

	i = -1;
	if (x == 0 && flags->width && flags->point && !flags->preci)
		while (++i < flags->width)
			flags->ret += write(1, " ", 1);
	else if (x == 0 && !flags->width && flags->point && !flags->preci)
		;
	else
		ft_flags_hexmin(flags, s);
}

void		ft_print_hexmin_ul(va_list ap, t_flags *flags)
{
	unsigned long	x;
	char			*s;

	x = va_arg(ap, unsigned long);
	s = ft_ultoa_base(x, BASEHEXMIN);
	if (x == 0)
		flags->hash = FALSE;
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
		ft_flags_on_hexmin_ul(flags, s, x);
	else
	{
		if (flags->hash)
			flags->ret += write(1, "0x", 2);
		flags->ret += write(1, s, flags->len);
	}
	free(s);
	s = NULL;
}

void		ft_print_hexmaj_ul(va_list ap, t_flags *flags)
{
	unsigned long	x;
	char			*s;

	x = va_arg(ap, unsigned long);
	s = ft_ultoa_base(x, BASEHEXMIN);
	if (x == 0)
		flags->hash = FALSE;
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
		ft_flags_on_hexmaj_ul(flags, s, x);
	else
	{
		if (flags->hash)
			flags->ret += write(1, "0X", 2);
		flags->ret += write(1, s, flags->len);
	}
	free(s);
	s = NULL;
}
