/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:18:39 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 12:22:50 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	flag_zero_string(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (!flags->moins)
	{
		while (++i < flags->width - flags->preci)
			flags->ret += write(1, " ", 1);
		flags->ret += write(1, s, flags->preci);
	}
	else
	{
		if (flags->len < flags->preci)
		{
			flags->ret += write(1, s, flags->len);
			i = flags->len;
		}
		else
		{
			flags->ret += write(1, s, flags->preci);
			i = flags->preci;
		}
		while (++i < flags->width)
			flags->ret += write(1, " ", 1);
	}
}

static void	ft_nopreci_string(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (!flags->moins)
	{
		while (++i < flags->width - flags->len)
			flags->ret += write(1, " ", 1);
		flags->ret += write(1, s, flags->len);
	}
	else
	{
		flags->ret += write(1, s, flags->len);
		i = flags->len;
		while (++i <= flags->width)
			flags->ret += write(1, " ", 1);
	}
}

static void	ft_preci_string(t_flags *flags, char *s)
{
	if (!flags->zero)
		no_flag_zero_string(flags, s);
	else
		flag_zero_string(flags, s);
}

void		ft_flags_string(t_flags *flags, char *s)
{
	if (!flags->point)
		ft_nopreci_string(flags, s);
	else
		ft_preci_string(flags, s);
}
