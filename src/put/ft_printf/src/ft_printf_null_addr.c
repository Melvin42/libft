/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_null_addr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:56:04 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 12:06:51 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_preci_null_addr(t_flags *flags)
{
	int	i;

	if (flags->moins)
	{
		flags->ret += write(1, "0x", 2);
		i = 2;
		while (++i <= flags->width)
			flags->ret += write(1, " ", 1);
	}
	else
	{
		i = 1;
		while (++i < flags->width)
			flags->ret += write(1, " ", 1);
		flags->ret += write(1, "0x", 2);
	}
}

static void	ft_nopreci_null_addr(t_flags *flags)
{
	int	i;

	if (flags->moins)
	{
		flags->ret += write(1, "0x0", 3);
		i = 3;
		while (++i <= flags->width)
			flags->ret += write(1, " ", 1);
	}
	else
	{
		i = 2;
		while (++i < flags->width)
			flags->ret += write(1, " ", 1);
		flags->ret += write(1, "0x0", 3);
	}
}

void		null_addr(t_flags *flags)
{
	if (!flags->point)
		ft_nopreci_null_addr(flags);
	else
		ft_preci_null_addr(flags);
}
