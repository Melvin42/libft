/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../inc/ft_printf.hexmaj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:55:04 by melperri          #+#    #+#             */
/*   Updated: 2021/01/27 20:03:59 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_flag_on_hexmaj(t_flags *flags, char *s, unsigned int x)
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

void		ft_print_hexmaj(va_list ap, t_flags *flags)
{
	unsigned int	x;
	char			*s;

	x = va_arg(ap, unsigned int);
	s = ft_utoa_base(x, BASEHEXMAJ);
	if (x == 0)
		flags->hash = FALSE;
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
		ft_flag_on_hexmaj(flags, s, x);
	else
	{
		if (flags->hash)
			flags->ret += write(1, "0X", 2);
		flags->ret += write(1, s, flags->len);
	}
	free(s);
	s = NULL;
}

void		ft_nopreci_hexmaj2(t_flags *flags, char *s, int i)
{
	if (flags->hash)
		flags->ret += write(1, "0X", 2);
	while (++i < flags->width - flags->len)
		flags->ret += write(1, "0", 1);
	flags->ret += write(1, s, flags->len);
}
