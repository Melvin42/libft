/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:10:05 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 12:23:04 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	no_flag_zero_string_moins(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (flags->preci <= flags->len)
	{
		flags->ret += write(1, s, flags->preci);
		i = flags->preci;
	}
	else
	{
		flags->ret += write(1, s, flags->len);
		i = flags->len;
	}
	while (++i <= flags->width)
		flags->ret += write(1, " ", 1);
}

static void	no_flag_zero_string_no_moins(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (flags->width)
	{
		if (flags->preci <= flags->len)
		{
			while (++i < flags->width - flags->preci)
				flags->ret += write(1, " ", 1);
			if (i > flags->width)
				return ;
		}
		else
		{
			while (++i < flags->width - flags->len)
				flags->ret += write(1, " ", 1);
			flags->ret += write(1, s, flags->len);
			return ;
		}
	}
	if (flags->len >= flags->preci)
		flags->ret += write(1, s, flags->preci);
	else
		flags->ret += write(1, s, flags->len);
}

void		no_flag_zero_string(t_flags *flags, char *s)
{
	if (flags->moins)
		no_flag_zero_string_moins(flags, s);
	else
		no_flag_zero_string_no_moins(flags, s);
}
