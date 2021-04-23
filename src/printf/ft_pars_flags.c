/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:43:40 by melperri          #+#    #+#             */
/*   Updated: 2021/01/27 18:55:26 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int			is_flag_on(t_flags *flags)
{
	if (flags->moins || flags->zero || flags->width || flags->point
			|| flags->preci || flags->star)
	{
		if (flags->moins && flags->zero)
			flags->zero = FALSE;
		return (TRUE);
	}
	else
		return (FALSE);
}

int			is_bonus_flags(t_flags *flags, char c)
{
	if (c == ' ')
		flags->space = TRUE;
	else if (c == '#')
		flags->hash = TRUE;
	else if (c == '+')
		flags->plus = TRUE;
	if (flags->space && flags->plus)
		flags->space = FALSE;
	if (flags->hash || flags->space || flags->plus)
		return (TRUE);
	else
		return (FALSE);
}

static void	fill_struct_part3(t_flags *flags, const char **full, va_list ap)
{
	while (ft_isdigit(**full))
		(*full)++;
	if (!flags->preci)
		while (**full == '*')
		{
			flags->star = TRUE;
			(*full)++;
		}
	if (flags->star)
	{
		flags->preci = ft_flag_star_preci(flags, ap);
		flags->star = FALSE;
	}
}

static void	fill_struct_part2(t_flags *flags, const char **full, va_list ap)
{
	if (flags->star && !flags->width)
	{
		flags->width = ft_flag_star_width(flags, ap);
		flags->star = FALSE;
	}
	while (ft_isdigit(**full))
		(*full)++;
	if (**full == '.')
	{
		flags->point = TRUE;
		(*full)++;
	}
	if (flags->point)
		if (ft_isdigit(**full))
			flags->preci = ft_atoi(&(**full));
	fill_struct_part3(flags, full, ap);
}

void		fill_struct_part1(t_flags *flags, const char **full, va_list ap)
{
	while (**full == '-' || **full == '#' || **full == ' ' || **full == '+')
	{
		if (is_bonus_flags(flags, **full))
			(*full)++;
		if (**full == '-')
		{
			flags->moins = TRUE;
			(*full)++;
		}
	}
	while (**full == '0')
	{
		flags->zero = TRUE;
		(*full)++;
	}
	while (**full == '*')
	{
		flags->star = TRUE;
		(*full)++;
	}
	if (ft_isdigit(**full))
		flags->width = ft_atoi(&(**full));
	fill_struct_part2(flags, full, ap);
}
