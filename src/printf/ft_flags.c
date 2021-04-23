/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:54:32 by melperri          #+#    #+#             */
/*   Updated: 2021/01/27 18:54:35 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_flag_space(t_flags *flags, int d)
{
	if (d >= 0)
	{
		if (flags->space && !flags->plus)
			flags->ret += write(1, " ", 1);
	}
}

int		ft_flag_star_width(t_flags *flags, va_list ap)
{
	int	star;

	star = va_arg(ap, int);
	if (star < 0)
	{
		flags->moins = TRUE;
		star *= -1;
	}
	return (star);
}

int		ft_flag_star_preci(t_flags *flags, va_list ap)
{
	int	star;

	star = va_arg(ap, int);
	if (star < 0)
	{
		flags->point = FALSE;
		return (FALSE);
	}
	else
		return (star);
}
